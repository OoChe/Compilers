#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE* sourceFile;                       // miniC source program

void icg_error(int n)
{
	printf("icg_error: %d\n", n);
	//3:printf("A Mini C Source file must be specified.!!!\n");
	//"error in DCL_SPEC"
	//"error in DCL_ITEM"
}

void main(int argc, char* argv[]) {
	char fileName[30];

	printf(" *** start of Mini C Compiler\n");
	if (argc != 2) {
		icg_error(1);
		exit(1);
	}
	strcpy(fileName, argv[1]);
	printf("   * source file name: %s\n", fileName);

	if ((sourceFile = fopen(fileName, "r")) == NULL) {
		icg_error(2);
		exit(1);
	}

	printf(" === start of Parser\n");
	parser();
}