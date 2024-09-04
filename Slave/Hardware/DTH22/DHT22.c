#include "stm32f4xx.h"
#include "DHT22.h"
#include "Delay.h"

uint8_t DHT_buffer[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
uint32_t sum          = 0;
void DHT22_Init(GPIOMode_TypeDef Mode)
{
    GPIO_InitTypeDef GPIO_InitStructure; //	结构体变量的定义或声明
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;      // Pg10端口配置
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;

    if (Mode == GPIO_Mode_OUT) {
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT; //		开漏输出
        GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    } else if (Mode == GPIO_Mode_IN) {
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    }

    GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化GPIOB
}

uint8_t DHT22_GetData()
{
    uint8_t retry    = 0;
    uint8_t temp     = 0;
    uint8_t readData = 0;
    for (int i = 0; i < 8; i++) {
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0 && retry < 100) {
            Delay_us(1);
            retry++;
        }
        retry = 0;
        temp  = 0;
        Delay_us(30);

        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 1) {
            temp = 1;
        }
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 1 && retry < 100) {
            Delay_us(1);
            retry++;
        }
        retry = 0;
        readData <<= 1;
        readData |= temp;
    }

    return readData;
}

uint8_t DHT22_Read()
{
   
  uint8_t j;
   // uint8_t retry = 0;
    DHT22_Init(GPIO_Mode_OUT);
    GPIO_ResetBits(GPIOB, GPIO_Pin_10);
  Delay_ms(1);
    GPIO_SetBits(GPIOB, GPIO_Pin_10);
    Delay_us(35);
    DHT22_Init(GPIO_Mode_IN);
    Delay_us(20);
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0) {

        Delay_us(160);
        for (j = 0; j < 5; j++) {
            DHT_buffer[j] = DHT22_GetData();
        }
        Delay_us(50);
    }
    sum = (DHT_buffer[0] + DHT_buffer[1] + DHT_buffer[2] + DHT_buffer[3]);
    if (DHT_buffer[4] == (u8)(sum)) {
        return 1;
    } else {
        return 0;
    }
}
