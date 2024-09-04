#if !defined(__REMOTE_H)
#define __REMOTE_H)
#include <stdint.h>
void TIM1_PWM_Init(void);
void Normal_Code(uint8_t A, uint8_t B, uint8_t C);
void Remote_Send(uint8_t mode);

#endif // __REMOTE_H)
