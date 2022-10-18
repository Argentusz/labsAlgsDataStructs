// Array Solution
void asArray(char ** str);
char *arrayUnity(const char *A, const char *B);
char *arraySubtraction(const char *A, const char *B);

// List Solution
typedef struct lSet {
    signed char letter;
    lSet * next;
    lSet * prev;
} lSet;
void asList(char ** str);
lSet * lSetFromStdin();
lSet * lSetFromString(char * tempLine);
lSet * lAppends(lSet * setTail, char letter);
void lPrintln(lSet * set);
void lUnity(lSet * dest, lSet * src);
lSet * lSubtract(lSet * from, lSet * what);

// Machine Word Solution
void asMachineWord(char ** str);
unsigned mwFromStdin();
void mwPrintln(unsigned n);
unsigned mwFromString(char * temp);

// Bits array solution
void asBitsPrint(const int *ar);
void asBits(char ** str);
int * bitsFromStdin();
int * bitsFromString(char * temp);
int* bitsSum(const int *first, const int *second);
int *bitsSubtraction(const int *first, const int *second);
