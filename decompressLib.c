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
	int charCode = (unsigned char)contents->data[indexData];;
	word = decToBin(charCode);		
	strcat(bitStream.data, word);
	free(word);
	for ( indexData = 1; indexData < contents->arraySize; indexData++){
		
		charCode = (unsigned char)contents->data[indexData];		
		word = (charCode == FLAG_INT && 
				(unsigned char)contents->data[indexData -1] == FLAG_INT)?
				decToBin(0) : decToBin(charCode);
						
		strcat(bitStream.data, word);
		free(word);		
	}
	
	bitStream.arraySize = strlen(bitStream.data);

	char * newBitStream = realloc(bitStream.data, bitStream.arraySize * sizeof(char));
	bitStream.data = newBitStream;

	

	return bitStream;
}






Array binToDecompressedContent(Array * bitStream){

	Array contents;
	contents.arraySize = bitStream->arraySize / SIZE_BYTE;
	contents.data = (char *)calloc(sizeof(char), contents.arraySize + 1);


	char * wordTest;
	char * wordReal;
	unsigned char chrDecompressed;
	




	Boolean streamEnd = FALSE;
	unsigned long index = 0;
	while(!streamEnd){

		wordTest = getWord(bitStream->data, index, SIZE_BYTE);

		if(strcmp(wordTest, FLAG_STR) == 0){
			wordTest = getWord(bitStream->data, index += SIZE_BYTE, SIZE_BYTE);
			if(strlen(wordTest) < SIZE_BYTE){
				streamEnd = TRUE;
			}else{
				index += SIZE_BYTE;
				strcpy(wordReal, wordTest);
			}
		}else{
			wordTest = getWord(bitStream->data, index, SIZE_COMPRESSED);
			index += SIZE_COMPRESSED;
			strcpy(wordReal, REDUNDANT_BITS);
			strcat(wordReal, wordTest);

		}

		chrDecompressed = (unsigned char)binToDec(wordReal);

		sprintf(contents.data, "%s%c" ,contents.data, chrDecompressed );




	}
	contents.arraySize = strlen(contents.data);
	char * newContents;
	newContents = realloc(contents.data, contents.arraySize * sizeof(char));
	contents.data = newContents;


	return contents;

}
//Loop
// realWord
// getWord 8 char

// if
// is word a FLAG_STR?
	// get next word 8 char
	// is word length < 8
		// done reading 

// getword 5 char
// add to word redundant bits 
//end if


// realword = convert word from bin to dec char
//end loop






char * decToBin(int decimalValue) {	
	
	
	printf("%d ", decimalValue );
	

	char * result;
	result = (char *)calloc(sizeof(char), SIZE_BYTE + 1);

	int i = SIZE_BYTE - 1;
	do {		
		result[i--] = decimalValue % 2 + BASE_BINARY_CHAR;
		decimalValue /= 2;
	} while (decimalValue != 0);	
	while(i >= 0){
		result[i--] = BASE_BINARY_CHAR;			
	}	
	

	return result;
}