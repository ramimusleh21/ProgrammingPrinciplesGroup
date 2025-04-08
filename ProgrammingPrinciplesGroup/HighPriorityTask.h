#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "globals.h"


typedef struct high_priority_task {
    int task_id;
    char task_name[MAX_NAME_LENGTH];
    char status[MAX_NAME_LENGTH];
    int priority;
} HIGHPTASK;


//C-Create

HIGHPTASK Create_HighP_Tasks(int task_id, char* task_name,  char* status, int priority);

//R-Read

void Print_HighP_Tasks(HIGHPTASK highptask);
bool Compare_HPT(HIGHPTASK lhs, HIGHPTASK rhs);
HIGHPTASK Copy_HPT(HIGHPTASK src);
//U-Update
void Write_HighP_Task_To_Stream(HIGHPTASK highptasks,FILE* stream);

//D-delete
void Delete_HighP_Task(HIGHPTASK highptask);
