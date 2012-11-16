CC=gcc
CFLAGS=-Wall -g -std=c11

LDFLAGS=-lm

all: euler001 euler002 euler003 factor

euler003: algebra.o

factor: algebra.o
	$(CC) $(CFLAGS) $(LDFLAGS) -DFACTOR $^  euler003.c -o $@

clean: 
	rm -f euler00{1..3} factor *.o
