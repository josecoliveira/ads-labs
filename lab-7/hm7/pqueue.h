#ifndef PQUEUE_H
#define PQUEUE_H

// pqueue.h - declaration file for PQueue data structure
using namespace std;

#define INFINITY 1000

typedef int KeyType;

class PQueue {
public:
    int length;
    int size;

    int *key;
    bool *inQ;

    // Constructor
    PQueue(int len);

    void insert(int k);

    int extractMin();

    void decreaseKey(int u, int k);

    // Utility routine - may be useful for debugging
    //bool empty() ;
    void showPQueue();

};

#endif