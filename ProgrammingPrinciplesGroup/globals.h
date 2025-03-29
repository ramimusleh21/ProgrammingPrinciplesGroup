#pragma once

typedef struct Task {
    int id;
    char name[100];
   //char description[255];
    int due_year; 
    int due_month; 
    int due_day; 

    int status; 
}TASK;

typedef struct TaskList {
    struct Task tasks[100];  
    int count;  
}TASKLIST;
