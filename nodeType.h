#ifndef NODETYPE_H
#define NODETYPE_H

#include <stdio.h>
#include "./token.h"

/***************************************************************************
 *  ������ tbl�� Ȯ��� ���, PGS�� ����� Ȯ���ϸ� ���� ������ ��������� ��.
 *  WHILE_ST���� �߰���
 ***************************************************************************/
enum nodeNumber {
	ERROR_NODE, // ERROR_NODE�� 0������ �����Ǿ�� ��.
	ACTUAL_PARAM, ADD, ADD_ASSIGN, ARRAY_VAR, ASSIGN_OP,
	CALL, COMPOUND_ST, CONST_TYPE, DCL, DCL_ITEM,
	DCL_LIST, DCL_SPEC, DIV, DIV_ASSIGN, EQ,
	EXP_ST, FORMAL_PARA, FUNC_DEF, FUNC_HEAD,
	GE, GT, IDENT, IF_ELSE_ST, IF_ST,
	INDEX, INT_TYPE, LE, LOGICAL_AND, LOGICAL_NOT,
	LOGICAL_OR, LT, MOD, MOD_ASSIGN, MUL,
	MUL_ASSIGN, NE, NUMBER, PARAM_DCL, POST_DEC,
	POST_INC, PRE_DEC, PRE_INC, PROGRAM, RETURN_ST,
	SIMPLE_VAR, STAT_LIST, SUB, SUB_ASSIGN, UNARY_MINUS,
	VOID_TYPE, WHILE_ST, CASE_ST, DEFAULT_ST, CONTINUE_ST,
	BREAK_ST, DO_WHILE_ST, SWITCH_ST, FOR_ST, INIT_PART,
	CONDITION_PART, POST_PART, REMAINDER,
};

char* nodeName[];
int ruleName[];
FILE* astFile;

typedef struct nodeType {
	struct tokenType token;            	// ��ū ����
	enum { terminal, nonterm } noderep; // ����� ����
	struct nodeType* son;             	// ���� ��ũ
	struct nodeType* brother;         	// ������ ��ũ
	struct nodeType* father;		   	// ���� ��ũ
} Node;

void printNode(Node* pt, int indent);
void printTree(Node* pt, int indent);

#endif