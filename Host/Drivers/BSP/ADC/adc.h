#ifndef __ADC_H
#define __ADC_H

#include "./SYSTEM/sys/sys.h"

#define ADC_ADCX_CHY_GPIO_PORT              GPIOA
#define ADC_ADCX_CHY_GPIO_PIN               GPIO_PIN_5
#define ADC_ADCX_CHY_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)     /* PA口时钟使能 */

#define ADC_ADCX                            ADC1
#define ADC_ADCX_CHY                        ADC_CHANNEL_19                                  /* 通道Y,  0 <= Y <= 19 */ 
#define ADC_ADCX_CHY_CLK_ENABLE()           do{ __HAL_RCC_ADC12_CLK_ENABLE(); }while(0)     /* ADC1 时钟使能 */

/* ADC单通道/多通道 DMA采集 DMA数据流相关 定义
 * 注意: 这里我们的通道还是使用上面的定义
 */
#define ADC_ADCX_DMASx                      DMA1_Stream7 
#define ADC_ADCX_DMASx_REQ                  DMA_REQUEST_ADC1             /* ADC1_DMA请求源 */
#define ADC_ADCX_DMASx_IRQn                 DMA1_Stream7_IRQn 
#define ADC_ADCX_DMASx_IRQHandler           DMA1_Stream7_IRQHandler 

#define ADC_ADCX_DMASx_IS_TC()              ( DMA1->HISR & (1 << 27) )   /* 获取DMA1 Stream7传输完成标志位，
                                                                          * 这是一个假函数形式，不能当函数使用
                                                                          */

#define ADC_ADCX_DMASx_CLR_TC()             do{ DMA1->HIFCR |= 1 << 27; }while(0)            /* 清除DMA1 Stream7传输完成标志位 */

#define ADC_CHANNEL_COUNT 4

/******************************************************************************************/
/*自定义函数*/
void adc1_nch_init(void);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
void start_adc_conversion(void);
void get_adc_values(uint16_t *values);
float ConvertADCToVoltage(uint16_t adcValue);


#endif
