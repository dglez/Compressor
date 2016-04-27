
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <stdio.h>
#include <stdlib.h>

/* defines */
#define MIN_LINE 1024 				/* minimum line chars*/
#define FILE_MODE_READ "r" 			/* file mode for reading */
#define FILE_MODE_APPEND "a" 		/* file mode for appending */
#define MAX_ARGS 4 					/* maximum amount of args in cmd*/
#define BYTE_SIZE 8					/* amount of bits in a byte */ 
#define BASE_BINARY_CHAR '0'		/* character used as base binary*/


/* enumerators and constants */
enum error {NO_ERRORS, ERROR};
static const char * FILE_INPUT = "input.txt"; /* default input file */
static const char * FILE_OUTPUT = "output.dog"; /*default output file */



/* typedefs */

typedef enum bool {FALSE, TRUE} Boolean;


typedef struct array{
	char * data;
	long arraySize;
	
}Array;

typedef struct arguments {
	const char * inputFile;
	const char * outputFile;
	Boolean decompress;
	int Error;
} Arguments;




/* function prototypes  compressLib*/
void streamCompress( Array *);
Boolean lineDecompress( char *);
Array readFile(FILE *);
char * decToBin(int);
Array binaryStream(Array *);



/* function prototypes  arguments*/
void argumentsGet(const int, const char **, Arguments *);

#endif