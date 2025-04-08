#pragma once
#include "globals.h"
#include "item.h"
#include "HighPriorityTask.h"
#include "LowPriorityTasks.h"
#include "MediumPriorityTasks.h"
#include "List.h"
#include <stdbool.h>
#include <stdio.h>
#include "functions.h"
#include "globals.h"
#include "Task_main.h"
#include "Task_Type.h"
#include "List.h"
#include "item.h"

//typedef struct Task {
//    int id;
//    char name[100];
//    char description[200];
//    int priority;
//    struct Task* next;
//} Task;


void AttemptToOpenFile();

void CreateNewFile();

void display_menu();

