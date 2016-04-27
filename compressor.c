#include <string.h>
#include "compressor.h"

int main(int argc, char const *argv[]){

	Arguments arg;
	FILE * fIn;
	FILE * fOut;
	Array contents;
	Array compressed;


	argumentsGet(argc, argv, &arg);

	if (arg.Error == NO_ERRORS) {

		// TODO:Check for errors and for input/output
		
		fOut = fopen(arg.outputFile, FILE_MODE_APPEND);	


		// read file
		fIn = fopen(arg.inputFile, FILE_MODE_READ);
		contents = readFile(fIn);
		fclose(fIn);






		printf("%s\n%ld\n",contents.data, contents.arraySize );

		printf("%s\n",binaryStream(&contents));
		








		




		
		// process line 
		// Free memory 
		// write processed line to compressed file
		// end loop

	}else{

	}


	return NO_ERRORS;
}