#include "Header.h"

int counterWords(char* str)
{
	int countWords = 1;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			countWords++;
		i++;
	}

	return countWords;
}

char* substring(char* str)
{
	char* sub = malloc(MAX_SIZE_WORD);
	static pos = 0;
	while (str[pos] != 0 && !isLetter(str[pos]))
		pos++;
	int j = 0;
	while (str[pos] != 0 && isLetter(str[pos]))
	{
		sub[j] = str[pos];
		if (sub[j] >= 'A' && sub[j] <= 'Z')
			sub[j] += 32;
		j++;
		pos++;
	}
	sub[j] = 0;
	return sub;
}

int isLetter(char a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return 1;
	else
		return 0;
}

void countDuplicateWords(struct Dictionary* A, char* str, int* pj)
{
	char* sub;
	sub = substring(str);
	while (strcmp(sub, "") != 0)
	{
		int flag = 0;
		for (int t = 0; t < *pj; t++)
			if (strcmp(A[t].theWord, sub) == 0)
			{
				flag = 1;
				A[t].countWords++;
				break;
			}

		if (flag == 0)
		{
			strcpy(A[*pj].theWord, sub);
			A[*pj].countWords = 1;
			(*pj)++;
		}

		sub = substring(str);
	}
}

void outputDictonary(struct Dictionary* A, int* pj)
{
	for (int i = 0; i < *pj; i++)
		printf("%s %d\n", A[i].theWord, A[i].countWords);
}

void inputText(char* str)
{
	printf("print text: \n");
	gets_s(str, MAX_SIZE_TEXT);
}

struct Dictionary* allocateArray(int countWords)
{
	struct Dictionary* A = (struct Dictionary*)malloc(countWords * sizeof(struct Dictionary));
	for (int i = 0; i < countWords; i++)
	{
		A[i].theWord = (char*)malloc(MAX_SIZE_WORD*sizeof(char));
		A[i].countWords = 0;
	}

	return A;
}

void freeMemory(struct Dictionary** A, int count)

{
	for (int i = 0; i < count; i++)
	{
		free((*A)[i].theWord);
	}

	free(*A);
}