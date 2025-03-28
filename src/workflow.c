// BWH Chemistry Library for ANSI C - LibChem
// Released under the GNU LGPL

// Workflow Functions

#include <stdio.h>
#include <stdlib.h>

// LibChem Error Handler
void libError(char libraryName[], char functionName[], char errorText[])
{
	printf("\n#################################");
	printf("\n  *** Runtime Error in LibChem:");
	printf("\n\tLibrary:\t %s", libraryName);
	printf("\n\tFunction:\t %s", functionName);
	printf("\n\tError:\t\t %s", errorText);
	printf("\n  *** Application Terminated");
	printf("\n#################################\n");
	exit(1);
}
