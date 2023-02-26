CC	= gcc
PROGS	= generate mergesort insertionsort

generate:	generate.o
	$(CC) -o generate generate.o

mergesort:	mergesort.o
	$(CC) -o mergesort mergesort.o

insertionsort:	insertionsort.o
	$(CC) -o insertionsort insertionsort.o
