#include "MyDrivers.h"

//--------------------------------------Public variables------------------------------

/*
	* @name   BSP_Motor_GPIO_Config
	* @brief  电机驱动逻辑引脚初始化
	* @param  None
	* @retval None      
*/
void BSP_Motor_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(BSP_Motor_GPIO_RCC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = BSP_Motor_GPIO_Pin;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BSP_Motor_GPIO_PORT, &GPIO_InitStructure); 	       
	
	GPIO_SetBits(BSP_Motor_GPIO_PORT, BSP_Motor_GPIO_Pin);
}

/*
	* @name   Motor_Speed_Calc
	* @brief  电机速度解算
	* @param  None
	* @retval None      
*/
void Motor_Speed_Calc(void)
{
	int32_t W1 = 0, W2 = 0, W3 = 0, W4 = 0; 
	
	//小车移动方向与全场定位模块固有坐标系一致。
	
	W1 = +Y_Dir_Speed + X_Dir_Speed - Z_Dir_Speed;  
  W2 = +Y_Dir_Speed - X_Dir_Speed + Z_Dir_Speed;  
  W3 = +Y_Dir_Speed - X_Dir_Speed - Z_Dir_Speed;
  W4 = +Y_Dir_Speed + X_Dir_Speed + Z_Dir_Speed;
	
	if(W1 > 0) Motor1_Direction_1 else Motor1_Direction_0
	if(W2 > 0) Motor2_Direction_1 else Motor2_Direction_0
	if(W3 > 0) Motor3_Direction_1 else Motor3_Direction_0
	if(W4 > 0) Motor4_Direction_1 else Motor4_Direction_0

	if(W1 < 0) W1 = -W1;
	if(W2 < 0) W2 = -W2;
	if(W3 < 0) W3 = -W3;
	if(W4 < 0) W4 = -W4;

	SET_CAR_Speed(W1, W2, W3, W4);		
}

/*
	* @name   SET_CAR_Speed
	* @brief  电机速度赋值
	* @param  None
	* @retval None      
*/
void SET_CAR_Speed(int16_t dt1, int16_t dt2, int16_t dt3, int16_t dt4)
{
	if(dt1 >= 900) dt1 = 900; if(dt1 <= 0) dt1 = 0;
	if(dt2 >= 900) dt2 = 900; if(dt2 <= 0) dt2 = 0;
	if(dt3 >= 900) dt3 = 900; if(dt3 <= 0) dt3 = 0;
	if(dt4 >= 900) dt4 = 900; if(dt4 <= 0) dt4 = 0;

  TIM3 -> CCR1 = dt1;
	TIM3 -> CCR2 = dt2;
	TIM3 -> CCR3 = dt3;
	TIM3 -> CCR4 = dt4;
}

/*
	* @name   Motor_PWM_Time_Init
	* @brief  电机PWM初始化
	* @param  None
	* @retval None      
*/
void Motor_PWM_Time_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin   = TIM3_PWM_PA;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = TIM3_PWM_PB;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	TIM_TimeBaseInitStructure.TIM_Period = 999; 
	TIM_TimeBaseInitStructure.TIM_Prescaler = 71; 
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Down;
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);	

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_Low; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	
	TIM_OC1Init(TIM3,&TIM_OCInitStructure); 
	TIM_OC2Init(TIM3,&TIM_OCInitStructure); 
	TIM_OC3Init(TIM3,&TIM_OCInitStructure); 
	TIM_OC4Init(TIM3,&TIM_OCInitStructure); 
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); 
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable); 
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable); 

	TIM_ARRPreloadConfig(TIM3,ENABLE);
	
	TIM_Cmd(TIM3,ENABLE); 
}
