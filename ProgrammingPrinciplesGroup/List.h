#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include "Task_Type.h"

typedef struct task_list {
    TASK_TYPES data;
    struct task_list* next;
} LISTNODE, * TLISTNODE;

// C-Create
bool Add_Task_To_Task_List(TLISTNODE* list, TASK_TYPES data);

// R-Read
void Display_Task_From_List(TLISTNODE list);
int Get_Task_Count(TLISTNODE list);

// U-Update
void Write_Task_To_Stream();
void Remove_Task_From_List(TLISTNODE* list, TASK_TYPES data);

// D-Delete
void Delete_Task_List(TLISTNODE* list);

#endif // LIST_H
