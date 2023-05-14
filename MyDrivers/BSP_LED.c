#include "MyDrivers.h"

/*
	* @name   BSP_LED_Init
	* @brief  LEDµÆÅäÖÃ
	* @param  None
	* @retval None   
*/
void BSP_LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 				 
	RCC_APB2PeriphClockCmd(LED1_RCC | LED2_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	GPIO_InitStructure.GPIO_Pin = LED1_Pin;		      
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(LED1_Port, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LED2_Pin;		      
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(LED2_Port, &GPIO_InitStructure);
	
	GPIO_SetBits(LED1_Port, LED1_Pin);
	GPIO_SetBits(LED2_Port, LED2_Pin);	
}

/*
	* @name   BSP_LED_ON
	* @brief  ´ò¿ªLEDµÆ
	* @param  LED_Num
	* @retval None   
*/
void BSP_LED_ON(uint8_t LED_Num)
{
	switch(LED_Num)
	{
		case LED1: GPIO_ResetBits(LED1_Port, LED1_Pin);break;
		case LED2: GPIO_ResetBits(LED2_Port, LED2_Pin);break;
		default: Assert_Failed();
	}
}
 
/*
	* @name   BSP_LED_OFF
	* @brief  ¹Ø±ÕLEDµÆ
	* @param  LED_Num
	* @retval None   
*/
void BSP_LED_OFF(uint8_t LED_Num)
{
	switch(LED_Num)
	{
		case LED1: GPIO_SetBits(LED1_Port, LED1_Pin);break;
		case LED2: GPIO_SetBits(LED2_Port, LED2_Pin);break;
		default: Assert_Failed();
	}
}

/*
	* @name   BSP_LED_Toggle
	* @brief  ·­×ªLEDµÆ
	* @param  LED_Num
	* @retval None   
*/
void BSP_LED_Toggle(uint8_t LED_Num)
{
	switch(LED_Num)
	{
		case LED1: LED1_Port -> ODR ^= LED1_Pin;break;
		case LED2: LED2_Port -> ODR ^= LED2_Pin;break;
		default: Assert_Failed();
	}
}

