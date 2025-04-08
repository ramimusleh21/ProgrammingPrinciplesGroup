#pragma once
#include "globals.h"
#include "item.h"
#include "HighPriorityTask.h"
#include "LowPriorityTasks.h"
#include "MediumPriorityTasks.h"
#include "List.h"
#include <stdbool.h>


typedef struct collection_of_task {
	int maxsize;
	TLISTNODE tasks;
}COLLECTION_OF_TASKS;


//C-Create

COLLECTION_OF_TASKS Create_Collection_Of_Tasks(int maxsize);


//R-Read

void Print_Collection_Of_Tasks(COLLECTION_OF_TASKS task_collection);
int Get_Max_No_Of_Tasks(COLLECTION_OF_TASKS task_collection);
int Get_Cur_No_Of_Tasks(COLLECTION_OF_TASKS task_collection);
bool Add_Task_Type_To_Collection_Of_Tasks(TASK_TYPES data, COLLECTION_OF_TASKS* task_collection);
void Add_HPT_Collection_Of_Tasks(HIGHPTASK hpt, COLLECTION_OF_TASKS* task_collection);
void Add_LPT_Collection_Of_Tasks(LOWPTASK lpt, COLLECTION_OF_TASKS* task_collection);
void Add_MPT_Collection_Of_Tasks(MEDIUMPTASK mpt, COLLECTION_OF_TASKS* task_collection);
void Delete_Collection_Of_Tasks(COLLECTION_OF_TASKS task_collection);
void Print_Unfinished_Tasks(COLLECTION_OF_TASKS task_collection);
void Print_Finished_Tasks(COLLECTION_OF_TASKS task_collection);
void Print_All_HPT(COLLECTION_OF_TASKS task_collection);
void Print_All_LPT(COLLECTION_OF_TASKS task_collection);
void Print_All_MPT(COLLECTION_OF_TASKS task_collection);


//Features
void Add_New_Task_To_Collection_Of_Tasks(COLLECTION_OF_TASKS* task_collection);
void Update_Task_Name(TLISTNODE task);
void Update_Task_Status(TLISTNODE task);
void Update_Task_Priority(TLISTNODE task);
void Update_Task_In_Collection_Of_Tasks(COLLECTION_OF_TASKS* task_collection);
void Delete_Task_From_Collection_Of_Tasks(COLLECTION_OF_TASKS* task_collection);