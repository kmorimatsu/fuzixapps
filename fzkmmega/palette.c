#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

int main(int argc, char* argv[]) {
	if (4<argc) {
		//void set_palette(uint8_t n,uint8_t b,uint8_t r,uint8_t g);
		set_palette(
			strtol(argv[1],0,10),
			strtol(argv[4],0,10),
			strtol(argv[2],0,10),
			strtol(argv[3],0,10)
		);
		return 0;
	} else {
		fprintf(stderr,
			"Syntax: palette n r g b\n"
			", where n: palette number  (0-255)\n"
			",       r: red intensity   (0-255)\n"
			",       g: green intensity (0-255)\n"
			",       b: blue intensity  (0-255)\n"
		);
		return -1;
	}
}
