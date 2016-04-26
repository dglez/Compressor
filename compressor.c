#include <stdio.h>
#include <string.h>
#include "compressor.h"

int main(int argc, char const *argv[]){

	Arguments arg;
	FILE * fIn;
	FILE * fOut;
	Line line;

	argumentsGet(argc, argv, &arg);

	if (arg.Error == NO_ERRORS) {

		// TODO:Check for errors and for input/output
		fIn = fopen(arg.inputFile, FILE_MODE_READ);
		fOut = fopen(arg.outputFile, FILE_MODE_APPEND);

		while(fgets(line.content, MIN_LINE, fIn) != NULL) {

			if (!arg.decompress) {
				printf("%s\n", "I am compressing");
			} else {
				printf("%s\n", "I am decompressing" );
			}

			printf("%s\n", line.content);

		}


		// Loop
		// read line
		// process line  
		// write processed line to compressed file
		// end loop

	}else{
	}


	return NO_ERRORS;
}