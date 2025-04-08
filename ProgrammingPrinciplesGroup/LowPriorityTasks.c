#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "globals.h"
#include "LowPriorityTasks.h"
#include <string.h>
#include <stdbool.h>

//implementation of LOW_PRIORITY_TASKS

//C-create

LOWPTASK Create_LowP_Tasks(int task_id, char* task_name,char* status, int priority) {
    LOWPTASK lowptasks = { 0 };
    lowptasks.task_id = task_id;
    lowptasks.priority = priority;
    strncpy_s(lowptasks.task_name, MAX_NAME_LENGTH, task_name, _TRUNCATE);
    strncpy_s(lowptasks.status, MAX_NAME_LENGTH, status, _TRUNCATE);
    return lowptasks;
}
bool Compare_LPT(LOWPTASK lhs, LOWPTASK rhs) {
    return (lhs.task_id = rhs.task_id);
}

LOWPTASK Copy_LPT(LOWPTASK src) {
    return Create_LowP_Tasks(src.task_name, src.status, src.task_id, src.priority);
}
//R-read

void Print_LowP_Tasks(LOWPTASK lowptask) {
    printf("Task  ID         : %d", lowptask.task_id);
    printf("Task Name       : %s", lowptask.task_name);
    printf("Task Priority   : LOW");
    printf("Tast Status     : %s", lowptask.status);
}

//U-update

void Write_LowP_Task_To_Stream(LOWPTASK lowptasks, FILE* stream) {
    // Implementation needed
}

//D-delete

void Delete_LowP_Task(LOWPTASK lowptask) {
    // Implementation needed
}



