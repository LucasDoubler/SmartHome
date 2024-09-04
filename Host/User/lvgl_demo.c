#include "lvgl_demo.h"
#include "./BSP/LED/led.h"
#include "./BSP/DHT22/dht22.h"
#include "FreeRTOS.h"
#include "task.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "ui.h"
#include "semphr.h"
#include "ff.h"
#include "timers.h"
#include "./BSP/ADC/adc.h"
#include "./BSP/RTC/rtc.h"
#include "queue.h"
/******************************************************************************************************/
/*自定义全局变量*/
// 全局变量

extern UART_HandleTypeDef huart3;
extern lv_coord_t ui_Chart1_series_1_array[]; // 温度图表数据
extern lv_coord_t ui_Chart2_series_1_array[]; // 湿度图表数据
extern lv_chart_series_t *ui_Chart1_series_1;
extern lv_chart_series_t *ui_Chart2_series_1;

QueueHandle_t bluetoothQueue; // 蓝牙队列

TimerHandle_t xTimer;                // 定时器句柄
TaskHandle_t xTemperatureTaskHandle; // 温度任务句柄

SemaphoreHandle_t xSensorDataSemaphore = NULL; // 传感器数据储存任务通知信号量
/* DHT22数据缓存 */
extern uint8_t DHT_buffer[5];
/* 温湿度数据 */
uint8_t temperature = 0;
uint8_t humidity = 0;
SemaphoreHandle_t xMutex; // 互斥信号量

SensorData_t Sdata;
#define MAX_ENTRIES 12                // 缓冲区大小
SensorData_t dataBuffer[MAX_ENTRIES]; // 传感器数据缓冲区，用于保存最近MAX_ENTRIES个数据
int bufferIndex = 0;
lv_obj_t *pagestate;
/******************************************************************************************************/
/*自定义函数*/
// 将传感器数据添加到缓冲区
void AddDataToBuffer(SensorData_t *data)
{
    // 保存数据到循环缓冲区
    dataBuffer[bufferIndex] = *data;
    bufferIndex = (bufferIndex + 1) % MAX_ENTRIES;
}
// 将传感器数据写入SD卡
void WriteDataToSD(SensorData_t *data)
{
    FIL file;
    FRESULT res;
    char buffer[64];
    AddDataToBuffer(data);
    res = f_open(&file, "0:\\LOG\\data.txt", FA_OPEN_APPEND | FA_WRITE);
    if (res == FR_OK)
    {
        /* 获取当前时间 */
        rtc_GetTime(data);
        snprintf(buffer, sizeof(buffer), "Time:%u:%u:%u %u-%u-%u\r\n T:%u H:%u ADC:%u %u %u %u\n",
                 data->hour, data->minute, data->second,
                 data->day, data->month, data->year,
                 data->temperature, data->humidity,
                 data->adcData[0], data->adcData[1], data->adcData[2],
                 data->adcData[3]);
        UINT bytesWritten;
        f_write(&file, buffer, strlen(buffer), &bytesWritten);
        f_close(&file);
    }
}

// 读取最近12次记录的函数
void ReadLast12Records(SensorData_t records[RECORD_COUNT])
{
    FIL file;
    FRESULT res;
    char buffer[128];
    int count = 0;
    int line_count = 0;

    // 打开记录文件
    res = f_open(&file, "0:\\LOG\\data.txt", FA_READ);
    if (res == FR_OK)
    {
        // 计算文件中的行数
        while (f_gets(buffer, sizeof(buffer), &file))
        {
            line_count++;
        }
        // 移动到最近12行的数据位置
        FSIZE_t start_line = (line_count > 24) ? line_count - RECORD_COUNT : 0;
        f_lseek(&file, 0); // 移动到文件开头
        line_count = 0;

        // 读取最近12行的数据
        while (f_gets(buffer, sizeof(buffer), &file))
        {
            if (line_count >= start_line)
            {
                // 解析时间和日期行
                sscanf(buffer, "Time:%hhu:%hhu:%hhu %hhu-%hhu-%hu",
                       &records[count].hour, &records[count].minute, &records[count].second,
                       &records[count].day, &records[count].month, &records[count].year);

                // 读取下一行（温度、湿度和ADC数据）
                f_gets(buffer, sizeof(buffer), &file);
                sscanf(buffer, " T:%hhu H:%hhu ADC:%hu %hu %hu %hu",
                       &records[count].temperature, &records[count].humidity,
                       &records[count].adcData[0], &records[count].adcData[1],
                       &records[count].adcData[2], &records[count].adcData[3]);
                printf("count:%d\n", count);
                printf("temperature:%d\n", records[count].temperature);
                printf("humidity:%d\n", records[count].humidity);
                count++;
            }
            line_count++;
        }

        // 关闭文件
        f_close(&file);
    }
    else
    {
        // 处理文件打开失败的情况
        printf("Failed to open file.\n");
    }
}

// 定时器回调函数
void vTimerCallback(TimerHandle_t xTimer)
{

    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // 释放信号量，通知 SensorDataStorage 任务
    xSemaphoreGiveFromISR(xSensorDataSemaphore, &xHigherPriorityTaskWoken);
}
/******************************************************************************************************/
/*FreeRTOS任务*/

/* START_TASK 任务
 * 优先级: 任务优先级 栈大小 任务句柄
 */
#define START_TASK_PRIO 1            /* 任务优先级 */
#define START_STK_SIZE 128           /* 栈大小 */
TaskHandle_t StartTask_Handler;      /* 任务句柄 */
void start_task(void *pvParameters); /* 任务函数 */

/* LV_DEMO_TASK 任务
 * 优先级: 任务优先级 栈大小 任务句柄
 */
#define LV_DEMO_TASK_PRIO 4            /* 任务优先级 */
#define LV_DEMO_STK_SIZE 512          /* 栈大小 */
TaskHandle_t LV_DEMOTask_Handler;      /* 任务句柄 */
void lv_demo_task(void *pvParameters); /* 任务函数 */

/* DHT22数据采集任务
 * 优先级: 任务优先级 栈大小 任务句柄
 */
#define DHT22_Task_PRIO 5            /* 任务优先级 */
#define DHT22_STK_SIZE 128        /* 栈大小 */
TaskHandle_t DHT22Task_Handler;      /* 任务句柄 */
void dht22_task(void *pvParameters); /* 任务函数 */

/* UI_TASK 更新LVGL传感器数据任务
 * 优先级: 任务优先级 栈大小 任务句柄
 */
#define UI_TASK_PRIO 7         /* 任务优先级 */
#define UI_STK_SIZE 512         /* 栈大小 */
TaskHandle_t UITask_Handler;     /* 任务句柄 */
void UITask(void *pvParameters); /* 任务函数 */

/* 传感器数据存储任务
 * 优先级: 任务优先级 栈大小 任务句柄
 */
#define SENSOR_DATA_STORAGE_TASK_PRIO 6     /* 任务优先级 */
#define SENSOR_DATA_STORAGE_STK_SIZE 512    /* 栈大小 */
TaskHandle_t SensorDataStorageTask_Handler; /* 任务句柄 */
void SensorDataStorage(void *pvParameters); /* 任务函数 */

/* HC-05蓝牙串口任务
 * 优先级: 任务优先级 栈大小 任务句柄
 */
#define HC_05_TASK_PRIO 8           /* 任务优先级 */
#define HC_05_STK_SIZE 256           /* 栈大小 */
TaskHandle_t HC_05Task_Handler;      /* 任务句柄 */
void HC_05_task(void *pvParameters); /* 任务函数 */

/******************************************************************************************************/

void lvgl_demo(void)
{
    lv_init();            /* lvgl系统初始化 */
    lv_port_disp_init();  /* lvgl显示接口初始化,需要在lv_init()之后调用 */
    lv_port_indev_init(); /* lvgl输入接口初始化,需要在lv_init()之后调用 */

    bluetoothQueue = xQueueCreate(10, sizeof(char *)); // 创建队列

    xSensorDataSemaphore = xSemaphoreCreateBinary(); // 创建二进制信号量
    xMutex = xSemaphoreCreateMutex();                // 创建互斥信号量
    xTaskCreate((TaskFunction_t)start_task,          /* 任务函数 */
                (const char *)"start_task",          /* 任务名称 */
                (uint16_t)START_STK_SIZE,            /* 栈大小 */
                (void *)NULL,                        /* 传递给任务函数的参数 */
                (UBaseType_t)START_TASK_PRIO,        /* 任务优先级 */
                (TaskHandle_t *)&StartTask_Handler); /* 任务句柄 */
    // 创建定时器
    xTimer = xTimerCreate("Timer", pdMS_TO_TICKS(60000), pdTRUE, (void *)0, vTimerCallback);
    if (xTimer != NULL)
    {
        xTimerStart(xTimer, 0);
    }
    vTaskStartScheduler(); /* 启动任务调度器 */
}

/**
 * @brief       start_task
 * @param       pvParameters : 传递给任务的参数(未使用)
 * @retval      无
 */
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL(); /* 进入临界区 */

    /* 创建LVGL任务 */
    xTaskCreate((TaskFunction_t)lv_demo_task,
                (const char *)"lv_demo_task",
                (uint16_t)LV_DEMO_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)LV_DEMO_TASK_PRIO,
                (TaskHandle_t *)&LV_DEMOTask_Handler);

    /* 创建DHT22任务 */
    xTaskCreate((TaskFunction_t)dht22_task,
                (const char *)"dht22_task",
                (uint16_t)DHT22_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)DHT22_Task_PRIO,
                (TaskHandle_t *)&DHT22Task_Handler);
    /*传感器UI数据更新任务 */
    xTaskCreate((TaskFunction_t)UITask,
                (const char *)"UITask",
                (uint16_t)UI_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)UI_TASK_PRIO,
                (TaskHandle_t *)&UITask_Handler);
    /*传感器数据存储任务 */
    xTaskCreate((TaskFunction_t)SensorDataStorage,
                (const char *)"SensorDataStorage",
                (uint16_t)SENSOR_DATA_STORAGE_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)SENSOR_DATA_STORAGE_TASK_PRIO,
                (TaskHandle_t *)&SensorDataStorageTask_Handler);
    /* HC-05蓝牙串口任务 */
    xTaskCreate((TaskFunction_t)HC_05_task,
                (const char *)"HC_05_task",
                (uint16_t)HC_05_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)HC_05_TASK_PRIO,
                (TaskHandle_t *)&HC_05Task_Handler);
    taskEXIT_CRITICAL();            /* 退出临界区 */
    vTaskDelete(StartTask_Handler); /* 删除初始任务 */
}

/**
 * @brief       LVGL任务函数
 * @param       pvParameters : 传递给任务的参数(未使用)
 * @retval      无
 */
void lv_demo_task(void *pvParameters)
{

    ui_init();

    // 文件路径为 "E:\PICTURE\PNG\Group 39.png"
    while (1)
    {

        lv_timer_handler(); /* LVGL定时器 */
        vTaskDelay(10);
    }
}

/**
 * @brief       DHT22数据采集任务函数
 * @param       pvParameters : 传递给任务的参数(未使用)
 * @retval      无
 */
void dht22_task(void *pvParameters)
{
    while (1)
    {
        DHT22_Read();
        uint8_t hum = ((DHT_buffer[0] << 8) + DHT_buffer[1]) / 10 - 2;
        uint8_t temp = ((DHT_buffer[2] << 8) + DHT_buffer[3]) / 10;
        // 获取互斥锁，更新全局变量
        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
        {
            temperature = temp;
            humidity = hum;
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(2000);
    }
}
/**
 * @brief   更新LVGL传感器数据任务
 *
 * @param pvParameters
 */
void UITask(void *pvParameters)
{
    char tempStr[4];
    char humStr[4];
    SensorData_t lastRecords[RECORD_COUNT];

    for (;;)
    {
        // 获取互斥锁，读取全局变量
        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
        {
            sprintf(tempStr, "%u", temperature);
            sprintf(humStr, "%u", humidity);
            xSemaphoreGive(xMutex);
        }
        pagestate = lv_scr_act();
        if (pagestate == ui_main)
        {
            lv_label_set_text(ui_TempLebal, tempStr);
            lv_label_set_text(ui_HumLebal, humStr);
            // 读取最近12次记录
            ReadLast12Records(lastRecords);

            // 提取温度数据并更新到 chart 组件的数据数组
            for (int i = 0; i < RECORD_COUNT; i++)
            {
                ui_Chart1_series_1_array[i] = lastRecords[i].temperature;
                ui_Chart2_series_1_array[i] = lastRecords[i].humidity;

            }
            // 更新 LVGL chart 组件显示

            lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, ui_Chart1_series_1_array);
            lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_1, ui_Chart2_series_1_array);
        }
        else if (pagestate == ui_AirQuality)
        {
            // 当活动页面为空气质量页面时，执行与主页面类似操作
        }
        vTaskDelay(pdMS_TO_TICKS(2000)); // 每秒更新一次显示
    }
}
/**
 * @brief 传感器数据存储任务
 *
 * @param pvParameters 任务参数指针
 */
void SensorDataStorage(void *pvParameters)
{

    for (;;)
    {
        // 等待信号量的释放，最大等待时间为 portMAX_DELAY
        if (xSemaphoreTake(xSensorDataSemaphore, portMAX_DELAY) == pdTRUE)
        {

            // 采集传感器数据
            Sdata.temperature = temperature;
            Sdata.humidity = humidity;
            start_adc_conversion(); // 可以直接集成，也可以保持为独立函数
            vTaskDelay(100);        // 等待ADC转换完成
            get_adc_values(Sdata.adcData);
            // 写入SD卡并更新缓冲区
            WriteDataToSD(&Sdata);
        }
    }
}
/**
 * @brief HC-05蓝牙串口任务
 *
 * @param pvParameters 任务参数指针
 */
void HC_05_task(void *pvParameters)
{
    uint8_t command;
    while (1)
    {
        // 检查是否有待发送的指令
        if (xQueueReceive(bluetoothQueue, &command, portMAX_DELAY))
        {
            // 转换枚举值到实际的指令字符串
            const char *command_str;
            switch (command)
            {
            case COMMAND_COOLING:
                command_str = "COOLING";
                break;
            case COMMAND_DEHUMIDIFYING:
                command_str = "DEHUMIDIFYING";
                break;
            case COMMAND_HEATING:
                command_str = "HEATING";
                break;
            case COMMAND_ECONOMY:
                command_str = "ECONOMY";
                break;
            case COMMAND_AUTO:      
                command_str = "AUTO";
                break;
            case COMMAND_SLEEP: 
                command_str = "SLEEP";
                break;  
            case COMMAND_INCREASE_TEMP: 
                command_str = "INCREASE_TEMP";
                break;
            case COMMAND_DECREASE_TEMP:
                command_str = "DECREASE_TEMP";
                break;
            default:
                break;
            }
            // 发送指令到HC06
            HAL_UART_Transmit(&huart3, (uint8_t *)command_str, strlen(command_str), HAL_MAX_DELAY);
        }
    }
}
