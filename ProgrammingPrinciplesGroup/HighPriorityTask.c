#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "globals.h"
#include "HighPriorityTask.h"
#include <string.h>

//implementation of HIGH_PRIORITY_TASKS

//C-create

HIGHPTASK Create_HighP_Tasks(int task_id,char* task_name,char* status,int priority) {
    HIGHPTASK highptasks = { 0 };
    highptasks.task_id = task_id;
    highptasks.priority = priority;
    strncpy_s(highptasks.task_name, MAX_NAME_LENGTH, task_name, _TRUNCATE);
    strncpy_s(highptasks.status, MAX_NAME_LENGTH, status, _TRUNCATE);
    return highptasks;
}

//R-read

bool Compare_HPT(HIGHPTASK lhs, HIGHPTASK rhs) {
    return (lhs.task_id = rhs.task_id);
}

HIGHPTASK Copy_HPT(HIGHPTASK src) {
    return Create_HighP_Tasks(src.task_name, src.status, src.task_id, src.priority);
}

void Print_HighP_Tasks(HIGHPTASK highptask) {
    printf("Task  ID         : %d   \n", highptask.task_id);
    printf("Task Name       : %s   \n", highptask.task_name);
    printf("Task Priority   : HIGH \n");
    printf("Tast Status     : %s   \n" , highptask.status);
}

//U-update

void Write_HighP_Task_To_Stream(HIGHPTASK highptasks, FILE* stream) {
    // Implementation needed
}

//D-delete

void Delete_HighP_Task(HIGHPTASK highptask) {
    // Implementation needed
}



