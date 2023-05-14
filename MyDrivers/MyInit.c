#include "MyDrivers.h"
/*--------------------��е����̬���ú�������������--------------------*/
/*--------------------------------------------------------------------
1. Robot_Arm_Init()------��е�۳�ʼ��̬���۵�״̬��
2. Robot_Arm_Pose(uint8_t num)------��е����̬.
---------------------------------num----------------------------------
0��ץȡ��̬��ֱ������ 1��ץȡһ�����Ϻ󱣳�ֱ����
2����ץȡ�������Ϸ��ú�ɫ���ϼܡ�3����ץȡ�������Ϸ�����ɫ���ϼܡ�3����ץȡ�������Ϸ�����ɫ���ϼܡ�
5�������ϼ���ȡ����ɫ���Ϸ��õ���ӹ����ĺ�ɫλ�á�6�������ϼ���ȡ����ɫ���Ϸ��õ���ӹ�������ɫλ�á�
7�������ϼ���ȡ����ɫ���Ϸ��õ���ӹ�������ɫλ�á�
8���Ӱ�ӹ�����ɫ����λ��ȡ����ɫ�����ҷ��õ���ɫ���ϼ��ϡ�9���Ӱ�ӹ�����ɫ����λ��ȡ����ɫ�����ҷ��õ���ɫ���ϼ��ϡ�
10���Ӱ�ӹ�����ɫ����λ��ȡ����ɫ�����ҷ��õ���ɫ���ϼ��ϡ�
11�������ϼ��Ϻ�ɫ���Ϸ��ó�Ʒ���ײ��ɫ����λ�á�12�������ϼ�����ɫ���Ϸ��ó�Ʒ���ײ���ɫ����λ�á�
13�������ϼ�����ɫ���Ϸ��ó�Ʒ���ײ���ɫ����λ�á�
14�������ϼ��Ϻ�ɫ���Ϸ��ó�Ʒ�������ɫ����λ�á�15�������ϼ�����ɫ���Ϸ��ó�Ʒ��������ɫ����λ�á�
16�������ϼ�����ɫ���Ϸ��ó�Ʒ�������ɫ����λ�á�
17��׼��ȡ���ײ����ϣ�ֱ��--->צ�ӳ�ץȡ״̬��18��צ�Ӻϲ���ץס���ϡ�
19��ȡ��ԭ�����ײ��ɫ���ϲ����õ����ϼܺ�ɫλ�á�20��ȡ��ԭ�����ײ���ɫ���ϲ����õ����ϼ���ɫλ�á�
21��ȡ��ԭ�����ײ���ɫ���ϲ����õ����ϼ���ɫλ�á�
--------------------------------------------------------------------*/
/*--------------------------Public variables-----------------------*/

/*
	* @name   Peripheral_Set
	* @brief  �����ʼ��
	* @param  None
	* @retval None   
*/
void Peripheral_Set(void)
{
	int8_t i = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	Delay_Init();
	//Usart1��ѡ��ӳ�䣬�ſ���ʹ��printf()��ӡ��
	USART1_Init(115200);
	//0:�������ģʽ
	USART1_Remap(0);
	//1:WiFiģʽ
//	USART1_Remap(1);
	//Led��ʼ��
	BSP_LED_Init();
	//������ʼ��
	Key_Init();
	//ѭ��ģ���ʼ��
	Tracking_Init();
	//�������оƬ�߼��������ų�ʼ��
	BSP_Motor_GPIO_Config();
	//���ڵ���ٶ�PWM�źų�ʼ��
	Motor_PWM_Time_Init();
	USART3_Init(9600);
	//0:��ά��ģʽ1:��ɫʶ��ģʽ 
	USART3_Remap(0);
	//��Ļ��ʾ
	TFT20_Init();  
	QR_Display(0, (void *)"000");
	QR_Display(1, (void *)"000");
	QR_Display(2, (void *)"000");
	QR_Display(3, (void *)"000");
	//������ʾȫ����λģ���ʼ����ʼ��
	BSP_LED_Toggle(LED2);
	/*----------WIFI����----------*/
//  WIFI_Connect();
  /*----------ȫ����λģ���ʼ��----------*/
	Delay_s(20);
	USART2_Init(115200);
  /*----------����ʱ������----------*/
	//������ʾȫ����λģ���ʼ��������
	BSP_LED_Toggle(LED2);
	//��̬����PID��ʼ��
	Position_PID_Init(&Position_PID_Z);
	//5ms �ж� �򿪡�
	Timer4_5ms_Init();   
	Timer6_1ms_Init();
	//��е�۳�ʼ��
	Robot_Arm_Init();

//	printf("WiFi_Debug Init ok\r\n");
	/*----------��ʱ�����������----------*/
	//һ������
	while(PCin(13) == 1);

	//�����ά��ʶ����
	Car_Move_Distance(Y_Positive_Dir, 649, 350, 0);
	Car_Move_Distance(X_Positive_Dir, 649, 560, 0); 
	//��ά��ɨ��
	QR_Scan();
	//1:��ɫʶ��ģʽ
	USART3_Remap(1); 
	//����ԭ����
	Car_Move_Distance(X_Positive_Dir, 649, 1570, 0);
	//��ת��-90��
	Rotate_Angle(-90);
  //��ɫʶ��
	Color_Scan();
	//��λ��ԭ������ɫ��
	Car_Move_Distance(Location_DownBlackLine, 269, 0, -90); //X_Dir_Speed
	Location_BlackBine(BlackBline_Anyway, 269);
	//ԭ����ץȡ����
	for(i = 0; i < 3; i++)
	{
		if(Color_Code[0][0] == QR_Code[0][i])
		{
			//�ƶ�
			Location_BlackBine(MaterialArea_Left, 249);
			//��ȡ
			Robot_Arm_Pose(23);
			//������ץȡ�������Ϸ��õ���Ӧ�����ϼ���
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2);break;
				case '2': Robot_Arm_Pose(3);break;
				case '3': Robot_Arm_Pose(4);break;
			}
			//�ص��м䣬Ϊ�´�ץȡ��׼��
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][1] == QR_Code[0][i])
		{
			//�ƶ�
			Location_BlackBine(MaterialArea_Middle, 249);
			//��ȡ
			Robot_Arm_Pose(1);
			//������ץȡ�������Ϸ��õ���Ӧ�����ϼ���
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2);break;
				case '2': Robot_Arm_Pose(3);break;
				case '3': Robot_Arm_Pose(4);break;
			}
			//�ص��м䣬Ϊ�´�ץȡ��׼��
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][2] == QR_Code[0][i])
		{
			//�ƶ�
			Location_BlackBine(MaterialArea_Right, 249);
			//��ȡ
			Robot_Arm_Pose(24);
			//������ץȡ�������Ϸ��õ���Ӧ�����ϼ���
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2);break;
				case '2': Robot_Arm_Pose(3);break;
				case '3': Robot_Arm_Pose(4);break;
			}
			//�ص��м䣬Ϊ�´�ץȡ��׼��
			Location_BlackBine(MaterialArea_Middle, 249);
		}
  }
	//�ƶ�����ӹ���
	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
	//ת��0��
	Rotate_Angle(0);
	//��λʮ����
	Location_Crossroad();
	Delay_s(500);
	//��X+����ǰ��
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
	
	Location_BlackBine(BlackBline_Anyway, 269);
	
	//��ӹ�����������
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(HalfProcessArea_Right,249); Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��
			case '2': Location_BlackBine(HalfProcessArea_Middle,249);Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,269);break;
			//��
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);  Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,269); break;
	  }                     
	}
	Location_BlackBine(BlackBline_Anyway, 269);
	
	
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8); Location_BlackBine(HalfProcessArea_Middle,269); break;
	  }                            
	}
	
	//�ƶ�����Ʒ��
	Car_Move_Distance(X_Negative_Dir, 599, 1070, 0);//��X-����ǰ��
	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//��Y+����ǰ�� 1630

	//��ת����90��
	Rotate_Angle(90);
	Location_Crossroad();//��λʮ����
	Delay_ms(600);
	//�����Ʒ��
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 90);//��X+����ǰ��
	Location_BlackBine(BlackBline_Anyway, 269);
	
	//��������
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(FinishArea_Right,249); Robot_Arm_Pose(11); Location_BlackBine(FinishArea_Middle,269); break;
			//��
			case '2': Location_BlackBine(FinishArea_Middle,249);Robot_Arm_Pose(12); Location_BlackBine(FinishArea_Middle,269); break;
			//��
		  case '3': Location_BlackBine(FinishArea_Left,249);  Robot_Arm_Pose(13); Location_BlackBine(FinishArea_Middle,269); break;
	  }                      
	}
	
	//�ڶ���ȥ��ԭ����
	Car_Move_Distance(X_Negative_Dir_PosyMinish, 649, 500, 90);
	//��ת��0��
	Rotate_Angle(0);
	
	Car_Move_Distance(X_Positive_Dir, 649, 1590, 0);
	//��ת��-90��
	Rotate_Angle(-90);
	Location_Crossroad();//��λʮ����
	Delay_ms(500);
	Location_BlackBine(BlackBline_Anyway, 269);
	
	//ץȡԭ�����ײ�����
	for(i = 0; i <= 3; i++)
	{
		if(Color_Code[1][0] == QR_Code[1][i])
		{
			//��λ�����������
			Location_BlackBine(MaterialArea_Left, 249);
			//׼��ץȡ����
			Robot_Arm_Pose(25);
			//��ǰ�ƶ�
			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
			//ץȡ����
			Robot_Arm_Pose(18);
			//����˳�
			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
			//�������ϵ����ϼ�
			switch(QR_Code[1][i])
			{
				case '1': Robot_Arm_Pose(19); break;
				case '2': Robot_Arm_Pose(20); break;
				case '3': Robot_Arm_Pose(21); break;
			}
			//�ص�����������
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(150);
		}
		else if(Color_Code[1][1] == QR_Code[1][i])
		{
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(100);
			//׼��ץȡ����
			Robot_Arm_Pose(17);
			//��ǰ�ƶ�
			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
			//ץȡ����
			Robot_Arm_Pose(18);
			//����˳�
			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
		  //�������ϵ����ϼ�
			switch(QR_Code[1][i])
			{
				case '1': Robot_Arm_Pose(19); break;
				case '2': Robot_Arm_Pose(20); break;
				case '3': Robot_Arm_Pose(21); break;
			}
			//�ص�����������
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(150);
		}
		else if(Color_Code[1][2] == QR_Code[1][i])
		{
			//��λ���������Ҳ�
			Location_BlackBine(MaterialArea_Right, 249);
			//׼��ץȡ����
			Robot_Arm_Pose(26);
			//��ǰ�ƶ�
			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
			//ץȡ����
			Robot_Arm_Pose(18);
			//����˳�
			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
			//�������ϵ����ϼ�
			switch(QR_Code[1][i])
			{
				case '1': Robot_Arm_Pose(19); break;
				case '2': Robot_Arm_Pose(20); break;
				case '3': Robot_Arm_Pose(21); break;
			}
			//�ص�����������
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(150);
		}
	}

	//�ƶ�����ӹ���
	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
	//ת��0��
	Rotate_Angle(0);
	//��λʮ����
	Location_Crossroad();
	Delay_ms(500);
	//��X+����ǰ��
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
	Location_BlackBine(BlackBline_Anyway, 269);
	
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[1][i])
		{
			//��
			case '1': Location_BlackBine(HalfProcessArea_Right,249); Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��                                             
			case '2': Location_BlackBine(HalfProcessArea_Middle,249);Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��                                                  
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);  Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,269); break;
	  }                                                  
	}
	Location_BlackBine(BlackBline_Anyway, 269);
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[1][i])
		{
			//��
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10);  Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��                                                                       
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9);  Location_BlackBine(HalfProcessArea_Middle,269); break;
			//��                                                                       
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8);  Location_BlackBine(HalfProcessArea_Middle,269); break;
		}                           
	}
	
	Car_Move_Distance(X_Negative_Dir, 649, 1075, 0);//��X-����ǰ��
	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//��Y+����ǰ�� 1630

	Rotate_Angle(90);
	Location_Crossroad();//��λʮ����
	Delay_ms(500);
	
	Car_Move_Distance(Location_DownBlackLine, 299, 0, 90);//��X+����ǰ��
	Location_BlackBine(BlackBline_Anyway, 269);

	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(FinishArea_Right,249); Robot_Arm_Pose(14); Location_BlackBine(FinishArea_Middle,269); break;
			//��
			case '2': Location_BlackBine(FinishArea_Middle,249);Robot_Arm_Pose(15); Location_BlackBine(FinishArea_Middle,269); break;
			//��
		  case '3': Location_BlackBine(FinishArea_Left,249);  Robot_Arm_Pose(16); Location_BlackBine(FinishArea_Middle,269); break;
	  }                  
	}
	Car_Move_Distance(Y_Positive_Dir_PosxMinish,  599, 80, 90);
	Car_Move_Distance(Y_Positive_Dir, 399, 2000, 0);
	
	/*----------ҵ���������----------*/
	
	/*----------ҵ���������----------*/
	/*
	//һ������
	while(PCin(13) == 1);
	//�����ά��ʶ����
	Car_Move_Distance(Y_Positive_Dir, 649, 390, 0);
	Car_Move_Distance(X_Positive_Dir, 649, 560, 0); 
	//��ά��ɨ��
	QR_Scan();
	USART3_Remap(1);    //1:��ɫʶ��ģʽ
	//����ԭ����
	Car_Move_Distance(X_Positive_Dir, 649, 1570, 0);
	//��ת��-90��
	Rotate_Angle(-90);
  //��ɫʶ��
	Color_Scan();
	//��λ��ԭ������ɫ��
	Car_Move_Distance(Location_DownBlackLine, 269, 0, -90); //X_Dir_Speed
	//ԭ����ץȡ����
	for(i = 0; i < 3; i++)
	{
		if(Color_Code[0][0] == QR_Code[0][i])
		{
			//�ƶ�
			Location_BlackBine(MaterialArea_Left, 249);
			//��ȡ
			Robot_Arm_Pose(1);
			//������ץȡ�������Ϸ��õ���Ӧ�����ϼ���
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2); break;
				case '2': Robot_Arm_Pose(3); break;
				case '3': Robot_Arm_Pose(4); break;
			}
			//�ص��м䣬Ϊ�´�ץȡ��׼��
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][1] == QR_Code[0][i])
		{
			//�ƶ�
//			Location_BlackBine(MaterialArea_Middle, 249);
			//��ȡ
			Robot_Arm_Pose(1);
			//������ץȡ�������Ϸ��õ���Ӧ�����ϼ���
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2); break;
				case '2': Robot_Arm_Pose(3); break;
				case '3': Robot_Arm_Pose(4); break;
			}
			//�ص��м䣬Ϊ�´�ץȡ��׼��
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][2] == QR_Code[0][i])
		{
			//�ƶ�
			Location_BlackBine(MaterialArea_Right, 249);
			//��ȡ
			Robot_Arm_Pose(22);
			//������ץȡ�������Ϸ��õ���Ӧ�����ϼ���
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2); break;
				case '2': Robot_Arm_Pose(3); break;
				case '3': Robot_Arm_Pose(4); break;
			}
			//�ص��м䣬Ϊ�´�ץȡ��׼��
			Location_BlackBine(MaterialArea_Middle, 249);
		}
  }
	
	//�ƶ�����ӹ���
	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
	//ת��0��
	Rotate_Angle(0);
	//��λʮ����
	Location_Crossroad();
	Delay_ms(350);

	//��X+����ǰ��
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
	//��ӹ�����������
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,249); break;
			//��
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,249); break;
			//��
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,249); break;
	  }                            
	}
//	
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10); Location_BlackBine(HalfProcessArea_Middle,249); break;
			//��
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9);  Location_BlackBine(HalfProcessArea_Middle,249); break;
			//��
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8);  Location_BlackBine(HalfProcessArea_Middle,249); break;
	  }                            
	}
	
	//�ƶ�����Ʒ��
	Car_Move_Distance(X_Negative_Dir, 599, 1075, 0);//��X-����ǰ��
	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//��Y+����ǰ�� 1630

	//��ת����90��
	Rotate_Angle(90);
	Location_Crossroad();//��λʮ����
	Delay_ms(350);
	//�����Ʒ��
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 90);//��X+����ǰ��
	//��������
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//��
			case '1': Location_BlackBine(FinishArea_Right,249);   Robot_Arm_Pose(11);  Location_BlackBine(FinishArea_Middle,249); break;
			//��
			case '2':   Robot_Arm_Pose(12);  Location_BlackBine(FinishArea_Middle,249); break;
			//��
//		  case '3': Location_BlackBine(FinishArea_Left,249);    Robot_Arm_Pose(13);  Location_BlackBine(FinishArea_Middle,249); break;
//	  }                        
//	}
//	//�ڶ���ȥ��ԭ����
//	Car_Move_Distance(X_Negative_Dir_PosyMinish, 599, 500, 90);
//	//��ת��0��
//	Rotate_Angle(0);
//	
//	Car_Move_Distance(X_Positive_Dir, 599, 1590, 0);
//	//��ת��-90��
//	Rotate_Angle(-90);
//	Location_Crossroad();//��λʮ����
//	TFT20_DrawFont_GBK16(0, 0, BLACK, WHITE,(void *) "3");
//	Delay_ms(350);
//	TFT20_DrawFont_GBK16(0, 0, BLACK, WHITE,(void *) "4");
//	//ץȡԭ�����ײ�wu��
//	for(i = 0; i <= 3; i++)
//	{
//		if(Color_Code[1][0] == QR_Code[1][i])
//		{
//			//��λ�����������
//			Location_BlackBine(MaterialArea_Left, 249);
//			//׼��ץȡ����
//			Robot_Arm_Pose(17);
//			//��ǰ�ƶ�
//			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
//			//ץȡ����
//		  Robot_Arm_Pose(18);
//			//����˳�
//			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
//			//�������ϵ����ϼ�
//			switch(QR_Code[1][i])
//			{
//				case '1': Robot_Arm_Pose(19); break;
//				case '2': Robot_Arm_Pose(20); break;
//				case '3': Robot_Arm_Pose(21); break;
//			}
//			//�ص�����������
//			Location_BlackBine(Second_MaterialArea_Middle, 249);
//		}
//		else if(Color_Code[1][1] == QR_Code[1][i])
//		{
//			//׼��ץȡ����
//			Robot_Arm_Pose(17);
//			//��ǰ�ƶ�
//			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
//			//ץȡ����
//			Robot_Arm_Pose(18);
//			//����˳�
//			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
//		  //�������ϵ����ϼ�
//			switch(QR_Code[1][i])
//			{
//				case '1': Robot_Arm_Pose(19); break;
//				case '2': Robot_Arm_Pose(20); break;
//				case '3': Robot_Arm_Pose(21); break;
//			}
//			//�ص�����������
//			Location_BlackBine(Second_MaterialArea_Middle, 249);
//		}
//		else if(Color_Code[1][2] == QR_Code[1][i])
//		{	
//			//��λ���������Ҳ�
//			Location_BlackBine(MaterialArea_Right, 249);
//			//׼��ץȡ����
//			Robot_Arm_Pose(17);
//			//��ǰ�ƶ�
//			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
//			//ץȡ����
//		  Robot_Arm_Pose(18);
//			//����˳�
//			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
//			//�������ϵ����ϼ�
//			switch(QR_Code[1][i])
//			{
//				case '1': Robot_Arm_Pose(19); break;
//				case '2': Robot_Arm_Pose(20); break;
//				case '3': Robot_Arm_Pose(21); break;
//			}
//			//�ص�����������
//			Location_BlackBine(Second_MaterialArea_Middle, 249);
//		}
//	}
//	
//	//�ƶ�����ӹ���
//	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
//	//ת��0��
//	Rotate_Angle(0);
//	//��λʮ����
//	Location_Crossroad();
//	Delay_ms(350);
//	//��X+����ǰ��
//	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
//	
//	for(i = 0; i <= 3; i++)
//	{
//		switch(QR_Code[1][i])
//		{
//			//��
//			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//��
//			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//��
//			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,249); break;
//	  }                            
//	}
//	
//	for(i = 0; i <= 3; i++)
//	{
//		switch(QR_Code[1][i])
//		{
//			//��
//			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10); Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//��
//			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9);  Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//��
//			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8);  Location_BlackBine(HalfProcessArea_Middle,249); break;
//		}                            
//	}
//	
//	Car_Move_Distance(X_Negative_Dir, 599, 1075, 0);//��X-����ǰ��

//	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//��Y+����ǰ�� 1630

//	Rotate_Angle(90);
//	Location_Crossroad();//��λʮ����
//	Delay_ms(350);
//	
//	Car_Move_Distance(Location_DownBlackLine, 299, 0, 90);//��X+����ǰ��

//	for(i = 0; i <= 3; i++)
//	{
//		switch(QR_Code[0][i])
//		{
//			//��
//			case '1': Location_BlackBine(FinishArea_Right,249); Robot_Arm_Pose(14);  Location_BlackBine(FinishArea_Middle,249); break;
//			//��
//			case '2': Robot_Arm_Pose(15); Location_BlackBine(FinishArea_Middle,249); break;
//			//��
//		  case '3': Location_BlackBine(FinishArea_Left,249);  Robot_Arm_Pose(16); Location_BlackBine(FinishArea_Middle,249); break;
//	  }                      
//	}

//	
//	Car_Move_Distance(Parking_XEnd, 599, 0, 90);
//	Car_Move_Distance(Location_DownBlackLine, 269, 0, 90);
//	
	*/
}
/*-------------------------------------------------------


---------------------------------------------------------*/

