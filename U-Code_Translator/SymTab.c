// [Symbol Table 구현 코드]
// 참고 코드 원본: https://github.com/hanXen/minic_compiler.git
#include "../emit.h"

void initSymbolTable() {
    base = 1;
    offset = 1;
    st_top = 0;
}

int insert(char* name, int typeSpecifier, int typeQualifier,
    int base, int offset, int width, int initialValue) {
    struct SymbolTable* stptr = &symbolTable[st_top];
    strcpy(stptr->name, name);
    stptr->typeSpecifier = typeSpecifier;
    stptr->typeQualifier = typeQualifier;
    stptr->base = base;
    stptr->offset = offset;
    stptr->width = width;
    stptr->initialValue = initialValue;

    st_top++;
    return st_top;
}

int lookup(char* name) {
    int i;
    for (i = 0; i < st_top; i++)
        if (!strcmp(name, symbolTable[i].name))
            return i;
    return -1;
}

void set(){
    base++;
    offset = 1;
}

void reset(){
    base--;
}