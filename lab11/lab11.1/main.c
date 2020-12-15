#include"Header.h"

int main()
{
	FILE* textInput = fopen("input.txt", "r");

	char str[MAX_SIZE_STRING];
	int countStr = 0;

	readingTextFile(textInput, str, &countStr);

	char** fileArr = allocateMemory(textInput, str, &countStr);

	fclose(textInput);

	removeBlankLines(fileArr, countStr);

	FILE* textOutput = fopen("output.txt", "w");

	outputResult(textOutput, fileArr, countStr);

	fclose(textOutput);
	
	freeMamory(fileArr, countStr);
  
  return 0;
}
