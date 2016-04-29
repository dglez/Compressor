#include "compressor.h"
#include <string.h>
#include <math.h>
#include <ctype.h>





Array StrToDecomrpessedBin(Array * contents){

	Array bitStream;
	bitStream.arraySize =  contents->arraySize * SIZE_BYTE;
	bitStream.data = (char *)calloc(sizeof(char), bitStream.arraySize);	

	int indexData = 0;	
	char * word;
	for ( indexData = 0; indexData < contents->arraySize; indexData++){
		word = decToBin((unsigned char)contents->data[indexData]);
		
		strcat(bitStream.data, word);		
	}
	free(word);

	
	bitStream.arraySize = strlen(bitStream.data);
		
	char * newBitStream = realloc(bitStream.data, bitStream.arraySize * sizeof(char));
	bitStream.data = newBitStream;

	

	return bitStream;
}





char * decToBin(unsigned char charCode) {	
	
	int code = (int)charCode;
	printf("%c %d ",charCode, code );

	char * result;
	result = (char *)calloc(sizeof(char), SIZE_BYTE + 1);

	int i = SIZE_BYTE - 1;
	do {		
		result[i--] = code % 2 + BASE_BINARY_CHAR;
		code /= 2;
	} while (code != 0);	
	while(i >= 0){
		result[i--] = BASE_BINARY_CHAR;			
	}	
	

	return result;
}