#ifndef __DELAY_H
#define __DELAY_H 
 
#include "stm32f4xx.h"
 
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
 
 

void Delay_init(void);
void Delay_us(u32 nus);
void Delay_ms(u32 nms);
void Delay_xms(u32 nms);
void Delay_s(u32 ns);
#endif
