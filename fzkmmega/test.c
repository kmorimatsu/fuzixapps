#include <stdio.h>
#include "p32mx370f.h"

int main(/*int argc, char* argv[]*/) {
	volatile unsigned int i,j;
	p32sfr16out(TRISBCLR,1<<15);
	printf("LED blinking\n");
	for(i=0;i<10;i++){
		p32sfr16out(LATBINV,1<<15);
		printf(".\n");
		for(j=0;j<16384;j++);
	}
	return 0;
}
