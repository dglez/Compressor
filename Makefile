# make file for the program

CC = gcc
FLAGS = -Wal -w
EXE = compressor
HEADER = compressor.h
OBJS = compressor.o compressLib.o
SOURCE = compressor.c compressLib.c


$(EXE):	$(OBJS)
		$(CC) $(FLAGS) $(SOURCE) -o $(EXE)

compressor.o: $(HEADER)
compressLib.o: $(HEADER)

.PHONY:	clean
clean:
	rm *.o