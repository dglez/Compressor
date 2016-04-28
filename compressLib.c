
#include "compressor.h"
#include <string.h>
#include <math.h>
#include <ctype.h>



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
	printf("%ld\n", contents.arraySize );

	/* allocate memory size of file */
	contents.data = (char *)malloc(contents.arraySize * sizeof(char));
	/* read file into an array*/
	fread(contents.data, sizeof(char), contents.arraySize, fIn);
	

	

	return contents;
}





void writeFile(Array * contents, FILE * fOut){
	fprintf(fOut, "%s", contents->data);
}






char * getWord(char * stream, int wordStart, int wordSize){

	char * word;
	word = (char *)calloc(sizeof(char), wordSize + 1);

	int i;
	int j = 0;
	for (i = wordStart ; i < wordStart + wordSize; i++){
			word[j] = stream[i];
			j++;
		}
		word[wordSize] = 0;

	return word;	
}






Array StrToComrpessedBin(Array * contents){

	Array bitStream;
	bitStream.arraySize =  contents->arraySize * SIZE_BYTE;
	bitStream.data = (char *)calloc(sizeof(char), bitStream.arraySize);	

	int indexData = 0;	
	char * word;
	for ( indexData = 0; indexData < contents->arraySize; indexData++){
		word = decToBinCompressed((int)contents->data[indexData]);
		strcat(bitStream.data, word);		
	}
	free(word);

	strcat(bitStream.data, FLAG);
	bitStream.arraySize = strlen(bitStream.data);
	printf("%zu\n", bitStream.arraySize );
	char * pad;
	pad = padding(bitStream.arraySize % SIZE_BYTE);
	strcat(bitStream.data, pad);
	free(pad);
	bitStream.arraySize = strlen(bitStream.data);
	printf("%zu\n", bitStream.arraySize );

	
	char * newBitStream = realloc(bitStream.data, bitStream.arraySize * sizeof(char));
	bitStream.data = newBitStream;

	printf("%s\n",bitStream.data );

	return bitStream;
}


char * padding(int pad){
	char * word;
	word = (char *)calloc( sizeof(char), pad + 1);

	int i;
	for (i = 0; i < pad; ++i){
		strcat(word, "0");
	}

	return word;
}








Array BinStreamTocharStr(Array * bitStream){

	Array contents;
	contents.arraySize = bitStream->arraySize;
	contents.data = (char *)calloc(sizeof(char), contents.arraySize);	
	
	int indexData = 0;		
	char chrDec;
	char * word;
	long count = 0;
	for ( indexData = 0; indexData < bitStream->arraySize; indexData += SIZE_BYTE){
		word = getWord(bitStream->data, indexData, SIZE_BYTE);
		chrDec = (char)binToDec(word);
		sprintf(contents.data, "%s%c", contents.data, chrDec );
		// strcat(contents.data, chrDec);	
		free(word);	
		count++;
	}

	contents.arraySize = strlen(contents.data);
	char * newContents = realloc(contents.data, sizeof(char) * (contents.arraySize + 1));
	contents.data = newContents;
	
	printf("%ld\n%s\n",contents.arraySize, contents.data );
	return contents;

}



/*

	


*/
char * decToBinCompressed(int charCode) {	
	
	
	Boolean compress = ((charCode > ALPHA_LOWER_BOUND && 
						charCode < ALPHA_UPPER_BOUND) || 
						charCode == ALPHA_SPACE);	
	char * result;
	char * bitStream;
	bitStream = (char *)calloc(sizeof(char), SIZE_BYTE + 1);

	int i = SIZE_BYTE - 1;
	do {		
		bitStream[i--] = charCode % 2 + BASE_BINARY_CHAR;
		charCode /= 2;
	} while (charCode != 0);	
	while(i >= 0){
		bitStream[i--] = BASE_BINARY_CHAR;			
	}

	if (compress){		
		result = getWord(bitStream, 3, SIZE_BYTE);
	}else{
		result = (char *)calloc(sizeof(char), SIZE_DOUBLE_BYTE + 1);
		strcat(result,FLAG);
		strcat(result,bitStream);
	}

	return result;
}



int binToDec(char * binCode){

	int result = 0;
	int maxChar = 0;
	int power = 0;
	int digit = 0;

	char binTrimmed[strlen(binCode)];
	trimSpaces(binTrimmed, binCode);

	maxChar = strlen(binTrimmed);
	power = maxChar - 1;

	int index;
	for (index = 0; index < maxChar; index++){
		digit = binTrimmed[index] - BASE_BINARY_CHAR;
		result += (int) digit * pow(2.0, power);
		power--;
	}

	return result;
}






/* trim spaces from s string */
void trimSpaces(char * strOut, const char * strIn){

	while (*strIn != '\0'){
		if (!isspace(*strIn)){
			*strOut = *strIn;
			strOut++;
		}
		strIn++;
	}
	*strOut = '\0';
}

