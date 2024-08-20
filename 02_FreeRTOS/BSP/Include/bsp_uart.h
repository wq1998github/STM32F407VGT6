#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include "stm32f4xx.h"

// 外部可调用函数的声明
void uart1_init(uint32_t baudrate);
void USART1_IRQHandler(void);

#endif
