#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 500

void inputSymbolInString(char* str, char* sym);
void addSpaces(char* str, int last);
void makingPharagraph(char* str, int numberSpace);
void textAlignment(char* str, int width);

#endif


