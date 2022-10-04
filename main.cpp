#include <iostream>
#include <ctime>

const int Nmax = 26;

// Array Solution
void asArray();
char *arrayUnity(const char *A, const char *B);
char *arraySubtraction(const char *A, const char *B);

// List Solution
typedef struct lSet {
    signed char letter;
    lSet * next;
    lSet * prev;
} lSet;
void asList();
lSet * lSetFromStdin();
lSet * lAppends(lSet * setTail, char letter);
void lPrintln(lSet * set);
void lUnity(lSet * dest, lSet * src);
lSet * lSubtract(lSet * from, lSet * what);

// Machine Word Solution
void asMachineWord();
unsigned mwFromStdin();
void mwPrintln(unsigned n);

int main() {
    int choose;
    std::cout << "1 - Array\n2 - List\n3 - Machine Word\n";
    std::cin >> choose;
    getchar();
    switch (choose) {
        case 1:
            std::cout << "Array:\n";
            asArray();
            break;
        case 2:
            std::cout << "List:\n";
            asList();
            break;
        case 3:
            std::cout << "Machine Word:\n";
            asMachineWord();
            break;
        default:;
    }
    return 0;
}


void asMachineWord() {
    std::cout << "Enter A: ";
    unsigned A = mwFromStdin();
    std::cout << "Enter B: ";
    unsigned B = mwFromStdin();
    std::cout << "Enter C: ";
    unsigned C = mwFromStdin();
    std::cout << "Enter D: ";
    unsigned D = mwFromStdin();

    std::cout << "A - {B+C+D}: ";
    unsigned int start = clock();
    unsigned res = A & ~(B | C | D);
    unsigned int end = clock();
    mwPrintln(res);
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
    unsigned res = 0;
    char * temp = new char[Nmax];
    fgets(temp, Nmax + 1, stdin);
    for(char * ptr = temp; *ptr != '\0' && *ptr != '\n'; ptr++) {
        unsigned num = 1 << ((*ptr - 'a'));
        res = res | num;
    }
    return res;
}


void asList() {
    std::cout << "Enter A: ";
    lSet * A = lSetFromStdin();
    std::cout << "Enter B: ";
    lSet * B = lSetFromStdin();
    std::cout << "Enter C: ";
    lSet * C = lSetFromStdin();
    std::cout << "Enter D: ";
    lSet * D = lSetFromStdin();

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
    lSet * tempSet = new lSet;
    tempSet->letter = -1;
    tempSet->next = nullptr;
    lSet * setTail = tempSet;
    char * tempLine = new char[Nmax];
    fgets(tempLine, Nmax, stdin);
    tempLine[strlen(tempLine)-1] = '\0';
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

void asArray() {
    char * A = new char[Nmax];
    char * B = new char[Nmax];
    char * C = new char[Nmax];
    char * D = new char[Nmax];
    char * T;
    char * Empty = new char[1];
    Empty[0] = '\0';

    std::cout << "enter A: ";
    fgets(A, Nmax, stdin);
    A[strlen(A)-1] = '\0';
    A = arrayUnity(A, Empty);

    std::cout << "enter B: ";
    fgets(B, Nmax, stdin);
    B[strlen(B)-1] = '\0';
    B = arrayUnity(B, Empty);

    std::cout << "enter C: ";
    fgets(C, Nmax, stdin);
    C[strlen(C)-1] = '\0';
    C = arrayUnity(C, Empty);

    std::cout << "enter D: ";
    fgets(D, Nmax, stdin);
    D[strlen(D)-1] = '\0';
    D = arrayUnity(D, Empty);

    unsigned int start = clock();
    T = arrayUnity(B, C);
    T = arrayUnity(T, D);
    A = arraySubtraction(A, T);
    unsigned int end = clock();
    std::cout<<"A - {B+C+D}): "<<A<<std::endl;
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

int * bitFromStdin() {
    int * res = new int[Nmax];
    char * temp = new char[Nmax];
    fgets(temp, Nmax + 1, stdin);
    for(char * ptr = temp; *ptr != '\0' && *ptr != '\n'; ptr++) {
        int index = *ptr - 'a';
        res[index] = 1;
    }
    return res;
}