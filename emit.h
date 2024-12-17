// [U-Code Translator 함수, 집합체 선언부 분리]
#ifndef EMIT_C
#define EMIT_C

#include <stdio.h>
#include "./nodeType.h"

#define numberOfOpcodes 40           // 35 + 4 + 1
#define LABEL_SIZE 10
#define TABLE_SIZE 100

FILE* ucodeFile;                        // ucode file

typedef enum {
	notop, neg, incop, decop, dup, swp, add, sub, mult, divop,
	modop, andop, orop, gt, lt, ge, le, eq, ne,
	lod, ldc, lda, ldi, ldp, str, sti, ujp, tjp, fjp,
	call, ret, retv, chkh, chkl, nop, proc, endop, bgn, sym,
	none
} opcode;

typedef enum {
    NONE_SPEC, VOID_SPEC, INT_SPEC, CHAR_SPEC, FLOAT_SPEC
} typeSpecifier;

typedef enum {
    NONE_QUAL, CONST_QUAL, VAR_QUAL, FUNC_QUAL, PARAM_QUAL
} typeQualifier;

struct SymbolTable {
    char name[LABEL_SIZE];
    int typeSpecifier;
    int typeQualifier;
    int base;
    int offset;
    int width;
    int initialValue;
};

struct SymbolTable symbolTable[TABLE_SIZE];
int st_top;
int base, offset;

// MiniC.c
void codeGen(Node* ptr);
void processDeclaration(Node* ptr);
void processFuncHeader(Node* ptr);
void processFunction(Node* ptr);
void icg_error(int n);
void processSimpleVariable(Node* ptr, int typeSpecifier, int typeQualifier);
void processArrayVariable(Node* ptr, int typeSpecifier, int typeQualifier);
void processStatement(Node* ptr);
void processOperator(Node* ptr);
void processCondition(Node* ptr);
void rv_emit(Node* ptr);
void genLabel(char* label);
int checkPredefined(Node* ptr);

// SymTab.c
void initSymbolTable();
int insert(char* name, int typeSpecifier, int typeQualifier,
    int base, int offset, int width, int initialValue);
int lookup(char* name);
void set();
void reset();

// EmitCode.c
void emit0(opcode op);
void emit1(opcode op, int num);
void emit2(opcode op, int base, int offset);
void emit3(opcode op, int p1, int p2, int p3);
void emitLabel(char* label);
void emitJump(opcode op, char* label);
void emitSym(int base, int offset, int size);
void emitFunc(char* label, int base, int offset, int size);

#endif