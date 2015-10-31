all: test

test: reed-solomon.o galois.o

reed-solomon.o: reed-solomon.c reed-solomon.h galois.h utils.h galois.o

galois.o: galois.c galois.h utils.h

clean:
	rm -f *.o
