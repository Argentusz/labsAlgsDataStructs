#include <string>

class Node {
    Node * left;
    Node  * middle;
public:
    Node() : left(nullptr), right(nullptr), middle(nullptr) { } // конструктор узла
    ~Node() { delete left; delete right; delete middle; }
    friend class Tree;

    char d{};
    Node * right;
};