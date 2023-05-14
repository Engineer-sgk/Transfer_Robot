#ifndef __BSP_Motor_H__
#define __BSP_Motor_H__

#include "MyDrivers.h"

#define BSP_Motor_GPIO_PORT GPIOC
#define BSP_Motor_GPIO_Pin  (GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_4 | GPIO_Pin_5 |\
														 GPIO_Pin_6  | GPIO_Pin_7  | GPIO_Pin_8 | GPIO_Pin_9)
														 
#define BSP_Motor_GPIO_RCC  RCC_APB2Periph_GPIOC

#define Motor1_Direction_1 {PCout(14) = 0; PCout(15) = 1;}  // 1
#define Motor2_Direction_1 {PCout( 4) = 1; PCout( 5) = 0;}  // 2
#define Motor3_Direction_1 {PCout( 6) = 0; PCout( 7) = 1;}  // 3
#define Motor4_Direction_1 {PCout( 8) = 1; PCout( 9) = 0;}  // 4
																					 
#define Motor1_Direction_0 {PCout(14) = 1; PCout(15) = 0;}  // 1
#define Motor2_Direction_0 {PCout( 4) = 0; PCout( 5) = 1;}  // 2
#define Motor3_Direction_0 {PCout( 6) = 1; PCout( 7) = 0;}  // 3
#define Motor4_Direction_0 {PCout( 8) = 0; PCout( 9) = 1;}  // 4 

#define ALL_Motor_Stop {PCout(14) = 0; PCout(15) = 0; PAout(6) = 1; \
												PCout( 4) = 0; PCout( 5) = 0; PAout(7) = 1; \
												PCout( 6) = 0; PCout( 7) = 0; PBout(0) = 1; \
	                      PCout( 8) = 0; PCout( 9) = 0; PBout(1) = 1;}
	  																									
//#define PWM_Max_Value 999                   
//#define PWM_Min_Value 150

#define TIM3_PWM_PA      (GPIO_Pin_6 | GPIO_Pin_7) 
#define TIM3_PWM_PB      (GPIO_Pin_0 | GPIO_Pin_1) 
											
void BSP_Motor_GPIO_Config(void);
void Motor_Speed_Calc(void);
void SET_CAR_Speed(int16_t dt1, int16_t dt2, int16_t dt3, int16_t dt4);
void Motor_PWM_Time_Init(void);
void Get_Target_Location(int16_t inc_x, int16_t inc_y, uint16_t speed);

#endif
