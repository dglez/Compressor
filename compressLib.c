
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


/* TODO:
./compress output.dog -b  // decompress  assuming output.txt
./compress output.dog diff.txt -b
./compress -b // assuming FILE_INPUT


./compress output.txt  // compress 		assuming output.dog
./compress diff.txt output.dog
./compress  	//assuming FILE_OUTPUT
*/
}
char * readFile(FILE * fIn){

	long input_size = 0;

	char * temp;

	fseek(fIn, 0, SEEK_END);	// move * from  start to end
	input_size = ftell(fIn);	// return how much * was moved 
	rewind(fIn);				// move * to position 0 again

	/* allocate memory size of file */
	temp = (char *)malloc(input_size * sizeof(char));
	/* read file into an array*/
	fread(temp, sizeof(char), input_size, fIn);
	temp[input_size] = 0;

	printf("%s\n", temp);
	return temp;
}



Boolean lineCompress( char * contents){


	return TRUE;


}

/**/
char * decToBin(int charCode) {	
	
	char * result;
	result = (char *)calloc(sizeof(char), BYTE_SIZE + 1); 
	int i = BYTE_SIZE - 1;
	result[BYTE_SIZE] = 0;

	do {		
		result[i--] = charCode % 2 + BASE_BINARY_CHAR;
		charCode /= 2;
	} while (charCode != 0);
	
	while(i >= 0){
		result[i--] = BASE_BINARY_CHAR;			
	}

	return result;
}
















