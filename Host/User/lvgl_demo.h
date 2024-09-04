#include "./system/sys/sys.h"
#ifndef __LVGL_DEMO_H
#define __LVGL_DEMO_H
#define RECORD_COUNT 12

typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t day;
    uint8_t month;
    uint16_t year;
    uint8_t temperature;
    uint8_t humidity;
    uint16_t adcData[4];
} SensorData_t;

typedef enum {
    COMMAND_COOLING,
    COMMAND_DEHUMIDIFYING,
    COMMAND_HEATING,
    COMMAND_ECONOMY,
    COMMAND_AUTO,
    COMMAND_SLEEP,
    COMMAND_INCREASE_TEMP,
    COMMAND_DECREASE_TEMP
} CommandType;
void lvgl_demo(void);  
#endif
