#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
#include "globals.h"


typedef struct medium_priority_task {
    int task_id;
    char task_name[MAX_NAME_LENGTH];
    char status[MAX_NAME_LENGTH];
    int priority;
} MEDIUMPTASK;


//C-Create

MEDIUMPTASK Create_MediumP_Tasks(int task_id, char* task_name,char* status, int priority);

//R-Read

void Print_MidP_Tasks(MEDIUMPTASK mediumptask);
MEDIUMPTASK Copy_MPT(MEDIUMPTASK src);
bool Compare_MPT(MEDIUMPTASK lhs, MEDIUMPTASK rhs);


//U-Update
void Write_MediumP_Task_To_Stream(MEDIUMPTASK mediumptasks, FILE* stream);

//D-delete
void Delete_MediumP_Task(MEDIUMPTASK mediumptask);
