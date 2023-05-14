#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "MyDrivers.h"

#define LED1_Port GPIOD
#define LED1_Pin  GPIO_Pin_2
#define LED1_RCC  RCC_APB2Periph_GPIOD

#define LED2_Port GPIOA
#define LED2_Pin  GPIO_Pin_15
#define LED2_RCC  RCC_APB2Periph_GPIOA

typedef enum
{
	LED1 = (uint8_t)0x00,
	LED2 = (uint8_t)0x01,
}LED_Num_t;

void BSP_LED_Init(void);
void BSP_LED_ON(uint8_t LED_Num);
void BSP_LED_OFF(uint8_t LED_Num);
void BSP_LED_Toggle(uint8_t LED_Num);

#endif
