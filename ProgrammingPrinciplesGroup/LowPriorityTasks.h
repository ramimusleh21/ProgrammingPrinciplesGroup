#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "globals.h"


typedef struct low_priority_task {
    int task_id;
    char task_name[MAX_NAME_LENGTH];
    char status[MAX_NAME_LENGTH];
    int priority;
} LOWPTASK;


//C-Create

LOWPTASK Create_LowP_Tasks(int task_id, const char* task_name, const char* status, int priority);
bool Compare_LPT(LOWPTASK lhs, LOWPTASK rhs);
LOWPTASK Copy_LPT(LOWPTASK src);

//R-Read

void Print_LowP_Tasks(LOWPTASK lowptask);


//U-Update
void Write_LowP_Task_To_Stream(LOWPTASK lowptasks, FILE* stream);

//D-delete
void Delete_LowP_Task(LOWPTASK lowptask);