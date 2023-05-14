#include "MyDrivers.h"
/* Public variables-----------------------------------------------------------*/
volatile uint16_t  usMCU_Run_Timer = 0;
volatile uint8_t   usPID_Run_Timer = 0;

uint8_t USART1_RX_Buff[9];
uint8_t USART1_Flag = 0;

/* Private variables-----------------------------------------------------------*/

/*
	* @name   TIM4_IRQHandler
	* @brief  Time4中断服务函数
	* @param  参数：None
	* @retval None   
*/
void TIM4_IRQHandler(void)
{
 if(TIM_GetITStatus(TIM4,TIM_IT_Update) == SET)
	{
    if(++usPID_Run_Timer >= 1)
		{
			if(System.Controll_Flag == 0)//普通姿态矫正
			{
				if(zangle > -0.000001 && zangle < +0.000001) 
					zangle = Lsat_zangle;
				//Z_Dir_Speed = Position_PID_Calc_1(&Position_PID_Z, (int)(zangle));
				Z_Dir_Speed = Position_PID_Calc(&Position_PID_Z, (int)Expect_Yaw, (int )zangle);
				Motor_Speed_Calc();
			}
			
			if(System.Controll_Flag == 11)//Stop Car
			{
				TIM_Cmd(TIM3, DISABLE); 
				ALL_Motor_Stop;
				TIM_Cmd(TIM3, ENABLE); 
				X_Dir_Speed = 0;
				Y_Dir_Speed = 0;
			}
			
			if(System.Controll_Flag == 12) //Location_Crossroad
			{
				Z_Dir_Speed = Position_PID_Calc(&Position_PID_Z, (int)Expect_Yaw, (int )zangle);
				if(Left2_Sensor_2 == 1 && Left1_Sensor_2 ==1 && Middle_Sensor_2 == 0 && Right1_Sensor_2 == 1 && Right2_Sensor_2 == 1)
				{
					X_Dir_Speed = 0;
				}
				else if(Left2_Sensor_2 == 0 && Left1_Sensor_2 == 1 && Middle_Sensor_2 == 1 && Right1_Sensor_2 == 1 && Right2_Sensor_2 == 1)
				{
					X_Dir_Speed = 349;
				}	
				else if(Left2_Sensor_2 == 1 && Left1_Sensor_2 == 0 && Middle_Sensor_2 == 1 && Right1_Sensor_2 == 1 && Right2_Sensor_2 == 1)
				{
					X_Dir_Speed = 299;
				}
				else if(Left2_Sensor_2 == 1 && Left1_Sensor_2 == 1 && Middle_Sensor_2 == 1 && Right1_Sensor_2 == 0 && Right2_Sensor_2 == 1)
				{
					X_Dir_Speed = -299;
				}
				else if(Left2_Sensor_2 == 1 && Left1_Sensor_2 == 1 && Middle_Sensor_2 == 1 && Right1_Sensor_2 == 1 && Right2_Sensor_2 == 0)
				{
					X_Dir_Speed = -349;
				}
				else if(Left2_Sensor_2 == 1 && Left1_Sensor_2 == 1 && Middle_Sensor_2 == 1 && Right1_Sensor_2 == 1 && Right2_Sensor_2 == 1)
				{
					X_Dir_Speed = -249;
				}
				if(Left_Sensor_1 == 1 && Middle_Sensor_1 == 0 && Right_Sensor_1 == 1)
				{
					Y_Dir_Speed = 0;
				}
				else if(Left_Sensor_1 == 0 && Middle_Sensor_1 == 1 && Right_Sensor_1 == 1)
				{
					Y_Dir_Speed = 349;
				}
				else if(Left_Sensor_1 == 1 && Middle_Sensor_1 == 1 && Right_Sensor_1 == 0)
				{
					Y_Dir_Speed = -349;
				}
				else if(Right_Sensor_1 == 1 && Left_Sensor_1 == 1 && Middle_Sensor_1 == 1)
				{
					Y_Dir_Speed = -299;
				}
				else if(Right_Sensor_1 == 1 && Left_Sensor_1 == 0 && Middle_Sensor_1 == 0)
				{
					Y_Dir_Speed = 249;
				}
				Motor_Speed_Calc();
			}
			
			if(System.Controll_Flag == 13)
			{
				Z_Dir_Speed = Position_PID_Calc(&Position_PID_Z, (int)(Expect_Yaw), (int)(zangle));
				if(Middle_Sensor_1 ==0 && Left_Sensor_3 == 1 && Middle_Sensor_3 == 0 && Right_Sensor_3 == 1)
				{
					Y_Dir_Speed = 0;
					X_Dir_Speed = 0;
				}
				else if(Left_Sensor_3 == 0 && Middle_Sensor_3 ==1 && Right_Sensor_3 == 1)
				{
					Y_Dir_Speed = 299;
				}
				else if(Left_Sensor_3 == 1 && Middle_Sensor_3 ==1 && Right_Sensor_3 == 0)
				{
					Y_Dir_Speed = -299;
				}
				else if(Left_Sensor_3 == 1 && Middle_Sensor_3 == 1 && Right_Sensor_3 == 1)
				{
					Y_Dir_Speed = -249;
				}
				else if(Left_Sensor_3 == 1 && Middle_Sensor_3 == 0 && Right_Sensor_3 == 0)
				{
					Y_Dir_Speed = -249;
				}
				else if(Left_Sensor_3 == 0 && Middle_Sensor_3 == 0 && Right_Sensor_3 == 1)
				{
					Y_Dir_Speed = 249;
				}
				Motor_Speed_Calc();
			}
			
			if(System.Controll_Flag == 14)
			{
				Z_Dir_Speed = Position_PID_Calc(&Position_PID_Z, (int)(Expect_Yaw), (int)(zangle));
				if(Middle_Sensor_1 == 0 && Left_Sensor_1 == 1 && Right_Sensor_1 == 1)
				{
					Y_Dir_Speed = 0;
					X_Dir_Speed = 0;
				}
				else if(Left_Sensor_1 == 0 && Middle_Sensor_1 ==1 &&Right_Sensor_1 == 1)
				{
					Y_Dir_Speed = 399;
				}
				else if(Left_Sensor_1 == 1 && Middle_Sensor_1 ==1 && Right_Sensor_1 == 0)
				{
					Y_Dir_Speed = -399;
				}
				else if(Middle_Sensor_1 == 1 && Left_Sensor_1 == 1 && Right_Sensor_1 == 1)
				{
					Y_Dir_Speed = 399;
				}
				else if(Left_Sensor_1 == 0 && Middle_Sensor_1 == 0 && Right_Sensor_1 == 1)
				{
					Y_Dir_Speed = 299;
				}
				else if(Left_Sensor_1 == 1 && Middle_Sensor_1 == 0 && Right_Sensor_1 == 0)
				{
					Y_Dir_Speed = -299;
				}
				Motor_Speed_Calc();
			}
		
			usPID_Run_Timer = 0;
		}

		if(++usMCU_Run_Timer >= TIMER4_1S)
		{
			BSP_LED_Toggle(LED1);
//			printf("pos_x = %.3f pos_y = %.3f zangle = %.3f ", pos_x, pos_y, zangle);
//			printf("X_Speed = %d Y_Speed = %d Z_Speed = %d ", X_Dir_Speed, Y_Dir_Speed, Z_Dir_Speed);
//			TFT20_ShowFloatNum(0,  0, pos_x, 3);
//			TFT20_ShowFloatNum(0, 16, pos_y, 3);
//			TFT20_ShowFloatNum(0, 32, zangle, 3);
			usMCU_Run_Timer = 0;
		}
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}

/*
	* @name   USART1_IRQHandler
	* @brief  USART1中断服务函数
	* @param  参数：None
	* @retval None   
*/
void USART1_IRQHandler(void)
{
//	uint8_t i = 0;
//	uint8_t dat;
//	static uint8_t Rx_Count = 0;
	if(USART1_Remap_Flag == FALSE)
	{
		if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
		{
			if(USART1 -> DR)
			{                                	
				WiFi_RX_BUF[WiFi_RxCounter] = USART_ReceiveData(USART1); 	
				WiFi_RxCounter++;                        
			}
//			dat = USART_ReceiveData(USART1);
//		 if(dat >= '1' && dat <= '3'|| dat == '+') 
//			{
//				USART1_RX_Buff[Rx_Count++]=dat;
//				if(Rx_Count == 7)
//					{
//						USART1_Flag = TRUE;
//						QR_Code[0][0]=USART1_RX_Buff[0];
//						QR_Code[0][1]=USART1_RX_Buff[1];
//						QR_Code[0][2]=USART1_RX_Buff[2];
//						
//						QR_Code[1][0]=USART1_RX_Buff[4];
//						QR_Code[1][1]=USART1_RX_Buff[5];
//						QR_Code[1][2]=USART1_RX_Buff[6];
//						Rx_Count = 0;
//						PAout(9) = 0;
//					}
//			}
//			else 
//			{
//				Rx_Count=0;
//				for(i = 0; i <= 7; i++)
//				{
//					USART1_RX_Buff[i] = 0;
//				}
//			}
			USART_ClearFlag(USART1, USART_FLAG_RXNE);
		}
  }
	if(USART1_Remap_Flag == TRUE)
	{
		USART_ClearITPendingBit(USART1, USART_IT_ORE);
		uartBuf[tail] = USART_ReceiveData(USART1);
		tail = (tail + 1) % 128;
		//USART_ClearFlag(USART1, USART_FLAG_RXNE);

	}
}


/*
	* @name   USART2_IRQHandler
	* @brief  USART2中断服务函数
	* @param  参数：None
	* @retval None   
*/
void USART2_IRQHandler(void)
{
	static uint8_t ch;
	static union
	{
		uint8_t date[24];
		float ActVal[6];
	}posture;
	static uint8_t count=0;
	static uint8_t i=0;
	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		USART_ClearITPendingBit(USART2, USART_FLAG_RXNE);
		ch = USART_ReceiveData(USART2);
		switch(count)
		{
			case 0: if(ch == 0x0d) count++; else count = 0;                                   break;
			case 1: if(ch == 0x0a) {i = 0; count=count++;}else if(ch == 0x0d);else count = 0; break;
			case 2: posture.date[i] = ch; i++;if(i >= 24){i = 0;count++;}                     break;
			case 3:if(ch == 0x0a) count++;else count = 0;                                     break;
			case 4:if(ch == 0x0d){
															zangle = posture.ActVal[0];
//															xangle = posture.ActVal[1];
//															yangle = posture.ActVal[2];
															pos_x  = posture.ActVal[3];
															pos_y  = posture.ActVal[4];
															/*w_z    = posture.ActVal[5];*/}count = 0;                    break;
			default:count = 0;                                                                break;       
		}
	}
}

/*
	* @name   USART3_IRQHandler
	* @brief  USART3中断服务函数
	* @param  参数：None
	* @retval None   
*/
void USART3_IRQHandler(void)
{
	uint8_t i = 0;
	uint8_t dat;
	static uint8_t Rx_Count = 0;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	 {
		 if(USART3_Remap_Flag == TRUE)//因为二维码是USART3重映射连接的。
		 {
			 dat = USART_ReceiveData(USART3);
			 if(dat >= '1' && dat <= '3'|| dat == '+') 
				{
					USART3_RX_Buff[Rx_Count++] = dat;
					if(Rx_Count == 7)
						{
							Usart3.Flag = TRUE;
							QR_Code[0][0] = USART3_RX_Buff[0];
							QR_Code[0][1] = USART3_RX_Buff[1];
							QR_Code[0][2] = USART3_RX_Buff[2];						
							QR_Code[1][0] = USART3_RX_Buff[4];
							QR_Code[1][1] = USART3_RX_Buff[5];
							QR_Code[1][2] = USART3_RX_Buff[6];
							Rx_Count = 0;
						}
				}
				 else 
					{
						Rx_Count=0;
						for(i = 0; i <= 7; i++)
						{
							USART3_RX_Buff[i] = 0;
						}
					}
			}
		 if(USART3_Remap_Flag == FALSE)
		 {
			 dat = USART_ReceiveData(USART3);
			 if(dat >= '1' && dat <= '3') 
		    {
					USART3_RX_Buff[Rx_Count++] = dat;
			    if(Rx_Count >= 6)
					{
						
						Color_Code[0][0] = USART3_RX_Buff[0];
						Color_Code[0][1] = USART3_RX_Buff[1];
						Color_Code[0][2] = USART3_RX_Buff[2];
																
						Color_Code[1][0] = USART3_RX_Buff[3];
						Color_Code[1][1] = USART3_RX_Buff[4];
						Color_Code[1][2] = USART3_RX_Buff[5];
						Rx_Count=0;
						Usart3.Flag = TRUE; 
					}
				 }
					else
					{
						Rx_Count=0;
						for(i = 0; i <= 7; i++)
						{
							USART3_RX_Buff[i] = 0;
						}
					}
		    }
		  USART_ClearFlag(USART3,USART_FLAG_RXNE);
	   }
}

