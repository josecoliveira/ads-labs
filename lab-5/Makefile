CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = cmdint

all: $(TARGETS)


# Link the object files:

cmdint: cmdint.o rbtree.o
	$(CC) -o $@ cmdint.o rbtree.o


# Compile the C++ files into object files

cmdint.o: cmdint.cpp rbtree.h
	$(CC) $(CFLAGS) cmdint.cpp 

rbtree.o: rbtree.cpp rbtree.h
	$(CC) $(CFLAGS) rbtree.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f cmdint
