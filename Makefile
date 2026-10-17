CC = gcc
CFLAGS = -Wall -g -Ilib
LIB_DIR = lib

all: main

main: main.c
	$(CC) -c $(LIB_DIR)/add.c $(LIB_DIR)/sub.c
	ar rcs libcalc.a add.o sub.o
	$(CC) $(CFLAGS) main.c -L. -lcalc -o main

clean:
	rm -f *.o *.a main
