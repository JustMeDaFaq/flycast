#pragma once
#include "types.h"

u32 pvr_map32(u32 offset32);
f32 vrf(u32 addr);
u32 vri(u32 addr);

//vram 32-64b
extern VArray2 vram;

//regs
void pvr_WriteReg(u32 paddr,u32 data);

void pvr_Update(u32 cycles);

//Init/Term , global
void pvr_Init(void);
void pvr_Term(void);
//Reset -> Reset - Initialise
void pvr_Reset(bool Manual);

void TAWrite(u32 address,u32* data,u32 count);
extern "C" void DYNACALL TAWriteSQ(u32 address,u8* sqb);

void YUV_init();

template<typename T> T DYNACALL pvr_read_area1(u32 addr);
template<typename T> void DYNACALL pvr_write_area1(u32 addr, T data);
template<typename T, bool upper> T pvr_read_area4(u32 addr);
template<typename T, bool upper> void pvr_write_area4(u32 addr, T data);

//registers 
#define PVR_BASE 0x005F8000
