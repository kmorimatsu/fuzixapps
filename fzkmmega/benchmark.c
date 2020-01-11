#include <stdio.h>

int main(/*int argc, char* argv[]*/) {
	volatile int i,j;
	printf("start\n");
	for(i=0;i<10;i++) {
		for(j=0;j<16384;j++);
		printf(".\n");
	}
	printf("done\n");
	return 0;
}
