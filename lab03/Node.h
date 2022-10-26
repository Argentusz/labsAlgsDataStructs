#include <string>

class Node {
    Node * left;
    Node * middle;
    Node * right;
public:
    enum Directions {
        Left,
        Middle,
        Right
    };
    Node() : left(nullptr), right(nullptr), middle(nullptr) { } // конструктор узла
    ~Node() { delete left; delete right; delete middle; }
//    bool exists(Directions);
    friend class Tree;
    char d{};
};

//bool Node::exists(Node::Directions s) {
//    switch (s) {
//        case Left:
//            if (this->left != nullptr) return true;
//        case Right:
//            if (this->right != nullptr) return true;
//        case Middle:
//            if (this->middle != nullptr) return true;
//    }
//    return false;
//}
