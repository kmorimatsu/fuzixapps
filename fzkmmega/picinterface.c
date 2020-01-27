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
int8_t FSfopen(const int8_t * fileName, const int8_t *mode){
	uint16_t ret;
	PICINTERFACE_P0=(uintptr_t)fileName;
	PICINTERFACE_P1=((uintptr_t)fileName)>>8;
	PICINTERFACE_P2=(uintptr_t)mode;
	PICINTERFACE_P3=((uintptr_t)mode)>>8;
	return PICINTERFACE_FSFOPEN;
}
int8_t FSfclose(void){
	return PICINTERFACE_FSFCLOSE;
}
int8_t FSfseek(int32_t offset, uint8_t whence){
	PICINTERFACE_P0=offset;
	PICINTERFACE_P1=offset>>8;
	PICINTERFACE_P2=offset>>16;
	PICINTERFACE_P3=offset>>24;
	PICINTERFACE_P4=whence;
	return PICINTERFACE_FSFSEEK;
}
int8_t FSfeof(void){
	return PICINTERFACE_FSFEOF;
}
uint16_t FSfwrite(const void *data_to_write, uint16_t size, uint16_t n){
	uint16_t ret;
	PICINTERFACE_P0=(uintptr_t)data_to_write;
	PICINTERFACE_P1=((uintptr_t)data_to_write)>>8;
	PICINTERFACE_P2=size;
	PICINTERFACE_P3=size>>8;
	PICINTERFACE_P4=n;
	PICINTERFACE_P5=n>>8;
	ret=PICINTERFACE_FSFWRITE;
	ret|=PICINTERFACE_P1<<8;
	return ret;
}
uint16_t FSfread(void *ptr, uint16_t size, uint16_t n){
	uint16_t ret;
	PICINTERFACE_P0=(uintptr_t)ptr;
	PICINTERFACE_P1=((uintptr_t)ptr)>>8;
	PICINTERFACE_P2=size;
	PICINTERFACE_P3=size>>8;
	PICINTERFACE_P4=n;
	PICINTERFACE_P5=n>>8;
	ret=PICINTERFACE_FSFREAD;
	ret|=PICINTERFACE_P1<<8;
	return ret;
}
uint32_t FSftell(void){
	uint32_t ret;
	ret=PICINTERFACE_FSFTELL;
	ret|=PICINTERFACE_P1<<8;
	ret|=PICINTERFACE_P2<<16;
	ret|=PICINTERFACE_P3<<24;
	return ret;
}
uint32_t FSfsize(void){
	uint32_t ret;
	ret=PICINTERFACE_FSFSIZE;
	ret|=PICINTERFACE_P1<<8;
	ret|=PICINTERFACE_P2<<16;
	ret|=PICINTERFACE_P3<<24;
	return ret;
}
