#if !defined(___DHT22__H)
#define ___DHT22__H

void DHT22_Init(GPIOMode_TypeDef Mode);
uint8_t DHT22_GetData();
uint8_t DHT22_Read();

#endif // ___DHT22__H
