#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "DHT22.h"
#include "GUI.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "Beep.h"
#include "usart.h"
#include <string.h>
#include "MQ_Series.h"
// 定义命令字符串
#define COMMAND_COOLING       "COOLING"
#define COMMAND_DEHUMIDIFYING "DEHUMIDIFYING"
#define COMMAND_HEATING       "HEATING"
#define COMMAND_ECONOMY       "ECONOMY"
#define COMMAND_AUTO          "AUTO"
#define COMMAND_SLEEP         "SLEEP"
#define COMMAND_INCREASE_TEMP "INCREASE_TEMP"
#define COMMAND_DECREASE_TEMP "DECREASE_TEMP"

extern u8 USART_RX_BUF[USART_REC_LEN]; // 接收缓冲,最大USART_REC_LEN个字节.末字节为换行符

extern uint8_t DHT_buffer[5];

// FreeRTOS 信号量
SemaphoreHandle_t uartRxSemaphore;

// 定义消息队列和事件组句柄
QueueHandle_t optionQueue;
EventGroupHandle_t optionEventGroup;
uint8_t temp;
uint8_t hum;

// 定义事件组位
#define OPTION_CHANGE_BIT (1 << 0)

#define START_PRIO        1
#define START_STK_SIZE    128
TaskHandle_t Start_Handler;
void Start(void *pvParameters);

#define TASK_DHT22_PRIO 8
#define TASK_DHT22_SIZE 128
TaskHandle_t Task_DHT22_Handler;
void Task_DHT22(void *pvParameters);

#define TASK_HC06_PRIO 5
#define TASK_HC06_SIZE 256
TaskHandle_t Task_HC06_Handler;
void Task_HC06(void *pvParameters);

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    OLED_Init();
    LED_Init();
    MQSeries_Init();
    MQSeries_Init();
    Delay_init();
    MQADC_DMA_Control(ENABLE);
    Beep_Init();
    uart_init(9600);

    xTaskCreate((TaskFunction_t)Start, "start", START_STK_SIZE, NULL, START_PRIO, &Start_Handler);

    vTaskStartScheduler();
}
void Start(void *pvParameters)
{
    taskENTER_CRITICAL(); // 进入临界区
                          // 创建TASK_MQ135任务
    // 创建TASK_DHT22任务,
    xTaskCreate((TaskFunction_t)Task_DHT22,
                (const char *)"Task_DHT22",
                (uint16_t)TASK_DHT22_SIZE,
                (void *)NULL,
                (UBaseType_t)TASK_DHT22_PRIO,
                (TaskHandle_t *)&Task_DHT22_Handler);
    vTaskDelete(Start_Handler); // 删除开始任务
    taskEXIT_CRITICAL();        // 退出临界区
}
void Task_DHT22(void *pvParameters)
{

    while (1) {
        LED_OFF(LED_PIN_YELLOW);
        if (1) {
            DHT22_Read();
            hum  = ((DHT_buffer[0] << 8) + DHT_buffer[1]) / 10;
            temp = ((DHT_buffer[2] << 8) + DHT_buffer[3]) / 10;
        }
        LED_ON(LED_PIN_YELLOW);
        vTaskDelay(1000);
    }
}
// 任务代码
void Task_HC06(void *pvParameters)
{
    // 创建信号量
    uartRxSemaphore = xSemaphoreCreateBinary();

    while (1) {
        // 等待接收到数据
        if (xSemaphoreTake(uartRxSemaphore, portMAX_DELAY) == pdTRUE) {
            // 处理接收到的数据
            //原计划是通过串口接收到的数据来控制空调的开关，但是由于时间关系，没有对空调各种编码进行一一实现
            if (strstr((const char *)USART_RX_BUF, "COOLING")) {
                // 执行COOLING命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "DEHUMIDIFYING")) {
                // 执行DEHUMIDIFYING命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "HEATING")) {
                // 执行HEATING命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "ECONOMY")) {
                // 执行ECONOMY命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "AUTO")) {
                // 执行AUTO命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "SLEEP")) {
                // 执行SLEEP命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "INCREASE_TEMP")) {
                // 执行INCREASE_TEMP命令对应的操作
            } else if (strstr((const char *)USART_RX_BUF, "DECREASE_TEMP")) {

                // 执行DECREASE_TEMP命令对应的操作
            } else {
                // 未知命令处理
            }
            // 清空接收状态和缓冲区，准备下一次接收
            USART_RX_STA = 0;
            memset(USART_RX_BUF, 0, USART_REC_LEN);
        }
    }
}
