#include <stdio.h>
#include <stdbool.h>
#include "Task_Type.h"
#include "List.h"

bool Add_Task_To_Task_List(TLISTNODE* list, TASK_TYPES data) {
	TLISTNODE new_node = (TLISTNODE)malloc(sizeof(LISTNODE));
	if (new_node == NULL) {
		fprintf(stderr, "Error in Allocating Memory\n");
		return false;
	}
	else {
		new_node->data = Copy_Task(data);
		new_node->next = *list;
		*list = new_node;
	}
	return true;
}
void Display_Task_From_List(TLISTNODE list) {
	TLISTNODE current = list;
	while (list != NULL) {
		Print_Tasks(current->data);
		current = current->next;
	}
}

int Get_Task_Count(TLISTNODE list) {
	int count = 0;
	TLISTNODE current = list;
	while (current != NULL) {
		count++;
		current = current->next;

	}
	return current;
}



void Write_Task_To_Stream() {

}
void Remove_Task_From_List(	TLISTNODE* list,TASK_TYPES data) {
	TLISTNODE current = *list;
	if (current != NULL && Compare_Tasks(current->data, data)) {
		*list = current->next;
		Delete_Tasks(current->data);
		free(current);
		return;
	}

	TLISTNODE prev = NULL;
	while (current != NULL && !Compare_Tasks(current->data, data)) {
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return;
	else {
		prev->next = current->next;
		Delete_Tasks(current->data);
		free(current);
	}

}


void Delete_Task_List(TLISTNODE* list) {
	TLISTNODE current = *list;
	while (current != *list) {
		TLISTNODE temp = current;
		Delete_Tasks(current->data);
		current = current->next;
		free(temp);
	}
}