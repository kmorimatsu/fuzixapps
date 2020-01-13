#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

int main(int argc, char* argv[]) {
	if (3<argc) {
		//void set_bgcolor(uint8_t b,uint8_t r,uint8_t g);
		set_bgcolor(
			strtol(argv[3],0,10),
			strtol(argv[1],0,10),
			strtol(argv[2],0,10)
		);
		return 0;
	} else {
		fprintf(stderr,
			"Syntax: bgcolor r g b\n"
			", where r: red intensity   (0-255)\n"
			",       g: green intensity (0-255)\n"
			",       b: blue intensity  (0-255)\n"
		);
		return -1;
	}
}
