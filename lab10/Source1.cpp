#include"header.h"

void sorting(struct Group* a, int students, int grades)
{
    for (int j = 1; j < grades; j++) {

        for (int i = students - 1; i >= j; i--)
            if (a[i].min > a[i - 1].min || (a[i].min == a[i - 1].min && strcmp(a[i].name, a[i - 1].name) < 0))
            {
                struct Group tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;

            }
    }
}

void initializationStruct(struct Group* a, int students, int grades)
{
    for (int i = 0; i < students; i++)
    {
        a[i].name = (char*)malloc(MAX_SIZE_NAME * sizeof(char));
        a[i].grades = (int*)malloc(grades * sizeof(int));
        printf("Enter name: ");
        scanf("%s", a[i].name);
        printf("Enter grades: ");
        for (int j = 0; j < grades; j++)
            scanf("%d", &a[i].grades[j]);
    }
}

void showResult(struct Group* a, int students, int grades)
{
    printf("_________________________________\n");
    for (int i = 0; i < students; i++) {
        printf("Student #%d: %s, grades: ", i + 1, a[i].name);
        for (int j = 0; j < grades; j++)
            printf("%d ", a[i].grades[j]);
        printf("\n");
    }
}

void culkulateAverage(struct Group* a, int students, int grades)
{
    int i, j;
    double average;
    for (i = 0; i < students; i++)
    {
        int sum = 0;
        for (j = 0; j < grades; j++)
            sum = sum + a[i].grades[j];

        average = (double)sum / grades;
        a[i].average = average;
    }
}

void showResult2(struct Group* a, int students, int grades)
{
    printf("_________________________________\n");
    for (int i = 0; i < students; i++) {
        printf("Student #%d: %s, average: %lf  grades: ", i + 1, a[i].name, a[i].average);
        for (int j = 0; j < grades; j++)
            printf("%d ", a[i].grades[j]);
        printf("\n");
    }
}

void removalOfPoorStudents(struct Group* a, int* pstudents, int grades)
{
    int i, j;

    int dif = 0;

    for (i = 0; i < *pstudents; i++)
    {
        int count = 0;
        for (j = 0; j < grades; j++)
        {
            if (a[i].grades[j] == 2)
            {
                count++;
            }

        }

        if (count >= 2)
        {
            dif++;
        }

        if (dif > 0 && count < 2)
        {
            a[i - dif] = a[i];

        }
    }

    *pstudents -= dif;
}

void surchMinGrades(struct Group* a, int students, int grades)
{
    for (int i = 0; i < students; i++)
    {
        int minimum = a[i].grades[0];
        for (int j = 1; j < grades; j++)
            if (a[i].grades[j] < minimum)
                minimum = a[i].grades[j];
        a[i].min = minimum;
    }

}

void freeMemory(Group** student, int count)
{
    for (int i = 0; i < count; i++)
    {
        free((*student)[i].name);
        free((*student)[i].grades);
        
    }

    free(*student);
}
