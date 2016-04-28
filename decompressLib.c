#include "compressor.h"
#include <string.h>
#include <math.h>
#include <ctype.h>





Array StrToDecomrpessedBin(Array * contents){

	Array bitStream;
	bitStream.arraySize =  contents->arraySize * SIZE_BYTE;
	printf("%zu\n", bitStream.arraySize);
	bitStream.data = (char *)calloc(sizeof(char), bitStream.arraySize);	

	int indexData = 0;	
	char * word;
	for ( indexData = 0; indexData < contents->arraySize; indexData++){

		word = decToBin((unsigned int)contents->data[indexData]);
		
		strcat(bitStream.data, word);		
	}
	

	
	bitStream.arraySize = strlen(bitStream.data);
		
	char * newBitStream; 
	newBitStream = realloc(bitStream.data, bitStream.arraySize * sizeof(char));
	bitStream.data = newBitStream;

	

	return bitStream;
}





char * decToBin(unsigned int charCode) {	
	
		
	char * result;
	result = (char *)calloc(sizeof(char), SIZE_BYTE + 1);

	int i = SIZE_BYTE - 1;
	do {		
		result[i--] = charCode % 2 + BASE_BINARY_CHAR;
		charCode /= 2;
	} while (charCode != 0);	
	while(i >= 0){
		result[i--] = BASE_BINARY_CHAR;			
	}	
	

	return result;
}