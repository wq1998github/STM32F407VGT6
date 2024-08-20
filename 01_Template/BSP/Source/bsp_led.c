#include "bsp_system.h"
#include "bsp_led.h"

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

/*
    1. https://wiki.lckfb.com/zh-hans/tkx/tkx-stm32f407vxt6/beginner/led-principle.html
    2. PB2 连接用户 LED 小灯
*/



void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOB, &GPIO_InitStruct);
}

#if 1
void led_control(BSP_LED_State state)
{
    if (BSP_LED_OFF == state)
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_2);
    }
    else
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_2);
    }
}
#else
void led_control(BSP_LED_State state)
{
    if (BSP_LED_OFF == state)
    {
        // GPIO_ResetBits(GPIOB, GPIO_Pin_2);
        PBout(2) = 0;
    }
    else
    {
        // GPIO_SetBits(GPIOB, GPIO_Pin_2);
        PBout(2) = 1;
    }
}
#endif
