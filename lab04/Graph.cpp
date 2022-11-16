#include <iostream>
#include "Graph.h"
#include <set>

Graph::Graph(int n) : N(n), matrix(N), powers(N), parents(N) {
    for (auto i = 0; i < N; i++) {
        matrix[i].resize(N);
    }
}

Graph::Graph() : N(9), matrix(N), powers(N), parents(N) {
    for (auto i = 0; i < N; i++) {
        matrix[i].resize(N);
    }
}

void Graph::MatrixPrintln() {
    std::cout << "    ";
    for (auto i = 1; i < N + 1; i++) std::cout << i << " ";
    std::cout << "\n";
    for (auto i = 0; i < N; i++) std::cout << "---";
    std::cout << "\n";
    for (auto i = 0; i < N; i++) {
        if (root == i+1) std::cout << i+1 << "*| ";
        else std::cout << i+1 << " | ";
        for(auto j = 0; j < N; j++) std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Graph::Connect(int i, int j) {
    matrix[i][j] = true;
    matrix[j][i] = true;
}

void Graph::Disconnect(int i, int j) {
    matrix[i][j] = false;
    matrix[j][i] = false;
}

void Graph::MatrixScan() {
    std::cout << "    ";
    for (auto i = 1; i < N + 1; i++) std::cout << i << " ";
    std::cout << "\n";
    for (auto i = 0; i < N; i++) std::cout << "---";
    std::cout << "\n";
    for (auto i = 0; i < N; i++) {
        std::cout << i+1 << " : ";
        for (auto j = 0; j <= i; j++) std::cout << this->matrix[i][j] << " ";
        for (auto j = i + 1; j < N; j++) {
            bool temp;
            std::cin >> temp;
            if (temp) this->Connect(i, j);
        }
    }
    std::cout << "\nRoot: ";
    int temp;
    std::cin >> temp;
    root = temp -1;
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < N; j++)
            if (matrix[i][j]) powers[i]++;

    this->fillParents();

    std::cout << "\n";
}

void Graph::fillParents() {
    int parent = -1;
    auto curr = this->root;
    this->parents[this->root] = parent;
    std::vector<int> children{};
    // Find children of root
    // Sign their parents as root
    // Send Recursive chain with known parent (root child at first)
    for (auto child = 0; child < N; child++) {
        if (child != parent && this->matrix[curr][child]) {
            this->parents[child] = curr;
            children.push_back(child);
        }
    }
    for (int i : children) {
        _fillParents(i, curr);
    }
}


void Graph::_fillParents(int curr, int parent) {
    std::vector<int>children{};
    for (auto child = 0; child < N; child++) {
        if (child != parent && this->matrix[curr][child]) {
            this->parents[child] = curr;
            children.push_back(child);
        }
    }
    for (int i : children) {
        _fillParents(i, curr);
    }
}


bool Graph::isTree() {
    int cons = 0;
    for (auto i = 0; i < N; i++) {
        for (auto j = i + 1; j < N; j++) {
            if (matrix[i][j]) cons++;
        }
    }
    if (cons + 1 == N) return true;
    return false;
}

bool Graph::isIsomorphicTo(Graph& B) {
    if (this->N != B.N) return false;
    if (this->matrix == B.matrix) return true;
    if (this->powers[this->root] == B.powers[B.root]) {
        // Find Children of node
        // Find if set of their powers equals
        // Find Children of children
        std::vector<int> currA;
        std::vector<int> currB;
        currA.push_back(this->root);
        currB.push_back(B.root);
        while (true) {
            std::vector<int> ChildrenA;
            std::vector<int> ChildrenB;
            for (auto x : currA) {
                auto temp = this->FindChildren(x);
                ChildrenA.insert(ChildrenA.begin(), temp.begin(), temp.end());
            }
            for (auto x : currB) {
                auto temp = B.FindChildren(x);
                ChildrenB.insert(ChildrenB.begin(), temp.begin(), temp.end());
            }
            std::set<int> currPowA{};
            std::set<int> currPowB{};
            for (auto x : ChildrenA) {
                currPowA.insert(this->powers[x]);
            }
            for (auto x : ChildrenB) {
                currPowB.insert(B.powers[x]);
            }
            if (currPowA.empty() && currPowB.empty()) {
                return true;
            } else if (currPowA == currPowB) {
                currA = ChildrenA;
                currB = ChildrenB;
            } else {
                return false;
            }
        }
    }
}


Graph::Graph(int n, int r): N(n), root(r), matrix(N), powers(N), parents(N) {
    for (auto i = 0; i < N; i++) {
        matrix[i].resize(N);
    }
}

std::vector<int> Graph::FindChildren(int node) {
    std::vector<int> res{};
    for (auto i = 0; i < N; i++)
        if (matrix[node][i] && i != parents[node])
            res.push_back(i);
    return res;
}




