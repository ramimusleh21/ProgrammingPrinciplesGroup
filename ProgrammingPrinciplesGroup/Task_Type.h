#pragma once
#include<stdio.h>
#include<stdbool.h>
#include"HighPriorityTask.h"
#include"LowPriorityTasks.h"
#include"MediumPriorityTasks.h"

typedef union components {
	HIGHPTASK highptask;
	MEDIUMPTASK mediumptask;
	LOWPTASK lowptask;
}COMPONENTS;

typedef enum type { HP, MP, LP }TYPE;

typedef struct task_types {
	TYPE type;
	COMPONENTS task_details;
} TASK_TYPES;

TASK_TYPES Create_Task_From_HPT(HIGHPTASK hpt);
TASK_TYPES Create_Task_From_LPT(LOWPTASK lpt);
TASK_TYPES Create_Task_From_MPT(MEDIUMPTASK mpt);

//R-Read
void Print_Tasks(TASK_TYPES data);
TASK_TYPES Copy_Task(TASK_TYPES src);
bool Compare_Tasks(TASK_TYPES lhs, TASK_TYPES rhs);

//U-Update
//void Write_Tasks_To_Stream(TASK_TYPES data, FILE* stream);
//TASK_TYPES Read_Task_From_Stream(FILE* stream);

//D-Delete
void Delete_Tasks(TASK_TYPES data);