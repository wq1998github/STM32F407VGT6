#ifndef __BSP_SYSTEM_H__
#define __BSP_SYSTEM_H__

#include "stm32f4xx.h"

// 0,不支持 RTOS
// 1,支持   RTOS
#define SYSTEM_SUPPORT_OS 0 // 定义是否支持 RTOS

// 位带操作,实现类似51单片机的GPIO控制功能
// 具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).
// IO口操作宏定义
#define BITBAND(addr, bitnum)   ((addr & 0xF0000000) + 0x2000000 + ((addr & 0xFFFFF) << 5) + (bitnum << 2))
#define MEM_ADDR(addr)          *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum)  MEM_ADDR(BITBAND(addr, bitnum))


// IO口地址映射
#define GPIOA_ODR_Addr (GPIOA_BASE + 0x0C) // 0x4001080C
#define GPIOB_ODR_Addr (GPIOB_BASE + 0x0C) // 0x40010C0C
#define GPIOC_ODR_Addr (GPIOC_BASE + 0x0C) // 0x4001100C
#define GPIOD_ODR_Addr (GPIOD_BASE + 0x0C) // 0x4001140C
#define GPIOE_ODR_Addr (GPIOE_BASE + 0x0C) // 0x4001180C
#define GPIOF_ODR_Addr (GPIOF_BASE + 0x0C) // 0x40011A0C
#define GPIOG_ODR_Addr (GPIOG_BASE + 0x0C) // 0x40011E0C
#define GPIOH_ODR_Addr (GPIOH_BASE + 0x0C) // 
#define GPIOI_ODR_Addr (GPIOI_BASE + 0x0C) // 
#define GPIOJ_ODR_Addr (GPIOJ_BASE + 0x0C) // 
#define GPIOK_ODR_Addr (GPIOK_BASE + 0x0C) // 

#define GPIOA_IDR_Addr (GPIOA_BASE + 0x08) // 0x40010808
#define GPIOB_IDR_Addr (GPIOB_BASE + 0x08) // 0x40010C08
#define GPIOC_IDR_Addr (GPIOC_BASE + 0x08) // 0x40011008
#define GPIOD_IDR_Addr (GPIOD_BASE + 0x08) // 0x40011408
#define GPIOE_IDR_Addr (GPIOE_BASE + 0x08) // 0x40011808
#define GPIOF_IDR_Addr (GPIOF_BASE + 0x08) // 0x40011A08
#define GPIOG_IDR_Addr (GPIOG_BASE + 0x08) // 0x40011E08
#define GPIOH_IDR_Addr (GPIOH_BASE + 0x08) // 
#define GPIOI_IDR_Addr (GPIOI_BASE + 0x08) // 
#define GPIOJ_IDR_Addr (GPIOJ_BASE + 0x08) // 
#define GPIOK_IDR_Addr (GPIOK_BASE + 0x08) // 

// IO口操作,只对单一的IO口!
// n = 0 ~ 15 !!!!!
#define PAout(n)        BIT_ADDR(GPIOA_ODR_Addr, n) // 输出
#define PAin(n)         BIT_ADDR(GPIOA_IDR_Addr, n) // 输入

#define PBout(n)        BIT_ADDR(GPIOB_ODR_Addr, n) // 输出
#define PBin(n)         BIT_ADDR(GPIOB_IDR_Addr, n) // 输入

#define PCout(n)        BIT_ADDR(GPIOC_ODR_Addr, n) // 输出
#define PCin(n)         BIT_ADDR(GPIOC_IDR_Addr, n) // 输入

#define PDout(n)        BIT_ADDR(GPIOD_ODR_Addr, n) // 输出
#define PDin(n)         BIT_ADDR(GPIOD_IDR_Addr, n) // 输入

#define PEout(n)        BIT_ADDR(GPIOE_ODR_Addr, n) // 输出
#define PEin(n)         BIT_ADDR(GPIOE_IDR_Addr, n) // 输入

#define PFout(n)        BIT_ADDR(GPIOF_ODR_Addr, n) // 输出
#define PFin(n)         BIT_ADDR(GPIOF_IDR_Addr, n) // 输入

#define PGout(n)        BIT_ADDR(GPIOG_ODR_Addr, n) // 输出
#define PGin(n)         BIT_ADDR(GPIOG_IDR_Addr, n) // 输入

#define PHout(n)        BIT_ADDR(GPIOH_ODR_Addr, n) // 输出
#define PHin(n)         BIT_ADDR(GPIOH_IDR_Addr, n) // 输入

#define PIout(n)        BIT_ADDR(GPIOI_ODR_Addr, n) // 输出
#define PIin(n)         BIT_ADDR(GPIOI_IDR_Addr, n) // 输入

#define PJout(n)        BIT_ADDR(GPIOJ_ODR_Addr, n) // 输出
#define PJin(n)         BIT_ADDR(GPIOJ_IDR_Addr, n) // 输入

#define PKout(n)        BIT_ADDR(GPIOK_ODR_Addr, n) // 输出
#define PKin(n)         BIT_ADDR(GPIOK_IDR_Addr, n) // 输入

/**
 * @brief  中断优先级分组配置
 */
void NVIC_Configuration(void);

#endif
