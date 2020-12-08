#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_NAME 30
#define MAX_SIZE_SUFFIX 10

char* removesub(char* s, char* sub);
char* insertsubstring(char* s, char* sub, int pos);
int Mystrlen(char* d);
char* Mystrstr(char* str, char* space);
char* Mystrcpy(char* dest, char* source);
char* Mystrcat(char* dest, char* source);
char** allocateArrayString(int n);
void inputArrayString(char** S, int n);
void outputArrayString(char** S, int n);
void changingSuffix(char** S, int n, char* suf1, char* suf2);
void freeMemory(char** S, int n);

#endif 
