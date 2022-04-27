// pqueue.cpp - implementation file for PQueue Data structure
#include "pqueue.h"
#include <iostream>
#include <iomanip>

using namespace std;

PQueue::PQueue(int len) {
    length = len;
    size = 0;

    key = new int[length + 1];
    inQ = new bool[length + 1];
    for (int i = 1; i <= length; i++)
        inQ[i] = false;
}

void PQueue::insert(int k) {
    size++;
    key[size] = k;
    inQ[size] = true;
}

int PQueue::extractMin() {
    /// YOU IMPLEMENT THIS
}

void PQueue::decreaseKey(int u, int k) {
    // No error checking for actual decrease of key
    key[u] = k;
}

void PQueue::showPQueue() {
    cout << "The contents of the priority queue Q:\nIndices:   ";
    for (int i = 1; i <= size; i++) {
        if (inQ[i]) cout << setw(5) << i;
    }
    cout << "\nKey values:";
    for (int i = 1; i <= size; i++) {
        if (inQ[i]) cout << setw(5) << key[i];
    }
    cout << "\n\n";
}