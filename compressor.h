
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

/* defines */
#define MIN_LINE 1024 /* minimum line chars*/
#define FILE_MODE_READ "r" /* file mode for reading */
#define FILE_MODE_APPEND "a" /* file mode for appending */
#define MAX_ARGS 4 /* maximum amount of args in cmd*/


/* enumerators and constants */
enum error {NO_ERRORS, ERROR};
static const char * FILE_INPUT = "input.txt"; /* default input file */
static const char * FILE_OUTPUT = "output.dog"; /*default output file */



/* typedefs */

typedef enum bool {FALSE, TRUE} Boolean;
typedef struct line {
	char content[MIN_LINE];
} Line;

typedef struct arguments {
	const char * inputFile;
	const char * outputFile;
	Boolean decompress;
	int Error;
} Arguments;




/* function prototypes  compressLib*/
Boolean compressLine( Line * line);
Boolean decompressLine( Line * line);

/* function prototypes  arguments*/
void argumentsGet(const int, const char **, Arguments *);

#endif