
#include "compressor.h"



void argumentsGet(const int argc, const char ** argv, Arguments * arg){

	int decompress;

	// if nothing has been passed then.
	if (argc == 1){
		arg->inputFile = FILE_INPUT;
		arg->outputFile = FILE_OUTPUT;
		arg->decompress = FALSE;
		arg->Error = NO_ERRORS;
	}else{
		arg->inputFile = FILE_INPUT;
		arg->outputFile = FILE_OUTPUT;
		arg->decompress = TRUE;
		arg->Error = NO_ERRORS;
	}



/*
./compress output.dog -b  // decompress  assuming output.txt
./compress output.dog diff.txt -b
./compress -b // assuming FILE_INPUT


./compress output.txt  // compress 		assuming output.dog
./compress diff.txt output.dog
./compress  	//assuming FILE_OUTPUT
*/
}