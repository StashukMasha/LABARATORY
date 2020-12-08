#include "header.h"

char* removesub(char* s, char* sub)
{
	char* tmp = Mystrstr(s, sub);
	return Mystrcpy(tmp, tmp + Mystrlen(sub));
}

char* insertsubstring(char* s, char* sub, int pos)
{
	char* copy = (char*)malloc(Mystrlen(s) * sizeof(char) + 1);
	Mystrcpy(copy, s);
	s[pos] = 0;
	Mystrcat(s, sub);
	Mystrcat(s, copy + pos);

	free(copy);
	return s;
}

int Mystrlen(char* d)
{
	int len;
	for (len = 0; d[len]; len++);
	return len;
}

char* Mystrstr(char* str, char* space)
{
	char* q, * p = str, * qs = space;
	int check = 1;
	while (*p && *qs && check)
	{
		for (q = p, qs = space; *q && *q == *qs; q++, qs++);
		if (!(*qs && *q))
			check = 0;
		else
			p++;
	}
	return *p ? p : NULL;
}

char* Mystrcpy(char* dest, char* source)
{
	int i;
	for (i = 0; source[i] != 0; i++)
		dest[i] = source[i];
	dest[i] = 0;
	return dest;
}

char* Mystrcat(char* dest, char* source)
{
	char* p;
	int i;
	for (p = dest; *p; p++);
	for (i = 0; source[i] != 0; i++)
		p[i] = source[i];
	p[i] = 0;
	return dest;
}

char* inputArr(char** S, int n)
{

	return S;
}

char** allocateArrayString(int n)
{
	char** ArrayString = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		ArrayString[i] = (char*)malloc(MAX_SIZE_NAME * sizeof(char));
	}

	return ArrayString;
}

void inputArrayString(char** S, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("vvedite FIO: ");
		fgets(S[i], MAX_SIZE_NAME, stdin);
	}

}

void outputArrayString(char** S, int n)
{
	printf("\nResultat:\n\n");

	for (int i = 0; i < n; i++)
	{
		puts(S[i]);
	}
}

void changingSuffix(char** S, int n, char* suf1, char* suf2)
{
	int i, j, t;

	for (i = 0; i < n; i++)
	{
		int pos = 0;
		for (j = 0; S[i][j] != ' '; j++)
		{
			pos++;
		}

		for (t = 0; t < Mystrlen(suf1); t++)
		{
			if (suf1[t] == S[i][pos - Mystrlen(suf1) + t])
			{
				removesub(S[i], suf1);
				int newpos = pos - Mystrlen(suf1);
				insertsubstring(S[i], suf2, newpos);
			}
		}
	}
}

void freeMemory(char** S, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(S[i]);
	}
}