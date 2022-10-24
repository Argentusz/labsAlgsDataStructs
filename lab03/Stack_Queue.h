template <class Item> class STACK
{ Item * S; int t;
public:
    STACK(int maxt) : S(new Item[ maxt ]), t( 0 ) { }
    int empty( ) const { return t == 0; }
    void push(Item item) { S[t++] = item; }
    Item pop( ) {return ( t ? S[ --t ] : 0 ); }
};

template <class Item> class QUEUE
{	Item * Q; int h, t, N;
public:
    QUEUE(int maxQ): h(0), t(0), N(maxQ), Q(new Item[maxQ + 1]) { }
    int empty( ) const { return (h % N) == t; }
    void push(Item item) { Q[ t++ ] = item; t %= N; }
    Item pop( ) { h %= N; return Q[ h++ ]; }
};