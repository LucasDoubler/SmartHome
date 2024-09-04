#if !defined(__LED__H)
#define __LED__H

#define LED_PIN_RED    GPIO_Pin_0
#define LED_PIN_YELLOW GPIO_Pin_1
#define LED_PIN_GREEN  GPIO_Pin_2
#define LED_GPIO       GPIOA
#define LED_RCC_GPIO   RCC_AHB1Periph_GPIOA
void LED_Init();
void LED_ON(uint16_t LED_PIN);
void LED_OFF(uint16_t LED_PIN);

#endif // __LED__H
