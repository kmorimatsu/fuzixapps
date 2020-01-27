/*
	PIC interface for FZKM-mega
*/

/*
	Structures and definitions follow
*/
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

/*
	Prototypings follow
*/
void start_composite(void);
void stop_composite(void);
void set_palette(uint8_t n,uint8_t b,uint8_t r,uint8_t g);
void set_bgcolor(uint8_t b,uint8_t r,uint8_t g);
void set_videomode(uint8_t m);
void setcursor(uint8_t x,uint8_t y);
void setcursorcolor(uint8_t c);
int8_t FSfopen(const int8_t * fileName, const int8_t *mode); // Returns 0 if fail.
int8_t FSfclose(void);                                       // Return 0 if sucess
int8_t FSfseek(int32_t offset, uint8_t whence);              // Return 0 if sucess
int8_t FSfeof(void);
uint16_t FSfwrite(const void *data_to_write, uint16_t size, uint16_t n);
uint16_t FSfread(void *ptr, uint16_t size, uint16_t n);
uint32_t FSftell(void);
uint32_t FSfsize(void);

/*
	Z80 I/O handling variables follow
*/
__sfr __banked __at 0x0048 PICINTERFACE_P0;
__sfr __banked __at 0x0148 PICINTERFACE_P1;
__sfr __banked __at 0x0248 PICINTERFACE_P2;
__sfr __banked __at 0x0348 PICINTERFACE_P3;
__sfr __banked __at 0x0448 PICINTERFACE_P4;
__sfr __banked __at 0x0548 PICINTERFACE_P5;
__sfr __banked __at 0x0648 PICINTERFACE_P6;
__sfr __banked __at 0x0748 PICINTERFACE_P7;
__sfr __banked __at 0x0848 PICINTERFACE_P8;
__sfr __banked __at 0x0948 PICINTERFACE_P9;
__sfr __banked __at 0x0a48 PICINTERFACE_P10;
__sfr __banked __at 0x0b48 PICINTERFACE_P11;
__sfr __banked __at 0x0c48 PICINTERFACE_P12;
__sfr __banked __at 0x0d48 PICINTERFACE_P13;
__sfr __banked __at 0x0e48 PICINTERFACE_P14;
__sfr __banked __at 0x0f48 PICINTERFACE_P15;

__sfr __banked __at 0x1048 PICINTERFACE_START_COMPOSITE;
__sfr __banked __at 0x1148 PICINTERFACE_STOP_COMPOSITE;
__sfr __banked __at 0x1248 PICINTERFACE_SET_PALETTE;
__sfr __banked __at 0x1348 PICINTERFACE_SET_BGCOLOR;
__sfr __banked __at 0x1448 PICINTERFACE_SET_VIDEOMODE;
__sfr __banked __at 0x1548 PICINTERFACE_SETCURSOR;
__sfr __banked __at 0x1648 PICINTERFACE_SETCURSORCOLOR;

__sfr __banked __at 0x2048 PICINTERFACE_FSFOPEN;
__sfr __banked __at 0x2148 PICINTERFACE_FSFCLOSE;
__sfr __banked __at 0x2248 PICINTERFACE_FSFSEEK;
__sfr __banked __at 0x2348 PICINTERFACE_FSFEOF;
__sfr __banked __at 0x2448 PICINTERFACE_FSFWRITE;
__sfr __banked __at 0x2548 PICINTERFACE_FSFREAD;
__sfr __banked __at 0x2648 PICINTERFACE_FSFTELL;
__sfr __banked __at 0x2648 PICINTERFACE_FSFSIZE;
