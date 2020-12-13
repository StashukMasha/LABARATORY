#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE_STRING 500

char** allocateMemory(FILE* file, char* str, int* count);
void removeBlankLines(char** A, int k);
void freeMamory(char** A, int k);
void outputResult(FILE* file, char** a, int count);
void readingTextFile(FILE* file, char* a, int* p);

#endif 