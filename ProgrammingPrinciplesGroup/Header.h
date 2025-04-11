#pragma
#ifndef HEADER_H
#define HEADER_H

#define MAX_TASKS 100
#define MAX_STR 100

typedef struct {
    char name[MAX_STR];
    int priority;
    char status[MAX_STR];
    int id;
} Task;

void addTask(Task tasks[], int* count);
void displayTasks(Task tasks[], int count);
void deleteTask(Task tasks[], int* count);
void updateTask(Task tasks[], int count);
void saveDeletedTasks(Task tasks[], int count);
void readDeletedTasks();
void clearTasks(Task tasks[], int* count);

#endif

