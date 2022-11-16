#include "Tree.h"
#include <iostream>
#include <cstring>
#include "Stack_Queue.h"
#include <random>
#include <functional>



Tree ::	Tree(char minName, char maxName, int maxHeight, int maxWid):
startName{minName}, endName{maxName},
maxRowAmount{maxHeight}, rowLen{maxWid}, offset{rowLen/2},
root{nullptr}, display{},
Nmax{maxName - minName + 1} {}

Tree::Tree(int maxWid) : startName{'a'}, endName{'z'},
                         rowLen{maxWid}, maxRowAmount{5}, offset{rowLen/2},
                         display{},
                         Nmax{'z' - 'a' + 1} {
    auto r = new Node;
    std::cout << "Имя: ";
    std::cin >> r->d;
    root = r;
    auto choises = new bool[3];
    std::cout << "Левая вершина(1/0): ";
    std::cin >> choises[0];
    std::cout << "Центральная вершина(1/0): ";
    std::cin >> choises[1];
    std::cout << "Правая вершина(1/0): ";
    std::cin >> choises[2];

    if (choises[0]) r->left = NodeFromStdin();
    else r->left = nullptr;
    if (choises[1]) r->middle = NodeFromStdin();
    else r->middle = nullptr;
    if (choises[2]) r->right = NodeFromStdin();
    else r->right = nullptr;
}

Node *Tree::NodeFromStdin() {
    auto r = new Node;
    auto choises = new bool[3];
    std::cout << "Имя: ";
    std::cin >> r->d;
    std::cout << "Левая вершина(1/0): ";
    std::cin >> choises[0];
    std::cout << "Центральная вершина(1/0): ";
    std::cin >> choises[1];
    std::cout << "Правая вершина(1/0): ";
    std::cin >> choises[2];

    if (choises[0]) r->left = NodeFromStdin();
    else r->left = nullptr;
    if (choises[1]) r->middle = NodeFromStdin();
    else r->middle = nullptr;
    if (choises[2]) r->right = NodeFromStdin();
    else r->right = nullptr;

    return r;
}


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
        std::cout << '\n' << display[ i ];
    }
    std::cout << '\n';
}



void Tree :: OutNodes(Node * v, int r, int c) {
    if (r && c && (c<rowLen)) display[r - 1][c - 1] = v->d;// вывод метки
    if (r < maxRowAmount) {
        if (v->left) OutNodes(v->left, r + 1, c - (offset >> r) - 3); //левый сын
        if (v->middle) OutNodes(v->middle, r + 1, c);	//средний сын
        if (v->right) OutNodes(v->right, r + 1, c + (offset >> r) + 3); //правый сын
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
    int height;
    for(height = 0; temp != 0; height++) {
        temp = rows[height];
    }
    height--;
    maxRowAmount = height;
    offset = rowLen / 2;
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

std::string Tree::IS(Node * root) {
    std::string temp{};
    if (root->left) temp += IS(root->left);
    if (root->middle) temp+= IS(root->middle);
    temp += root->d;
    temp += "_";
    if (root->right) temp += IS(root->right);
    return temp;
}

void Tree::OutTree2() {
    clrScr();
    OutNodes(root, 1, offset);
    for (int i = maxRowAmount; i >= 0; i--) {
        std::cout << '\n' << display[ i ];
    }
    std::cout << '\n';
}


