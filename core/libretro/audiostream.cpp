#include "types.h"
#include "emulator.h"

#include <libretro.h>

#define SAMPLE_COUNT 512

extern retro_audio_sample_batch_t audio_batch_cb;

SoundFrame RingBuffer[SAMPLE_COUNT];

void WriteSample(s16 r, s16 l)
{
   static const u32 RingBufferByteSize = sizeof(RingBuffer);
   static const u32 RingBufferSampleCount = SAMPLE_COUNT;
   static volatile u32 WritePtr;  //last written sample
   static volatile u32 ReadPtr;   //next sample to read
	const u32 ptr = (WritePtr+1)%RingBufferSampleCount;
	RingBuffer[ptr].r=r;
	RingBuffer[ptr].l=l;
	WritePtr=ptr;

   if (WritePtr==(SAMPLE_COUNT-1))
      if ( dc_is_running() && (!settings.rend.ThreadedRendering || settings.aica.LimitFPS) )
         audio_batch_cb((const int16_t*)RingBuffer, SAMPLE_COUNT);
}
