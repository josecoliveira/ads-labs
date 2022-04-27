#ifndef GRAPH_H
#define GRAPH_H

// graph.h - declaration file for Graph structure

using namespace std;

#define NIL 0

// Adjacency list node
class Node {
public:
    int v;
    int wuv;
    Node *next;
};

class Graph {
public:
    int n;
    int *pi;
    Node **Adj;

    // Constructor
    Graph(int size);

    void readEdges();

    void computeMST();

    void printMST();

    // Utility routines - may be useful for debugging
    void showAdj();
};

#endif