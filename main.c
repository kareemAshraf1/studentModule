// main.c
#include<stdio.h>
#include "student.h"

int main() {
    const char *filename = "test.csv";
    int local_nTargetId,opt;
    student_t sData;
    printf("Enter your id : ");
    scanf("%d", &local_nTargetId);

    int result = ASM_nReadStudentData(filename, local_nTargetId, &sData);
    printf("Enter 0 to edit your data. ");
    printf("Enter 1 to view your record. ");
    scanf("%d",&opt);
    if(opt == 0){
    if (result == 0) {
        printf("%d\n", sData.nUnique_Id);
        printf("%s\n", sData.cName);

        printf("%s\n", sData.cPassword);
        char newPassword[50], newName[50];
        printf("Enter the new name : ");
        scanf("%49s", newName);
        printf("Enter the new password : ");
        scanf("%49s", newPassword);
        ASM_nEditStudentData(&sData, newName, newPassword);
        printf("your new name : %s\n", sData.cName);
        printf("your new password : %s\n", sData.cPassword);
    } else {
        printf("Student with ID %d not found.\n", local_nTargetId);
    }
    }else if(opt == 1){
        printf("your name : %s\n", sData.cName);
        printf("your total grade : %.2f\n", sData.fTotal_Grade);


    }
    return 0;
}

