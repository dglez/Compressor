# make file for the program

CC = gcc
FLAGS = -Wall -w
EXE = compressor
HEADER = compressor.h
OBJS = compressor.o compressLib.o decompressLib.o
SOURCE = compressor.c compressLib.c decompressLib.c
LIBS = -lc -lm


$(EXE):	$(OBJS)
		$(CC) $(FLAGS) $(SOURCE) -o $(EXE) $(LIBS)

compressor.o: $(HEADER)
compressLib.o: $(HEADER)

.PHONY:	clean
clean:
	rm *.o