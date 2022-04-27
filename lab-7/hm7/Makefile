#################################################################
#
#
#  Files:
#  driver.cpp       The main program
#
#  graph.h          The header file for the Graph class
#  graph.cpp        The implemention file for the Graph class
#
#  driver	    The executable program
#
##################################################################

CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = driver

all: $(TARGETS)


# Link the object files:

driver: driver.o graph.o pqueue.o
	$(CC) -o $@ driver.o graph.o pqueue.o

# Compile the C++ files into object files

driver.o: driver.cpp graph.h pqueue.h
	$(CC) $(CFLAGS) driver.cpp 

graph.o: graph.cpp graph.h 
	$(CC) $(CFLAGS) graph.cpp 

pqueue.o: pqueue.cpp pqueue.h 
	$(CC) $(CFLAGS) pqueue.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f driver
