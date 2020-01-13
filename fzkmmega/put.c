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
		fprintf(stderr,"Syntax: put filename\n");
		return -1;
	}
	// Open file to read in Fuzix
	stream=fopen(argv[1],"r");
	if (!stream) {
		fprintf(stderr,"File invalid: %s\n",argv[1]);
		return -1;
	}
	// Open file to write in USB memory
	usbstream=FSfopen(argv[1],"w",&g_usbstream);
	if (!usbstream) {
		fprintf(stderr,"File cannot be exported: %s\n",argv[1]);
		return -1;
	}
	// Copy file
	while(!feof(stream)){
		i=fread(g_buff,1,512,stream);
		FSfwrite(g_buff,1,i,usbstream);
	}
	// All done
	fclose(stream);
	FSfclose(usbstream);
	fprintf(stderr,"File exported: %s\n",argv[1]);
	return 0;
}
