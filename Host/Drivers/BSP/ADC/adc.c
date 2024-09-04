#include "./BSP/ADC/adc.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/usart/usart.h"
#include "FreeRTOS.h"

ADC_HandleTypeDef g_adc_handle;
uint32_t adc_values[ADC_CHANNEL_COUNT];
uint8_t current_channel = 0;
uint8_t adc_conversion_complete = 1;

void adc1_nch_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    ADC_ChannelConfTypeDef adc_ch_conf = {0};
    /* 开启GPIOA引脚时钟和ADC1时钟 */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_ADC12_CLK_ENABLE();

    /* ADC外设时钟选择为CLKP */
    __HAL_RCC_ADC_CONFIG(RCC_ADCCLKSOURCE_CLKP);

    /* 初始化ADC通道对应的GPIO: PA0-PA1-PA4-PA5 */
    gpio_init_struct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5;
    gpio_init_struct.Mode = GPIO_MODE_ANALOG;
    gpio_init_struct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &gpio_init_struct);

    /* 初始化ADC */
    g_adc_handle.Instance = ADC1;
    g_adc_handle.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV2;                /* 输入时钟2分频,即adc_ker_ck=per_ck/2=32Mhz */
    g_adc_handle.Init.Resolution = ADC_RESOLUTION_16B;                      /* 16位分辨率 */
    g_adc_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;                       /* 扫描模式 */
    g_adc_handle.Init.EOCSelection = ADC_EOC_SINGLE_CONV;                   /* 每个转换结束产生中断 */
    g_adc_handle.Init.LowPowerAutoWait = DISABLE;                           /* 自动低功耗关闭 */
    g_adc_handle.Init.ContinuousConvMode = DISABLE;                         /* 关闭连续转换 */
    g_adc_handle.Init.NbrOfConversion = ADC_CHANNEL_COUNT;                  /* 转换通道数为4 */
    g_adc_handle.Init.DiscontinuousConvMode = DISABLE;                      /* 禁止不连续采样模式 */
    g_adc_handle.Init.NbrOfDiscConversion = 0;                              /* 不连续采样通道数为0 */
    g_adc_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;                /* 软件触发 */
    g_adc_handle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE; /* 使用软件触发 */
    g_adc_handle.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;     /* 常规转换存储在DR寄存器里 */
    g_adc_handle.Init.Overrun = ADC_OVR_DATA_PRESERVED;                     /* 保留溢出数据 */
    g_adc_handle.Init.OversamplingMode = DISABLE;                           /* 过采样关闭 */
    g_adc_handle.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;                 /* 不左移 */

    if (HAL_ADC_Init(&g_adc_handle) != HAL_OK)
    {
        /* 初始化错误处理 */
        printf("ADC init failed.\r\n");
    }

    /* ADC校准 */
    if (HAL_ADCEx_Calibration_Start(&g_adc_handle, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK)
    {
        /* 校准错误处理 */
        printf("ADC calibration failed.\r\n");
    }

    /* 配置ADC通道 */
    adc_ch_conf.Rank = ADC_REGULAR_RANK_1;
    adc_ch_conf.SamplingTime = ADC_SAMPLETIME_810CYCLES_5;
    adc_ch_conf.SingleDiff = ADC_SINGLE_ENDED;
    adc_ch_conf.OffsetNumber = ADC_OFFSET_NONE;
    adc_ch_conf.Offset = 0;

    adc_ch_conf.Channel = ADC_CHANNEL_16; /* PA0 */
    HAL_ADC_ConfigChannel(&g_adc_handle, &adc_ch_conf);

    adc_ch_conf.Rank = ADC_REGULAR_RANK_2;
    adc_ch_conf.Channel = ADC_CHANNEL_17; /* PA1 */
    HAL_ADC_ConfigChannel(&g_adc_handle, &adc_ch_conf);

    adc_ch_conf.Rank = ADC_REGULAR_RANK_3;
    adc_ch_conf.Channel = ADC_CHANNEL_18; /* PA4 */
    HAL_ADC_ConfigChannel(&g_adc_handle, &adc_ch_conf);

    adc_ch_conf.Rank = ADC_REGULAR_RANK_4;
    adc_ch_conf.Channel = ADC_CHANNEL_19; /* PA5 */
    HAL_ADC_ConfigChannel(&g_adc_handle, &adc_ch_conf);

    /* 配置ADC中断优先级并使能 */
    HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(ADC_IRQn);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC1)
    {
        // 读取当前通道的ADC转换结果
        adc_values[current_channel] = HAL_ADC_GetValue(hadc);

        current_channel++;

        if (current_channel < ADC_CHANNEL_COUNT)
        {
            // 继续下一个通道的转换
            HAL_ADC_Start_IT(hadc);
        }
        else
        {
            // 所有通道都转换完成
            current_channel = 0;
            adc_conversion_complete = 1;
            // 停止ADC
            HAL_ADC_Stop_IT(hadc);
        }
    }
}

// 启动ADC转换
void start_adc_conversion(void)
{
    current_channel = 0;
    adc_conversion_complete = 0;
    HAL_ADC_Start_IT(&g_adc_handle);
}

// 获取最新的ADC值，并返回是否有新值
void get_adc_values(uint16_t *values)
{

    for (int i = 0; i < ADC_CHANNEL_COUNT; i++)
    {
        values[i] = adc_values[i];
    }
    // 重置标志，为下一次转换做准备
    adc_conversion_complete = 0;
}
float ConvertADCToVoltage(uint16_t adcValue)
{
    float V_REF = 3.3f;
    // 16位ADC的最大值
    const uint32_t ADC_MAX_VALUE = 65535; // 2^16 - 1

    // 计算电压值
    float voltage = ((float)adcValue / ADC_MAX_VALUE) * V_REF;

    return voltage;
}
void ADC_IRQHandler(void)
{
    HAL_ADC_IRQHandler(&g_adc_handle);
}
