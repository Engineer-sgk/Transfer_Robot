#ifndef __Servo_Data_Analysic_H__
#define __Servo_Data_Analysic_H__

#include "MyDrivers.h"

extern int genWrite(uint8_t Id, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//普通写指令
extern int regWrite(uint8_t Id, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//异步写指令
extern int regAction(uint8_t Id);//异步写执行行
extern void syncWrite(uint8_t Id[], uint8_t IDN, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen);//同步写指令
extern int writeByte(uint8_t Id, uint8_t MemAddr, uint8_t bDat);//写1个字节
extern int writeWord(uint8_t Id, uint8_t MemAddr, uint16_t wDat);//写2个字节
extern int Read(uint8_t Id, uint8_t MemAddr, uint8_t *nData, uint8_t nLen);//读指令
extern int readByte(uint8_t Id, uint8_t MemAddr);//读1个字节
extern int readWord(uint8_t Id, uint8_t MemAddr);//读2个字节
extern int Ping(uint8_t Id);//Ping指令

extern void writeBuf(uint8_t Id, uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun);
extern void Host2SCS(uint8_t *DataL, uint8_t* DataH, int Data);//1个16位数拆分为2个8位数
extern int SCS2Host(uint8_t DataL, uint8_t DataH);//2个8位数组合为1个16位数
extern int Ack(uint8_t Id);//应答
extern int checkHead(void);//帧头检测

//硬件接口函数
extern int writeSCS(uint8_t *nDat, int nLen);
extern int readSCS(uint8_t *nDat, int nLen);
extern void rFlushSCS(void);
extern void wFlushSCS(void);


#endif

