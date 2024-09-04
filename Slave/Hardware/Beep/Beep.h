#if !defined(__BEEP__H)
#define __BEEP__H

#include "stm32f4xx.h"

#define PWM_FREQ_1HZ   1
#define PWM_FREQ_10HZ  10
#define PWM_FREQ_100HZ 100
void Beep_Init(void);
void Beep_Control(uint8_t on_off, uint16_t frequency);
#endif // __BEEP__H
