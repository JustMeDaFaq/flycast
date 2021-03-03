#pragma once
#include "types.h"

f32 vrf(u32 addr);
u32 vri(u32 addr);

//vram 32-64b
extern VArray2 vram;
//read
u8 DYNACALL pvr_read_area1_8(u32 addr);
u16 DYNACALL pvr_read_area1_16(u32 addr);
u32 DYNACALL pvr_read_area1_32(u32 addr);
//write
void DYNACALL pvr_write_area1_8(u32 addr,u8 data);
void DYNACALL pvr_write_area1_16(u32 addr,u16 data);
void DYNACALL pvr_write_area1_32(u32 addr,u32 data);

//regs
void pvr_WriteReg(u32 paddr,u32 data);

void TAWrite(u32 address,u32* data,u32 count);
extern "C" void DYNACALL TAWriteSQ(u32 address,u8* sqb);

void YUV_init();
