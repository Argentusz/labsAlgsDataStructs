#include "Tree.h"
#include <iostream>
#include <cstring>
#include "Stack_Queue.h"
Tree ::	Tree(char nm, char mnm, int mxr):
        num(nm), maxnum(mnm), maxrow(mxr), offset(40), root(nullptr),
        SCREEN(new char * [maxrow]) {
    for(int i = 0; i < maxrow; ++i ) SCREEN[ i ] = new char[ 80 ];
}

Tree :: ~Tree( ) {
    for(int i = 0; i < maxrow; ++i) delete [ ]SCREEN[ i ];
    delete [ ]SCREEN; delete root;
}

Node * Tree :: MakeNode(int depth) {
    Node * v = nullptr;
    int Y = (depth < rand( )%6+1) && (num <= 'z');
    if (Y) {	// создание узла, если Y = 1
        v = new Node;
        v->lft = MakeNode(depth+1);
        v->rgt = MakeNode(depth+1);
        v->mdl = MakeNode(depth+1);
        v->d = num++;
    }
    return v;
}

void Tree :: OutTree( ) {
    clrscr( );
    OutNodes(root, 1, offset);
    for (int i = 0; i < maxrow; i++) {
        SCREEN[ i ][ 79 ] = 0;
        std::cout << '\n' << SCREEN[ i ];
    }
    std::cout << '\n';
}

void Tree :: OutNodes(Node * v, int r, int c) {
    if (r && c && (c<80)) SCREEN[r-1][c-1] = v->d;// вывод метки
    if (r < maxrow) {
        if (v->lft) OutNodes(v->lft, r + 1, c - (offset >> r)); //левый сын
        if (v->mdl) OutNodes(v->mdl, r + 1, c);	//средний сын
        if (v->rgt) OutNodes(v->rgt, r + 1, c + (offset >> r)); //правый сын
    }
}

int Tree :: DFS() {
    const int MaxS = 20; // максимальный размер стека
    int count = 0;
    STACK <Node *> S(MaxS);  //создание стека указателей на узлы
    S.push(root);           // STACK <- root
    while (!S.empty( ))  // Пока стек не пуст…
    {   Node * v = S.pop( );                       // поднять узел из стека
        std::cout << v->d <<  '_'; count++;       // выдать тег, счёт узлов
        if (v->rgt) S.push(v->rgt);               // STACK <- (правый сын)
        if (v->lft) S.push(v->lft);               // STACK <- (левый сын)
        if (v->mdl) S.push(v->mdl);
    }
    return count;
}
int Tree :: BFS() {
    const int MaxQ = 20; //максимальный размер очереди
    int count = 0;
    QUEUE < Node * > Q(MaxQ);  //создание очереди указателей на узлы
    Q.push(root); // QUEUE <- root поместить в очередь корень дерева
    while (!Q.empty( )) //пока очередь не пуста
    { 	Node * v = Q.pop( );// взять из очереди,
        std::cout << v->d << '_'; count++; // выдать тег, счёт узлов
        if (v->lft) Q.push(v->lft); // QUEUE <- (левый сын)
        if (v->rgt) Q.push(v->rgt);// QUEUE <- (правый сын)
        if (v->mdl) Q.push(v->mdl);//QUEUE <- (средний сын)
    }
    return count;
}

void Tree :: clrscr( )
{ for(int i = 0; i < maxrow; i++)
        memset(SCREEN[i], '.', 80);
}