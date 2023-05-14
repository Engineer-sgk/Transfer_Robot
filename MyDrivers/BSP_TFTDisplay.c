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
* �� �� : TFT20_DrawFont_Num32
* �� �� : ��ʾ�����������
* �� �� : XY ��ʾ��ʼ�� fc[in]������ɫ bc[in]����ɫ num[in]
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
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
	* @brief  �԰˽���/ʮ����/ʮ��������ʾ�������������
	* @param  x:x������ 0-127 y:y������ 0-7 number:����ʾ������֧�ָ��� radix:ѡ����ʾ���ƣ���ѡOCT/DEC/HEX
            ndigit:ռ�ü����ַ� 
	* @retval None   
*/
void TFT20_ShowNumber(uint8_t x, uint8_t y, int32_t number)
{
	uint8_t i = 0;
	char str[25] = {0}; 				//��������ת�ַ����Ĵ洢buffer
	sprintf(str,"%d",number);
	while(str[i])
	{
		TFT20_DrawFont_GBK16(x, y, BLACK, WHITE, (uint8_t *)str);	
	}	
}

/*
	* @name   TFT20_ShowFloatNum
	* @brief  ��ʾ������
	* @param  x:x������ 0-127 y:y������ 0-7 number:����ʾ��������֧�ָ��� 
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
* �� �� : RGB
* �� �� : R,G,B ת16λ
* �� �� : ��
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
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
* �� �� : TFT20_RGB24_RGB16
* �� �� : 24λrgb����ת16λ
* �� �� : ��
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
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
* �� �� : TFT20_delay_ms
* �� �� : ��ʱ
* �� �� : ��
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_delay_ms(uint16_t ms)
{
	Delay_ms(ms);
}


/*******************************************************************************
* �� �� : TFT20_Reset
* �� �� : Һ����Ӳ��λ
* �� �� : ��
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_Reset()
{	
//    TFT20_RST=0;
    TFT20_delay_ms(100);
//    TFT20_RST=1;
    TFT20_delay_ms(50);
}


/*******************************************************************************
* �� �� : TFT20_Init
* �� �� : Һ������ʼ��
* �� �� : ��
* �� �� : ��
* �� �� : ��
* ˵ �� : Һ������ʼ��_ILI9225_176X220
*******************************************************************************/
void TFT20_Init()
{	
	TFT20_SPI_Init();//SPI  GPIO��ʼ��
	
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

#if USE_HORIZONTAL//��������˺���
	//R01H:SM=0,GS=0,SS=0 (for details,See the datasheet of ILI9225)
	TFT20_WriteReg(0x01, 0x001C); // set the display line number and display direction
	//R03H:BGR=1,ID0=1,ID1=1,AM=1 (for details,See the datasheet of ILI9225)
	TFT20_WriteReg(0x03, 0x1038); // set GRAM write direction .
#else//����
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
	
  TFT20_Clear(WHITE); //��ɫ //����
}




/*******************************************************************************
* �� �� : TFT20_SetXY
* �� �� : ����TFT����ʾ��ʼ��
* �� �� : X Y ��ʼ��
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_SetXY(uint16_t XStart,uint16_t YStart)
{	
#if USE_HORIZONTAL//��������˺���  	    	
	TFT20_WriteReg(0x21,XStart);//����XY��ʼ��ַ
	TFT20_WriteReg(0x20,YStart);
#else             //����	
	TFT20_WriteReg(0x20,XStart);
	TFT20_WriteReg(0x21,YStart);
#endif
	TFT20_WriteIndex(0x22);		//��GRAM��ȡ���ݼĴ�����18λ���ݡ�
} 


/*******************************************************************************
* �� �� : TFT20_SetRegion
* �� �� : ������ʾ����
* �� �� : X Y �����յ�
* �� �� : ��
* �� �� : ��
* ˵ �� : �ڴ�����д�������Զ�����
*******************************************************************************/
void TFT20_SetRegion(uint8_t XStart,uint8_t YStart,uint8_t XEnd,uint8_t YEnd)
{
#if USE_HORIZONTAL//����	
	TFT20_WriteReg(0x38,XEnd);
	TFT20_WriteReg(0x39,XStart);
	TFT20_WriteReg(0x36,YEnd);
	TFT20_WriteReg(0x37,YStart);
	TFT20_WriteReg(0x21,XStart);
	TFT20_WriteReg(0x20,YStart);
#else             //����	
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
* �� �� : TFT20_Clear
* �� �� : ȫ�������ɫ������������
* �� �� : Color[in] ��ɫ����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
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
* �� �� : TFT20_LocalClear
* �� �� : �ֲ�����
* �� �� : XY ��ʾ��ʼ��  Color ��ɫ����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_LocalClear(uint16_t XStart,uint16_t YStart,uint16_t C,uint16_t H,uint16_t Color)   //�ֲ�����
{
	uint16_t temp;
	
	TFT20_SetRegion(XStart,YStart,XStart+C-1,YStart+H-1); //������ʾ���ڴ�С
	for(temp=0;temp<(C*H);temp++)
	 {	
		TFT20_WriteData(Color>>8);
		TFT20_WriteData(Color);				
	 }	
}


/*******************************************************************************
* �� �� : TFT20_DrawPoint
* �� �� : ��������ɫ��
* �� �� : XStart[in] YStart[in] XY���λ��  Color[in] ��ɫ����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_DrawPoint(uint16_t XStart,uint16_t YStart,uint16_t Color)
{
	TFT20_SetXY(XStart,YStart);
	TFT20_WriteData(Color>>8);
	TFT20_WriteData(Color);
}    


/*******************************************************************************
* �� �� : TFT20_BGR_RGB
* �� �� : BGR->RGB��ʽת��
* �� �� : ��
* �� �� : ��
* �� �� : RGB��ʽ����ɫֵ
* ˵ �� : ��ILI93xx����������ΪGBR��ʽ��������д���ʱ��ΪRGB��ʽ��
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
* �� �� : TFT20_DrawCircle
* �� �� : ��Բ
* �� �� : x[in] y[in] XYԲ�ĵ�λ�� R[in] �뾶 Color[in] ��ɫ����
* �� �� : ��
* �� �� : ��
* ˵ �� : Bresenham�㷨 
*******************************************************************************/
void TFT20_DrawCircle(uint16_t X,uint16_t Y,uint16_t R,uint16_t Color) //��Բ 
{
	unsigned short  a,b; //������
	int c; 
	a=0;   //���븳ֵΪ��
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


//��
/*******************************************************************************
* �� �� : TFT20_DrawLine
* �� �� : ���ߺ���
* �� �� : X Y ��ʼ�� �յ�����  Color[in] ��ɫ����
* �� �� : ��
* �� �� : ��
* ˵ �� : ʹ��Bresenham �����㷨
*******************************************************************************/
void TFT20_DrawLine(uint16_t XStart, uint16_t YStart,uint16_t XEnd, uint16_t YEnd,uint16_t Color)   
{
	int dx,dy,      //X Y ��ֵ
			dx2,dy2,    //X Y ��ֵ������
			x_inc,y_inc,//�ڻ�ͼ���������ص��ƶ��ķ���
			juece,      //���߱���
			temp;      //��ʱ����

	TFT20_SetXY(XStart,YStart);//����TFT����ʾ��ʼ��
	
	dx = XEnd-XStart;//����x����
	dy = YEnd-YStart;//����y����

	if(dx>=0) x_inc= 1;  //ȷ������
	else {x_inc= -1;dx= -dx;} 
	
	if(dy>=0) y_inc= 1;
	else {y_inc= -1;dy= -dy;} 

	dx2 = dx<<1; //����2
	dy2 = dy<<1;

	if(dx>dy)	     //x�������y����,��ôÿ��x����ֻ��һ����,ÿ��y���������ɸ���
	{              //���ߵĵ�������x����,��x���������
		juece= dy2-dx;  //��ʼ�������
		for(temp=0;temp<=dx;temp++) //Ҫ���ĵ������ᳬ��x����
		{
			TFT20_DrawPoint(XStart,YStart,Color);
			if(juece>=0) //�Ƿ���Ҫ����y����ֵ
			{
				juece -=dx2;
				YStart +=y_inc;//����y����ֵ
			} 
			juece +=dy2; //����
			XStart +=x_inc;//x����ֵÿ�λ���󶼵���1���ƶ�����һ�����أ�
		}
	}
	else          //y�����x�ᣬ��ÿ��y����ֻ��һ���㣬x�����ɸ���
	{             //��y��Ϊ��������
		juece= dx2-dy;  //��ʼ�������
		for (temp=0;temp<=dy;temp++) //����
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
* �� �� : TFT20_Drawbox
* �� �� : �����Σ���б�ߣ�
* �� �� : xy ��ʾ��ʼ�� w[in]���ο�� h[in]�߶�  Color[in] ��ɫ
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_Drawbox(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t Color)
{
	TFT20_DrawLine(x    ,y  ,x+w  ,y    ,0xEF7D);//�Ϻ�
	TFT20_DrawLine(x+w	,y	,x+w	,y+h  ,0x2965);//����
	TFT20_DrawLine(x    ,y+h,x+w  ,y+h  ,0x2965);//�º�
	TFT20_DrawLine(x    ,y  ,x    ,y+h  ,0xEF7D);//����
  TFT20_DrawLine(x+1  ,y+1,x+w-1,y+h-1,Color );//��б
}


/*******************************************************************************
* �� �� : TFT20_Drawbox2
* �� �� : ������
* �� �� : xy ��ʾ��ʼ�� w[in]���ο�� h[in]�߶�
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
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
* �� �� : TFT20_DisplayImg
* �� �� : ����λ����ʾͼƬ
* �� �� : XY ��ʾ��ʼ��  *img[in] ͼƬ����
* �� �� : ��
* �� �� : ��
* ˵ �� : 16λBMP/Image2LCDȡģѡ������/ˮƽɨ��/16λ/������ͼ��ͷ����/��������
          �Զ�����/��λ��ǰ/��ͼƬ����ǰ����ͼƬ�ߴ� ��:uint8_t a[]={176,220,dat};
*******************************************************************************/
void TFT20_DisplayImg(uint16_t XStart,uint16_t YStart,uint8_t *img)
{
	uint16_t temp;
	
//	TFT20_Clear(GRAY0); //��ɫ0 //����
	TFT20_SetRegion(XStart,YStart,XStart+img[0]-1,YStart+img[1]-1); //������ʾ���ڴ�С
	for(temp=0;temp<(img[0]*img[1]);temp++)
	 {	
		TFT20_WriteData(*(img+temp*2+3));	//���ݵ�λ��ǰ
		TFT20_WriteData(*(img+temp*2+2));				
	 }	
}


/*******************************************************************************
* �� �� : TFT20_DisplayButtonDown
* �� �� : ����Ļ��ʾһ͹��İ�ť��
* �� �� : x0,y0,x1,y1 ��ť�����ϽǺ����½�����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_DisplayButtonDown(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1)
{
	TFT20_DrawLine(x0  ,y0  ,x1  ,y0  ,GRAY2); //���Ϻ�
	TFT20_DrawLine(x0+1,y0+1,x1  ,y0+1,GRAY1); //���º�
	TFT20_DrawLine(x0  ,y0  ,x0  ,y1  ,GRAY2); //������ 
	TFT20_DrawLine(x0+1,y0+1,x0+1,y1  ,GRAY1); //������
	TFT20_DrawLine(x0  ,y1  ,x1  ,y1  ,WHITE); //�º�
	TFT20_DrawLine(x1  ,y0  ,x1  ,y1  ,WHITE); //����
}


/*******************************************************************************
* �� �� : TFT20_DisplayButtonUp
* �� �� : ����Ļ��ʾһ���µİ�ť��
* �� �� : x0,y0,x1,y1 ��ť�����ϽǺ����½�����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_DisplayButtonUp(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1)
{
	TFT20_DrawLine(x0  ,y0  ,x1  ,y0  ,WHITE); //�Ϻ�
	TFT20_DrawLine(x0  ,y0  ,x0  ,y1  ,WHITE); //����
	TFT20_DrawLine(x0+1,y1-1,x1  ,y1-1,GRAY1); //���Ϻ�
	TFT20_DrawLine(x0  ,y1  ,x1  ,y1  ,GRAY2); //���º�
	TFT20_DrawLine(x1-1,y0+1,x1-1,y1  ,GRAY1); //������
  TFT20_DrawLine(x1  ,y0  ,x1  ,y1  ,GRAY2); //������
}


/*******************************************************************************
* �� �� : TFT20_DrawFont_GBK16
* �� �� : ��ʾ���ֻ��ַ� ��GBK16��
* �� �� : XY ��ʾ��ʼ�� fc[in]������ɫ bc[in]����ɫ *Dat[in] ��ʾ����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_DrawFont_GBK16(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint8_t *Dat)
{
	uint8_t  i,j;
	unsigned short k,x0=x;//����x0�������
	while(*Dat) 
	{	
		if((*Dat) < 128) //С��128��ΪASCLL�ַ�
		{
			k=*Dat; //ASCLL�ַ��������
			if(k==0x0D) {x=x0;y+=16;} //����  +16
			else 
			{
				if(k>32) k-=32; else k=0;//�����ַ��������
			  for(i=0;i<16;i++)
				 for(j=0;j<8;j++) 
					{
				    if(asc16[k*16+i]&(0x80>>j))	TFT20_DrawPoint(x+j,y+i,fc); //������ɫ
						else {if(fc!=bc) TFT20_DrawPoint(x+j,y+i,bc);}  //����ɫ
					}
				x+=8;
			}
			Dat++;
		}
	}
}


/*******************************************************************************
* �� �� : TFT20_DrawFont_GBK24
* �� �� : ��ʾ���ֻ��ַ� ��GBK24��
* �� �� : XY ��ʾ��ʼ�� fc[in]������ɫ bc[in]����ɫ *Dat[in] ��ʾ����
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_DrawFont_GBK24(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint8_t *Dat)
{
	uint8_t i,j;
	unsigned short k,x0=x;
	while(*Dat) 
	{
		if((*Dat)<128) 
		{
			k=*Dat; //ASCLL�ַ��������
			if(k==0x0D) {x=x0;y+=24;} //����  +24
			else 
			{
				if(k>32) k-=32; else k=0;//�����ַ��������
			  for(i=0;i<16;i++)
				 for(j=0;j<8;j++) 
					{
				    if(asc16[k*16+i]&(0x80>>j))	TFT20_DrawPoint(x+j,y+i+4,fc); //������ɫ
						else {if(fc!=bc) TFT20_DrawPoint(x+j,y+i+4,bc);}  //����ɫ
					}
				x+=8;
			}
			Dat++;
		}
	}
}


/*******************************************************************************
* �� �� : TFT20_DrawFont_Num32
* �� �� : ��ʾ�����������
* �� �� : XY ��ʾ��ʼ�� fc[in]������ɫ bc[in]����ɫ num[in]
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_DrawFont_Num56(uint16_t x,uint16_t y,uint16_t fc,uint16_t bc,uint16_t num)
{
	uint8_t i,j,k,c;

  for(i = 0;i < 56;i++)  //56 ������ģ����Ӧ�ı�
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
* �� �� : SPI_Init
* �� �� : ����Ӳ��SPI����ͨ���޸�SPEED_4ֵ������SPI�����ٶ�
* �� �� : ��
* �� �� : ��
* �� �� : ��
* ˵ �� : SPEED_4Ϊ4��Ƶ����٣�SPEED_128Ϊ�����
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
* �� �� : TFT20_SPI_WriteData
* �� �� : дһ���ֽ�����
* �� �� : Dat[in] ��д������
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void  TFT20_SPI_WriteData(uint8_t Dat)
{
#if USE_HARDWARE_SPI    //Ӳ��SPI

#else //ģ��SPI
	uint8_t temp;
	for(temp=0x80;temp>0;temp>>=1) //��λ�ȷ�
	{
		if(Dat&temp) TFT20_SDA=1; //�������
    else TFT20_SDA=0;
    TFT20_CLK=0; 
   	TFT20_CLK=1;
	}
#endif
}


/*******************************************************************************
* �� �� : TFT20_WriteIndex
* �� �� : ��Һ����дһ��8λָ��
* �� �� : Index[in] ָ��
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_WriteIndex(uint8_t Index)
{
   TFT20_CS=0;
   TFT20_RS=0;
   TFT20_SPI_WriteData(Index);
   TFT20_CS=1;
}


/*******************************************************************************
* �� �� : TFT20_WriteData
* �� �� : ��Һ����д��һ��8λ����
* �� �� : Dat[in] ��д������
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_WriteData(uint8_t Dat)
{
   TFT20_CS=0;
   TFT20_RS=1;
   TFT20_SPI_WriteData(Dat);
   TFT20_CS=1;
}


/*******************************************************************************
* �� �� : TFT20_WriteReg
* �� �� : д�Ĵ�������
* �� �� : Index[in] �Ĵ�����ַ Dat[in] ��д������
* �� �� : ��
* �� �� : ��
* ˵ �� : ��
*******************************************************************************/
void TFT20_WriteReg(uint8_t Index,uint16_t Dat)
{
	TFT20_WriteIndex(Index); //ָ��Ĵ�����ַ��
	TFT20_WriteData(Dat>>8);
	TFT20_WriteData(Dat);	
}

