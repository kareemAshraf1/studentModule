// student.h
#include<stdio.h>
#ifndef STUDENT_H
#define STUDENT_H

typedef struct student_t{
    char cGender[10];
    float fTotal_Grade;
    unsigned int nUnique_Id;
    unsigned int nAge;
    struct student_t* sNext;
    char cName[50];
    char cPassword[50];
} student_t;

int ASM_nReadStudentData(const char *filename, int local_nTargetId, student_t *sData);
int ASM_nEditStudentData(student_t *sData, const char *newName, const char *newPassword);

#endif // STUDENT_H
