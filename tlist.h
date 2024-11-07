#ifndef TLISH_H
#define TLISH_H

#include <stdio.h>

// add NO_KEYWORD 3 (for, do-while, switch)
#define NO_KEYWORD 10
#define ID_LENGTH 12
// input sourceFile Name
FILE* sourceFile;

// add do-while, for, switch symbol #
enum tsymbol {
	tnull = -1,
	tnot,         tnotequ,     tremainder, tremAssign,  tident,	   tnumber,
	/* 0          1            2		   3            4          5		 */
	tand,		  tlparen,	   trparen,    tmul,        tmulAssign,tplus,
	/* 6          7            8		   9            10         11		 */
	tinc,		  taddAssign,  tcomma,     tminus,      tdec,      tsubAssign,
	/* 12         13           14		   15           16         17		 */
	tdiv,		  tdivAssign,  tcolon,     tsemicolon,  tless,     tlesse,
	/* 18         19           20          21           22         23		 */
	tassign,      tequal,      tgreat,     tgreate,     tlbracket, trbracket,
	/* 24         25           26          27           28         29		 */
	teof,
	/* 30																	 */
	//   ...........    word symbols ................................. //
	/* 31         32           33		   34           35         36		 */
	tbreak,		  tcase,	   tconst,	   tcontinue,   tdefault,  tdo,       
	/* 37         38           39		   40           41         42		 */
	telse,		  tfor,        tif,		   tint,	    treturn,   tswitch,
	/* 43         44           45          46			47					 */
	tvoid,        twhile,	   tlbrace,	   tor,		    trbrace,
};
char* tokenName[];

typedef struct tokenType {
	int number;
	union {
		char id[ID_LENGTH];
		int num;
	} value;
} tokeyType;

struct tokenType scanner();

#endif