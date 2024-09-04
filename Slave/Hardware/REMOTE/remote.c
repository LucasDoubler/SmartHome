#include "stm32f4xx.h"
#include "Delay.h"
void TIM1_PWM_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    // 启用TIM1和GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    // 配置GPIOA的第8引脚为复用功能（TIM1_CH1）
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 选择TIM1的复用功能
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_TIM1);

    // TIM1配置
    TIM_TimeBaseStructure.TIM_Period        = 2210; // ARR值
    TIM_TimeBaseStructure.TIM_Prescaler     = 0;    // 不分频
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    // 配置PWM模式1
    TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse       = TIM_TimeBaseStructure.TIM_Period / 2; // 占空比50%
    TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_High;
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);

    // 使能PWM输出
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);

    // 启动定时器
    TIM_Cmd(TIM1, ENABLE);
}
// 测试空调选用美的空调，因为美的空调采用R05D编码，以下函数为R05D编码函数的组成函数
void Lead_Code()
{
    TIM_SetCompare1(TIM1, 189); // 接收器拉低
    Delay_us(4400);
    TIM_SetCompare1(TIM1, 0); // 接收器拉高
    Delay_us(4400);
}

void Stop_Code()
{
    TIM_SetCompare1(TIM1, 189); // 接收器拉低
    Delay_us(540);
    TIM_SetCompare1(TIM1, 0); // 接收器拉高
    Delay_us(5220);
}

void Send_0_Code()
{
    TIM_SetCompare1(TIM1, 189); // 接收器拉低
    Delay_us(540);
    TIM_SetCompare1(TIM1, 0); // 接收器拉高
    Delay_us(540);
}

void Send_1_Code()
{
    TIM_SetCompare1(TIM1, 189); // 接收器拉低
    Delay_us(540);
    TIM_SetCompare1(TIM1, 0); // 接收器拉高
    Delay_us(1620);
}

void Send_Byte(u8 data)
{
    int i;
    for (i = 7; i >= 0; i--) {
        if (data & (1 << i)) {
            Send_1_Code();
        } else {
            Send_0_Code();
        }
    }
}
/**
 * @brief 发送R05D编码,数据格式：引导码+48位数据+分隔码+48位数据（LAA’BB’CC’ S LAA’BB’CC’）
 *
 * @param A
 * @param B
 * @param C
 */
void Normal_Code(uint8_t A, uint8_t B, uint8_t C)
{
    Lead_Code();
    Send_Byte(A);
    Send_Byte(~A);
    Send_Byte(B);
    Send_Byte(~B);
    Send_Byte(C);
    Send_Byte(~C);
    Stop_Code();
    Lead_Code();
    Send_Byte(A);
    Send_Byte(~A);
    Send_Byte(B);
    Send_Byte(~B);
    Send_Byte(C);
    Send_Byte(~C);
    Stop_Code();
}

/**
 * @brief 发送空调指令，但由于空调指令过于繁多，需要根据R05D编码逐一编写，所以我懒得写了，暂时搁置
 * @attention 这里采用的测试编码是“制冷 低风 17”，为0xB2, 0x9F, 0x00。
 * @param mode
 */
void Remote_Send(uint8_t mode)
{
    Normal_Code(0xB2, 0x9F, 0x00);
}