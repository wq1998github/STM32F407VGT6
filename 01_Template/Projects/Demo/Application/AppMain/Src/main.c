/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

#include "stm32f4xx.h"

#include "bsp_system.h"
#include "bsp_systick.h"
#include "bsp_led.h"
#include "bsp_uart.h"

void board_init(void)
{
    NVIC_Configuration();
    bsp_systick_init();
    led_init();
    uart1_init(115200);
}

int main(void)
{
    board_init();

    /* Infinite loop */
    while (1)
    {
        led_control(BSP_LED_ON);
        printf("LED ON!!!!!");
        delay_ms(1000);

        led_control(BSP_LED_OFF);
        printf("LED OFF!!!!!");
        delay_ms(1000);
    }
}
