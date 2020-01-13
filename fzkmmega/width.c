#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

int main(int argc, char* argv[]) {
	char mode;
	if (1<argc) {
		switch(strtol(argv[1],0,10)){
			case 30:
				mode=0;
				break;
			case 36:
				mode=1;
				break;
			case 40:
				mode=2;
				break;
			case 48:
				mode=3;
				break;
			case 64:
				mode=4;
				break;
			case 80:
				mode=5;
				break;
			default:
				mode=-1;
				break;
		}
	} else {
		mode=-1;
	}
	if (0<=mode && mode<=5) {
		set_videomode(mode);
		return 0;
	} else {
		fprintf(stderr,"Valid width: 30,36,40,48,64,80\n");
		return -1;
	}
}
