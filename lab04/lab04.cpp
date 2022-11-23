#include "Graph.h"
#include <iostream>

int main() {
    Graph G{5};
    G.MatrixScan();
    Graph G2{5};
    G2.MatrixScan();
    if (G.isTree() && G2.isTree()) {
        G.MatrixPrintln();
        G2.MatrixPrintln();
        if (G.isIsomorphicTo(G2))  std::cout << "Isomorphic";
        else  std::cout << "Not isomorphic";
    } else  std::cout << "Graph is not a tree";
}
