#include "MyDrivers.h"

#define Imax  150

Position_PID_t Position_PID_Z;

/*
	* @name   Position_PID_Init
	* @brief  位置式PID参数初始化
	* @param  None
	* @retval None   
*/
void Position_PID_Init(Position_PID_t *Position_PID)
{
	Position_PID -> SetValue     = 0.0f;
	Position_PID -> pid_Calc_out = 0.0f;
	Position_PID -> error        = 0.0f;
	Position_PID -> error_last   = 0.0f;
	Position_PID -> error_pre    = 0.0f;
	Position_PID -> integral     = 0.0f;

	Position_PID -> Kp           = 150.0f;   //200     //150.0f
	Position_PID -> Ki           = 0.00f;    //1       //0.01f;
	Position_PID -> Kd           = 1500.00f; // 500    //1500.00f;
}

/*
	* @name   Position_PID_Calc
	* @brief  位置式PID计算
	* @param  Next_val:用户期望值 actual:当前值
	* @retval None   
*/
float Position_PID_Calc(Position_PID_t *Position_PID, float Next_val, float actual) 
{
	Position_PID -> SetValue = Next_val;
  Position_PID -> error    = Position_PID -> SetValue - actual;
  Position_PID -> integral += Position_PID -> error;
										 
	if(Position_PID -> integral > Imax) Position_PID -> integral = Imax;
	if(Position_PID -> integral <-Imax) Position_PID -> integral =-Imax;
										 
  Position_PID -> pid_Calc_out = (Position_PID -> Kp * Position_PID -> error) + 
															   (Position_PID -> Ki * Position_PID -> integral)+ 
															    Position_PID -> Kd * (Position_PID -> error - Position_PID -> error_last);

  Position_PID -> error_last = Position_PID -> error;
  return (Position_PID -> pid_Calc_out * 1.0f);
}

/*
	* @name   Position_PID_Calc_1
	* @brief  位置式PID计算
	* @param  Next_val:用户期望值 actual:当前值
	* @retval None   
*/
float Position_PID_Calc_1(Position_PID_t *Position_PID, float actual) 
{
  Position_PID -> error    = Position_PID -> SetValue - actual;
  Position_PID -> integral += Position_PID -> error;
										 
	if(Position_PID -> integral > Imax) Position_PID -> integral = Imax;
	if(Position_PID -> integral <-Imax) Position_PID -> integral =-Imax;
										 
  Position_PID -> pid_Calc_out = (Position_PID -> Kp * Position_PID -> error) + 
															   (Position_PID -> Ki * Position_PID -> integral)+ 
															    Position_PID -> Kd * (Position_PID -> error - Position_PID -> error_last);

  Position_PID -> error_last = Position_PID -> error;
  return (Position_PID -> pid_Calc_out * 1.0f);
}
