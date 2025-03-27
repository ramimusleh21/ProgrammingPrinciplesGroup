#pragma once
typedef struct Task {
    int id;
    char name[100];
    char description[200];
    int priority;
    struct Task* next;
} Task;
