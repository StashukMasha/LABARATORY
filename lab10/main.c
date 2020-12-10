#include"header.h"

int main()
{
    struct Group* Student;

    int quantitiStudents;
    printf("enter quantiti of students: ");
    scanf("%d", &quantitiStudents);
    Student = (struct Group*)malloc(quantitiStudents * sizeof(struct Group));

    int quantitiGrades;
    printf("enter quantiti of grades: ");
    scanf("%d", &quantitiGrades);

    initializationStruct(Student, quantitiStudents, quantitiGrades);
    showResult(Student, quantitiStudents, quantitiGrades);
    surchMinGrades(Student, quantitiStudents, quantitiGrades);
    sorting(Student, quantitiStudents, quantitiGrades);
    showResult(Student, quantitiStudents, quantitiGrades);
    culkulateAverage(Student, quantitiStudents, quantitiGrades);
    showResult2(Student, quantitiStudents, quantitiGrades);
    removalOfPoorStudents(Student, &quantitiStudents, quantitiGrades);
    showResult2(Student, quantitiStudents, quantitiGrades);
    freestudents(&Student, quantitiStudents);

    return 0;
}
