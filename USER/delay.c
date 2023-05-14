#include "MyDrivers.h"

static uint8_t   D_us=0;		//微妙系数
static uint16_t  D_ms=0;		//毫秒系数

/*
	* @name   Delay_Init
	* @brief  初始化Systick定时器
	* @param  参数：None
	* @retval None   
*/
void Delay_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	
	D_us = SystemCoreClock/8000000;
	D_ms = (uint16_t)D_us * 1000;
	
}

/*
	* @name   Delay_us
	* @brief  微妙延时
	* @param  参数：uint32_t nus
	* @retval None   
*/
void Delay_us(uint32_t nus)
{
	uint32_t temp;
	SysTick->CTRL = 0x00;			//关闭SysTick定时器
	SysTick->LOAD = nus*D_us; 		//延时重装载值	  		 
	SysTick->VAL  = 0x00;        	//清空计数器
	SysTick->CTRL|= 0x01 ;			//启动SysTick定时器  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	  	//等待延时结束  
	SysTick->CTRL = 0x00;						//关闭SysTick定时器
	SysTick->VAL  = 0X00;      					//清空计数器
}

/*
	* @name   Delay_ms
	* @brief  毫秒延时
	* @param  参数：uint32_t nms
	* @retval None   
*/
void Delay_ms(uint32_t nms)
{
	uint32_t temp;
	SysTick->CTRL = 0x00;			//关闭SysTick定时器
	SysTick->LOAD = nms*D_ms; 		//延时重装载值	  		 
	SysTick->VAL  = 0x00;        	//清空计数器
	SysTick->CTRL|= 0x01 ;			//启动SysTick定时器  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	  	//等待延时结束  
	SysTick->CTRL = 0x00;						//关闭SysTick定时器
	SysTick->VAL  = 0X00;      					//清空计数器	
}

/*
	* @name   Delay_s
	* @brief  秒延时
	* @param  参数：uint32_t ns
	* @retval None   
*/
void Delay_s(uint32_t ns)
{
	while(ns--)
	{
		Delay_ms(1000);
	}
}



