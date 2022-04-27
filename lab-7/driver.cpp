// driver.cpp - driver program to run Graph algorithms
#include "graph.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int numVertices, source;
    cin >> numVertices;
    Graph G(numVertices);
    G.readEdges();

    //cout << "Built graph, n = " << G.n << "\n\n" ;
    //G.showAdj() ;

    //cout << "Running Prim's" << endl;
    G.computeMST();
    G.printMST();

    return 0;
}