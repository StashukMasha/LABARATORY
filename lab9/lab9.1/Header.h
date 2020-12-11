#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define MAX_SIZE_TEXT 1000
#define MAX_SIZE_WORD 20

struct Dictionary
{
	char* theWord;
	int countWords;
};

int counterWords(char* str);
char* substring(char* str);
int isLetter(char a);
void countDuplicateWords(struct Dictionary* A, char* str, int* pj);
void outputDictonary(struct Dictionary* A, int* pj);
void inputText(char* str);
struct Dictionary* allocateArray(int countWords);
void freeMemory(struct Dictionary* A, int count);
