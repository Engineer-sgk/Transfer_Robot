#include "MyDrivers.h"

static uint8_t Mem[SMSBCL_PRESENT_CURRENT_H-SMSBCL_PRESENT_POSITION_L+1];
static int Err = 0;

int getErr(void)
{
	return Err;
}

int WritePosEx(uint8_t Id, int16_t Position, uint16_t Speed, uint8_t ACC)
{
	uint8_t bBuf[7];
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}

	bBuf[0] = ACC;
	Host2SCS(bBuf+1, bBuf+2, Position);
	Host2SCS(bBuf+3, bBuf+4, 0);
	Host2SCS(bBuf+5, bBuf+6, Speed);
	
	return genWrite(Id, SMSBCL_ACC, bBuf, 7);
}

int RegWritePosEx(uint8_t Id, int16_t Position, uint16_t Speed, uint8_t ACC)
{
	uint8_t bBuf[7];
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}

	bBuf[0] = ACC;
	Host2SCS(bBuf+1, bBuf+2, Position);
	Host2SCS(bBuf+3, bBuf+4, 0);
	Host2SCS(bBuf+5, bBuf+6, Speed);
	
	return regWrite(Id, SMSBCL_ACC, bBuf, 7);
}

void RegWriteAction(void)
{
	regAction(0xfe);
}

void SyncWritePosEx(uint8_t Id[], uint8_t IDN, int16_t Position[], uint16_t Speed[], uint8_t ACC[])
{
	uint8_t offbuf[32*7];
	uint8_t i;
	uint16_t V;
  for(i = 0; i<IDN; i++){
		if(Position[i]<0){
			Position[i] = -Position[i];
			Position[i] |= (1<<15);
		}

		if(Speed){
			V = Speed[i];
		}else{
			V = 0;
		}
		if(ACC){
			offbuf[i*7] = ACC[i];
		}else{
			offbuf[i*7] = 0;
		}
		Host2SCS(offbuf+i*7+1, offbuf+i*7+2, Position[i]);
    Host2SCS(offbuf+i*7+3, offbuf+i*7+4, 0);
    Host2SCS(offbuf+i*7+5, offbuf+i*7+6, V);
	}
  syncWrite(Id, IDN, SMSBCL_ACC, offbuf, 7);
}

int WheelMode(uint8_t Id)
{
	return writeByte(Id, SMSBCL_MODE, 1);		
}

int WriteSpe(uint8_t Id, int16_t Speed, uint8_t ACC)
{
	uint8_t bBuf[2];
	if(Speed<0){
		Speed = -Speed;
		Speed |= (1<<15);
	}
	bBuf[0] = ACC;
	genWrite(Id, SMSBCL_ACC, bBuf, 1);
	
	Host2SCS(bBuf+0, bBuf+1, Speed);

	genWrite(Id, SMSBCL_GOAL_SPEED_L, bBuf, 2);
	return 1;
}

int EnableTorque(uint8_t Id, uint8_t Enable)
{
	return writeByte(Id, SMSBCL_TORQUE_ENABLE, Enable);
}

int unLockEprom(uint8_t Id)
{
	return writeByte(Id, SMSBCL_LOCK, 0);
}

int LockEprom(uint8_t Id)
{
	return writeByte(Id, SMSBCL_LOCK, 1);
}

int CalibrationOfs(uint8_t Id)
{
	return writeByte(Id, SMSBCL_TORQUE_ENABLE, 128);
}

int FeedBack(int Id)
{
	int nLen = Read(Id, SMSBCL_PRESENT_POSITION_L, Mem, sizeof(Mem));
	if(nLen!=sizeof(Mem)){
		Err = 1;
		return -1;
	}
	Err = 0;
	return nLen;
}

int ReadPos(int Id)
{
	int Pos = -1;
	if(Id==-1){
		Pos = Mem[SMSBCL_PRESENT_POSITION_H-SMSBCL_PRESENT_POSITION_L];
		Pos <<= 8;
		Pos |= Mem[SMSBCL_PRESENT_POSITION_L-SMSBCL_PRESENT_POSITION_L];
	}else{
		Err = 0;
		Pos = readWord(Id, SMSBCL_PRESENT_POSITION_L);
		if(Pos==-1){
			Err = 1;
		}
	}
	if(!Err && Pos&(1<<15)){
		Pos = -(Pos&~(1<<15));
	}	
	return Pos;
}

int ReadSpeed(int Id)
{
	int Speed = -1;
	if(Id==-1){
		Speed = Mem[SMSBCL_PRESENT_SPEED_H-SMSBCL_PRESENT_POSITION_L];
		Speed <<= 8;
		Speed |= Mem[SMSBCL_PRESENT_SPEED_L-SMSBCL_PRESENT_POSITION_L];
	}else{
		Err = 0;
		Speed = readWord(Id, SMSBCL_PRESENT_SPEED_L);
		if(Speed==-1){
			Err = 1;
			return -1;
		}
	}
	if(!Err && Speed&(1<<15)){
		Speed = -(Speed&~(1<<15));
	}	
	return Speed;
}

int ReadLoad(int Id)
{
	int Load = -1;
	if(Id==-1){
		Load = Mem[SMSBCL_PRESENT_LOAD_H-SMSBCL_PRESENT_POSITION_L];
		Load <<= 8;
		Load |= Mem[SMSBCL_PRESENT_LOAD_L-SMSBCL_PRESENT_POSITION_L];
	}else{
		Err = 0;
		Load = readWord(Id, SMSBCL_PRESENT_LOAD_L);
		if(Load==-1){
			Err = 1;
		}
	}
	if(!Err && Load&(1<<10)){
		Load = -(Load&~(1<<10));
	}	
	return Load;
}

int ReadVoltage(int Id)
{
	int Voltage = -1;
	if(Id==-1){
		Voltage = Mem[SMSBCL_PRESENT_VOLTAGE-SMSBCL_PRESENT_POSITION_L];	
	}else{
		Err = 0;
		Voltage = readByte(Id, SMSBCL_PRESENT_VOLTAGE);
		if(Voltage==-1){
			Err = 1;
		}
	}
	return Voltage;
}

int ReadTemper(int Id)
{
	int Temper = -1;
	if(Id==-1){
		Temper = Mem[SMSBCL_PRESENT_TEMPERATURE-SMSBCL_PRESENT_POSITION_L];	
	}else{
		Err = 0;
		Temper = readByte(Id, SMSBCL_PRESENT_TEMPERATURE);
		if(Temper==-1){
			Err = 1;
		}
	}
	return Temper;
}

int ReadMove(int Id)
{
	int Move = -1;
	if(Id==-1){
		Move = Mem[SMSBCL_MOVING-SMSBCL_PRESENT_POSITION_L];	
	}else{
		Err = 0;
		Move = readByte(Id, SMSBCL_MOVING);
		if(Move==-1){
			Err = 1;
		}
	}
	return Move;
}

int ReadCurrent(int Id)
{
	int Current = -1;
	if(Id==-1){
		Current = Mem[SMSBCL_PRESENT_CURRENT_H-SMSBCL_PRESENT_POSITION_L];
		Current <<= 8;
		Current |= Mem[SMSBCL_PRESENT_CURRENT_L-SMSBCL_PRESENT_POSITION_L];
	}else{
		Err = 0;
		Current = readWord(Id, SMSBCL_PRESENT_CURRENT_L);
		if(Current==-1){
			Err = 1;
			return -1;
		}
	}
	if(!Err && Current&(1<<15)){
		Current = -(Current&~(1<<15));
	}	
	return Current;
}




