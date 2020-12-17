#include "Header.h"

void inputSymbolInString(char* str, char* sym)
{
	char* tmp = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(tmp, str);
	strcpy(str, sym);
	strcat(str, tmp);
	free(tmp);

}

void textAlignment(char* str, int width)
{
	int length = strlen(str);
	int firstPosition = 0;
	int lastPosition = width;
	while (lastPosition < length)
	{
		if (str[lastPosition] != ' ')
		{
			addSpaces(str, firstPosition, lastPosition);
		}

		if (str[lastPosition] != '\0')
		{
			makingPharagraph(str, lastPosition);
		}

		firstPosition = lastPosition + 1;
		lastPosition += width;
	}
}

void addSpaces(char* str, int last)
{
	char* space = " ";
	int numberSpace = last;

	if (str[numberSpace] != ' ' && numberSpace < strlen(str))
	{
		numberSpace--;
	}

	while (numberSpace != last)
	{
		numberSpace++;
		inputSymbolInString(&str[numberSpace], space);
	}
}

void makingPharagraph(char* str, int numberSpace)
{
	char* paragraph = "\n";
	numberSpace++;
	inputSymbolInString(&str[numberSpace], paragraph);
}


