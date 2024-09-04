#include "stm32f4xx.h"
#include "LED.h"

void LED_Init()
{
    GPIO_InitTypeDef GPIOS;
    RCC_AHB1PeriphClockCmd(LED_RCC_GPIO, ENABLE);
    GPIOS.GPIO_Mode  = GPIO_Mode_OUT;
    GPIOS.GPIO_OType = GPIO_OType_PP;
    GPIOS.GPIO_Pin   = LED_PIN_GREEN | LED_PIN_RED | LED_PIN_YELLOW;
    GPIOS.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIOS.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_GPIO, &GPIOS);
 
}
void LED_ON(uint16_t LED_PIN)
{
    GPIO_SetBits(LED_GPIO, LED_PIN);
}
void LED_OFF(uint16_t LED_PIN)
{
    GPIO_ResetBits(LED_GPIO, LED_PIN);
}