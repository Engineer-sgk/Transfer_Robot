#ifndef __Car_Action_H__
#define __Car_Action_H__

#include "MyDrivers.h"

typedef enum
{
	X_Positive_Dir = (uint8_t)0x00,
	Y_Positive_Dir = (uint8_t)0x01,
	X_Negative_Dir = (uint8_t)0x02,
	Y_Negative_Dir = (uint8_t)0x03,
	Y_Positive_Dir_PosxMagnify = (uint8_t)0x04,
	Location_DownBlackLine     = (uint8_t)0x05,
	Y_Positive_Dir_PosxMinish  = (uint8_t)0x06,
	X_Negative_Dir_PosyMagnify = (uint8_t)0x07,
	X_Negative_Dir_PosyMinish  = (uint8_t)0x08,
	X_Positive_Dir_PosyMagnify = (uint8_t)0x09,
	Second_Location_DownBlackLine  = (uint8_t)0x0A,
	Parking_XEnd   = (uint8_t)0x0B,
}Direction_t;

typedef enum
{
	MaterialArea_Right     = (uint8_t)0x00,
	MaterialArea_Middle    = (uint8_t)0x01,
	MaterialArea_Left      = (uint8_t)0x02,
	
	HalfProcessArea_Right  = (uint8_t)0x03,
	HalfProcessArea_Middle = (uint8_t)0x04,
	HalfPrcoessArea_Left   = (uint8_t)0x05,
	
	FinishArea_Right       = (uint8_t)0x06,
	FinishArea_Middle      = (uint8_t)0x07,
	FinishArea_Left        = (uint8_t)0x08,
	
	BlackBline_Anyway      = (uint8_t)0x09,
	Second_MaterialArea_Middle = (uint8_t)0x0A,
}Position_Line_t;

typedef enum
{
	OnTheLeft   = (uint8_t)0x00,
	OnTheRight  = (uint8_t)0x01,
	OnTheMiddle = (uint8_t)0x02,
}Position_Car_t;

typedef struct 
{
	uint8_t Flag;
}NowCarPosition_t;

extern NowCarPosition_t NowCarPosition;

void Rotate_Angle(int16_t angle);

void Location_Material_Area_BlackLine_Of_X(void);

void Current_Position_Sensor_Clear(void);

void Location_Crossroad(void);

void Location_Half_Processing_Area_Right(void);
void Location_Half_Processing_Area_Left(void);

void Location_Middle_Line_L_R(void);
void Location_Middle_Line_R_L(void);

void Car_Move_Distance(uint8_t Direction_t, int16_t Speed, int16_t Distance, int16_t Target_Angle);

void Location_BlackBine(uint8_t Position_Line_t, int16_t Speed);

#endif
