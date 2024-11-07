#pragma once
#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>

int superLetter(char ch);
int superLetterOrDigit(char ch);
int getNumber(char firstCharacter);
int hexValue(char ch);
void lexicalError(int n);

#define NO_KEYWORD 7
#define ID_LENGTH 12

enum tsymbol {
    tnull = -1,
    tnot, tnotequ, tremainder, tremAssign, tident, tnumber,
    /* 0          1            2         3            4          5     */
    tand, tlparen, trparen, tmul, tmulAssign, tplus,
    /* 6          7            8         9           10         11     */
    tinc, taddAssign, tcomma, tminus, tdec, tsubAssign,
    /* 12         13          14        15           16         17     */
    tdiv, tdivAssign, tsemicolon, tless, tlesse, tassign,
    /* 18         19          20        21           22         23     */
    tequal, tgreat, tgreate, tlbracket, trbracket, teof,
    /* 24         25          26        27           28         29     */
    //   ...........    word symbols ................................. //
    /* 30         31          32        33           34         35     */
    tconst, telse, tif, tint, treturn, tvoid,
    /* 36         37          38        39                             */
    twhile, tlbrace, tor, trbrace
};

char* tokenName[];

char* keyword[NO_KEYWORD];

enum tsymbol tnum[NO_KEYWORD];

struct tokenType {
    int number;
    union {
        char id[ID_LENGTH];
        int num;
    } value;
};

struct tokenType scanner();

void lexicalError(int n)
{
    printf(" *** Lexical Error : ");
    switch (n) {
    case 1: printf("an identifier length must be less than 12.\n");
        break;
    case 2: printf("next character must be &\n");
        break;
    case 3: printf("next character must be |\n");
        break;
    case 4: printf("invalid character\n");
        break;
    }
}

int superLetter(char ch)
{
    if (isalpha(ch) || ch == '_') return 1;
    else return 0;
}

int superLetterOrDigit(char ch)
{
    if (isalnum(ch) || ch == '_') return 1;
    else return 0;
}

int getNumber(char firstCharacter)
{
    int num = 0;
    int value;
    char ch;

    if (firstCharacter == '0') {
        ch = fgetc(sourceFile);
        if ((ch == 'X') || (ch == 'x')) {		// hexa decimal
            while ((value = hexValue(ch = fgetc(sourceFile))) != -1)
                num = 16 * num + value;
        }
        else if ((ch >= '0') && (ch <= '7'))	// octal
            do {
                num = 8 * num + (int)(ch - '0');
                ch = fgetc(sourceFile);
            } while ((ch >= '0') && (ch <= '7'));
        else num = 0;						// zero
    }
    else {									// decimal
        ch = firstCharacter;
        do {
            num = 10 * num + (int)(ch - '0');
            ch = fgetc(sourceFile);
        } while (isdigit(ch));
    }
    ungetc(ch, sourceFile);  /*  retract  */
    return num;
}

int hexValue(char ch)
{
    switch (ch) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return (ch - '0');
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        return (ch - 'A' + 10);
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        return (ch - 'a' + 10);
    default: return -1;
    }
}
