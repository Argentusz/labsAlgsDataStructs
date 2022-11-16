#include <vector>


class Graph {
private:
    int N;
    std::vector< std::vector<bool> > matrix;
    int root;
    std::vector <int> powers;
    std::vector <int> parents;
    void fillParents();
    void _fillParents(int, int);
public:
    Graph();
    explicit Graph(int, int);
    explicit Graph(int);
    void MatrixPrintln();
    void Connect(int, int);
    void Disconnect(int, int);
    void MatrixScan();
    bool isTree();
    bool isIsomorphicTo(Graph&);
    std::vector<int> FindChildren(int);
};
