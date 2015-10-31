all: test

test: reed-solomon.o galois.o

clean:
	rm -f *.o
