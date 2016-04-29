
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <stdio.h>
#include <stdlib.h>

/* defines */
#define MIN_LINE 1024 				/* minimum line chars*/
#define FILE_MODE_READ "r" 			/* file mode for reading */
#define FILE_MODE_APPEND "a" 		/* file mode for appending */
#define MAX_ARGS 4 					/* maximum amount of args in cmd*/
#define SIZE_BYTE 8					/* amount of bits in a byte */
#define SIZE_DOUBLE_BYTE 16 		/* amount of bits in a uncompressed char with flag */
#define SIZE_COMPRESSED 5			/* amount of bits of a compressed char */ 
#define BASE_BINARY_CHAR '0'		/* character used as base binary*/
#define ALPHA_SPACE 32					/* decimal value of space character */
#define ALPHA_LOWER_BOUND 96		/* decimal value of lower character to compress */
#define ALPHA_UPPER_BOUND	128		/* decimal value of higher character to compress */
#define FLAG "11111111"				/* not compressed character flag */
#define PAD_STR "0"

	


/* enumerators and constants */
enum error {NO_ERRORS, ERROR};
static const char * FILE_INPUT = "input.txt"; /* default input file */
static const char * FILE_OUTPUT = "output.dog"; /*default output file */



/* typedefs */

typedef enum bool {FALSE, TRUE} Boolean;


typedef struct array{
	char * data;
	size_t arraySize;
	
}Array;

typedef struct arguments {
	const char * inputFile;
	const char * outputFile;
	Boolean decompress;
	int Error;
} Arguments;




/* function prototypes  compressLib*/

Array StrToComrpessedBin(Array *);
Array BinStreamTocharStr(Array * );
char * decToBinCompressed(int);
char * getWord(char * , int , int );
char * padding(int);

Array readFile(FILE *);
void writeFile(Array * , FILE *);

int binToDec(char *);
void trimSpaces(char * , const char * );


/* function prototypes  DecompressLib.c */
Array StrToDecomrpessedBin(Array * );
char * decToBin(unsigned char);





/* function prototypes  arguments*/
void argumentsGet(const int, const char **, Arguments *);

#endif