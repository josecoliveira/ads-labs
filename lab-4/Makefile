#################################################################
#
#  Makefile for Fibonacci Heap program, CS 4122/5122, Spring 2021
#
#  Files:
#  cmdint.cc     The main program - the command interpreter
#
#  fibheap.h      The header file for the Fibonacci Heap class
#  fibheap.cc    The implemention file for the Fibonacci Heap class
#
#  cmdint	  The executable program
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint

all: $(TARGETS)


# Link the object files:

cmdint: cmdint.o fibheap.o
	$(CC) -o $@ cmdint.o fibheap.o


# Compile the C++ files into object files

cmdint.o: cmdint.cc fibheap.h
	$(CC) $(CFLAGS) cmdint.cc 

fibheap.o: fibheap.cc fibheap.h
	$(CC) $(CFLAGS) fibheap.cc 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
