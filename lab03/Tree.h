#include <vector>
#include "Node.h"



class Tree {
    int rowLen = 80;
    int Nmax = 26;
    Node * root;
    char startName, endName;
    int maxRowAmount, offset;
    std::vector<std::string> display;
    void clrScr();
    Node* MakeNode(int depth);
    void OutNodes(Node * v, int r, int c);
    Tree (const Tree &);
public:
    Tree(char minName, char maxName, int maxRow);
    ~Tree();
    Tree operator = (const Tree &) const = delete;
    void MakeTree() {
        root = MakeNode(0);
    }
    bool exist() {
        return root != nullptr;
    }
    std::string DFS();	// обход дерева «в глубину»
    std::string BFS();	// обход «в ширину»
    int DFSIF(const std::function<bool(Node*)>&);
    void OutTree();	// выдача на экран
};