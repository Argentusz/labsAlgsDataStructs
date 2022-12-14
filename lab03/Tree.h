#include <vector>
#include "Node.h"



class Tree {
    int rowLen;
    int Nmax;
    Node * root;
    char startName, endName;
    int maxRowAmount, offset;
    std::vector<std::string> display;
    void clrScr();
    Node* MakeNode(int depth);
    void OutNodes(Node * v, int r, int c);
    Tree (const Tree &);
public:
    Tree(char minName, char maxName, int maxHeight = 8, int maxWid = 131);
    explicit Tree(int maxWid = 131);
    static Node * NodeFromStdin();
    ~Tree();
    Tree operator = (const Tree &) const = delete;
    void MakeTree() {
        root = MakeNode(0);
    }
    bool exist() {
        return root != nullptr;
    }
    Node * Root() {
        return root;
    }
    std::string DFS();	// обход дерева «в глубину»
    std::string BFS();	// обход «в ширину»
    std::string IS(Node *);
    int DFSIF(const std::function<bool(Node*)>&);
    int* rowVertices();
    void OutTree();	// выдача на экран
    void OutTree2();
};