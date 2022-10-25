#include "Tree.h"
#include <iostream>
#include <cstring>
#include "Stack_Queue.h"
#include <random>
#include <functional>



Tree ::	Tree(char minName, char maxName):
startName{minName}, endName{maxName},
maxRowAmount{8}, rowLen{80}, offset{rowLen/2},
root{nullptr}, display{},
Nmax{maxName - minName + 1} {}

Tree :: ~Tree( ) {
    std::vector<std::string>().swap(display);
    delete root;
}

Node * Tree :: MakeNode(int depth) {
    Node * v = nullptr;
    std::random_device randomDevice{};
    std::uniform_int_distribution<int> dist(1, maxRowAmount);
    if ((depth < dist(randomDevice)) && (startName <= endName)) {
        v = new Node;
        v->d = startName++;
        v->left = MakeNode(depth + 1);
        v->right = MakeNode(depth + 1);
        v->middle = MakeNode(depth + 1);
    }
    return v;
}

void Tree :: OutTree( ) {
    clrScr();
    OutNodes(root, 1, offset);
    for (int i = 0; i < maxRowAmount; i++) {
        display[i][rowLen - 1] = 0;
        std::cout << '\n' << display[ i ];
    }
    std::cout << '\n';
}

void Tree :: OutNodes(Node * v, int r, int c) {
    if (r && c && (c<rowLen)) display[r - 1][c - 1] = v->d;// вывод метки
    if (r < maxRowAmount) {
        if (v->left) OutNodes(v->left, r + 1, c - (offset >> r)); //левый сын
        if (v->middle) OutNodes(v->middle, r + 1, c);	//средний сын
        if (v->right) OutNodes(v->right, r + 1, c + (offset >> r)); //правый сын
    }
}

std::string Tree :: DFS() {
    const int MaxS = Nmax;
    std::string str{};
    STACK <Node *> S(MaxS);
    S.push(root);
    while (!S.empty( )) {
        Node * v = S.pop( );
        str += v->d;
        str += '_';
        if (v->right) S.push(v->right);
        if (v->left) S.push(v->left);
        if (v->middle) S.push(v->middle);
    }
    return str;
}
std::string Tree :: BFS() {
    const int MaxQ = Nmax;
    std::string str{};
    QUEUE <Node*> Q(MaxQ);
    Q.push(root);
    while (!Q.empty( )) {
        Node * v = Q.pop( );
        str += v->d;
        str += '_';
        if (v->left) Q.push(v->left);
        if (v->right) Q.push(v->right);
        if (v->middle) Q.push(v->middle);
    }
    return str;
}

int* Tree :: rowVertices() {
    int* rows = new int[Nmax];
    std::memset(rows, 0, Nmax * 4);
    QUEUE<Node*> Q(Nmax);
    QUEUE<int> level(Nmax);
    Q.push(root);
    level.push(1);
    while (!Q.empty( )) {
        Node * v = Q.pop();
        if (v->left) { Q.push(v->left); level.push(level.next() + 1);}
        if (v->right) { Q.push(v->right);level.push(level.next() + 1);}
        if (v->middle) { Q.push(v->middle);level.push(level.next() + 1);}
        rows[level.pop() - 1]++;
    }
    return rows;
}

void Tree :: clrScr( ) {
    auto rows = rowVertices();
    int temp = -1;
    int width = -1;
    int height;
    for(height = 0; temp != 0; height++) {
        temp = rows[height];
        if (width < temp) width = temp;
    }
    height--;
    std:: cout << "Width: " << width << "Height: " << height << "\n";
    for(int i = 0; i < maxRowAmount; i++) {
        display.emplace_back(rowLen, '.');
    }
}

int Tree::DFSIF(const std::function<bool(Node *)>& ifFunc) {
    const int MaxS = Nmax;
    int res{};
    STACK <Node *> S(MaxS);
    S.push(root);
    while (!S.empty( )) {
        Node * v = S.pop( );
        if(ifFunc(v)) res++;
        if (v->right) S.push(v->right);
        if (v->left) S.push(v->left);
        if (v->middle) S.push(v->middle);
    }
    return res;
}
