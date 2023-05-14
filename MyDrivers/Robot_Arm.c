#include "MyDrivers.h"
/*
1号舵机，数值越小，逆时针转动，2613时，到达我规定的零点。
2号舵机，数值越小，越往物料架移动。
3号舵机，数值越小，越往物料架移动。
4号舵机，(1440)：爪子张开。1760爪子合并。
*/

/*--------------------机械臂姿态调用函数级函数传参--------------------*/
/*--------------------------------------------------------------------
1. Robot_Arm_Init()------机械臂初始姿态，折叠状态。
2. Robot_Arm_Pose(uint8_t num)------机械臂姿态.
---------------------------------num----------------------------------
0：抓取姿态（直立） 
1：上层中间物料抓取。 23 ：上层左边物料抓取。24 ：上层右边物料抓取。
2：物料放置红色物料架。3：物料放置绿色物料架。4：物料放置蓝色物料架。
5：半加工区的红色位置。6：半加工区的绿色位置。7：半加工区的蓝色位置。
8：取到蓝色放置到蓝色物料架上。9：取到绿色，放置到绿色物料架上。10：取到红色，放置到红色物料架上。
11：成品区底层红色物料位置。  12：成品区底层绿色物料位置。      13：成品区底层蓝色物料位置。
14：成品区顶层红色物料位置。  15：成品区顶层绿色物料位置。      16：成品区顶层红色物料位置。
17：准备取处底层物料（直立--->爪子呈抓取状态）   18：爪子合并，抓住物料。
19：取出原料区底层红色物料并放置到物料架红色位置。20：取出原料区底层绿色物料并放置到物料架绿色位置。
21：取出原料区底层蓝色物料并放置到物料架蓝色位置。
25：取底层左 26：取底层右
--------------------------------------------------------------------*/
/*
	* @name   Robot_Arm_Init
	* @brief  机械臂初始姿态
	* @param  None
	* @retval None   
*/
void Robot_Arm_Init(void)
{
	RegWritePosEx(1, 2613, 2000, 0);
	RegWritePosEx(2, 1700, 2000, 0);
	RegWritePosEx(3, 3152, 2000, 0);
	RegWritePosEx(4, 1440, 2000, 0);
	RegWriteAction(); 
	Delay_ms(300);
}

/*
	* @name   Robot_Arm_Pose
	* @brief  机械臂姿态
	* @param  None
	* @retval None   
*/
void Robot_Arm_Pose(uint8_t num)
{
	switch(num)
	{
		case 0: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1440, 2000, 0);RegWriteAction(); Delay_s(1); 
		break;
		//上层中间物料抓取
		case 1:RegWritePosEx(1, 2575, 2000, 0);RegWritePosEx(2, 2920, 2000, 0);//2940
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_s(1); //
		WritePosEx(4, 1770, 2000, 0);
		Delay_ms(600);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//上层左边物料抓取
		case 23: RegWritePosEx(1, 2630, 2000, 0);RegWritePosEx(2, 2920, 2000, 0);//2940
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_s(1); //
		WritePosEx(4, 1770, 2000, 0);
		Delay_ms(600);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//上层右边物料抓取
		case 24:RegWritePosEx(1, 2520, 2000, 0);RegWritePosEx(2, 2920, 2000, 0);//2940
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_ms(800); //
		WritePosEx(4, 1770, 2000, 0);
		Delay_ms(600);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//放置---红色姿态
		case 2:  RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		
		RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();Delay_ms(200);WritePosEx(1, 2613, 2000, 0);
		break;
		//放置---绿色姿态
		case 3: RegWritePosEx(1, 2593, 2000, 0);RegWritePosEx(2, 1971, 3000, 0);RegWritePosEx(3, 759, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();
		break;
		//放置---蓝色姿态
		case 4: RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1940, 3000, 0);RegWritePosEx(3, 775, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		
		RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1460, 2000, 0);RegWriteAction();Delay_ms(200);
		WritePosEx(1, 2613, 2000, 0);
		break;
		
		//半加工区放置红色，1.从物料架上取到红色物料。 2. 准备放置红色物料。 3. 放置。 4. 保持准备姿势。
		case 5: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction(); Delay_ms(400);//直立姿势（准备姿势）。
		//从物料架上取到红色物料。
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//直立
		WritePosEx(2, 2192, 2000, 0); WritePosEx(3, 1579, 2000, 0); WritePosEx(1, 2535, 3000, 0); //2590
		//弯腰放置
		WritePosEx(2, 3543, 2000, 0);Delay_s(1);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//放置
		//直立姿势
		RegWritePosEx(1, 2535, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;

		//半加工区放置---绿色，1.从物料架上取到红色物料。 2. 准备放置红色物料。 3. 放置。 4. 保持准备姿势。
		case 6: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();Delay_ms(400);//直立姿势（准备姿势）。
		//从物料架上取到绿色物料。
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);//849
		RegWriteAction();Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(400);
		//直立准备
		RegWritePosEx(1, 2570, 3000, 0); RegWritePosEx(2, 3580, 2000, 0);RegWritePosEx(3, 1579, 2000, 0); //1579
		RegWriteAction();Delay_ms(400);
		//放置
		WritePosEx(2, 3543, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3543
		//直立姿势（准备姿势）。
		RegWritePosEx(1, 2570, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0); 
		break;
		
		//半加工区放置---蓝色
		case 7: 
			//直立
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();Delay_ms(400);
		//从物料架上取到蓝色物料。
		RegWritePosEx(1, 2265, 2000, 0);RegWritePosEx(2, 1900, 3000, 0);RegWritePosEx(3, 794, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(300);
		//直立，准备放置
		RegWritePosEx(1, 2640, 3000, 0); RegWritePosEx(2, 3580, 2000, 0);RegWritePosEx(3, 1595, 2000, 0); //1579
		RegWriteAction();Delay_ms(400);
		//放置物料
		WritePosEx(2, 3530, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3543
		//直立姿势（准备姿势）。
		RegWritePosEx(1, 2640, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0); 
		break;
		
		//从半加工区将---蓝色物料---放置小车蓝色物料架位置
		case 8: RegWritePosEx(2, 2192, 2000, 0); RegWritePosEx(1, 2613, 3000, 0); RegWritePosEx(3, 1579, 2000, 0);
		RegWritePosEx(4, 1440, 3000, 0);//2618->2668
		RegWriteAction();Delay_ms(400);  //直立准备,有必要，要让三号舵机做抓取准备。
		//抓取地面物料
		WritePosEx(2, 3523, 2000, 0);Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(500);
		//直立姿势（准备姿势）。
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 794, 2000, 0);
		RegWriteAction();Delay_ms(800);
		//放置到蓝色物料架
		WritePosEx(1, 2255, 2000, 0);Delay_ms(200); RegWritePosEx(2, 1940, 3000, 0);RegWritePosEx(3, 790, 2000, 0);
		RegWriteAction(); Delay_ms(500); WritePosEx(4, 1480, 2000, 0); Delay_ms(300);
		//恢复到直立状态
		RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500); 
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		
		break;
		
		//从半加工区将---绿色物料---放置小车绿色物料架位置
		case 9: RegWritePosEx(2, 2192, 2000, 0); RegWritePosEx(1, 2570, 3000, 0); RegWritePosEx(3, 1600, 2000, 0);RegWritePosEx(4, 1440, 3000, 0);
		RegWriteAction(); Delay_ms(400);  //直立准备,有必要，要让三号舵机做抓取准备。
		//开始抓取地面物料
		WritePosEx(2, 3520, 2000, 0); Delay_ms(800); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//直立姿势（准备姿势）。
		RegWritePosEx(1, 2613, 2000, 0); RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 739, 2000, 0);
		RegWriteAction();Delay_ms(600);
		//将绿色物料放置到物料架上。
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);//849
		RegWriteAction();Delay_ms(300);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//将绿色物料放置到物料架上。
		//恢复到直立状态
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//从半加工区将---红色物料---放置小车红色物料架位置
		case 10: RegWritePosEx(2, 2192, 2000, 0); RegWritePosEx(1, 2535, 3000, 0); RegWritePosEx(3, 1579, 2000, 0);RegWritePosEx(4, 1440, 3000, 0);
		RegWriteAction();Delay_ms(400);  
		//抓取地面物料
		WritePosEx(2, 3523, 2000, 0);Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(500);
		//直立姿势（准备姿势）。
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(600);
		//将红色物料放置到物料架上。
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction();Delay_ms(600);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);
		//恢复到直立状态
		WritePosEx(3, 1906, 2000, 0); Delay_ms(300); WritePosEx(2, 2192, 3000, 0); WritePosEx(1, 2613, 2000, 0);
		Delay_ms(800); 
		break;
		
		//成品区红色底层位置
		case 11:RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction(); Delay_ms(400);//直立姿势（准备姿势）。
		//从物料架上取到红色物料。
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//直立准备
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2540, 3000, 0);RegWritePosEx(3, 1746, 2000, 0);
		RegWriteAction();Delay_ms(500);

		WritePosEx(2, 3370, 2000, 0);Delay_ms(800);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3387

		RegWritePosEx(1, 2540, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//直立姿势（准备姿势）。
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//成品区绿色位置
		case 12: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);RegWriteAction();Delay_ms(400);
		//从物料架取到绿色物料
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);//849
		RegWriteAction();Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(400);
		//直立
		RegWritePosEx(2, 3580, 2000, 0);RegWritePosEx(1, 2564, 3000, 0);RegWritePosEx(3, 1720, 2000, 0);
		RegWriteAction();Delay_ms(500);//直立准备
		//放置物料
		WritePosEx(2, 3350, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2564, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//直立姿势（准备姿势）。
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//成品区底层蓝色位置
		case 13: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);RegWritePosEx(4, 1460, 2000, 0);Delay_ms(400);//直立姿势（准备姿势）。
		
		RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1900, 3000, 0);RegWritePosEx(3, 785, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(300);//从物料架上取到红色物料。
		
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2615, 3000, 0);RegWritePosEx(3, 1760, 2000, 0);
		RegWriteAction();Delay_ms(500);//直立准备

		WritePosEx(2, 3340, 2000, 0);Delay_ms(800);WritePosEx(4, 1330, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2615, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//直立姿势（准备姿势）。
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//成品区顶层红色位置
		case 14: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction(); Delay_ms(400);//直立姿势（准备姿势）。
		//从物料架上取到红色物料。
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//直立准备
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2540, 3000, 0);RegWritePosEx(3, 2136, 2000, 0);
		RegWriteAction();Delay_ms(500);

		WritePosEx(2, 3020, 2000, 0);Delay_ms(800);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3387

		RegWritePosEx(1, 2540, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//直立姿势（准备姿势）。
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//顶层绿色位置
		case 15: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);RegWriteAction();Delay_ms(400);
		//从物料架取到绿色物料
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);
		RegWriteAction();Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(400);//从物料架上取到红色物料。
		//直立
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2560, 3000, 0);RegWritePosEx(3, 2136, 2000, 0);
		RegWriteAction();Delay_ms(500);//直立准备
		//放置物料
		WritePosEx(2, 3020, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2560, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//直立姿势（准备姿势）。
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//成品区！！！顶层蓝色位置
		case 16: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);RegWritePosEx(4, 1460, 2000, 0);Delay_ms(400);//直立姿势（准备姿势）。
		
		RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1900, 3000, 0);RegWritePosEx(3, 785, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(300);//从物料架上取到红色物料。
		
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2610, 3000, 0);RegWritePosEx(3, 2136, 2000, 0);
		RegWriteAction();Delay_ms(500);//直立准备

		WritePosEx(2, 3020, 2000, 0);Delay_ms(800);WritePosEx(4, 1330, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2610, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//直立姿势（准备姿势）。
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		/* 从原料区底层取到红色放置到红色物料架。1. 直立。2. 抓取状态。3. 车前进。4. 爪子合并。 5. 车后退。 
	  6. 直立。 7. 放置到物料架。*/
		//取中间
		case 17:
			//1. 直立。
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1440, 2000, 0);RegWriteAction();
		  //2. 抓取状。
		RegWritePosEx(2, 3410, 2000, 0);RegWritePosEx(1, 2590, 3000, 0);RegWritePosEx(3, 1680, 2000, 0);
		RegWriteAction();Delay_ms(500); 
		break;
		//取左边
		case 25:
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1440, 2000, 0);RegWriteAction();
		  //2. 抓取状。
		RegWritePosEx(2, 3410, 2000, 0);RegWritePosEx(1, 2610, 3000, 0);RegWritePosEx(3, 1680, 2000, 0);
		RegWriteAction();Delay_ms(500); 
		break;
		//取右边
		case 26:
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1440, 2000, 0);RegWriteAction();
		  //2. 抓取状。
		RegWritePosEx(2, 3410, 2000, 0);RegWritePosEx(1, 2560, 3000, 0);RegWritePosEx(3, 1680, 2000, 0);
		RegWriteAction();Delay_ms(500); 
		break;
		
		case 18:
		  //4. 爪子合并。
		Delay_ms(500);WritePosEx(4, 1770, 2000, 0);Delay_ms(500); break;
		
		/* 从原料区底层取到红色放置到红色物料架。1. 直立。2. 抓取状。3. 车前进。4. 爪子合并。 5. 车后退。 
	  6. 直立。 7. 放置到物料架。*/
		case 19:       
			 //6. 直立。
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);
		  //7. 放置到物料架。
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		  //8. 直立机械臂
		RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500);
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		break;			
		
		/* 从原料区底层取到绿色放置到绿色物料架。1. 直立。2. 抓取状。3. 车前进。4. 爪子合并。 5. 车后退。 
	  6. 直立。 7. 放置到物料架。*/
		case 20:       
			 //6. 直立。
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);
		  //7. 放置到物料架。
		RegWritePosEx(1, 2593, 2000, 0);RegWritePosEx(2, 1971, 3000, 0);RegWritePosEx(3, 759, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1440, 2000, 0); Delay_ms(300);
		  //8. 直立机械臂
		RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500);
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		break;	
		
		/* 从原料区底层取到蓝色放置到蓝色物料架。1. 直立。2. 抓取状。3. 车前进。4. 爪子合并。 5. 车后退。 
	  6. 直立。 7. 放置到物料架。*/
		case 21:       
			 //6. 直立。
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);
		  //7. 放置到物料架。
		RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1940, 3000, 0);RegWritePosEx(3, 775, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1440, 2000, 0); Delay_ms(300);
		  //8. 直立机械臂
		RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500);
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		break;		
		
		case 22:RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 2957, 2000, 0);//2613
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_s(1); //
		WritePosEx(4, 1640, 2000, 0);
		Delay_s(1);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_s(1); 
		break;
		
		
		
		default: Assert_Failed();break;
	}
}

