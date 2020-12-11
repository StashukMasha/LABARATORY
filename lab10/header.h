#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE_NAME 20

struct  Group
{
    char* name;
    int* grades;
    int min;
    double average;
};

void initializationStruct(struct Group* a, int students, int grades);
void showResult(struct Group* a, int students, int grades);
void sorting(struct Group* a, int students, int grades);
void culkulateAverage(struct Group* a, int students, int grades);
void showResult2(struct Group* a, int students, int grades);
void removalOfPoorStudents(struct Group* a, int* pstudents, int grades);
void surchMinGrades(struct Group* a, int students, int grades);
void freeMemory(Group** student, int count);
