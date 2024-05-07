// student.c
#include "student.h"
#include <stdio.h>
#include <string.h>

int ASM_nReadStudentData(const char *filename, int local_nTargetId, student_t *sData) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("The file not found");
        return 1;
    } else {
        while (fscanf(file, "%u,%9[^,],%49[^,],%f,%u,%49[^,],%49[^,]\n",
                      &sData->nUnique_Id, sData->cGender, sData->cName,
                      &sData->fTotal_Grade, &sData->nAge, sData->cPassword) == 6) {
            if (sData->nUnique_Id == local_nTargetId) {
                fclose(file);
                return 0;
            }
        }
        fclose(file);
        return 1;
    }
}

int ASM_nEditStudentData(student_t *sData, const char *newName, const char *newPassword) {
    if (sData != NULL) {
        if (newName != NULL) {
            strncpy(sData->cName, newName, sizeof(sData->cName) - 1);
            sData->cName[sizeof(sData->cName) - 1] = '\0';
        }
        if (newPassword != NULL) {
            strncpy(sData->cPassword, newPassword, sizeof(sData->cPassword) - 1);
            sData->cPassword[sizeof(sData->cPassword) - 1] = '\0';
        }
        return 0;
    } else {
        return -1;
    }
}

