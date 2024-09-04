
#include "Delay.h"

// 如果使用OS,则包括下面的头文件即可

#include "FreeRTOS.h" //FreeRTOS使用
#include "task.h"

static u8 fac_us  = 0; // us延时倍乘数
static u16 fac_ms = 0; // ms延时倍乘数,在os下,代表每个节拍的ms数

/**
 * @brief 初始化延迟函数，这里为了兼容FreeRTOS，所以将SYSTICK的时钟频率改为AHB的频率！
 *
 */
void Delay_init(void)
{
    u32 reload;
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
    // 因为1ms需要记的次数为load=168M/1000，所以1us需要记 的次数等于168
    fac_us = 84;
    reload = 84;
    // configTICK_RATE_HZ 产生节拍的频率为1000Hz，也就是1/1000s产生一次中断，所以load=168M/1000
    reload *= 1000000 / configTICK_RATE_HZ; // 根据configTICK_RATE_HZ设定溢出时间
                                            // reload为24位寄存器,最大值:16777216,在168M下,约合0.0998s左右

    fac_ms = 1000 / configTICK_RATE_HZ;        // 代表OS可以延时的最少单位,这个变量代表节拍为nms
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk; // 开启SYSTICK中断
    SysTick->LOAD = reload;                    // 每1/configTICK_RATE_HZ断一次
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;  // 开启SYSTICK
}

/**
 * @brief 延时n微秒函数
 * @param nus 要延时的us数，范围0~199732

 */
void Delay_us(u32 nus)
{
    u32 ticks;
    u32 told, tnow, tcnt = 0;   // tcnt计数总次数
    u32 reload = SysTick->LOAD; // LOAD的值
    ticks      = nus * fac_us;  // 需要的节拍数
    told       = SysTick->VAL;  // 刚进入时的计数器值
    while (1) {
        tnow = SysTick->VAL;
        if (tnow != told) {                       // 如果定时器还在递减，则tcnt=tcnt+1
            if (tnow < told) tcnt += told - tnow; // 这里注意一下SYSTICK是一个递减的计数器就可以了.
            // 如果定时器已经过了一轮，则需要用新一轮的时间+前面一轮的时间+前面计数的时间
            else
                tcnt += reload - tnow + told;
            // 每次用told记录上一次的位置
            told = tnow;
            // 时间到了退出
            if (tcnt >= ticks) break; // 时间超过/等于要延迟的时间,则退出.
        }
    };
}

/**
 * @brief 延时n毫秒函数
 * @attention 如果系统已经运行，则使用FreeRTOS提供的vTaskDelay()函数进行延时，延时精度受FreeRTOS调度器影响；
 *       如果延时时间大于OS的最少时间周期，则采用FreeRTOS的延时方式；
 *       如果延时时间小于OS的最少时间周期，则采用普通方式延时，即调用之前定义的delay_us()函数。
 * 		 如果系统尚未运行，则采用普通方式延时，即调用之前定义的delay_us()函数。
 * @param nms 要延时的xms数，范围：0~65535
 */
void Delay_xms(u32 nms)
{
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) // 系统已经运行
    {
        if (nms >= fac_ms) // 延时的时间大于OS的最少时间周期
        {
            vTaskDelay(nms / fac_ms); // FreeRTOS延时
        }
        nms %= fac_ms; // OS已经无法提供这么小的延时了,采用普通方式延时
    }
    Delay_us((u32)(nms * 1000)); // 普通方式延时
}

/**
 * @brief 延时n毫秒函数
 * @attention 该函数采用循环调用微秒级延时函数delay_us()来实现毫秒级延时，不会引起任务调度。
 * @param nms 要延时的ms数
 */
void Delay_ms(u32 nms)
{

    u32 i;
    for (i = 0; i < nms; i++) Delay_us(1000);
}
/**
  * @brief 秒级延时函数，不引起任务调度
  * @param ns 要延时的秒数
  * @attention 该函数采用循环调用毫秒级延时函数delay_ms()来实现秒级延时，不会引起任务调度。
  */
void Delay_s(u32 ns)
{
    u32 i;
    for(i = 0; i < ns; i++)
        Delay_ms(1000);
}