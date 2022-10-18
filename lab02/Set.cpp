#include <iostream>
#include "Set.h"

Set & Set :: operator & (const Set & B) const
{ Set *C = new Set;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B.n; j++)
            if (A[ i ] == B.A[ j ]) C->A[ C->n++ ] = A[ i ];
    }
    C->A[C->n ] = 0; // ограничитель строки
    return *C;
};

Set & Set :: operator | (const Set & B) const
{ Set *C = new Set;
    memcpy(C->A, A, n); C->n = n;
    for(int i = 0; i < B.n; i++) {
        bool f = true;
        for (int j = 0; j < n; j++)
            if (B.A[ i ] == A[ j ]) f = false;
        if ( f ) C->A[ C->n++ ] = B.A[ i ];
    }
    C->A[ C->n ] = 0;
    return *C;
}

Set & Set :: operator ~ ( ) const
{ Set *C = new Set;
    for (char c = 'A'; c <= 'Z'; c++) {
        bool f = true;
        for (int j = 0; j < n; j++)
            if (c == A[ j ]) { f = false; break; }
        if ( f ) C->A[ C->n++ ] = c;
    }
    C->A[ C->n ] = 0;
    return *C;
}

void Set :: Show()
{ std::cout << '\n' << S << " = [" << A << "]"; }

Set :: Set( ): n(0), S ('0'), A(new char[ N+1 ])
{ A[ 0 ] = 0; }

Set :: Set(char s): S(s), n(0), A(new char[ N+1 ])
{
    for (int i = 0; i < N; i++)
        if (rand() % 2) A[ n++ ] = i + 'A';
    A[n] = 0;
    std::cout << '\n' << S << " = [" << A << "]";
}

Set :: Set(const Set & B) : S(B.S), n(B.n), A(new char[N+1])
{
    memcpy(A, B.A, N+1);
}

Set & Set :: operator = (const Set& B)
{ if (this != &B)
    { N = B.N; memcpy(A, B.A, N+1); S = 'R'; }
    return *this;
}

int Set::power( ) { return n; }

Set::~Set( ) { delete [ ] A; } // деструктор
