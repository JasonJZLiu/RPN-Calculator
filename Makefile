CC=gcc
MAKE=make
SHELL=/bin/sh

LDFLAGS=-lm

all : calc

calc : main.o calc.o stack.o
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

main.o : main.c calc.h stack.h
	$(CC) -o $@ -c $< $(INC) $(CFLAGS)
	
calc.o : calc.c calc.h stack.h
	$(CC) -o $@ -c $< $(INC) $(CFLAGS)

stack.o : stack.c stack.h
	$(CC) -o $@ -c $< $(INC) $(CFLAGS)


clean :
	rm -f *.o
	rm -f calc
	
.PHONY : all clean

