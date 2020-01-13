#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

int main(int argc, char* argv[]) {
	int color;
	if (1<argc) {
		color=strtol(argv[1],0,10);
	} else {
		color=-1;
	}
	if (0<=color && color<=255) {
		setcursorcolor(color);
		return 0;
	} else {
		fprintf(stderr,"Valid color: 0-255\n");
		return -1;
	}
}
