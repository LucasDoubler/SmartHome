#include "stm32f4xx.h"
#include "MQ_Series.h"

u16 ADC_Value[3];
/**
 * @brief MQ135,MQ6,MQ7相关io口初始化，GPIO,ADC,DMA的初始化
 *
 */
void MQSeries_Init(void)
{
    // 启用相应的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);  // 启用ADC1时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);  // 启用DMA2时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // 启用GPIOA时钟

    // 配置GPIOA的引脚作为模拟输入
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;                        // 模拟输入模式
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;                     // 上拉
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5; // 对应传感器引脚
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                     // GPIO速度
    GPIO_Init(GPIOA, &GPIO_InitStructure);                                // 初始化GPIOA

    // ADC配置
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1, ENABLE);  // 重置ADC1
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1, DISABLE); // 关闭ADC1重置
    ADC_InitTypeDef ADC_InitStructure;
    ADC_InitStructure.ADC_Resolution         = ADC_Resolution_12b;            // 12位分辨率
    ADC_InitStructure.ADC_ScanConvMode       = ENABLE;                        // 启用扫描模式
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;                        // 连续转换模式
    ADC_InitStructure.ADC_ExternalTrigConv   = ADC_ExternalTrigConvEdge_None; // 外部触发转换
    ADC_InitStructure.ADC_DataAlign          = ADC_DataAlign_Right;           // 数据右对齐
    ADC_InitStructure.ADC_NbrOfConversion    = 3;                             // 转换通道数量
    ADC_Init(ADC1, &ADC_InitStructure);                                       // 初始化ADC1

    // ADC通用配置
    ADC_CommonInitTypeDef ADC_CommonInitStructure;
    ADC_CommonInitStructure.ADC_Mode             = ADC_Mode_Independent;          // 独立模式
    ADC_CommonInitStructure.ADC_Prescaler        = ADC_Prescaler_Div4;            // 预分频器设置
    ADC_CommonInitStructure.ADC_DMAAccessMode    = ADC_DMAAccessMode_1;           // DMA访问模式
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_10Cycles; // 两个采样阶段之间的延迟
    ADC_CommonInit(&ADC_CommonInitStructure);                                     // 初始化ADC通用配置

    // 配置ADC转换通道
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_480Cycles); // 配置通道3，采样时间480个时钟周期
    ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 2, ADC_SampleTime_480Cycles); // 配置通道4，采样时间480个时钟周期
    ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 3, ADC_SampleTime_480Cycles); // 配置通道5，采样时间480个时钟周期

    // 配置DMA以从ADC接收数据
    DMA_DeInit(DMA2_Stream0);
    while (DMA_GetCmdStatus(DMA2_Stream0) != DISABLE) {} // 等待DMA空闲
    DMA_InitTypeDef DMAInitStructure;
    DMAInitStructure.DMA_Channel            = DMA_Channel_0;
    DMAInitStructure.DMA_PeripheralBaseAddr = (u32)&ADC1->DR;
    DMAInitStructure.DMA_Memory0BaseAddr    = (u32)&ADC_Value;                 // ADC数据存储位置
    DMAInitStructure.DMA_DIR                = DMA_DIR_PeripheralToMemory;      // 数据方向
    DMAInitStructure.DMA_BufferSize         = 3;                               // 缓冲区大小
    DMAInitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;       // 禁止外设地址增量
    DMAInitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;            // 禁止内存地址增量
    DMAInitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; // 外设数据大小
    DMAInitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;     // 内存数据大小
    DMAInitStructure.DMA_Mode               = DMA_Mode_Circular;               // 循环模式
    DMAInitStructure.DMA_Priority           = DMA_Priority_Medium;             // DMA优先级
    DMAInitStructure.DMA_FIFOThreshold      = DMA_FIFOThreshold_HalfFull;
    DMAInitStructure.DMA_FIFOMode           = DMA_FIFOMode_Disable;
    DMAInitStructure.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single; // 外设突发模式
    DMAInitStructure.DMA_MemoryBurst        = DMA_MemoryBurst_Single;     // 内存突发模式
    DMA_Init(DMA2_Stream0, &DMAInitStructure);                            // 初始化DMA

    ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
    // 启用ADC DMA模式
    ADC_DMACmd(ADC1, ENABLE);
}
/**
 * @brief 控制MQ传感器ADC和DMA的开启和关闭
 * 
 * @param ADC_DMA_State 输入ENABLE或DISABLE,控制开关
 */
void MQADC_DMA_Control(FunctionalState ADC_DMA_State)
{
    // 控制ADC的开启和关闭
    if (ADC_DMA_State == ENABLE) {
        ADC_Cmd(ADC1, ENABLE);
        DMA_Cmd(DMA2_Stream0, ENABLE);
        ADC_SoftwareStartConv(ADC1);
    } else {
        ADC_Cmd(ADC1, DISABLE);
        DMA_Cmd(DMA2_Stream0, DISABLE);
    }
}