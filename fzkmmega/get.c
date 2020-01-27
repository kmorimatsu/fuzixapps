#include <stdio.h>
#include <stdlib.h>
#include "picinterface.h"

char g_buff[512];

int main(int argc, char* argv[]) {
	FILE* stream;
	int i;
	// Check parameter
	if (argc<2) {
		fprintf(stderr,"Syntax: get filename [newfilename]\n");
		return -1;
	}
	// Open file to read in USB memory
	if (!FSfopen(argv[1],"r")) {
		fprintf(stderr,"File invalid: %s\n",argv[1]);
		return -1;
	}
	// Open file to write in Fuzix
	if (argc>2) {
		stream=fopen(argv[2],"w");
	} else {
		stream=fopen(argv[1],"w");
	}
	if (!stream) {
		fprintf(stderr,"File cannot be imported: %s\n",argv[1]);
		return -1;
	}
	// Copy file
	fprintf(stderr,"File is beeing imported: %s",argv[1]);
	if (argc>2) fprintf(stderr," as %s",argv[2]);
	while(!FSfeof()){
		i=FSfread(g_buff,1,512);
		if (fwrite(g_buff,1,i,stream)!=i) {
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
