#include"mystring.h"

char* strstrMy(char* str, char* space)
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

char* strcpyMy(char* dest, char* source)
{
    for (int i = 0; dest[i] = source[i]; i++);
    return dest;
}

void removeWhiteSpaces(char* str)
{
    int i = 0;
    char* wp;
    char space[] = "  ";
    while (str[i] != 0)
    {
        while (wp = strstrMy(str, space))
            strcpyMy(wp, wp + 1);
        i++;
    }
}