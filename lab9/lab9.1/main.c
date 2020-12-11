#include "Header.h"

int main()
{
	char str[MAX_SIZE_TEXT];
	int j = 0;

	inputText(str);

	int countWords = counterWords(str);
	
	struct Dictionary* words = allocateArray(countWords);

	countDuplicateWords(words, str, &j);

	outputDictonary(words, &j);

	freeMemory(&words, countWords);

	return 0;
}
