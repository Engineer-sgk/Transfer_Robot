#ifndef __BSP_TFTDisplay_H__
#define __BSP_TFTDisplay_H__

#include "MyDrivers.h"

#define TFT20_PB (GPIO_Pin_13 | GPIO_Pin_15 | GPIO_Pin_2 | GPIO_Pin_12)
#define TFT20_CLK  PBout(13)
#define TFT20_SDA  PBout(15)
#define TFT20_RS   PBout(2)   //ԭ��ͼ�е�TFT_A0
#define TFT20_CS   PBout(12)

#define LCD_X_SIZE	     176
#define LCD_Y_SIZE	     220

#define USE_HORIZONTAL  		1	//ʹ�ú��� 1:ʹ�� 	0:��ʹ��.
#define USE_HARDWARE_SPI    0 //SPI      1:Ӳ�� 0:ģ��SPI

#if USE_HORIZONTAL 
#define X_MAX_PIXEL	        LCD_Y_SIZE
#define Y_MAX_PIXEL	        LCD_X_SIZE
#else
#define X_MAX_PIXEL	        LCD_X_SIZE
#define Y_MAX_PIXEL	        LCD_Y_SIZE
#endif

#define RED  	  0xf800  //��ɫ
#define GREEN	  0x07e0  //��ɫ
#define BLUE 	  0x001f  //��ɫ
#define WHITE	  0xffff  //��ɫ
#define BLACK	  0x0000  //��ɫ
#define YELLOW  0xFFE0  //��ɫ
#define GRAY0   0xEF7D  //��ɫ0 0011 0001 0110 0101   3165 
#define GRAY1   0x8410  //��ɫ1 0000 0000 0000 0000
#define GRAY2   0x4208  //��ɫ2 1111 1111 1101 1111

typedef enum 
{
    OCT = 8,
    DEC = 10,
    HEX = 16
}RADIX;

//-----------------------------------------TFT�ײ㺯��---------------------------------
void TFT20_Init(void);
void TFT20_Reset(void); 
void TFT20_SPI_Init(void);
void TFT20_SPI_WriteData(uint8_t Dat);
void TFT20_WriteIndex(uint8_t Index);
void TFT20_WriteData(uint8_t Dat);
void TFT20_WriteReg(uint8_t Index,uint16_t Dat);

//-----------------------------------------Ӧ�ò㺯��---------------------------------
void TFT20_DrawFont_GBK16(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint8_t *Dat);
void TFT20_DrawFont_GBK24(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint8_t *Dat);
void TFT20_DrawFont_Num56(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint16_t num);
void TFT20_DrawFont_Num32(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint16_t num);
void TFT20_DrawLine(uint16_t XStart, uint16_t YStart,uint16_t XEnd, uint16_t YEnd,uint16_t Color);  
void TFT20_Drawbox(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t Color);
void TFT20_Drawbox2(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t mode);
void TFT20_delay_ms(uint16_t ms);
void TFT20_SetXY(uint16_t XStart,uint16_t YStart);
void TFT20_SetRegion(uint8_t XStart,uint8_t YStart,uint8_t XEnd,uint8_t YEnd);
void TFT20_Clear(uint16_t Color); 
void TFT20_LocalClear(uint16_t XStart,uint16_t YStart,uint16_t C,uint16_t H,uint16_t Color); 
void TFT20_DrawPoint(uint16_t XStart,uint16_t YStart,uint16_t Color);
uint16_t TFT20_BGR_RGB(uint16_t BGR);
uint16_t TFT20_RGB24_RGB16(uint32_t rgb);

void TFT20_ShowNumber(uint8_t x, uint8_t y, int32_t number);
void QR_Display(uint8_t x, uint8_t *p);
void TFT20_ShowFloatNum(uint8_t x, uint8_t y, float Num, uint8_t gigit);

#endif
