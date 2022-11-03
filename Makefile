all: qsort

CC=gcc
CFLAGS= -std=c99 -g 
shellcode: qsort.o
			$(CC) $(CFLAGS) -o qsort qsort.o
shellcode.o:qsort.c
			$(CC) $(CFLAGS) -c qsort.c
						
clean:
			rm -f qsort.o
