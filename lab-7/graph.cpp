// graph.cpp - implementation file for Graph structure
#include "graph.h"
#include "pqueue.h"
#include <iostream>
#include <iomanip>

// using namespace std ;
#include <vector>
#include <map>

Graph::Graph(int size) {
    int i, j;

    n = size;
    pi = new int[n + 1];
    Adj = new Node *[n + 1];
    for (i = 1; i <= n; i++) {
        Adj[i] = NIL;
    }
}

// Read a graph from input
void Graph::readEdges() {
    int u, v, wt;

    cin >> u >> v >> wt;
    while (!cin.eof()) {
        Node *x = new Node;
        x->v = v;
        x->wuv = wt;
        x->next = Adj[u];
        Adj[u] = x;
        cin >> u >> v >> wt;
    }
}

void Graph::computeMST() {
    /// YOU IMPLEMENT THIS
}

void Graph::printMST() {
    for (int u = 1; u <= n; u++) {
        if (pi[u] != 0) cout << u << " -- " << pi[u] << endl;
    }
}

void Graph::showAdj() {
    cout << "The Adjacency lists:\n";
    for (int v = 1; v <= n; v++) {
        cout << "Adj[" << v << "]";
        for (Node *x = Adj[v]; x != NIL; x = x->next) {
            cout << "->[" << x->v << "," << x->wuv;
            cout << "]";
        }
        cout << endl;
    }
    cout << "\n\n";
}