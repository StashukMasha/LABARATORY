#include"Header.h"

void removeBlankLines(char** A, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (strcmp(A[i], "\n\0") == 0)
		{
			free(A[i]);
			A[i] = '\0';
		}
	}
}

void freeMamory(char** A, int k)
{
	for (int i = 0; i < k; i++)
		free(A[i]);
	free(A);
}

void outputResult(FILE* file, char** a, int count)
{
	int counter = 0;
	for (int i = 0; i < count; i++)
		if (a[i] != '\0')
		{
			counter++;
			fprintf(file, "%d ", counter);
			fprintf(file, "%s", a[i]);
		}
}

void readingTextFile(FILE* file, char* a, int* p)
{
	while (!feof(file))
	{
		fgets(a, MAX_SIZE_STRING, file);
		(*p)++;
	}
	rewind(file);
}

char** allocateMemory(FILE* file, char* str, int* count)
{
	char** string = (char**)malloc(*count * sizeof(char*));
	for (int i = 0; i < *count; i++)
	{
		fgets(str, MAX_SIZE_STRING, file);
		string[i] = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(string[i], str);
	}

	return string;
}
