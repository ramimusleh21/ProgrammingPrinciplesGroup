// prog71990w25 - Rami m. - Group Assignment

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
#include "globals.h"
#include "Task_main.h"
#include "Task_Type.h"
#include "HighPriorityTask.h"
#include "LowPriorityTasks.h"
#include "MediumPriorityTasks.h"
#include "List.h"


int main() {
    AttemptToOpenFile();

    int choice;
    COLLECTION_OF_TASKS task_collection = Create_Collection_Of_Tasks(1000);

    do {
        display_menu();

        printf("Enter your Option: ");
        (void)scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 1:
            Add_New_Task_To_Collection_Of_Tasks(&task_collection);
            break;
        case 2:
            Delete_Task_From_Collection_Of_Tasks(&task_collection);
            break;
        case 3:
            Update_Task_In_Collection_Of_Tasks(&task_collection);
            break;
        case 4:
            //display_single_task(&task_list);  
            break;
        case 5:
            //display_range_tasks(&task_list);  
            break;
        case 6:
            Print_Collection_Of_Tasks(task_collection);
            break;
        case 7:
            //search_task(&task_list); 
            break;
        case 8:
            //save_data(&task_list); 
            break;
        case 9:
            //load_data(&task_list); 
            break;
        case 0:
            printf("Exiting the application...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

