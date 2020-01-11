#include <stdlib.h>
#include "picinterface.h"

void start_composite(void){
	PICINTERFACE_START_COMPOSITE=0;
}
void stop_composite(void){
	PICINTERFACE_STOP_COMPOSITE=0;
}
void set_palette(uint8_t n,uint8_t b,uint8_t r,uint8_t g){
	PICINTERFACE_P1=b;
	PICINTERFACE_P2=r;
	PICINTERFACE_P3=g;
	PICINTERFACE_SET_PALETTE=n;
}
void set_bgcolor(uint8_t b,uint8_t r,uint8_t g){
	PICINTERFACE_P1=r;
	PICINTERFACE_P2=g;
	PICINTERFACE_SET_BGCOLOR=b;
}
void set_videomode(uint8_t m){
	PICINTERFACE_SET_VIDEOMODE=m;
}
void setcursor(uint8_t x,uint8_t y){
	PICINTERFACE_P1=y;
	PICINTERFACE_SETCURSOR=x;
}
void setcursorcolor(uint8_t c){
	PICINTERFACE_SETCURSORCOLOR=c;
}
FSFILE* FSfopen(const int8_t * fileName, const int8_t *mode, FSFILE* stream){
	uint16_t ret;
	PICINTERFACE_P0=(uintptr_t)fileName;
	PICINTERFACE_P1=((uintptr_t)fileName)>>8;
	PICINTERFACE_P2=(uintptr_t)mode;
	PICINTERFACE_P3=((uintptr_t)mode)>>8;
	PICINTERFACE_P4=(uintptr_t)stream;
	PICINTERFACE_P5=((uintptr_t)stream)>>8;
	ret=PICINTERFACE_FSFOPEN;
	ret|=PICINTERFACE_P1<<8;
	return (FSFILE*)ret;
}
int8_t FSfclose(FSFILE *fo){
	PICINTERFACE_P1=((uintptr_t)fo)>>8;
	PICINTERFACE_FSFCLOSE=(uintptr_t)fo;
	return 0;
}
int8_t FSfseek(FSFILE *stream, int32_t offset, uint8_t whence){
	PICINTERFACE_P0=offset;
	PICINTERFACE_P1=offset>>8;
	PICINTERFACE_P2=offset>>16;
	PICINTERFACE_P3=offset>>24;
	PICINTERFACE_P4=(uintptr_t)stream;
	PICINTERFACE_P5=((uintptr_t)stream)>>8;
	PICINTERFACE_P6=whence;
	return PICINTERFACE_FSFSEEK;
}
int8_t FSfeof( FSFILE * stream ){
	PICINTERFACE_P0=(uintptr_t)stream;
	PICINTERFACE_P1=((uintptr_t)stream)>>8;
	return PICINTERFACE_FSFEOF;
}
uint16_t FSfwrite(const void *data_to_write, uint16_t size, uint16_t n, FSFILE *stream){
	uint16_t ret;
	PICINTERFACE_P0=(uintptr_t)data_to_write;
	PICINTERFACE_P1=((uintptr_t)data_to_write)>>8;
	PICINTERFACE_P2=size;
	PICINTERFACE_P3=size>>8;
	PICINTERFACE_P4=n;
	PICINTERFACE_P5=n>>8;
	PICINTERFACE_P6=(uintptr_t)stream;
	PICINTERFACE_P7=((uintptr_t)stream)>>8;
	ret=PICINTERFACE_FSFWRITE;
	ret|=PICINTERFACE_P1<<8;
	return ret;
}
uint16_t FSfread(void *ptr, uint16_t size, uint16_t n, FSFILE *stream){
	uint16_t ret;
	PICINTERFACE_P0=(uintptr_t)ptr;
	PICINTERFACE_P1=((uintptr_t)ptr)>>8;
	PICINTERFACE_P2=size;
	PICINTERFACE_P3=size>>8;
	PICINTERFACE_P4=n;
	PICINTERFACE_P5=n>>8;
	PICINTERFACE_P6=(uintptr_t)stream;
	PICINTERFACE_P7=((uintptr_t)stream)>>8;
	ret=PICINTERFACE_FSFREAD;
	ret|=PICINTERFACE_P1<<8;
	return ret;
}
