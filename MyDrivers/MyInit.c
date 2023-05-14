#include "MyDrivers.h"
/*--------------------机械臂姿态调用函数级函数传参--------------------*/
/*--------------------------------------------------------------------
1. Robot_Arm_Init()------机械臂初始姿态，折叠状态。
2. Robot_Arm_Pose(uint8_t num)------机械臂姿态.
---------------------------------num----------------------------------
0：抓取姿态（直立）， 1：抓取一个物料后保持直立。
2：将抓取到的物料放置红色物料架。3：将抓取到的物料放置绿色物料架。3：将抓取到的物料放置蓝色物料架。
5：从物料架上取到红色物料放置到半加工区的红色位置。6：从物料架上取到绿色物料放置到半加工区的绿色位置。
7：从物料架上取到蓝色物料放置到半加工区的蓝色位置。
8：从半加工区蓝色物料位置取到蓝色，并且放置到蓝色物料架上。9：从半加工区绿色物料位置取到绿色，并且放置到绿色物料架上。
10：从半加工区红色物料位置取到红色，并且放置到红色物料架上。
11：将物料架上红色物料放置成品区底层红色物料位置。12：将物料架上绿色物料放置成品区底层绿色物料位置。
13：将物料架上蓝色物料放置成品区底层蓝色物料位置。
14：将物料架上红色物料放置成品区顶层红色物料位置。15：将物料架上绿色物料放置成品区顶层绿色物料位置。
16：将物料架上蓝色物料放置成品区顶层红色物料位置。
17：准备取处底层物料（直立--->爪子呈抓取状态）18：爪子合并，抓住物料。
19：取出原料区底层红色物料并放置到物料架红色位置。20：取出原料区底层绿色物料并放置到物料架绿色位置。
21：取出原料区底层蓝色物料并放置到物料架蓝色位置。
--------------------------------------------------------------------*/
/*--------------------------Public variables-----------------------*/

/*
	* @name   Peripheral_Set
	* @brief  外设初始化
	* @param  None
	* @retval None   
*/
void Peripheral_Set(void)
{
	int8_t i = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	Delay_Init();
	//Usart1不选择映射，才可以使用printf()打印。
	USART1_Init(115200);
	//0:舵机控制模式
	USART1_Remap(0);
	//1:WiFi模式
//	USART1_Remap(1);
	//Led初始化
	BSP_LED_Init();
	//按键初始化
	Key_Init();
	//循迹模块初始化
	Tracking_Init();
	//电机驱动芯片逻辑控制引脚初始化
	BSP_Motor_GPIO_Config();
	//调节电机速度PWM信号初始化
	Motor_PWM_Time_Init();
	USART3_Init(9600);
	//0:二维码模式1:颜色识别模式 
	USART3_Remap(0);
	//屏幕显示
	TFT20_Init();  
	QR_Display(0, (void *)"000");
	QR_Display(1, (void *)"000");
	QR_Display(2, (void *)"000");
	QR_Display(3, (void *)"000");
	//用来提示全场定位模块初始化开始。
	BSP_LED_Toggle(LED2);
	/*----------WIFI连接----------*/
//  WIFI_Connect();
  /*----------全场定位模块初始化----------*/
	Delay_s(20);
	USART2_Init(115200);
  /*----------心跳时基开启----------*/
	//用来提示全场定位模块初始化结束。
	BSP_LED_Toggle(LED2);
	//姿态矫正PID初始化
	Position_PID_Init(&Position_PID_Z);
	//5ms 中断 打开。
	Timer4_5ms_Init();   
	Timer6_1ms_Init();
	//机械臂初始化
	Robot_Arm_Init();

//	printf("WiFi_Debug Init ok\r\n");
	/*----------临时代码测试区域----------*/
	//一键启动
	while(PCin(13) == 1);

	//到达二维码识别区
	Car_Move_Distance(Y_Positive_Dir, 649, 350, 0);
	Car_Move_Distance(X_Positive_Dir, 649, 560, 0); 
	//二维码扫描
	QR_Scan();
	//1:颜色识别模式
	USART3_Remap(1); 
	//到达原料区
	Car_Move_Distance(X_Positive_Dir, 649, 1570, 0);
	//旋转到-90°
	Rotate_Angle(-90);
  //颜色识别
	Color_Scan();
	//定位到原料区黑色线
	Car_Move_Distance(Location_DownBlackLine, 269, 0, -90); //X_Dir_Speed
	Location_BlackBine(BlackBline_Anyway, 269);
	//原料区抓取物料
	for(i = 0; i < 3; i++)
	{
		if(Color_Code[0][0] == QR_Code[0][i])
		{
			//移动
			Location_BlackBine(MaterialArea_Left, 249);
			//夹取
			Robot_Arm_Pose(23);
			//将本次抓取到的物料放置到对应的物料架上
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2);break;
				case '2': Robot_Arm_Pose(3);break;
				case '3': Robot_Arm_Pose(4);break;
			}
			//回到中间，为下次抓取做准备
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][1] == QR_Code[0][i])
		{
			//移动
			Location_BlackBine(MaterialArea_Middle, 249);
			//夹取
			Robot_Arm_Pose(1);
			//将本次抓取到的物料放置到对应的物料架上
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2);break;
				case '2': Robot_Arm_Pose(3);break;
				case '3': Robot_Arm_Pose(4);break;
			}
			//回到中间，为下次抓取做准备
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][2] == QR_Code[0][i])
		{
			//移动
			Location_BlackBine(MaterialArea_Right, 249);
			//夹取
			Robot_Arm_Pose(24);
			//将本次抓取到的物料放置到对应的物料架上
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2);break;
				case '2': Robot_Arm_Pose(3);break;
				case '3': Robot_Arm_Pose(4);break;
			}
			//回到中间，为下次抓取做准备
			Location_BlackBine(MaterialArea_Middle, 249);
		}
  }
	//移动到半加工区
	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
	//转向到0°
	Rotate_Angle(0);
	//定位十字线
	Location_Crossroad();
	Delay_s(500);
	//向X+方向前进
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
	
	Location_BlackBine(BlackBline_Anyway, 269);
	
	//半加工区放置物料
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(HalfProcessArea_Right,249); Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//中
			case '2': Location_BlackBine(HalfProcessArea_Middle,249);Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,269);break;
			//右
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);  Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,269); break;
	  }                     
	}
	Location_BlackBine(BlackBline_Anyway, 269);
	
	
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//中
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//右
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8); Location_BlackBine(HalfProcessArea_Middle,269); break;
	  }                            
	}
	
	//移动到成品区
	Car_Move_Distance(X_Negative_Dir, 599, 1070, 0);//向X-方向前进
	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//向Y+方向前进 1630

	//旋转到正90°
	Rotate_Angle(90);
	Location_Crossroad();//定位十字线
	Delay_ms(600);
	//到达成品区
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 90);//向X+方向前进
	Location_BlackBine(BlackBline_Anyway, 269);
	
	//放置物料
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(FinishArea_Right,249); Robot_Arm_Pose(11); Location_BlackBine(FinishArea_Middle,269); break;
			//中
			case '2': Location_BlackBine(FinishArea_Middle,249);Robot_Arm_Pose(12); Location_BlackBine(FinishArea_Middle,269); break;
			//右
		  case '3': Location_BlackBine(FinishArea_Left,249);  Robot_Arm_Pose(13); Location_BlackBine(FinishArea_Middle,269); break;
	  }                      
	}
	
	//第二次去往原料区
	Car_Move_Distance(X_Negative_Dir_PosyMinish, 649, 500, 90);
	//旋转到0°
	Rotate_Angle(0);
	
	Car_Move_Distance(X_Positive_Dir, 649, 1590, 0);
	//旋转到-90°
	Rotate_Angle(-90);
	Location_Crossroad();//定位十字线
	Delay_ms(500);
	Location_BlackBine(BlackBline_Anyway, 269);
	
	//抓取原料区底层物料
	for(i = 0; i <= 3; i++)
	{
		if(Color_Code[1][0] == QR_Code[1][i])
		{
			//定位到物料区左侧
			Location_BlackBine(MaterialArea_Left, 249);
			//准备抓取姿势
			Robot_Arm_Pose(25);
			//向前移动
			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
			//抓取物料
			Robot_Arm_Pose(18);
			//向后退出
			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
			//放置物料到物料架
			switch(QR_Code[1][i])
			{
				case '1': Robot_Arm_Pose(19); break;
				case '2': Robot_Arm_Pose(20); break;
				case '3': Robot_Arm_Pose(21); break;
			}
			//回到物料区中线
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(150);
		}
		else if(Color_Code[1][1] == QR_Code[1][i])
		{
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(100);
			//准备抓取姿势
			Robot_Arm_Pose(17);
			//向前移动
			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
			//抓取物料
			Robot_Arm_Pose(18);
			//向后退出
			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
		  //放置物料到物料架
			switch(QR_Code[1][i])
			{
				case '1': Robot_Arm_Pose(19); break;
				case '2': Robot_Arm_Pose(20); break;
				case '3': Robot_Arm_Pose(21); break;
			}
			//回到物料区中线
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(150);
		}
		else if(Color_Code[1][2] == QR_Code[1][i])
		{
			//定位到物料区右侧
			Location_BlackBine(MaterialArea_Right, 249);
			//准备抓取姿势
			Robot_Arm_Pose(26);
			//向前移动
			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
			//抓取物料
			Robot_Arm_Pose(18);
			//向后退出
			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
			//放置物料到物料架
			switch(QR_Code[1][i])
			{
				case '1': Robot_Arm_Pose(19); break;
				case '2': Robot_Arm_Pose(20); break;
				case '3': Robot_Arm_Pose(21); break;
			}
			//回到物料区中线
			Location_BlackBine(Second_MaterialArea_Middle, 249);
			Delay_ms(150);
		}
	}

	//移动到半加工区
	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
	//转向到0°
	Rotate_Angle(0);
	//定位十字线
	Location_Crossroad();
	Delay_ms(500);
	//向X+方向前进
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
	Location_BlackBine(BlackBline_Anyway, 269);
	
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[1][i])
		{
			//左
			case '1': Location_BlackBine(HalfProcessArea_Right,249); Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//中                                             
			case '2': Location_BlackBine(HalfProcessArea_Middle,249);Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,269); break;
			//右                                                  
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);  Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,269); break;
	  }                                                  
	}
	Location_BlackBine(BlackBline_Anyway, 269);
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[1][i])
		{
			//左
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10);  Location_BlackBine(HalfProcessArea_Middle,269); break;
			//中                                                                       
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9);  Location_BlackBine(HalfProcessArea_Middle,269); break;
			//右                                                                       
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8);  Location_BlackBine(HalfProcessArea_Middle,269); break;
		}                           
	}
	
	Car_Move_Distance(X_Negative_Dir, 649, 1075, 0);//向X-方向前进
	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//向Y+方向前进 1630

	Rotate_Angle(90);
	Location_Crossroad();//定位十字线
	Delay_ms(500);
	
	Car_Move_Distance(Location_DownBlackLine, 299, 0, 90);//向X+方向前进
	Location_BlackBine(BlackBline_Anyway, 269);

	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(FinishArea_Right,249); Robot_Arm_Pose(14); Location_BlackBine(FinishArea_Middle,269); break;
			//中
			case '2': Location_BlackBine(FinishArea_Middle,249);Robot_Arm_Pose(15); Location_BlackBine(FinishArea_Middle,269); break;
			//右
		  case '3': Location_BlackBine(FinishArea_Left,249);  Robot_Arm_Pose(16); Location_BlackBine(FinishArea_Middle,269); break;
	  }                  
	}
	Car_Move_Distance(Y_Positive_Dir_PosxMinish,  599, 80, 90);
	Car_Move_Distance(Y_Positive_Dir, 399, 2000, 0);
	
	/*----------业务代码区域----------*/
	
	/*----------业务代码区域----------*/
	/*
	//一键启动
	while(PCin(13) == 1);
	//到达二维码识别区
	Car_Move_Distance(Y_Positive_Dir, 649, 390, 0);
	Car_Move_Distance(X_Positive_Dir, 649, 560, 0); 
	//二维码扫描
	QR_Scan();
	USART3_Remap(1);    //1:颜色识别模式
	//到达原料区
	Car_Move_Distance(X_Positive_Dir, 649, 1570, 0);
	//旋转到-90°
	Rotate_Angle(-90);
  //颜色识别
	Color_Scan();
	//定位到原料区黑色线
	Car_Move_Distance(Location_DownBlackLine, 269, 0, -90); //X_Dir_Speed
	//原料区抓取物料
	for(i = 0; i < 3; i++)
	{
		if(Color_Code[0][0] == QR_Code[0][i])
		{
			//移动
			Location_BlackBine(MaterialArea_Left, 249);
			//夹取
			Robot_Arm_Pose(1);
			//将本次抓取到的物料放置到对应的物料架上
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2); break;
				case '2': Robot_Arm_Pose(3); break;
				case '3': Robot_Arm_Pose(4); break;
			}
			//回到中间，为下次抓取做准备
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][1] == QR_Code[0][i])
		{
			//移动
//			Location_BlackBine(MaterialArea_Middle, 249);
			//夹取
			Robot_Arm_Pose(1);
			//将本次抓取到的物料放置到对应的物料架上
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2); break;
				case '2': Robot_Arm_Pose(3); break;
				case '3': Robot_Arm_Pose(4); break;
			}
			//回到中间，为下次抓取做准备
			Location_BlackBine(MaterialArea_Middle, 249);
		}
		else if(Color_Code[0][2] == QR_Code[0][i])
		{
			//移动
			Location_BlackBine(MaterialArea_Right, 249);
			//夹取
			Robot_Arm_Pose(22);
			//将本次抓取到的物料放置到对应的物料架上
			switch(QR_Code[0][i])
			{
				case '1': Robot_Arm_Pose(2); break;
				case '2': Robot_Arm_Pose(3); break;
				case '3': Robot_Arm_Pose(4); break;
			}
			//回到中间，为下次抓取做准备
			Location_BlackBine(MaterialArea_Middle, 249);
		}
  }
	
	//移动到半加工区
	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
	//转向到0°
	Rotate_Angle(0);
	//定位十字线
	Location_Crossroad();
	Delay_ms(350);

	//向X+方向前进
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
	//半加工区放置物料
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,249); break;
			//中
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,249); break;
			//右
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,249); break;
	  }                            
	}
//	
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10); Location_BlackBine(HalfProcessArea_Middle,249); break;
			//中
			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9);  Location_BlackBine(HalfProcessArea_Middle,249); break;
			//右
			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8);  Location_BlackBine(HalfProcessArea_Middle,249); break;
	  }                            
	}
	
	//移动到成品区
	Car_Move_Distance(X_Negative_Dir, 599, 1075, 0);//向X-方向前进
	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//向Y+方向前进 1630

	//旋转到正90°
	Rotate_Angle(90);
	Location_Crossroad();//定位十字线
	Delay_ms(350);
	//到达成品区
	Car_Move_Distance(Location_DownBlackLine, 289, 0, 90);//向X+方向前进
	//放置物料
	for(i = 0; i <= 3; i++)
	{
		switch(QR_Code[0][i])
		{
			//左
			case '1': Location_BlackBine(FinishArea_Right,249);   Robot_Arm_Pose(11);  Location_BlackBine(FinishArea_Middle,249); break;
			//中
			case '2':   Robot_Arm_Pose(12);  Location_BlackBine(FinishArea_Middle,249); break;
			//右
//		  case '3': Location_BlackBine(FinishArea_Left,249);    Robot_Arm_Pose(13);  Location_BlackBine(FinishArea_Middle,249); break;
//	  }                        
//	}
//	//第二次去往原料区
//	Car_Move_Distance(X_Negative_Dir_PosyMinish, 599, 500, 90);
//	//旋转到0°
//	Rotate_Angle(0);
//	
//	Car_Move_Distance(X_Positive_Dir, 599, 1590, 0);
//	//旋转到-90°
//	Rotate_Angle(-90);
//	Location_Crossroad();//定位十字线
//	TFT20_DrawFont_GBK16(0, 0, BLACK, WHITE,(void *) "3");
//	Delay_ms(350);
//	TFT20_DrawFont_GBK16(0, 0, BLACK, WHITE,(void *) "4");
//	//抓取原料区底层wu料
//	for(i = 0; i <= 3; i++)
//	{
//		if(Color_Code[1][0] == QR_Code[1][i])
//		{
//			//定位到物料区左侧
//			Location_BlackBine(MaterialArea_Left, 249);
//			//准备抓取姿势
//			Robot_Arm_Pose(17);
//			//向前移动
//			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
//			//抓取物料
//		  Robot_Arm_Pose(18);
//			//向后退出
//			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
//			//放置物料到物料架
//			switch(QR_Code[1][i])
//			{
//				case '1': Robot_Arm_Pose(19); break;
//				case '2': Robot_Arm_Pose(20); break;
//				case '3': Robot_Arm_Pose(21); break;
//			}
//			//回到物料区中线
//			Location_BlackBine(Second_MaterialArea_Middle, 249);
//		}
//		else if(Color_Code[1][1] == QR_Code[1][i])
//		{
//			//准备抓取姿势
//			Robot_Arm_Pose(17);
//			//向前移动
//			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
//			//抓取物料
//			Robot_Arm_Pose(18);
//			//向后退出
//			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
//		  //放置物料到物料架
//			switch(QR_Code[1][i])
//			{
//				case '1': Robot_Arm_Pose(19); break;
//				case '2': Robot_Arm_Pose(20); break;
//				case '3': Robot_Arm_Pose(21); break;
//			}
//			//回到物料区中线
//			Location_BlackBine(Second_MaterialArea_Middle, 249);
//		}
//		else if(Color_Code[1][2] == QR_Code[1][i])
//		{	
//			//定位到物料区右侧
//			Location_BlackBine(MaterialArea_Right, 249);
//			//准备抓取姿势
//			Robot_Arm_Pose(17);
//			//向前移动
//			Car_Move_Distance(Location_DownBlackLine, 349, 0, -90);
//			//抓取物料
//		  Robot_Arm_Pose(18);
//			//向后退出
//			Car_Move_Distance(Second_Location_DownBlackLine, 349, 0, -90);
//			//放置物料到物料架
//			switch(QR_Code[1][i])
//			{
//				case '1': Robot_Arm_Pose(19); break;
//				case '2': Robot_Arm_Pose(20); break;
//				case '3': Robot_Arm_Pose(21); break;
//			}
//			//回到物料区中线
//			Location_BlackBine(Second_MaterialArea_Middle, 249);
//		}
//	}
//	
//	//移动到半加工区
//	Car_Move_Distance(X_Negative_Dir_PosyMagnify, 599, 1050, -90);//!!!
//	//转向到0°
//	Rotate_Angle(0);
//	//定位十字线
//	Location_Crossroad();
//	Delay_ms(350);
//	//向X+方向前进
//	Car_Move_Distance(Location_DownBlackLine, 289, 0, 0);
//	
//	for(i = 0; i <= 3; i++)
//	{
//		switch(QR_Code[1][i])
//		{
//			//左
//			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(5); Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//中
//			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(6); Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//右
//			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(7); Location_BlackBine(HalfProcessArea_Middle,249); break;
//	  }                            
//	}
//	
//	for(i = 0; i <= 3; i++)
//	{
//		switch(QR_Code[1][i])
//		{
//			//左
//			case '1': Location_BlackBine(HalfProcessArea_Right,249);  Robot_Arm_Pose(10); Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//中
//			case '2': Location_BlackBine(HalfProcessArea_Middle,249); Robot_Arm_Pose(9);  Location_BlackBine(HalfProcessArea_Middle,249); break;
//			//右
//			case '3': Location_BlackBine(HalfPrcoessArea_Left,249);   Robot_Arm_Pose(8);  Location_BlackBine(HalfProcessArea_Middle,249); break;
//		}                            
//	}
//	
//	Car_Move_Distance(X_Negative_Dir, 599, 1075, 0);//向X-方向前进

//	Car_Move_Distance(Y_Positive_Dir, 599, 1630, 0);//向Y+方向前进 1630

//	Rotate_Angle(90);
//	Location_Crossroad();//定位十字线
//	Delay_ms(350);
//	
//	Car_Move_Distance(Location_DownBlackLine, 299, 0, 90);//向X+方向前进

//	for(i = 0; i <= 3; i++)
//	{
//		switch(QR_Code[0][i])
//		{
//			//左
//			case '1': Location_BlackBine(FinishArea_Right,249); Robot_Arm_Pose(14);  Location_BlackBine(FinishArea_Middle,249); break;
//			//中
//			case '2': Robot_Arm_Pose(15); Location_BlackBine(FinishArea_Middle,249); break;
//			//右
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

