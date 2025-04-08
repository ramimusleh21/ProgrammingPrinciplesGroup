#define _CRT_SECURE_NO_WARNINGS
#define MAX_SUBJECT 100
#define MAX_BUF 50
#include <stdio.h>
#include "functions.h"
#include "globals.h"
#include "Task_main.h"
#include "Task_Type.h"
#include "HighPriorityTask.h"
#include "LowPriorityTasks.h"
#include "MediumPriorityTasks.h"
#include "List.h"

COLLECTION_OF_TASKS Create_Collection_Of_Tasks(int maxsize) {
    COLLECTION_OF_TASKS task_collection = { 0 };
    task_collection.maxsize = maxsize;
    task_collection.tasks = NULL;
    return task_collection;
}

void Print_Collection_Of_Tasks(COLLECTION_OF_TASKS task_collection) {
    int count = Get_Cur_No_Of_Tasks(task_collection);
    printf("No of Tasks: %d\n", count);
    Display_Task_From_List(task_collection.tasks);
}

int Get_Max_No_Of_Tasks(COLLECTION_OF_TASKS task_collection) {
    return task_collection.maxsize;
}

int Get_Cur_No_Of_Tasks(COLLECTION_OF_TASKS task_collection) {
    return Get_Task_Count(task_collection.tasks);
}

bool Add_Task_Type_To_Collection_Of_Tasks(TASK_TYPES data, COLLECTION_OF_TASKS* task_collection) {
    if (Get_Cur_No_Of_Tasks(*task_collection) >= Get_Max_No_Of_Tasks(*task_collection))
        return false;

    return Add_Task_To_Task_List(&(task_collection->tasks), data);
}

// convenience function
void Add_HPT_Collection_Of_Tasks(HIGHPTASK hpt, COLLECTION_OF_TASKS* task_collection) {
    TASK_TYPES data = Create_Task_From_HPT(hpt);
    Add_Task_Type_To_Collection_Of_Tasks(data, task_collection);
}

// convenience function
void Add_LPT_Collection_Of_Tasks(LOWPTASK lpt, COLLECTION_OF_TASKS* task_collection) {
    TASK_TYPES data = Create_Task_From_LPT(lpt);
    Add_Task_Type_To_Collection_Of_Tasks(data, task_collection);
}

// convenience function
void Add_MPT_Collection_Of_Tasks(MEDIUMPTASK mpt, COLLECTION_OF_TASKS* task_collection) {
    TASK_TYPES data = Create_Task_From_MPT(mpt);
    Add_Task_Type_To_Collection_Of_Tasks(data, task_collection);
}

void Delete_Collection_Of_Tasks(COLLECTION_OF_TASKS task_collection) {
    Delete_Task_List(&(task_collection.tasks));
}

void Print_Unfinished_Tasks(COLLECTION_OF_TASKS task_collection) {
    TLISTNODE current = task_collection.tasks;
    printf("Unfinished Tasks:\n");
    while (current != NULL) {
        if (strcmp(current->data.task_details.highptask.status, "unfinished") == 0 ||
            strcmp(current->data.task_details.mediumptask.status, "unfinished") == 0 ||
            strcmp(current->data.task_details.lowptask.status, "unfinished") == 0) {
            Print_Tasks(current->data);
        }
        current = current->next;
    }
}

void Print_Finished_Tasks(COLLECTION_OF_TASKS task_collection) {
    TLISTNODE current = task_collection.tasks;
    printf("Finished Tasks:\n");
    while (current != NULL) {
        if (strcmp(current->data.task_details.highptask.status, "finished") == 0 ||
            strcmp(current->data.task_details.mediumptask.status, "finished") == 0 ||
            strcmp(current->data.task_details.lowptask.status, "finished") == 0) {
            Print_Tasks(current->data);
        }
        current = current->next;
    }
}

void Print_All_HPT(COLLECTION_OF_TASKS task_collection) {
    TLISTNODE current = task_collection.tasks;
    printf("High Priority Tasks:\n");
    while (current != NULL) {
        if (current->data.type == HP) {
            Print_Tasks(current->data);
        }
        current = current->next;
    }
}

void Print_All_LPT(COLLECTION_OF_TASKS task_collection) {
    TLISTNODE current = task_collection.tasks;
    printf("Low Priority Tasks:\n");
    while (current != NULL) {
        if (current->data.type == LP) {
            Print_Tasks(current->data);
        }
        current = current->next;
    }
}

void Print_All_MPT(COLLECTION_OF_TASKS task_collection) {
    TLISTNODE current = task_collection.tasks;
    printf("Medium Priority Tasks:\n");
    while (current != NULL) {
        if (current->data.type == MP) {
            Print_Tasks(current->data);
        }
        current = current->next;
    }
}



void Add_New_Task_To_Collection_Of_Tasks(COLLECTION_OF_TASKS* task_collection) {
    char task_name[MAX_NAME_LENGTH];
    int priority;
    int task_id = Get_Cur_No_Of_Tasks(*task_collection) + 1;
    const char* status = "unfinished";

    printf("Enter task name: ");
    (void)scanf("%s", task_name);
    printf("Enter task priority (1 for High, 2 for Medium, 3 for Low): ");
    (void)scanf("%d", &priority);

    bool added = false;
    if (priority == 1) {
        HIGHPTASK hpt = Create_HighP_Tasks(task_id, task_name, status, priority);
        added = Add_Task_Type_To_Collection_Of_Tasks(Create_Task_From_HPT(hpt), task_collection);
    }
    else if (priority == 2) {
        MEDIUMPTASK mpt = Create_MediumP_Tasks(task_id, task_name, status, priority);
        added = Add_Task_Type_To_Collection_Of_Tasks(Create_Task_From_MPT(mpt), task_collection);
    }
    else if (priority == 3) {
        LOWPTASK lpt = Create_LowP_Tasks(task_id, task_name, status, priority);
        added = Add_Task_Type_To_Collection_Of_Tasks(Create_Task_From_LPT(lpt), task_collection);
    }
    else {
        printf("Invalid priority entered.\n");
    }

    if (added) {
        printf("Task added successfully. Task ID: %d\n", task_id);
    }
    else {
        printf("Failed to add task.\n");
    }
}



void Update_Task_Name(TLISTNODE task) {
    char new_task_name[MAX_NAME_LENGTH];
    printf("Enter new task name: ");
    (void)scanf("%s", new_task_name);

    if (task->data.type == HP) {
        strcpy(task->data.task_details.highptask.task_name, new_task_name);
    }
    else if (task->data.type == MP) {
        strcpy(task->data.task_details.mediumptask.task_name, new_task_name);
    }
    else if (task->data.type == LP) {
        strcpy(task->data.task_details.lowptask.task_name, new_task_name);
    }
    printf("Task name updated successfully.\n");
}

void Update_Task_Status(TLISTNODE task) {
    char new_status[MAX_NAME_LENGTH];
    printf("Enter new task status (unfinished/finished): ");
    (void)scanf("%s", new_status);

    if (task->data.type == HP) {
        strcpy(task->data.task_details.highptask.status, new_status);
    }
    else if (task->data.type == MP) {
        strcpy(task->data.task_details.mediumptask.status, new_status);
    }
    else if (task->data.type == LP) {
        strcpy(task->data.task_details.lowptask.status, new_status);
    }
    printf("Task status updated successfully.\n");
}

void Update_Task_Priority(TLISTNODE task) {
    int new_priority;
    printf("Enter new task priority (1 for High, 2 for Medium, 3 for Low): ");
    (void)scanf("%d", &new_priority);

    if (task->data.type == HP) {
        task->data.task_details.highptask.priority = new_priority;
    }
    else if (task->data.type == MP) {
        task->data.task_details.mediumptask.priority = new_priority;
    }
    else if (task->data.type == LP) {
        task->data.task_details.lowptask.priority = new_priority;
    }
    printf("Task priority updated successfully.\n");
}

void Update_Task_In_Collection_Of_Tasks(COLLECTION_OF_TASKS* task_collection) {
    int task_id;
    int choice;

    printf("Enter task ID to update: ");
    (void)scanf("%d", &task_id);

    TLISTNODE current = task_collection->tasks;
    while (current != NULL) {
        if ((current->data.type == HP && current->data.task_details.highptask.task_id == task_id) ||
            (current->data.type == MP && current->data.task_details.mediumptask.task_id == task_id) ||
            (current->data.type == LP && current->data.task_details.lowptask.task_id == task_id)) {

            printf("Select the field to update:\n");
            printf("1. Task Name\n");
            printf("2. Task Status\n");
            printf("3. Task Priority\n");
            printf("Enter your choice: ");
            (void)scanf("%d", &choice);

            switch (choice) {
            case 1:
                Update_Task_Name(current);
                break;
            case 2:
                Update_Task_Status(current);
                break;
            case 3:
                Update_Task_Priority(current);
                break;
            default:
                printf("Invalid choice.\n");
                break;
            }
            return;
        }
        current = current->next;
    }

    printf("Task with ID %d not found.\n", task_id);
}

void Delete_Task_From_Collection_Of_Tasks(COLLECTION_OF_TASKS* task_collection) {
    int task_id;
    printf("Enter task ID to delete: ");
    (void)scanf("%d", &task_id);

    TLISTNODE* current = &(task_collection->tasks);
    while (*current != NULL) {
        if (((*current)->data.type == HP && (*current)->data.task_details.highptask.task_id == task_id) ||
            ((*current)->data.type == MP && (*current)->data.task_details.mediumptask.task_id == task_id) ||
            ((*current)->data.type == LP && (*current)->data.task_details.lowptask.task_id == task_id)) {

            TLISTNODE temp = *current;
            *current = (*current)->next;
            free(temp);
            printf("Task with ID %d deleted successfully.\n", task_id);
            return;
        }
        current = &((*current)->next);
    }

    printf("Task with ID %d not found.\n", task_id);
}