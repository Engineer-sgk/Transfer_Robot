#include "MyDrivers.h"
#include "Fonts.h"

void QR_Display(uint8_t x, uint8_t *p)
{
	float y=3.5;
	
	if(x==0)
	{
		if     (1==Cmpmemory(p,"123",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,RED   ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+1),56*x+5,GREEN,GRAY0,2);TFT20_DrawFont_Num56(32*(y+2),56*x+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"132",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,RED   ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+1),56*x+5,BLUE ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+2),56*x+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"213",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num56(32*(y+1),56*x+5,RED  ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+2),56*x+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"231",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num56(32*(y+1),56*x+5,BLUE ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+2),56*x+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"312",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+1),56*x+5,RED  ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+2),56*x+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"321",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+1),56*x+5,GREEN,GRAY0,2);TFT20_DrawFont_Num56(32*(y+2),56*x+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"000",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,BLACK ,GRAY0,0);TFT20_DrawFont_Num56(32*(y+1),56*x+5,BLACK,GRAY0,0);TFT20_DrawFont_Num56(32*(y+2),56*x+5,BLACK,GRAY0,0);}
	}                                                                                                                                                        
	else if(x==1)                                                                                                                                             
	{                                                                                                                                                        
		if     (1==Cmpmemory(p,"123",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,RED   ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+1),56*x+5,GREEN,GRAY0,2);TFT20_DrawFont_Num56(32*(y+2),56*x+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"132",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,RED   ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+1),56*x+5,BLUE ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+2),56*x+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"213",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num56(32*(y+1),56*x+5,RED  ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+2),56*x+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"231",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num56(32*(y+1),56*x+5,BLUE ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+2),56*x+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"312",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+1),56*x+5,RED  ,GRAY0,1);TFT20_DrawFont_Num56(32*(y+2),56*x+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"321",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num56(32*(y+1),56*x+5,GREEN,GRAY0,2);TFT20_DrawFont_Num56(32*(y+2),56*x+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"000",3)) {TFT20_DrawFont_Num56(32*y,56*x+5,BLACK ,GRAY0,0);TFT20_DrawFont_Num56(32*(y+1),56*x+5,BLACK,GRAY0,0);TFT20_DrawFont_Num56(32*(y+2),56*x+5,BLACK,GRAY0,0);}
	}                                                                                                                                                         
	else if(x==2)                                                                                                                                             
	{                    
		y=0.2;
		if     (1==Cmpmemory(p,"123",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,RED   ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+1),32*3+5,GREEN,GRAY0,2);TFT20_DrawFont_Num32(32*(y+2),32*3+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"132",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,RED   ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+1),32*3+5,BLUE ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+2),32*3+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"213",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num32(32*(y+1),32*3+5,RED  ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+2),32*3+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"231",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num32(32*(y+1),32*3+5,BLUE ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+2),32*3+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"312",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+1),32*3+5,RED  ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+2),32*3+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"321",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+1),32*3+5,GREEN,GRAY0,2);TFT20_DrawFont_Num32(32*(y+2),32*3+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"000",3)) {TFT20_DrawFont_Num32(32*(y),32*3+5,BLACK ,GRAY0,0);TFT20_DrawFont_Num32(32*(y+1),32*3+5,BLACK,GRAY0,0);TFT20_DrawFont_Num32(32*(y+2),32*3+5,BLACK,GRAY0,0);}
	}
	else if(x==3) 
	{
		y=0.2;
		if     (1==Cmpmemory(p,"123",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,RED   ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+1),32*4+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num32(32*(y+2),32*4+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"132",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,RED   ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+1),32*4+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+2),32*4+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"213",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num32(32*(y+1),32*4+5,RED   ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+2),32*4+5,BLUE ,GRAY0,3);}
		else if(1==Cmpmemory(p,"231",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num32(32*(y+1),32*4+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+2),32*4+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"312",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+1),32*4+5,RED   ,GRAY0,1);TFT20_DrawFont_Num32(32*(y+2),32*4+5,GREEN,GRAY0,2);}
		else if(1==Cmpmemory(p,"321",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,BLUE  ,GRAY0,3);TFT20_DrawFont_Num32(32*(y+1),32*4+5,GREEN ,GRAY0,2);TFT20_DrawFont_Num32(32*(y+2),32*4+5,RED  ,GRAY0,1);}
		else if(1==Cmpmemory(p,"000",3)) {TFT20_DrawFont_Num32(32*(y),32*4+5,BLACK ,GRAY0,0);TFT20_DrawFont_Num32(32*(y+1),32*4+5,BLACK ,GRAY0,0);TFT20_DrawFont_Num32(32*(y+2),32*4+5,BLACK,GRAY0,0);}
	}

}

/*******************************************************************************
* 函 数 : TFT20_DrawFont_Num32
* 功 能 : 显示数码管体数字
* 输 入 : XY 显示起始点 fc[in]字体颜色 bc[in]背景色 num[in]
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DrawFont_Num32(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint16_t num)
{
	u8 i,j,k,c;

  for(i=0;i<32;i++)
	 {
		for(j=0;j<4;j++) 
		 {
			c=*(sz32+num*32*4+i*4+j);
			for(k=0;k<8;k++)	
			 {
	       if(c&(0x80>>k)) TFT20_DrawPoint(x+j*8+k,y+i,fc);
				 else {if(fc!=bc) TFT20_DrawPoint(x+j*8+k,y+i,bc);}
			}
		}
	}
}

/*
	* @name   TFT20_ShowNumber
	* @brief  以八进制/十进制/十六进制显示传入的整形数据
	* @param  x:x轴坐标 0-127 y:y轴坐标 0-7 number:待显示整数，支持负数 radix:选择显示进制，可选OCT/DEC/HEX
            ndigit:占用几个字符 
	* @retval None   
*/
void TFT20_ShowNumber(uint8_t x, uint8_t y, int32_t number)
{
	uint8_t i = 0;
	char str[25] = {0}; 				//定义数字转字符串的存储buffer
	sprintf(str,"%d",number);
	while(str[i])
	{
		TFT20_DrawFont_GBK16(x, y, BLACK, WHITE, (uint8_t *)str);	
	}	
}

/*
	* @name   TFT20_ShowFloatNum
	* @brief  显示浮点数
	* @param  x:x轴坐标 0-127 y:y轴坐标 0-7 number:待显示浮点数，支持负数 
	* @retval None   
*/
void TFT20_ShowFloatNum(uint8_t x, uint8_t y, float Num, uint8_t gigit)
{
	char str[64] = {0};
	switch(gigit)
	{         
		case 1: sprintf(str, "%.1f", Num);   break;
		case 2: sprintf(str, "%.2f", Num);   break;
		case 3: sprintf(str, "%.3f", Num);   break;
		case 4: sprintf(str, "%.4f", Num);   break;
		default : sprintf(str, "%.3f", Num); break;
	}         
	TFT20_DrawFont_GBK16(x, y, BLACK, WHITE, (uint8_t *)str);	
}

/*******************************************************************************
* 函 数 : RGB
* 功 能 : R,G,B 转16位
* 输 入 : 无
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
uint16_t RGB(uint16_t R,uint16_t G,uint16_t B)
{
	uint16_t RGB16;
	R>>=3;
	G>>=2;
	B>>=3;
	RGB16=R<<11|G<<5|B;
	
	return RGB16;
}

/*******************************************************************************
* 函 数 : TFT20_RGB24_RGB16
* 功 能 : 24位rgb编码转16位
* 输 入 : 无
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
uint16_t TFT20_RGB24_RGB16(u32 rgb)
{
	uint16_t R,G,B,RGB16;
	
	R=(rgb&0xff0000)>>19;
	G=(rgb&0x00ff00)>>10;
	B=(rgb&0x0000ff)>>3;
	
	RGB16=R<<11|G<<5|B;
	
	return RGB16;
}



/*******************************************************************************
* 函 数 : TFT20_delay_ms
* 功 能 : 延时
* 输 入 : 无
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_delay_ms(uint16_t ms)
{
	Delay_ms(ms);
}


/*******************************************************************************
* 函 数 : TFT20_Reset
* 功 能 : 液晶屏硬复位
* 输 入 : 无
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_Reset()
{	
//    TFT20_RST=0;
    TFT20_delay_ms(100);
//    TFT20_RST=1;
    TFT20_delay_ms(50);
}


/*******************************************************************************
* 函 数 : TFT20_Init
* 功 能 : 液晶屏初始化
* 输 入 : 无
* 输 出 : 无
* 返 回 : 无
* 说 明 : 液晶屏初始化_ILI9225_176X220
*******************************************************************************/
void TFT20_Init()
{	
	TFT20_SPI_Init();//SPI  GPIO初始化
	
	TFT20_Reset(); //Reset before LCD Init.

	//LCD Init For 2.2inch LCD Panel with ILI9225.	
	TFT20_WriteReg(0x10, 0x0000); // Set SAP,DSTB,STB
	TFT20_WriteReg(0x11, 0x0000); // Set APON,PON,AON,VCI1EN,VC
	TFT20_WriteReg(0x12, 0x0000); // Set BT,DC1,DC2,DC3
	TFT20_WriteReg(0x13, 0x0000); // Set GVDD
	TFT20_WriteReg(0x14, 0x0000); // Set VCOMH/VCOML voltage
	TFT20_delay_ms(40); // Delay 20 ms
	
	// Please follow this power on sequence
	TFT20_WriteReg(0x11, 0x0018); // Set APON,PON,AON,VCI1EN,VC
	TFT20_WriteReg(0x12, 0x1121); // Set BT,DC1,DC2,DC3
	TFT20_WriteReg(0x13, 0x0063); // Set GVDD
	TFT20_WriteReg(0x14, 0x3961); // Set VCOMH/VCOML voltage
	TFT20_WriteReg(0x10, 0x0800); // Set SAP,DSTB,STB
	TFT20_delay_ms(10); // Delay 10 ms
	TFT20_WriteReg(0x11, 0x1038); // Set APON,PON,AON,VCI1EN,VC
	TFT20_delay_ms(30); // Delay 30 ms
	
	TFT20_WriteReg(0x02, 0x0100); // set 1 line inversion

#if USE_HORIZONTAL//如果定义了横屏
	//R01H:SM=0,GS=0,SS=0 (for details,See the datasheet of ILI9225)
	TFT20_WriteReg(0x01, 0x001C); // set the display line number and display direction
	//R03H:BGR=1,ID0=1,ID1=1,AM=1 (for details,See the datasheet of ILI9225)
	TFT20_WriteReg(0x03, 0x1038); // set GRAM write direction .
#else//竖屏
	//R01H:SM=0,GS=0,SS=1 (for details,See the datasheet of ILI9225)
	TFT20_WriteReg(0x01, 0x011C); // set the display line number and display direction 
	//R03H:BGR=1,ID0=1,ID1=1,AM=0 (for details,See the datasheet of ILI9225)
	TFT20_WriteReg(0x03, 0x1030); // set GRAM write direction.
#endif

	TFT20_WriteReg(0x07, 0x0000); // Display off
	TFT20_WriteReg(0x08, 0x0808); // set the back porch and front porch
	TFT20_WriteReg(0x0B, 0x1100); // set the clocks number per line
	TFT20_WriteReg(0x0C, 0x0000); // CPU interface
	TFT20_WriteReg(0x0F, 0x0501); // Set Osc
	TFT20_WriteReg(0x15, 0x0020); // Set VCI recycling
	TFT20_WriteReg(0x20, 0x0000); // RAM Address
	TFT20_WriteReg(0x21, 0x0000); // RAM Address
	
	//------------------------ Set GRAM area --------------------------------//
	TFT20_WriteReg(0x30, 0x0000); 
	TFT20_WriteReg(0x31, 0x00DB); 
	TFT20_WriteReg(0x32, 0x0000); 
	TFT20_WriteReg(0x33, 0x0000); 
	TFT20_WriteReg(0x34, 0x00DB); 
	TFT20_WriteReg(0x35, 0x0000); 
	TFT20_WriteReg(0x36, 0x00AF); 
	TFT20_WriteReg(0x37, 0x0000); 
	TFT20_WriteReg(0x38, 0x00DB); 
	TFT20_WriteReg(0x39, 0x0000); 
	
	// ---------- Adjust the Gamma 2.2 Curve -------------------//
	TFT20_WriteReg(0x50, 0x0603); 
	TFT20_WriteReg(0x51, 0x080D); 
	TFT20_WriteReg(0x52, 0x0D0C); 
	TFT20_WriteReg(0x53, 0x0205); 
	TFT20_WriteReg(0x54, 0x040A); 
	TFT20_WriteReg(0x55, 0x0703); 
	TFT20_WriteReg(0x56, 0x0300); 
	TFT20_WriteReg(0x57, 0x0400); 
	TFT20_WriteReg(0x58, 0x0B00); 
	TFT20_WriteReg(0x59, 0x0017); 
	
	TFT20_WriteReg(0x0F, 0x0701); // Vertical RAM Address Position
	TFT20_WriteReg(0x07, 0x0012); // Vertical RAM Address Position
	TFT20_delay_ms(50); // Delay 50 ms
	TFT20_WriteReg(0x07, 0x1017); // Vertical RAM Address Position  
	
  TFT20_Clear(WHITE); //白色 //清屏
}




/*******************************************************************************
* 函 数 : TFT20_SetXY
* 功 能 : 设置TFT屏显示起始点
* 输 入 : X Y 起始点
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_SetXY(uint16_t XStart,uint16_t YStart)
{	
#if USE_HORIZONTAL//如果定义了横屏  	    	
	TFT20_WriteReg(0x21,XStart);//设置XY起始地址
	TFT20_WriteReg(0x20,YStart);
#else             //竖屏	
	TFT20_WriteReg(0x20,XStart);
	TFT20_WriteReg(0x21,YStart);
#endif
	TFT20_WriteIndex(0x22);		//从GRAM读取数据寄存器的18位数据。
} 


/*******************************************************************************
* 函 数 : TFT20_SetRegion
* 功 能 : 设置显示窗口
* 输 入 : X Y 起点和终点
* 输 出 : 无
* 返 回 : 无
* 说 明 : 在此区域写点数据自动换行
*******************************************************************************/
void TFT20_SetRegion(uint8_t XStart,uint8_t YStart,uint8_t XEnd,uint8_t YEnd)
{
#if USE_HORIZONTAL//横屏	
	TFT20_WriteReg(0x38,XEnd);
	TFT20_WriteReg(0x39,XStart);
	TFT20_WriteReg(0x36,YEnd);
	TFT20_WriteReg(0x37,YStart);
	TFT20_WriteReg(0x21,XStart);
	TFT20_WriteReg(0x20,YStart);
#else             //竖屏	
	TFT20_WriteReg(0x36,XEnd);
	TFT20_WriteReg(0x37,XStart);
	TFT20_WriteReg(0x38,YEnd);
	TFT20_WriteReg(0x39,YStart);
	TFT20_WriteReg(0x20,XStart);
	TFT20_WriteReg(0x21,YStart);
#endif
	TFT20_WriteIndex(0x22);	
}


/*******************************************************************************
* 函 数 : TFT20_Clear
* 功 能 : 全屏填充颜色函数（清屏）
* 输 入 : Color[in] 颜色数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_Clear(uint16_t Color)               
{	
   uint16_t i,m;
   TFT20_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
   for(i=0;i<X_MAX_PIXEL;i++)
    for(m=0;m<Y_MAX_PIXEL;m++)
    {	
	  	TFT20_WriteData(Color>>8);
	    TFT20_WriteData(Color); 
    }   
}


/*******************************************************************************
* 函 数 : TFT20_LocalClear
* 功 能 : 局部清屏
* 输 入 : XY 显示起始点  Color 颜色数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_LocalClear(uint16_t XStart,uint16_t YStart,uint16_t C,uint16_t H,uint16_t Color)   //局部清屏
{
	uint16_t temp;
	
	TFT20_SetRegion(XStart,YStart,XStart+C-1,YStart+H-1); //设置显示窗口大小
	for(temp=0;temp<(C*H);temp++)
	 {	
		TFT20_WriteData(Color>>8);
		TFT20_WriteData(Color);				
	 }	
}


/*******************************************************************************
* 函 数 : TFT20_DrawPoint
* 功 能 : 画任意颜色点
* 输 入 : XStart[in] YStart[in] XY描点位置  Color[in] 颜色数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DrawPoint(uint16_t XStart,uint16_t YStart,uint16_t Color)
{
	TFT20_SetXY(XStart,YStart);
	TFT20_WriteData(Color>>8);
	TFT20_WriteData(Color);
}    


/*******************************************************************************
* 函 数 : TFT20_BGR_RGB
* 功 能 : BGR->RGB格式转换
* 输 入 : 无
* 输 出 : 无
* 返 回 : RGB格式的颜色值
* 说 明 : 从ILI93xx读出的数据为GBR格式，而我们写入的时候为RGB格式。
*******************************************************************************/
uint16_t TFT20_BGR_RGB(uint16_t BGR)
{
  uint16_t R,G,B,RGB;   
  B=(BGR>>0)&0x1f;
  G=(BGR>>5)&0x3f;
  R=(BGR>>11)&0x1f;	
	
  RGB=(B<<11)+(G<<5)+(R<<0);	
	
  return (RGB);
}


/*******************************************************************************
* 函 数 : TFT20_DrawCircle
* 功 能 : 画圆
* 输 入 : x[in] y[in] XY圆心点位置 R[in] 半径 Color[in] 颜色数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : Bresenham算法 
*******************************************************************************/
void TFT20_DrawCircle(uint16_t X,uint16_t Y,uint16_t R,uint16_t Color) //画圆 
{
	unsigned short  a,b; //短整型
	int c; 
	a=0;   //必须赋值为零
	b=R; 
	c=3-2*R; 
	while(a<b) 
	{ 
		TFT20_DrawPoint(X+a,Y+b,Color); //7 
		TFT20_DrawPoint(X-a,Y+b,Color); //6 
		TFT20_DrawPoint(X+a,Y-b,Color); //2 
		TFT20_DrawPoint(X-a,Y-b,Color); //3 
		TFT20_DrawPoint(X+b,Y+a,Color); //8 
		TFT20_DrawPoint(X-b,Y+a,Color); //5 
		TFT20_DrawPoint(X+b,Y-a,Color); //1 
		TFT20_DrawPoint(X-b,Y-a,Color); //4 

		if(c<0) c=c+4*a+6; 
		else {c=c+4*(a-b)+10;b-=1;} 
		a+=1; 
	} 
	if(a==b) 
	{ 
		TFT20_DrawPoint(X+a,Y+b,Color); 
		TFT20_DrawPoint(X+a,Y+b,Color); 
		TFT20_DrawPoint(X+a,Y-b,Color); 
		TFT20_DrawPoint(X-a,Y-b,Color); 
		TFT20_DrawPoint(X+b,Y+a,Color); 
		TFT20_DrawPoint(X-b,Y+a,Color); 
		TFT20_DrawPoint(X+b,Y-a,Color); 
		TFT20_DrawPoint(X-b,Y-a,Color); 
	} 
} 


//，
/*******************************************************************************
* 函 数 : TFT20_DrawLine
* 功 能 : 画线函数
* 输 入 : X Y 起始点 终点坐标  Color[in] 颜色数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 使用Bresenham 画线算法
*******************************************************************************/
void TFT20_DrawLine(uint16_t XStart, uint16_t YStart,uint16_t XEnd, uint16_t YEnd,uint16_t Color)   
{
	int dx,dy,      //X Y 差值
			dx2,dy2,    //X Y 差值的两倍
			x_inc,y_inc,//在绘图过程中像素点移动的方向
			juece,      //决策变量
			temp;      //临时变量

	TFT20_SetXY(XStart,YStart);//设置TFT屏显示起始点
	
	dx = XEnd-XStart;//计算x距离
	dy = YEnd-YStart;//计算y距离

	if(dx>=0) x_inc= 1;  //确定方向
	else {x_inc= -1;dx= -dx;} 
	
	if(dy>=0) y_inc= 1;
	else {y_inc= -1;dy= -dy;} 

	dx2 = dx<<1; //乘以2
	dy2 = dy<<1;

	if(dx>dy)	     //x距离大于y距离,那么每个x轴上只有一个点,每个y轴上有若干个点
	{              //且线的点数等于x距离,以x轴递增画点
		juece= dy2-dx;  //初始化误差项
		for(temp=0;temp<=dx;temp++) //要画的点数不会超过x距离
		{
			TFT20_DrawPoint(XStart,YStart,Color);
			if(juece>=0) //是否需要增加y坐标值
			{
				juece -=dx2;
				YStart +=y_inc;//增加y坐标值
			} 
			juece +=dy2; //调整
			XStart +=x_inc;//x坐标值每次画点后都递增1（移动到下一个像素）
		}
	}
	else          //y轴大于x轴，则每个y轴上只有一个点，x轴若干个点
	{             //以y轴为递增画点
		juece= dx2-dy;  //初始化误差项
		for (temp=0;temp<=dy;temp++) //画线
		{
			TFT20_DrawPoint(XStart,YStart,Color);
			if(juece>=0)
			{
				juece -=dy2;
				XStart +=x_inc;
			}
			juece +=dx2;
			YStart +=y_inc;
		}
	}
}


/*******************************************************************************
* 函 数 : TFT20_Drawbox
* 功 能 : 画矩形（带斜线）
* 输 入 : xy 显示起始点 w[in]矩形宽度 h[in]高度  Color[in] 颜色
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_Drawbox(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t Color)
{
	TFT20_DrawLine(x    ,y  ,x+w  ,y    ,0xEF7D);//上横
	TFT20_DrawLine(x+w	,y	,x+w	,y+h  ,0x2965);//右竖
	TFT20_DrawLine(x    ,y+h,x+w  ,y+h  ,0x2965);//下横
	TFT20_DrawLine(x    ,y  ,x    ,y+h  ,0xEF7D);//左竖
  TFT20_DrawLine(x+1  ,y+1,x+w-1,y+h-1,Color );//正斜
}


/*******************************************************************************
* 函 数 : TFT20_Drawbox2
* 功 能 : 画矩形
* 输 入 : xy 显示起始点 w[in]矩形宽度 h[in]高度
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_Drawbox2(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t mode)
{
	if(mode==0){
		TFT20_DrawLine(x    ,y  ,x+w  ,y    ,0xEF7D);
		TFT20_DrawLine(x+w	,y	,x+w	,y+h  ,0x2965);
		TFT20_DrawLine(x    ,y+h,x+w  ,y+h  ,0x2965);
		TFT20_DrawLine(x    ,y  ,x    ,y+h  ,0xEF7D);
		}
	if(mode==1){
		TFT20_DrawLine(x    ,y  ,x+w  ,y    ,0x2965);
		TFT20_DrawLine(x+w	,y 	,x+w	,y+h  ,0xEF7D);
		TFT20_DrawLine(x    ,y+h,x+w  ,y+h  ,0xEF7D);
		TFT20_DrawLine(x    ,y  ,x    ,y+h  ,0x2965);
	}
	if(mode==2){
		TFT20_DrawLine(x    ,y  ,x+w  ,y    ,0x0000);
		TFT20_DrawLine(x+w  ,y  ,x+w  ,y+h  ,0x0000);
		TFT20_DrawLine(x    ,y+h,x+w  ,y+h  ,0x0000);
		TFT20_DrawLine(x    ,y  ,x    ,y+h  ,0x0000);
	}
}


/*******************************************************************************
* 函 数 : TFT20_DisplayImg
* 功 能 : 任意位置显示图片
* 输 入 : XY 显示起始点  *img[in] 图片数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 16位BMP/Image2LCD取模选项设置/水平扫描/16位/不包含图像头数据/自左至右
          自顶至底/低位在前/在图片数组前加上图片尺寸 例:uint8_t a[]={176,220,dat};
*******************************************************************************/
void TFT20_DisplayImg(uint16_t XStart,uint16_t YStart,uint8_t *img)
{
	uint16_t temp;
	
//	TFT20_Clear(GRAY0); //灰色0 //清屏
	TFT20_SetRegion(XStart,YStart,XStart+img[0]-1,YStart+img[1]-1); //设置显示窗口大小
	for(temp=0;temp<(img[0]*img[1]);temp++)
	 {	
		TFT20_WriteData(*(img+temp*2+3));	//数据低位在前
		TFT20_WriteData(*(img+temp*2+2));				
	 }	
}


/*******************************************************************************
* 函 数 : TFT20_DisplayButtonDown
* 功 能 : 在屏幕显示一凸起的按钮框
* 输 入 : x0,y0,x1,y1 按钮框左上角和右下角坐标
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DisplayButtonDown(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1)
{
	TFT20_DrawLine(x0  ,y0  ,x1  ,y0  ,GRAY2); //上上横
	TFT20_DrawLine(x0+1,y0+1,x1  ,y0+1,GRAY1); //上下横
	TFT20_DrawLine(x0  ,y0  ,x0  ,y1  ,GRAY2); //左左竖 
	TFT20_DrawLine(x0+1,y0+1,x0+1,y1  ,GRAY1); //左右竖
	TFT20_DrawLine(x0  ,y1  ,x1  ,y1  ,WHITE); //下横
	TFT20_DrawLine(x1  ,y0  ,x1  ,y1  ,WHITE); //右竖
}


/*******************************************************************************
* 函 数 : TFT20_DisplayButtonUp
* 功 能 : 在屏幕显示一凹下的按钮框
* 输 入 : x0,y0,x1,y1 按钮框左上角和右下角坐标
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DisplayButtonUp(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1)
{
	TFT20_DrawLine(x0  ,y0  ,x1  ,y0  ,WHITE); //上横
	TFT20_DrawLine(x0  ,y0  ,x0  ,y1  ,WHITE); //左竖
	TFT20_DrawLine(x0+1,y1-1,x1  ,y1-1,GRAY1); //下上横
	TFT20_DrawLine(x0  ,y1  ,x1  ,y1  ,GRAY2); //下下横
	TFT20_DrawLine(x1-1,y0+1,x1-1,y1  ,GRAY1); //右左竖
  TFT20_DrawLine(x1  ,y0  ,x1  ,y1  ,GRAY2); //右右竖
}


/*******************************************************************************
* 函 数 : TFT20_DrawFont_GBK16
* 功 能 : 显示汉字或字符 （GBK16）
* 输 入 : XY 显示起始点 fc[in]字体颜色 bc[in]背景色 *Dat[in] 显示数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DrawFont_GBK16(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint8_t *Dat)
{
	uint8_t  i,j;
	unsigned short k,x0=x;//记忆x0起点坐标
	while(*Dat) 
	{	
		if((*Dat) < 128) //小于128的为ASCLL字符
		{
			k=*Dat; //ASCLL字符编号索引
			if(k==0x0D) {x=x0;y+=16;} //换行  +16
			else 
			{
				if(k>32) k-=32; else k=0;//数组字符编号索引
			  for(i=0;i<16;i++)
				 for(j=0;j<8;j++) 
					{
				    if(asc16[k*16+i]&(0x80>>j))	TFT20_DrawPoint(x+j,y+i,fc); //字体颜色
						else {if(fc!=bc) TFT20_DrawPoint(x+j,y+i,bc);}  //背景色
					}
				x+=8;
			}
			Dat++;
		}
	}
}


/*******************************************************************************
* 函 数 : TFT20_DrawFont_GBK24
* 功 能 : 显示汉字或字符 （GBK24）
* 输 入 : XY 显示起始点 fc[in]字体颜色 bc[in]背景色 *Dat[in] 显示数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DrawFont_GBK24(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint8_t *Dat)
{
	uint8_t i,j;
	unsigned short k,x0=x;
	while(*Dat) 
	{
		if((*Dat)<128) 
		{
			k=*Dat; //ASCLL字符编号索引
			if(k==0x0D) {x=x0;y+=24;} //换行  +24
			else 
			{
				if(k>32) k-=32; else k=0;//数组字符编号索引
			  for(i=0;i<16;i++)
				 for(j=0;j<8;j++) 
					{
				    if(asc16[k*16+i]&(0x80>>j))	TFT20_DrawPoint(x+j,y+i+4,fc); //字体颜色
						else {if(fc!=bc) TFT20_DrawPoint(x+j,y+i+4,bc);}  //背景色
					}
				x+=8;
			}
			Dat++;
		}
	}
}


/*******************************************************************************
* 函 数 : TFT20_DrawFont_Num32
* 功 能 : 显示数码管体数字
* 输 入 : XY 显示起始点 fc[in]字体颜色 bc[in]背景色 num[in]
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_DrawFont_Num56(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint16_t num)
{
	uint8_t i,j,k,c;

  for(i = 0;i < 56;i++)  //56 根据字模做相应改变
	 {
		for(j = 0;j < 4;j++) 
		 {
			c =*(Display + num * 56 * 4 + i * 4 + j);
			for(k = 0;k < 8;k++)	
			 {
	       if(c&(0x80 >> k)) TFT20_DrawPoint(x+j*8+k,y+i,fc);
				 else {if(fc != bc) TFT20_DrawPoint(x+j*8+k,y+i,bc);}
			 }
		}
	}
}


/*******************************************************************************
* 函 数 : SPI_Init
* 功 能 : 配置硬件SPI，可通过修改SPEED_4值来更改SPI总线速度
* 输 入 : 无
* 输 出 : 无
* 返 回 : 无
* 说 明 : SPEED_4为4分频最高速，SPEED_128为最低速
*******************************************************************************/
void TFT20_SPI_Init(void)	
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin=TFT20_PB;          
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
	GPIO_ResetBits(GPIOB,TFT20_PB); 
}

/*******************************************************************************
* 函 数 : TFT20_SPI_WriteData
* 功 能 : 写一个字节数据
* 输 入 : Dat[in] 待写入数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void  TFT20_SPI_WriteData(uint8_t Dat)
{
#if USE_HARDWARE_SPI    //硬件SPI

#else //模拟SPI
	uint8_t temp;
	for(temp=0x80;temp>0;temp>>=1) //高位先发
	{
		if(Dat&temp) TFT20_SDA=1; //输出数据
    else TFT20_SDA=0;
    TFT20_CLK=0; 
   	TFT20_CLK=1;
	}
#endif
}


/*******************************************************************************
* 函 数 : TFT20_WriteIndex
* 功 能 : 向液晶屏写一个8位指令
* 输 入 : Index[in] 指令
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_WriteIndex(uint8_t Index)
{
   TFT20_CS=0;
   TFT20_RS=0;
   TFT20_SPI_WriteData(Index);
   TFT20_CS=1;
}


/*******************************************************************************
* 函 数 : TFT20_WriteData
* 功 能 : 向液晶屏写入一个8位数据
* 输 入 : Dat[in] 待写入数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_WriteData(uint8_t Dat)
{
   TFT20_CS=0;
   TFT20_RS=1;
   TFT20_SPI_WriteData(Dat);
   TFT20_CS=1;
}


/*******************************************************************************
* 函 数 : TFT20_WriteReg
* 功 能 : 写寄存器数据
* 输 入 : Index[in] 寄存器地址 Dat[in] 待写入数据
* 输 出 : 无
* 返 回 : 无
* 说 明 : 无
*******************************************************************************/
void TFT20_WriteReg(uint8_t Index,uint16_t Dat)
{
	TFT20_WriteIndex(Index); //指令（寄存器地址）
	TFT20_WriteData(Dat>>8);
	TFT20_WriteData(Dat);	
}

