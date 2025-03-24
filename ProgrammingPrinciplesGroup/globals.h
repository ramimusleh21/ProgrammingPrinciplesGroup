#pragma once

struct Task {
    int id;
    char name[100];
    char description[255];
    char due_date[12]; 
    int status; 
};

struct TaskList {
    struct Task tasks[100];  
    int count;  
};
