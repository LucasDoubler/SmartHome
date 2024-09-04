

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/SDRAM/sdram.h"
#include "./BSP/LED/led.h"
#include "./BSP/KEY/key.h"
#include "./BSP/MPU/mpu.h"
#include "./BSP/TOUCH/touch.h"
#include "./BSP/LCD/lcd.h"
#include "lvgl_demo.h"
#include "./BSP/SDMMC/sdmmc_sdcard.h"
#include "ff.h"
#include "diskio.h"
#include "./BSP/RTC/rtc.h"
#include "./BSP/HC05/hc05.h"
FATFS fsproject;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef g_uart1_handle; /* UART句柄 */

int main(void)
{
    sys_cache_enable();                 // 启用系统缓存
    HAL_Init();                         // 初始化HAL库
    sys_stm32_clock_init(192, 5, 2, 4); // 初始化系统时钟
    delay_init(480);                    // 初始化延时函数
    led_init();                         // 初始化LED
    usart1_init(115200);      // 初始化串口
    usart3_init(9600);        // 初始化串口
    mpu_memory_protection(); // 启用内存保护单元

    key_init();      // 初始化按键
    sdram_init();    // 初始化SDRAM
    rtc_init();      // 初始化RTC
    adc1_nch_init(); // 初始化ADC
    lvgl_demo();                        // 运行LVGL演示程序
}
