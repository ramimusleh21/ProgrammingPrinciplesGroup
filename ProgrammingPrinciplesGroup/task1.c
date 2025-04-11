#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


#define MAX_TASKS 100
#define MAX_STR 100


typedef struct {
    int id;
    char name[MAX_STR];
    int priority;
    char status[MAX_STR];
} Task;


void addTask(Task tasks[], int* count);
void displayTasks(Task tasks[], int count);
void deleteTask(Task tasks[], int* count);
void updateTask(Task tasks[], int count);
void saveDeletedTasks(Task tasks[], int count);
void readDeletedTasks();
void clearTasks(Task tasks[], int* count);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        printf("\n SIMPLE TASK MANAGER \n");
        printf("1. Add a New Task\n");
        printf("2. Show All Tasks\n");
        printf("3. Delete a Task\n");
        printf("4. Update a Task\n");
        printf("5. Save Deleted Tasks to File\n");
        printf("6. Read Deleted Tasks from File\n");
        printf("7. Clear All Tasks\n");
        printf("0. Exit\n");
        printf("Please pick an option: ");
        scanf_s("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1:
            addTask(tasks, &taskCount);
            break;
        case 2:
            displayTasks(tasks, taskCount);
            break;
        case 3:
            deleteTask(tasks, &taskCount);
            break;
        case 4:
            updateTask(tasks, taskCount);
            break;
        case 5:
            saveDeletedTasks(tasks, taskCount); 
            break;
        case 6:
            readDeletedTasks();
            break;
        case 7:
            clearTasks(tasks, &taskCount);
            break;
        case 0:
            printf("Bye!\n");
            break;
        default:
            printf("Please choose a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

void addTask(Task tasks[], int* count) {
    if (*count >= MAX_TASKS) {
        printf("Your task list is full.\n");
        return;
    }

    printf("Please enter the task name: ");
    fgets(tasks[*count].name, MAX_STR, stdin);
    tasks[*count].name[strcspn(tasks[*count].name, "\n")] = 0;

    printf(" Please enter task priority (1-10): ");
    scanf_s("%d", &tasks[*count].priority);
    getchar();

    printf("Enter task status (e.g., pending, done): ");
    fgets(tasks[*count].status, MAX_STR, stdin);
    tasks[*count].status[strcspn(tasks[*count].status, "\n")] = 0;

    tasks[*count].id = *count + 1;
    (*count)++;

    printf("Task added successfully!\n");
}

void displayTasks(Task tasks[], int count) {
    if (count == 0) {
        printf("No tasks to show.\n");
        return;
    }

    printf("\n--- Task List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Priority: %d | Status: %s\n",
            tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].status);
    }
}

void deleteTask(Task tasks[], int* count) {
    if (*count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int id;
    printf("Enter the task ID to delete: ");
    scanf_s("%d", &id);
    getchar();

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                tasks[j] = tasks[j + 1];
                tasks[j].id = j + 1;
            }
            (*count)--;
            found = 1;
            printf("Task deleted.\n");
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

void updateTask(Task tasks[], int count) {
    if (count == 0) {
        printf("No tasks to update.\n");
        return;
    }

    int id;
    printf("Enter the task ID to update: ");
    scanf_s("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            printf("Current Name: %s\n", tasks[i].name);
            printf("Enter new name (leave empty to keep): ");
            char newName[MAX_STR];
            fgets(newName, MAX_STR, stdin);
            if (newName[0] != '\n') {
                newName[strcspn(newName, "\n")] = 0;
                strcpy(tasks[i].name, newName);
            }

            printf("Current Priority: %d\n", tasks[i].priority);
            printf("Enter new priority (0 to skip): ");
            int newPriority;
            scanf_s("%d", &newPriority);
            getchar();
            if (newPriority > 0) {
                tasks[i].priority = newPriority;
            }

            printf("Current Status: %s\n", tasks[i].status);
            printf("Enter new status (leave empty to keep): ");
            char newStatus[MAX_STR];
            fgets(newStatus, MAX_STR, stdin);
            if (newStatus[0] != '\n') {
                newStatus[strcspn(newStatus, "\n")] = 0;
                strcpy(tasks[i].status, newStatus);
            }

            printf("Task updated.\n");
            return;
        }
    }

    printf("Task not found.\n");
}

void saveDeletedTasks(Task tasks[], int count) {
    FILE* file = fopen("deleted_tasks.txt", "w");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%s\n",
            tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].status);
    }
    fclose(file);
    printf("Deleted tasks saved to file.\n");
}

void readDeletedTasks() {
    FILE* file = fopen("deleted_tasks.txt", "r");
    if (!file) {
        printf("No deleted tasks file found.\n");
        return;
    }

    char line[200];
    printf("\n  Deleted Tasks \n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void clearTasks(Task tasks[], int* count) {
    *count = 0;
    printf("All tasks are cleared.\n");
}
