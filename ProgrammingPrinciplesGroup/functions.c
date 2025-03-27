#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"


void AttemptToOpenFile() {
    FILE* fp = fopen("TaskRecords.txt", "r");

    if (fp == NULL) {
        CreateNewFile();
        return;
    }
    else {
        printf("File Accessed\n");
        fclose(fp);
    }
}

void CreateNewFile() {
    FILE* fp = fopen("TaskRecords.txt", "w");
    printf("File Created\n");
    fprintf(fp, "Hello");
    fclose(fp);
}

void display_menu() {
    printf("1. Add Task\n");
    printf("2. Delete Task\n");
    printf("3. Update Task\n");
    printf("4. Display Single Task\n");
    printf("5. Display Range of Tasks\n");
    printf("6. Display All Tasks\n");
    printf("7. Search Task\n");
    printf("8. Save Data\n");
    printf("9. Load Data\n");
    printf("10. Displays task based on priority");
    printf("0. Exit\n");
}