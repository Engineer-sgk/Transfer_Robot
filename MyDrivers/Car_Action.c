#include "MyDrivers.h"

NowCarPosition_t NowCarPosition = 
{
	OnTheMiddle,
};

/*
	* @name   Car_Move_Distance
	* @brief  小车按照规定移动指定距离
	* @param  Direction_t：运动模式 Speed 速度 Distance 距离 Target_Angle 目标航向角
	* @retval None      
*/
void Car_Move_Distance(uint8_t Direction_t, int16_t Speed, int16_t Distance, int16_t Target_Angle)
{
	switch(Direction_t)
	{
		case X_Positive_Dir: 
			Expect_Yaw = Target_Angle;
			X_Dir_Speed = Speed;
		  Y_Dir_Speed = 0;
			System.Controll_Flag = 0;
		  while(1)
			{
				if(pos_x > -0.000001 && pos_x < +0.000001) 
					pos_x = Last_Pos_x;
				if(pos_x >= Distance)
				{
					X_Dir_Speed = 0;
					System.Controll_Flag = 11;
					Delay_ms(50);
					System.Controll_Flag = 0;
					break;
				}
			}
		break;
		
		case Y_Positive_Dir: 
			Expect_Yaw = Target_Angle;
		  X_Dir_Speed = 0;
		  Y_Dir_Speed = Speed;
			System.Controll_Flag = 0;
				while(1)
				{
					if(pos_y> -0.000001 && pos_y < +0.000001) 
						pos_y = Last_Pos_y;
					if(pos_y >= Distance)
					{
						Y_Dir_Speed = 0;
						System.Controll_Flag = 11;
						Delay_ms(50);
					  System.Controll_Flag = 0;
						break;
				}
				}
		 break;
				
		case X_Negative_Dir: 
			Expect_Yaw = Target_Angle;
		  Y_Dir_Speed = 0;
			X_Dir_Speed = -Speed;
			System.Controll_Flag = 0;
		  while(1)
			{
				if(pos_x > -0.000001 && pos_x < +0.000001) 
					pos_x = Last_Pos_x;
				if(pos_x <= Distance)
				{
					X_Dir_Speed = 0;
					System.Controll_Flag = 11;
					Delay_ms(50);
					System.Controll_Flag = 0;
					break;
				}
			}
		break;
				
		case Y_Negative_Dir: 
			Expect_Yaw = Target_Angle;
		  X_Dir_Speed = 0;
		  Y_Dir_Speed = -Speed;
			System.Controll_Flag = 0;
			while(1)
			{
				if(pos_y> -0.000001 && pos_y < +0.000001) 
					pos_y = Last_Pos_y;
				if(pos_y <= Distance)
				{
					Y_Dir_Speed = 0;
					System.Controll_Flag = 11;
					Delay_ms(50);
					System.Controll_Flag = 0;
					break;
				}
				}
		 break;
				
		case Y_Positive_Dir_PosxMagnify :
			Expect_Yaw = Target_Angle;
		  Y_Dir_Speed = Speed;
		  X_Dir_Speed = 0;
			System.Controll_Flag = 0;
				while(1)
				 {
					 if(pos_x> -0.000001 && pos_x < +0.000001) 
						pos_x = Last_Pos_x;
					 if(pos_x >= Distance)
						{
							Y_Dir_Speed = 0;
							System.Controll_Flag = 11;
							Delay_ms(50);
					    System.Controll_Flag = 0;
							break;
						}
				 }
		break;
				 
		case Location_DownBlackLine :
			Expect_Yaw = Target_Angle;
			Y_Dir_Speed = 0;
		  X_Dir_Speed = Speed;
			System.Controll_Flag = 0;
				while(1)
				{
					if(Middle_Sensor_1 == 0 && Left_Sensor_1 == 0 && Right_Sensor_1 == 0)
					{
						X_Dir_Speed = 0;
						System.Controll_Flag = 11;
						Delay_ms(50);
					  System.Controll_Flag = 0;
					 break;
					}
				}
				break;
				
		case Y_Positive_Dir_PosxMinish:
			Expect_Yaw = Target_Angle;
		  X_Dir_Speed = 0;
		  Y_Dir_Speed = Speed;
			System.Controll_Flag = 0;
		  while(1)
		  	{
					if(pos_x> -0.000001 && pos_x < +0.000001) 
						pos_x = Last_Pos_x;
					if(pos_x <= Distance)
					{
						Y_Dir_Speed = 0;
						System.Controll_Flag = 11;
						Delay_ms(50);
					  System.Controll_Flag = 0;
						break;
				  }
		  	}
		 break;
				
		case X_Negative_Dir_PosyMagnify:
			Expect_Yaw = Target_Angle;
		  Y_Dir_Speed = 0;
		  X_Dir_Speed = -Speed;
			System.Controll_Flag = 0;
			while(1)
		  	{
					if(pos_y> -0.000001 && pos_y < +0.000001) 
						pos_y = Last_Pos_y;
					if(pos_y >= Distance)
					{
						X_Dir_Speed = 0;
						System.Controll_Flag = 11;
						Delay_ms(50);
					  System.Controll_Flag = 0;
						break;
				  }
		  	}
		  	break;
				
		case X_Negative_Dir_PosyMinish:
			Expect_Yaw = Target_Angle;
		  Y_Dir_Speed = 0;
			X_Dir_Speed = -Speed;
			System.Controll_Flag = 0;
			while(1)
			{
				if(pos_y> -0.000001 && pos_y < +0.000001) 
					pos_y = Last_Pos_y;
				if(pos_y <= Distance)
				{
					X_Dir_Speed = 0;
					System.Controll_Flag = 11;
					Delay_ms(50);
					System.Controll_Flag = 0;
					break;
				}
			}
		break;
			
		case X_Positive_Dir_PosyMagnify:
			Expect_Yaw = Target_Angle;
			Y_Dir_Speed = 0;
			X_Dir_Speed = Speed;
			System.Controll_Flag = 0;
		while(1)
		{
			if(pos_y> -0.000001 && pos_y < +0.000001) 
				pos_y = Last_Pos_y;
			if(pos_y >= Distance)
			{
				X_Dir_Speed = 0;
				System.Controll_Flag = 11;
				break;
			}
		}
		break;
		
		case Second_Location_DownBlackLine:
			Expect_Yaw = Target_Angle;
			Y_Dir_Speed = 0;
		  X_Dir_Speed = -Speed;
			System.Controll_Flag = 0;
				while(1)
				{
					if(Middle_Sensor_3 == 0 && Left_Sensor_3 == 0 && Right_Sensor_3 == 0)
					{
						X_Dir_Speed = 0;
						System.Controll_Flag = 11;
						Delay_ms(50);
					  System.Controll_Flag = 0;
						break;
					}
				}
		break;
				
		case Parking_XEnd:
			Expect_Yaw = Target_Angle;
			X_Dir_Speed = 0;
		  Y_Dir_Speed = Speed;
			System.Controll_Flag = 0;
		  while(1)
			{
				if(pos_x> -0.000001 && pos_x < +0.000001) 
					pos_x = Last_Pos_x;
				if(pos_x <= 170 && pos_x >= -50 )
				{
					if(Middle_Sensor_2 == 0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0)
					{
						Y_Dir_Speed = 0;
						System.Controll_Flag = 11;
						Delay_ms(50);
					  System.Controll_Flag = 0;
						break;
					}
				}
			}
		break;
			
	
		default: Assert_Failed();break;
	}
}

/*
MaterialArea_Right    
MaterialArea_Middle   
MaterialArea_Left     

HalfProcessArea_Right 
HalfProcessArea_Middle
HalfPrcoessArea_Left  

FinishArea_Right      
FinishArea_Middle     
FinishArea_Left   

Second_MaterialArea_Right 
Second_MaterialArea_Middle
Second_MaterialArea_Left  


*/
void Location_BlackBine(uint8_t Position_Line_t, int16_t Speed)
{
	switch(Position_Line_t)
	{
		case MaterialArea_Left :
			X_Dir_Speed = 0;
			Y_Dir_Speed = Speed;
		  System.Controll_Flag = 0;
		while(1)
		{
			if(Middle_Sensor_2 ==  0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0 && Right2_Sensor_2 == 1 && Left2_Sensor_2 == 1)
			{
				Y_Dir_Speed = 0;
				System.Controll_Flag = 11;
				NowCarPosition.Flag = OnTheLeft;
				Delay_ms(50);
				System.Controll_Flag = 0;
				break;
			}
		}
		break;
		
		case MaterialArea_Middle :
			X_Dir_Speed = 0;
			if(NowCarPosition.Flag == OnTheLeft)
				Y_Dir_Speed = -Speed;
			else if(NowCarPosition.Flag == OnTheRight)
				Y_Dir_Speed = Speed;
			else 
				Y_Dir_Speed = 0;
			System.Controll_Flag = 0;
			while(1)
			{
				if(Middle_Sensor_1 == 0 && Middle_Sensor_3 == 0 && Left_Sensor_3 == 1 && Right_Sensor_3 == 1)
				{
					System.Controll_Flag = 13;
					NowCarPosition.Flag = OnTheMiddle;
					 break;
				}
			}
			break;
			
		case MaterialArea_Right :
		  X_Dir_Speed = 0;
		  Y_Dir_Speed = -Speed;
		  System.Controll_Flag = 0;
			while(1)
			{
				if(Middle_Sensor_2 ==  0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0)
				{
					System.Controll_Flag = 11;
					Y_Dir_Speed = 0;
					Delay_ms(50);
					System.Controll_Flag = 0;
					NowCarPosition.Flag = OnTheRight;
					break;
				}
			}
			break;
			
		case HalfPrcoessArea_Left :
			System.Controll_Flag = 0;
		  X_Dir_Speed = 0;
		  Y_Dir_Speed = Speed;
		while(1)
		{
			if(Middle_Sensor_2 ==  0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0)
				{
					System.Controll_Flag = 11;
					Y_Dir_Speed = 0;
					Delay_ms(50);
					System.Controll_Flag = 0;
					NowCarPosition.Flag = OnTheLeft;
					break;
				}
		}
		break;
		
		case HalfProcessArea_Middle :
			System.Controll_Flag = 0;
		  X_Dir_Speed = 0;
			if(NowCarPosition.Flag == OnTheRight)
				Y_Dir_Speed = Speed;
			else if(NowCarPosition.Flag == OnTheMiddle)
				Y_Dir_Speed = 0;
			else
				Y_Dir_Speed = -Speed;
			while(1)
			{
				if(Middle_Sensor_3 == 0 && Left_Sensor_3 == 1 && Right_Sensor_3 == 1)
					{
						System.Controll_Flag = 13;
						NowCarPosition.Flag = OnTheMiddle;
					  break;
					}
			}
			break;
		
		case HalfProcessArea_Right :
			System.Controll_Flag = 0;
		  X_Dir_Speed = 0;
			Y_Dir_Speed = -Speed;
		while(1)
		{
			if(Middle_Sensor_2 == 0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0)
				{
					System.Controll_Flag = 11;
					Y_Dir_Speed = 0;
					Delay_ms(50);
					System.Controll_Flag = 0;
					NowCarPosition.Flag = OnTheRight;
					break;
				}
		}
		break;
		
		case FinishArea_Left :
			System.Controll_Flag = 0;
		  X_Dir_Speed = 0;
			Y_Dir_Speed = Speed;
			while(1)
			{
				if(Middle_Sensor_2 == 0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0)
				{
					System.Controll_Flag = 11;
					Y_Dir_Speed = 0;
					Delay_ms(50);
					System.Controll_Flag = 0;
					NowCarPosition.Flag = OnTheLeft;
					break;
				}
			}
			break;
			
		case FinishArea_Middle :
			System.Controll_Flag = 0;
		  X_Dir_Speed = 0;
		  if(NowCarPosition.Flag == OnTheLeft)
				Y_Dir_Speed = -Speed;
			else if(NowCarPosition.Flag == OnTheMiddle)
				Y_Dir_Speed = 0;
			else
				Y_Dir_Speed = Speed;
			while(1)
			{
				if(Middle_Sensor_1 == 0 &&Middle_Sensor_3 == 0 && Left_Sensor_3 == 1 && Right_Sensor_3 == 1)
				{
					System.Controll_Flag = 13;
					NowCarPosition.Flag = OnTheMiddle;
					break;
				}
			}
			break;
			
		case FinishArea_Right :
			System.Controll_Flag = 0;
		  X_Dir_Speed = 0;
		  Y_Dir_Speed = -Speed;
			while(1)
			{
				if(Middle_Sensor_2 == 0 && Left1_Sensor_2 == 0 && Right1_Sensor_2 == 0)
				{
					Y_Dir_Speed = 0;
					System.Controll_Flag = 11;
					Delay_ms(50);
					System.Controll_Flag = 0;
					NowCarPosition.Flag = OnTheRight;
					break;
				}
			}
			break;
			
		case BlackBline_Anyway:
			System.Controll_Flag = 13;
		  while(1)
			{
				if(Left_Sensor_3 == 1 && Middle_Sensor_3 == 0 && Right_Sensor_3 == 1)
				{
					X_Dir_Speed = 0;
					Y_Dir_Speed = 0;
					break;
				}
			}
			break;

		case Second_MaterialArea_Middle:
			X_Dir_Speed = 0;
			if(NowCarPosition.Flag == OnTheLeft)
				Y_Dir_Speed = -Speed;
			else if(NowCarPosition.Flag == OnTheRight)
				Y_Dir_Speed = Speed;
			else if(Left_Sensor_1 == 1 && Middle_Sensor_1 == 0 && Right_Sensor_1 == 1)
				Y_Dir_Speed = 0;
			else 
			{
				Y_Dir_Speed = 0;
			  System.Controll_Flag = 14;
			}
			while(1)
			{
				if(Left_Sensor_1 == 1 && Middle_Sensor_1 == 0 && Right_Sensor_1 == 1)
				{
					System.Controll_Flag = 14;
					NowCarPosition.Flag = OnTheMiddle;
					break;
				}
			}
			break;
			
			default: Assert_Failed();break; 
	}
}

/*
	* @name   Rotate_Angle
	* @brief  Rotate an Angle
	* @param  angle（-180 ~ 180
	* @retval None   
*/
void Rotate_Angle(int16_t angle)
{
	Expect_Yaw  = angle;
	System.Controll_Flag = 0;
	while(1)
	{
			if((zangle < angle + 1) && (zangle > angle - 1))
			{
				X_Dir_Speed = 0;
	      Y_Dir_Speed = 0;
				break;
			}
		}
}

/*
	* @name   Current_Position_Sensor_Clear
	* @brief  当前位置下，全场定位模块清零，一切从0开始。
	* @param  None
	* @retval None   
*/

void Current_Position_Sensor_Clear(void)
{
	TIM_Cmd(TIM4, DISABLE);
	USART2_Printf((void *)"ACT0");
	Delay_ms(100);
	TIM_Cmd(TIM4, ENABLE);
}

/*
	* @name   Location_Crossroad()
	* @brief  定位到十字路线
	* @param  None
	* @retval None   
*/
void Location_Crossroad(void)
{
	System.Controll_Flag = 12;
	while(1)
	{
		if(Middle_Sensor_1 == 0 && Middle_Sensor_2 == 0 &&  Left_Sensor_1 == 1 && Right_Sensor_1 == 1)
			/* Middle_Sensor_3 ==0 && Left_Sensor_1 == 1 && Right_Sensor_1 == 1 && 
			Left1_Sensor_2 == 1 && Right1_Sensor_2 == 1 && Left_Sensor_3 == 1 && Right_Sensor_3 == 1*/
		{
			System.Controll_Flag = 12;
		 break;
		}
	}
}


