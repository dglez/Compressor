#include <string.h>
#include "compressor.h"

int main(int argc, char const *argv[]){

	Arguments arg;
	FILE * fIn;
	FILE * fOut;
	Array contents;
	Array compressedStream;
	Array compressedContent;
	Array decompressedStream;
	Array decompressedContent;


	argumentsGet(argc, argv, &arg);

	if (arg.Error == NO_ERRORS) {

		// TODO:Check for errors and for input/output
		
		
		

		// read file
		fIn = fopen(arg.inputFile, FILE_MODE_READ);
		contents = readFile(fIn);
		fclose(fIn);

		// compressed
		compressedStream = StrToComrpessedBin(&contents);
		printf("%s\n",compressedStream.data );
		compressedContent = BinStreamTocharStr(&compressedStream);
		decompressedStream = StrToDecomrpessedBin(&compressedContent);
		printf("%s\n",decompressedStream.data );
		printf("\n");

		decompressedContent = binToDecompressedContent(&decompressedStream);

		printf("%s\n",decompressedContent.data );


		


		// write processed line to compressed file
		fOut = fopen(arg.outputFile, FILE_MODE_APPEND);	
		writeFile(&compressedContent, fOut);
		fclose(fOut);

		
		// Free memory 

		
		

	}else{

	}


	return NO_ERRORS;
}