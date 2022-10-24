#include <string>

class Node {
    char d{};
    Node * left;
    Node  * middle;
    Node * right;
public:
    Node() : left(nullptr), right(nullptr), middle(nullptr) { } // конструктор узла
    ~Node() { delete left; delete right; delete middle; }
    friend class Tree;
};