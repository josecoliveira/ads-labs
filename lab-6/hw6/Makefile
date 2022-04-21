#################################################################
#
#  Makefile for Dynamic Programming Assignment, CS 5521, Spring 2020
#
#  Files:
#  driver.cpp       The main program
#
#  alignment.h        The header file for the alignment calculator
#  alignment.cpp      The implemention file for the alignment calculator
#
#  align	    The executable program
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = align

all: $(TARGETS)


# Link the object files:

align: driver.o alignment.o progbar.o
	$(CC) -o $@ driver.o alignment.o progbar.o


# Compile the C++ files into object files

driver.o: driver.cpp alignment.h
	$(CC) $(CFLAGS) driver.cpp 

progbar.o: progbar.cpp progbar.h
	$(CC) $(CFLAGS) progbar.cpp 

alignment.o: alignment.cpp alignment.h table.h
	$(CC) $(CFLAGS) alignment.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f align
