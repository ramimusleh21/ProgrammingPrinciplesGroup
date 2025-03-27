// prog71990w25 - Rami m. - Group Assignment

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "globals.h"
#include "functions.h"


int main() {
    struct TaskList task_list;
    task_list.count = 0;  
    
    AttemptToOpenFile();
    
    int choice;


    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            //add_task(&task_list);  
            break;
        case 2:
            //delete_task(&task_list);  
            break;
        case 3:
            //update_task(&task_list); 
            break;
        case 4:
            //display_single_task(&task_list);  
            break;
        case 5:
            //display_range_tasks(&task_list);  
            break;
        case 6:
            //display_all_tasks(&task_list); 
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