CC=gcc
CFLAGS=-Wall -g -std=c11

LDFLAGS=-lm

all: euler001 euler002 euler003

euler003: algebra.o

clean: 
	rm -f euler001
