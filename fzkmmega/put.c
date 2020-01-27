#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

char g_buff[512];

int main(int argc, char* argv[]) {
	FILE* stream;
	int i;
	// Check parameter
	if (argc<2) {
		fprintf(stderr,"Syntax: put filename [newfilename]\n");
		return -1;
	}
	// Open file to read in Fuzix
	stream=fopen(argv[1],"r");
	if (!stream) {
		fprintf(stderr,"File invalid: %s\n",argv[1]);
		return -1;
	}
	// Open file to write in USB memory
	if (argc>2) {
		i=FSfopen(argv[2],"w");
	} else {
		i=FSfopen(argv[1],"w");
	}
	if (!i) {
		fclose(stream);
		fprintf(stderr,"File cannot be exported: %s\n",argv[1]);
		return -1;
	}
	// Copy file
	fprintf(stderr,"File is beeing exported: %s",argv[1]);
	if (argc>2) fprintf(stderr," as %s",argv[2]);
	while(!feof(stream)){
		i=fread(g_buff,1,512,stream);
		if (FSfwrite(g_buff,1,i)!=i) {
			fclose(stream);
			fprintf(stderr," error.\n");
			return -1;
		}
	}
	// All done
	fclose(stream);
	fprintf(stderr," done.\n");
	return 0;
}
