/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"

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

void vTaskLED(void *pvParameters)
{
    led_init();

    while (1)
    {
        led_control(BSP_LED_ON);
        delay_ms(1000);
        led_control(BSP_LED_OFF);
        delay_ms(1000);
    }
}

void vTaskUart(void *pvParameters)
{
    uart1_init(115200);

    while (1)
    {
        printf("Hello World\r\n");
        delay_ms(1000);
    }
}

int main(void)
{
    board_init();

    BaseType_t xHandle = NULL;

    xHandle = xTaskCreate(vTaskLED, "LED", 1024, (void *)0, 1, NULL);
    xHandle = xTaskCreate(vTaskUart, "Uart", 1024, (void *)0, 1, NULL);

    (void)xHandle;

    vTaskStartScheduler();
}
