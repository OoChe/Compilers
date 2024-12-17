#ifndef NODETYPE_H
#define NODETYPE_H

#include <stdio.h>
#include "./token.h"

/***************************************************************************
 *  문법과 tbl이 확장된 경우, PGS의 출력을 확인하며 변경 사항을 적용해줘야 함.
 *  WHILE_ST부터 추가됨
 ***************************************************************************/
enum nodeNumber {
	ERROR_NODE, // ERROR_NODE가 0번으로 지정되어야 함.
	ACTUAL_PARAM,	ADD,			ADD_ASSIGN,		ARRAY_VAR,	 ASSIGN_OP,
	CALL,			COMPOUND_ST,	CONST_TYPE,		DCL,		 DCL_ITEM,
	DCL_LIST,		DCL_SPEC,		DIV,			DIV_ASSIGN,	 EQ,
	EXP_ST,			FORMAL_PARA,	FUNC_DEF,		FUNC_HEAD,
	GE,				GT,				IDENT,			IF_ELSE_ST,	 IF_ST,
	INDEX,			INT_TYPE,		LE,				LOGICAL_AND, LOGICAL_NOT,
	LOGICAL_OR,		LT,				MOD,			MOD_ASSIGN,	 MUL,
	MUL_ASSIGN,		NE,				NUMBER,			PARAM_DCL,	 POST_DEC,
	POST_INC,		PRE_DEC,		PRE_INC,		PROGRAM,	 RETURN_ST,
	SIMPLE_VAR,		STAT_LIST,		SUB,			SUB_ASSIGN,	 UNARY_MINUS,
	VOID_TYPE,		WHILE_ST,		CASE_ST,		DEFAULT_ST,	 CONTINUE_ST,
	BREAK_ST,		DO_WHILE_ST,	SWITCH_ST,		FOR_ST,		 INIT_PART,
	CONDITION_PART, POST_PART,		REMAINDER,
};

char* nodeName[];
int ruleName[];
FILE* astFile;

typedef struct nodeType {
	struct tokenType token;            	// 토큰 종류
	enum { terminal, nonterm } noderep; // 노드의 종류
	struct nodeType* son;             	// 왼쪽 링크
	struct nodeType* brother;         	// 오른쪽 링크
	struct nodeType* father;		   	// 상위 링크
} Node;

Node* parser();
void printNode(Node* pt, int indent);
void printTree(Node* pt, int indent);

#endif