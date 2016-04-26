#include <string.h>
#include "compressor.h"

int main(int argc, char const *argv[]){

	Arguments arg;
	FILE * fIn;
	FILE * fOut;
	Line line;	
	char * contents;


	argumentsGet(argc, argv, &arg);

	if (arg.Error == NO_ERRORS) {

		// TODO:Check for errors and for input/output
		
		fOut = fopen(arg.outputFile, FILE_MODE_APPEND);	


		// read file
		fIn = fopen(arg.inputFile, FILE_MODE_READ);
		contents = readFile(fIn);
		fclose(fIn);

		




		
		// process line 
		// Free memory 
		// write processed line to compressed file
		// end loop

	}else{

	}


	return NO_ERRORS;
}