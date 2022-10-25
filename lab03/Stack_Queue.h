template <class Item> class STACK {
private:
    Item * S;
    int t;
public:
    explicit STACK(int maxT) : S(new Item[ maxT ]), t(0) {}
    int empty() const {
        return t == 0;
    }
    void push(Item item) {
        S[t++] = item;
    }
    Item pop() {
        return ( t ? S[ --t ] : 0 );
    }
};

template <class Item> class QUEUE {
    Item * Q;
    int h;
    int t;
    int N;
public:
    explicit QUEUE(int maxQ): h(0), t(0), N(maxQ), Q(new Item[maxQ + 1]) {}
    int empty() const {
        return (h % N) == t;
    }
    void push(Item item) {
        Q[ t++ ] = item; t %= N;
    }
    Item pop() {
        h %= N; return Q[ h++ ];
    }
    Item next() {
        return Q[h];
    }
};