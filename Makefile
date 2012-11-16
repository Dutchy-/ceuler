CC=gcc
CFLAGS=-Wall -g -std=c11

LDFLAGS=-lm

all: euler001 euler002 euler003 factor

euler003: algebra.o

euler004: str_util.o

factor: algebra.o
	$(CC) $(CFLAGS) $(LDFLAGS) -DFACTOR $^  euler003.c -o $@

clean: 
	rm -f euler00{1..4} factor *.o
