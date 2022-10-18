#include <iostream>
#include "ArraySet.h"
#include "helpers.h"

ArraySet & ArraySet :: operator & (const ArraySet & B) const
{
    auto *C = new ArraySet;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B.n; j++)
            if (A[ i ] == B.A[ j ]) C->A[ C->n++ ] = A[ i ];
    }
    C->A[C->n] = 0;
    return *C;
};

ArraySet & ArraySet :: operator | (const ArraySet & B) const
{
    auto *C = new ArraySet;
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

ArraySet & ArraySet :: operator ~ ( ) const
{
    auto *C = new ArraySet;
    for (char c = 'a'; c <= 'z'; c++) {
        bool f = true;
        for (int j = 0; j < n; j++)
            if (c == A[ j ]) { f = false; break; }
        if ( f ) C->A[ C->n++ ] = c;
    }
    C->A[ C->n ] = 0;
    return *C;
}

void ArraySet :: Show()
{ std::cout << '\n' << S << " = [" << A << "]"; }

ArraySet :: ArraySet( ): n(0), S ('0'), A(new char[N + 1 ])
{ A[ 0 ] = 0; }

ArraySet :: ArraySet(char s, const std::string& str): S(s), n((int)str.length()), A(new char[N + 1 ])
{
    str.copy(A, n);
    arrayUnity(A, "");
}

ArraySet :: ArraySet(const ArraySet & B) : S(B.S), n(B.n), A(new char[N + 1])
{
    memcpy(A, B.A, N+1);
}

ArraySet & ArraySet :: operator = (const ArraySet& B)
{
    if (this != &B)
    {
        N = ArraySet::N;
        memcpy(A, B.A, N+1);
    }
    return *this;
}

int ArraySet::power( ) const { return n; }

ArraySet::~ArraySet( ) { delete [ ] A; } // деструктор
