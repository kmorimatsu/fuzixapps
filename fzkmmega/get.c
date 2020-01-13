#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

char g_buff[512];
FSFILE g_usbstream;

int main(int argc, char* argv[]) {
	FILE* stream;
	FSFILE* usbstream;
	int i;
	// Check parameter
	if (argc<2) {
		fprintf(stderr,"Syntax: get filename\n");
		return -1;
	}
	// Open file to read in USB memory
	usbstream=FSfopen(argv[1],"r",&g_usbstream);
	if (!usbstream) {
		fprintf(stderr,"File invalid: %s\n",argv[1]);
		return -1;
	}
	// Open file to write in Fuzix
	stream=fopen(argv[1],"w");
	if (!stream) {
		fprintf(stderr,"File cannot be imported: %s\n",argv[1]);
		return -1;
	}
	// Copy file
	while(!FSfeof(usbstream)){
		i=FSfread(g_buff,1,512,usbstream);
		fwrite(g_buff,1,i,stream);
	}
	// All done
	fclose(stream);
	FSfclose(usbstream);
	fprintf(stderr,"File imported: %s\n",argv[1]);
	return 0;
}
