#include "header.h"

int main()
{
	int quantityStrings;
	char suf1[MAX_SIZE_SUFFIX];
	char suf2[MAX_SIZE_SUFFIX];
	

	printf("vvedite kol-vo uchenikov: ");
	scanf_s("%d", &quantityStrings);
	getchar();

	char** arrayStrings = allocateArrayString(quantityStrings);

	inputArrayString(arrayStrings, quantityStrings);
	outputArrayString(arrayStrings, quantityStrings);
	
	printf("vvedite suf1 kotorii hotite izmenit: ");
	gets_s(suf1, MAX_SIZE_SUFFIX);
	
	printf("vvedite suf2 na kotorii hotite izmenit: ");
	gets_s(suf2, MAX_SIZE_SUFFIX);

	changingSuffix(arrayStrings, quantityStrings, suf1, suf2);

	outputArrayString(arrayStrings, quantityStrings);

	freeMemory(arrayStrings, quantityStrings);

	return 0;
}