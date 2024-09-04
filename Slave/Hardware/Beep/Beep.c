#include "Beep.h"

// 初始化蜂鸣器
void Beep_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    // 使能GPIO时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    // 使能定时器时钟
    RCC_APB2PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // GPIO配置
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;   // 使用PB0作为TIM1的通道1输出
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF; // 复用模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // 推挽输出
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // GPIO复用映射配置
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);

    // 定时器配置
    TIM_TimeBaseStructure.TIM_Period        = 1000 - 1; // 计数器周期为1ms，即1000个计数
    TIM_TimeBaseStructure.TIM_Prescaler     = 8400 - 1; // 预分频，使定时器时钟为84MHz/8400 = 10kHz
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // PWM模式配置
    TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse       = 500; // 初始占空比50%
    TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_High;
    TIM_OC4Init(TIM2, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

    // 启动定时器
    TIM_Cmd(TIM2, ENABLE);
}

// 
/**
 * @brief 控制蜂鸣器的开关和频率
 * 
 * @param on_off 输入ENABLE或DISABLE
 * @param frequency 输入0-10000之间的数值，对应0-10000hz的频率
 */



void Beep_Control(uint8_t on_off, uint16_t frequency) {
    if (on_off == 1) {
        // 打开蜂鸣器
        TIM_SetAutoreload(TIM2, 10000 / frequency); // 假设预分频为8400，计数周期为1000
        TIM_Cmd(TIM2, ENABLE);
    } else {
        // 关闭蜂鸣器
        TIM_Cmd(TIM2, DISABLE);
    }
}