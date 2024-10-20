
 
#include "./BSP/MPU/mpu.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
 

uint8_t mpu_set_protection(uint32_t baseaddr, uint32_t size, uint32_t rnum, uint8_t ap, uint8_t sen, uint8_t cen, uint8_t ben)
{
    MPU_Region_InitTypeDef mpu_initure;

    HAL_MPU_Disable();                                        /* 配置MPU之前先关闭MPU,配置完成以后在使能MPU */

    mpu_initure.Enable = MPU_REGION_ENABLE;                   /* 使能该保护区域 */
    mpu_initure.Number = rnum;                                /* 设置保护区域 */
    mpu_initure.BaseAddress = baseaddr;                       /* 设置基址 */
    mpu_initure.Size = size;                                  /* 设置保护区域大小 */
    mpu_initure.SubRegionDisable = 0X00;                      /* 禁止子区域 */
    mpu_initure.TypeExtField = MPU_TEX_LEVEL0;                /* 设置类型扩展域为level0 */
    mpu_initure.AccessPermission = (uint8_t)ap;               /* 设置访问权限, */
    mpu_initure.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;  /* 允许指令访问(允许读取指令) */
    mpu_initure.IsShareable = sen;                            /* 是否共用? */
    mpu_initure.IsCacheable = cen;                            /* 是否cache? */
    mpu_initure.IsBufferable = ben;                           /* 是否缓冲? */
    HAL_MPU_ConfigRegion(&mpu_initure);                       /* 配置MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);                   /* 开启MPU */
    return 0;
}

/**
 * @brief       设置需要保护的存储块
 * @param       无
 * @note        必须对部分存储区域进行MPU保护,否则可能导致程序运行异常
 *              比如MCU屏不显示,摄像头采集数据出错等等问题...
 */
void mpu_memory_protection(void)
{
    /* 保护整个D1 SRAM 512KB */
    mpu_set_protection( 0x24000000,                 /* 基地址 */
                        MPU_REGION_SIZE_512KB,      /* 长度 */
                        MPU_REGION_NUMBER1,         /* NUMER1 */
                        MPU_REGION_FULL_ACCESS,     /* 全访问 */
                        MPU_ACCESS_SHAREABLE,       /* 允许共享 */
                        MPU_ACCESS_CACHEABLE,       /* 允许cache */
                        MPU_ACCESS_NOT_BUFFERABLE); /* 禁止缓冲 */
    
    /* 保护SDRAM区域,共32M字节 */
    mpu_set_protection( 0XC0000000,                 /* 基地址 */
                        MPU_REGION_SIZE_32MB,       /* 长度 */
                        MPU_REGION_NUMBER2,         /* NUMER2 */
                        MPU_REGION_FULL_ACCESS,     /* 全访问 */
                        MPU_ACCESS_NOT_SHAREABLE,   /* 禁止共享 */
                        MPU_ACCESS_CACHEABLE,       /* 允许cache */
                        MPU_ACCESS_BUFFERABLE);     /* 允许缓冲 */
}

