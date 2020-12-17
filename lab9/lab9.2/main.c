#include "Header.h"

int main()
{
	char* str = (char*)malloc(STRING_SIZE * sizeof(char));
	int width;

	printf("Input text:\n");
	gets_s(str, STRING_SIZE);

	printf("Input width: ");
	scanf_s("%d", &width);

	textAlignment(str, width);

	puts(str);

	return 0;
}
