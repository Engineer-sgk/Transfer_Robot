#include "MyDrivers.h"

static uint8_t   D_us=0;		//΢��ϵ��
static uint16_t  D_ms=0;		//����ϵ��

/*
	* @name   Delay_Init
	* @brief  ��ʼ��Systick��ʱ��
	* @param  ������None
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
	* @brief  ΢����ʱ
	* @param  ������uint32_t nus
	* @retval None   
*/
void Delay_us(uint32_t nus)
{
	uint32_t temp;
	SysTick->CTRL = 0x00;			//�ر�SysTick��ʱ��
	SysTick->LOAD = nus*D_us; 		//��ʱ��װ��ֵ	  		 
	SysTick->VAL  = 0x00;        	//��ռ�����
	SysTick->CTRL|= 0x01 ;			//����SysTick��ʱ��  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	  	//�ȴ���ʱ����  
	SysTick->CTRL = 0x00;						//�ر�SysTick��ʱ��
	SysTick->VAL  = 0X00;      					//��ռ�����
}

/*
	* @name   Delay_ms
	* @brief  ������ʱ
	* @param  ������uint32_t nms
	* @retval None   
*/
void Delay_ms(uint32_t nms)
{
	uint32_t temp;
	SysTick->CTRL = 0x00;			//�ر�SysTick��ʱ��
	SysTick->LOAD = nms*D_ms; 		//��ʱ��װ��ֵ	  		 
	SysTick->VAL  = 0x00;        	//��ռ�����
	SysTick->CTRL|= 0x01 ;			//����SysTick��ʱ��  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	  	//�ȴ���ʱ����  
	SysTick->CTRL = 0x00;						//�ر�SysTick��ʱ��
	SysTick->VAL  = 0X00;      					//��ռ�����	
}

/*
	* @name   Delay_s
	* @brief  ����ʱ
	* @param  ������uint32_t ns
	* @retval None   
*/
void Delay_s(uint32_t ns)
{
	while(ns--)
	{
		Delay_ms(1000);
	}
}



