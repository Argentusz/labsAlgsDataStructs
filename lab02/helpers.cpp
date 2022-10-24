#include "helpers.h"
#include <iostream>
#include <bitset>
#include <cstring>

const int Nmax = 26;

void printRaw(unsigned a) {
    std::bitset<sizeof(a)*8> raw(a);
    std::cout << raw << '\n';
    std::cout << std::hex << a << '\n';
}

void asMachineWord(char ** str) {
    unsigned A;
    unsigned B;
    unsigned C;
    unsigned D;
    if (str == nullptr) {
        std::cout << "Enter A: ";
        A = mwFromStdin();
        std::cout << "Enter B: ";
        B = mwFromStdin();
        std::cout << "Enter C: ";
        C = mwFromStdin();
        std::cout << "Enter D: ";
        D = mwFromStdin();
    } else {
        A = mwFromString(str[0]);
        B = mwFromString(str[1]);
        C = mwFromString(str[2]);
        D = mwFromString(str[3]);
    }

    std::cout << "A - {B+C+D}: ";
    unsigned int start = clock();
    unsigned res = A & ~(B | C | D);
    unsigned int end = clock();
    mwPrintln(res);
    printRaw(res);
    std::cout << "Time elapsed: " << end - start << "ms\n";
}

void mwPrintln(unsigned n) {
    for(char ltr = 'a'; ltr <= 'z'; ltr++) {
        if(n%2) std::cout << ltr;
        n = n >> 1;
    }
    std::cout << std::endl;
}


unsigned mwFromStdin() {
    char * temp = new char[Nmax];
    fgets(temp, Nmax + 1, stdin);
    return mwFromString(temp);
}

unsigned mwFromString(char * temp) {
    unsigned res = 0;
    for(char * ptr = temp; *ptr != '\0' && *ptr != '\n'; ptr++) {
        unsigned num = 1 << (*ptr - 'a');
        res = res | num;
    }
    return res;
}


void asList(char ** str) {
    lSet * A;
    lSet * B;
    lSet * C;
    lSet * D;
    if (str == nullptr) {
        std::cout << "Enter A: ";
        A = lSetFromStdin();
        std::cout << "Enter B: ";
        B = lSetFromStdin();
        std::cout << "Enter C: ";
        C = lSetFromStdin();
        std::cout << "Enter D: ";
        D = lSetFromStdin();
    } else {
        A = lSetFromString(str[0]);
        B = lSetFromString(str[1]);
        C = lSetFromString(str[2]);
        D = lSetFromString(str[3]);
    }

    unsigned int start = clock();
    lUnity(B, C);
    lUnity(B, D);
    A = lSubtract(A, B);
    unsigned int end = clock();

    std::cout << "A - {B+C+D}: ";
    lPrintln(A);
    std::cout << "Time elapsed: " << end - start << "ms\n";
}

lSet * lSetFromStdin() {
    char * tempLine = new char[Nmax];
    fgets(tempLine, Nmax, stdin);
    tempLine[strlen(tempLine)-1] = '\0';
    return lSetFromString(tempLine);
}

lSet * lSetFromString(char * tempLine) {
    lSet * tempSet = new lSet;
    tempSet->letter = -1;
    tempSet->next = nullptr;
    lSet * setTail = tempSet;
    for(char * ptr = tempLine; *ptr != '\0'; ptr++) {
        setTail = lAppends(setTail, *ptr);
    }
    lSet * newSet = new lSet;
    lUnity(newSet, tempSet);
    return newSet;
}

void lPrintln(lSet * set) {
    lSet * ptr;
    for(ptr = set; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->letter;
    }
    std::cout << std::endl;
}

void lUnity(lSet * dest, lSet * src) {
    lSet * destTail;
    for(destTail = dest; destTail->next != nullptr; destTail = destTail->next);
    for(lSet * srcPtr = src; srcPtr != nullptr; srcPtr = srcPtr->next) {
        bool isIn = false;
        for(lSet * destPtr = dest; destPtr != nullptr; destPtr = destPtr->next) {
            if (destPtr->letter == srcPtr->letter) {
                isIn = true;
                break;
            }
        }
        if (!isIn) {
            destTail = lAppends(destTail, srcPtr->letter);
        }
    }
}

lSet * lSubtract(lSet * from, lSet * what) {
    for(lSet * fromPtr = from; fromPtr != nullptr; fromPtr = fromPtr->next) {
        bool isIn = false;
        for(lSet * whatPtr = what; whatPtr != nullptr; whatPtr = whatPtr->next) {
            if (whatPtr->letter == fromPtr->letter) {
                isIn = true;
                break;
            }
        }
        if(isIn) {
            if(fromPtr->next != nullptr && fromPtr->prev != nullptr) {
                fromPtr->prev->next = fromPtr->next;
                fromPtr->next->prev = fromPtr->prev;
            } else if (fromPtr->next == nullptr && fromPtr->prev == nullptr) {
                fromPtr = nullptr;
            } else if (fromPtr->next == nullptr) {
                fromPtr->prev->next = nullptr;
            } else {
                fromPtr->next->prev = nullptr;
                from = from->next;
            }
        }
        if(fromPtr == nullptr) break;
    }
    return from;
}

lSet * lAppends(lSet * setTail, char letter) {
    lSet * ptr;
    if (setTail->letter == -1) {
        ptr = setTail;
        ptr->prev = nullptr;
    } else {
        ptr = new lSet;
        setTail->next = ptr;
        ptr->prev = setTail;
    }
    ptr->next = nullptr;
    ptr->letter = letter;
    setTail = ptr;
    return setTail;
}

void asArray(char ** str) {
    char * A = new char[Nmax];
    char * B = new char[Nmax];
    char * C = new char[Nmax];
    char * D = new char[Nmax];
    char * T;
    char * Empty = new char[1];
    Empty[0] = '\0';

    if(str == nullptr) {
        std::cout << "enter A: ";
        fgets(A, Nmax, stdin);
        A[strlen(A) - 1] = '\0';
        A = arrayUnity(A, Empty);

        std::cout << "enter B: ";
        fgets(B, Nmax, stdin);
        B[strlen(B) - 1] = '\0';
        B = arrayUnity(B, Empty);

        std::cout << "enter C: ";
        fgets(C, Nmax, stdin);
        C[strlen(C) - 1] = '\0';
        C = arrayUnity(C, Empty);

        std::cout << "enter D: ";
        fgets(D, Nmax, stdin);
        D[strlen(D) - 1] = '\0';
        D = arrayUnity(D, Empty);
    } else {
        A = str[0];
        A = arrayUnity(A, Empty);
        B = str[1];
        B = arrayUnity(B, Empty);
        C = str[2];
        C = arrayUnity(C, Empty);
        D = str[3];
        D = arrayUnity(D, Empty);
    }

    unsigned int start = clock();
    T = arrayUnity(B, C);
    T = arrayUnity(T, D);
    A = arraySubtraction(A, T);
    unsigned int end = clock();
    std::cout<<"A - {B+C+D}: "<<A<<std::endl;
    std::cout << "Time elapsed: " << end - start << "ms\n";

}

char *arrayUnity(const char * A, const char * B) {
    char * C = new char[26];
    strcpy(C,B);
    int i = 0;
    int j;
    int k = (int)strlen(C);
    bool isIn;
    while (A[i]!='\0') {
        j=0;
        isIn = false;
        while (C[j]!='\0') {
            if (A[i]==C[j]) {
                isIn = true;
                break;
            }
            j++;
        }
        if (!isIn) {
            C[k] = A[i];
            k++;
        }
        i++;
    }
    C[k] = '\0';
    return C;
}


char *arraySubtraction(const char * A, const char * B) {
    char *C = new char[26];
    int i,j,k;
    i = 0;
    k = 0;
    bool isIn;
    while (A[i] != '\0')
    {
        j = 0;
        isIn = false;
        while (B[j]!='\0') {
            if (A[i]==B[j]) {
                isIn = true;
                break;
            }
            j++;
        }
        if (!isIn) {
            C[k] = A[i];
            k++;
        }
        i++;
    }
    C[strlen(C)] = '\0';
    return C;
}

int * bitsFromStdin() {
    char * temp = new char[Nmax];
    fgets(temp, Nmax + 1, stdin);
    return bitsFromString(temp);
}

int * bitsFromString(char * temp) {
    int * res = new int[Nmax];
    for(char * ptr = temp; *ptr != '\0' && *ptr != '\n'; ptr++) {
        int index = *ptr - 'a';
        res[index] = 1;
    }
    return res;
}

int* bitsSum(const int *first, const int *second) {
    int *res = new int[Nmax];
    int i;
    for (i=0; i<Nmax; i++){
        if (first[i]||second[i]) {
            res[i]=1;
        } else {
            res[i] = 0;
        }
    }
    return res;
}

int *bitsSubtraction(const int *first, const int *second) {
    int *res = new int[Nmax];
    int i;
    for (i=0; i<Nmax; i++){
        if (!first[i] || (first[i]+second[i]==2)) {
            res[i]=0;
        } else {
            res[i] = 1;
        }
    }
    return res;
}

void asBits(char ** str) {
    int * A;
    int * B;
    int * C;
    int * D;
    if (str == nullptr) {
        std::cout << "enter A: ";
        A = bitsFromStdin();
        std::cout << "enter B: ";
        B = bitsFromStdin();
        std::cout << "enter C: ";
        C = bitsFromStdin();
        std::cout << "enter D: ";
        D = bitsFromStdin();
    } else {
        A = bitsFromString(str[0]);
        B = bitsFromString(str[1]);
        C = bitsFromString(str[2]);
        D = bitsFromString(str[3]);
    }

    unsigned int start = clock();
    int *T = bitsSum(B,C);
    T = bitsSum(T,D);
    T = bitsSubtraction(A,T);
    unsigned int end = clock();
    std::cout<<"A - {B+C+D}: ";
    asBitsPrint(T);
    std::cout << "Time elapsed: " << end - start << "ms\n";

}

void asBitsPrint(const int *ar) {
    char symb = 'a';
    for (int i=0; i<Nmax;i++){
        if(ar[i]) {
            std::cout<<symb;
        }
        symb++;
    }
    std::cout<<"\n";
}

