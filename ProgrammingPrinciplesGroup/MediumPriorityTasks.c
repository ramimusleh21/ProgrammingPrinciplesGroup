#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "globals.h"
#include "MediumPriorityTasks.h"
#include <string.h>
#include <stdbool.h>

//Implementation of Medium task Priority

//C-Create

MEDIUMPTASK Create_MediumP_Tasks(int task_id,  char* task_name,  char* status, int priority) {
    MEDIUMPTASK mediumptask = { 0 };
    mediumptask.task_id = task_id;
    mediumptask.priority = priority;
    strncpy_s(mediumptask.task_name, MAX_NAME_LENGTH, task_name, _TRUNCATE);
    strncpy_s(mediumptask.status, MAX_NAME_LENGTH, status, _TRUNCATE);
    return mediumptask;
}

//R-Read

void Print_MidP_Tasks(MEDIUMPTASK mediumptask) {
    printf("Task  ID         : %d   \n", mediumptask.task_id);
    printf("Task Name       : %s   \n", mediumptask.task_name);
    printf("Task Priority   : MEDIUM \n");
    printf("Tast Status     : %s   \n", mediumptask.status);
}

bool Compare_MPT(MEDIUMPTASK lhs, MEDIUMPTASK rhs) {
    return (lhs.task_id = rhs.task_id);
}

MEDIUMPTASK Copy_MPT(MEDIUMPTASK src) {
    return Create_MediumP_Tasks(src.task_name, src.status, src.task_id, src.priority);
}
//U-update

void Write_MediumP_Task_To_Stream(MEDIUMPTASK mediumptasks, FILE* stream) {
    // Implementation needed
}

//d-DELETE
void Delete_MediumP_Task(MEDIUMPTASK mediumptask) {
    // Implementation needed
}



