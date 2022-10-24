#include "Tree.h"
#include <iostream>
#include <cstring>
#include "Stack_Queue.h"
#include <random>



Tree ::	Tree(char nm, char maxNum, int maxRow): startName{nm}, endName{maxNum}, maxRowAmount{maxRow}, offset{rowLen / 2},
root{nullptr}, SCREEN{new char * [maxRowAmount]} {
    for(int i = 0; i < maxRowAmount; ++i ) SCREEN[i] = new char[rowLen];
}

Tree :: ~Tree( ) {
    for(int i = 0; i < maxRowAmount; ++i) delete []SCREEN[i];
    delete [ ]SCREEN;
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
        SCREEN[i][rowLen - 1] = 0;
        std::cout << '\n' << SCREEN[ i ];
    }
    std::cout << '\n';
}

void Tree :: OutNodes(Node * v, int r, int c) {
    if (r && c && (c<rowLen)) SCREEN[r-1][c-1] = v->d;// вывод метки
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
    QUEUE < Node * > Q(MaxQ);
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

void Tree :: clrScr( ) {
    for(int i = 0; i < maxRowAmount; i++) {
        memset(SCREEN[i], '.', rowLen);
    }
}