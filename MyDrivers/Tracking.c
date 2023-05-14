#include "MyDrivers.h"

/*
	* @name   Tracking_Init()
	* @brief  ѭ��ģ���ʼ������,Y+����ѭ��ģ�飺B: PB3 A:PB5 C:PB4��X+����ѭ��ģ�飺B: PC0 A: PC1 C:PC2
	* @param  None
	* @retval None   
*/
void Tracking_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/*
	* @name   Tracking_X_Positive_Dir()
	* @brief  ѭ��ģ����,X+����ѭ��ģ�飺B: PC0 A: PC1 C:PC2
	* @param  None
	* @retval Data_Out   
*/
int16_t Tracking_X_Positive_Dir(void)
{
	int8_t Data_Out = 0;
	
	if(PCin(1) == 0 && PCin(0) == 0 && PCin(2) == 0)
		Data_Out = 0;
	else
		Data_Out = 1;

	return Data_Out;
}

/*
	* @name   Tracking_Y_Positive_Dir()
	* @brief  ѭ��ģ����,Y+����ѭ��ģ�飺B: PB3 A:PB5 C:PB4
	* @param  None
	* @retval Data_Out   
*/
int16_t Tracking_Y_Positive_Dir(void)
{
	int8_t Data_Out = 0;
	
	if(PBin(3) == 0 && PBin(5) == 0 && PBin(4) == 0)
		Data_Out = 0;
	else
		Data_Out = 1;

	return Data_Out;
}

///*
//	* @name   Get_Tracking_Data1()
//	* @brief  ѭ��ģ����1,X+����ѭ��ģ�飺B: PC0 A: PC1 C:PC2
//	* @param  None
//	* @retval Data_Out   
//*/
//int16_t Get_Tracking_Data1(void)
//{
//	int16_t Data_Out = 0;
//	int16_t Left_Tracking_Value, Right_Tracking_Value = 0 /*Middle_Tracking_Value = 0*/;
//	
////	if(PCin(1) == 0)
////		Middle_Tracking_Value = 400;
////	else
////		Middle_Tracking_Value = 0;
//	
//	if(PCin(2) == 0)
//		Left_Tracking_Value = 400;
//  else
//		Left_Tracking_Value = 0;
//	
//	if(PCin(0) == 0)
//		Right_Tracking_Value = 400;
//  else
//		Right_Tracking_Value = 0;
//	
//	Data_Out = (Left_Tracking_Value - Right_Tracking_Value);
//	
//	return Data_Out;
//}

///*
//	* @name   Get_Tracking_Data2()
//	* @brief  ѭ��ģ����2,B: PB3 A:PB4 C:PB5
//	* @param  None
//	* @retval Data_Out   
//*/
//int16_t Get_Tracking_Data2(void)
//{
//	int16_t Data_Out = 0;
//	int16_t Left_Tracking_Value, Right_Tracking_Value = 0/*0, Middle_Tracking_Value = 0*/;
//	
////	if(PBin(5) == 0)
////		Middle_Tracking_Value = 400;
////	else
////		Middle_Tracking_Value = 0;
//	
//	if(PBin(3) == 0)
//		Right_Tracking_Value = 400;
//  else
//		Right_Tracking_Value = 0;
//	
//	if(PBin(5) == 0)
//		Left_Tracking_Value = 400;
//  else
//		Left_Tracking_Value = 0;
//	
//	Data_Out = (Left_Tracking_Value - Right_Tracking_Value);
//	
//	return Data_Out;
//}
