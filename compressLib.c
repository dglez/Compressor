
#include "compressor.h"
#include <string.h>



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





Array readFile(FILE * fIn){

	Array contents;

	fseek(fIn, 0, SEEK_END);			// move * from  start to end
	contents.arraySize = ftell(fIn);	// return how much * was moved 
	rewind(fIn);						// move * to position 0 again

	/* allocate memory size of file */
	contents.data = (char *)malloc(contents.arraySize * sizeof(char));
	/* read file into an array*/
	fread(contents.data, sizeof(char), contents.arraySize, fIn);
	contents.data[contents.arraySize] = 0;

	return contents;
}








void streamCompress(Array * contents){

	Array bitStream;
	bitStream = binaryStream(contents);
	printf("%s\n",bitStream.data);
}






Array binaryStream(Array * contents){

	Array bitStream;
	bitStream.arraySize = (contents->arraySize * BYTE_SIZE) + 1;
	bitStream.data = (char *)calloc(sizeof(char), bitStream.arraySize);	

	int indexData = 0;	
	char * word;
	for ( indexData = 0; indexData < contents->arraySize; indexData++){
		word = decToBin((int)contents->data[indexData]);
		strcat(bitStream.data, word);		
	}
	return bitStream;
}









/**/
char * decToBin(int charCode) {	
	
	char * result;
	result = (char *)calloc(sizeof(char), BYTE_SIZE + 1); 
	

	int i = BYTE_SIZE - 1;
	do {		
		result[i--] = charCode % 2 + BASE_BINARY_CHAR;
		charCode /= 2;
	} while (charCode != 0);
	
	while(i >= 0){
		result[i--] = BASE_BINARY_CHAR;			
	}

	return result;
}
















