// prog71990w25 - Rami m. - Group Assignment

#include<stdio.h>
#include "globals.h"

void display_menu() {
    printf("1. Add Task\n");
    printf("2. Delete Task\n");
    printf("3. Update Task\n");
    printf("4. Display Single Task\n");
    printf("5. Display Range of Tasks\n");
    printf("6. Display All Tasks\n");
    printf("7. Search Task\n");
    printf("8. Save Data\n");
    printf("9. Load Data\n");
    printf("0. Exit\n");
}

int main() {
    struct TaskList task_list;
    task_list.count = 0;  
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