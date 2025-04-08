#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "globals.h"
#include "Task_main.h"
#include "Task_Type.h"
#include "HighPriorityTask.h"
#include "LowPriorityTasks.h"
#include "MediumPriorityTasks.h"
#include "List.h"




TASK_TYPES Create_Task_From_HPT(HIGHPTASK hpt) {
	TASK_TYPES data = { 0 };
	data.task_details.highptask = hpt;
	data.type = HP;
	return data;
}

TASK_TYPES Create_Task_From_LPT(LOWPTASK lpt) {
	TASK_TYPES data = { 0 };
	data.task_details.lowptask = lpt;
	data.type = LP;
	return data;
}

TASK_TYPES Create_Task_From_MPT(MEDIUMPTASK mpt) {
	TASK_TYPES data = { 0 };
	data.task_details.mediumptask = mpt;
	data.type = MP;
	return data;
}


bool Compare_Tasks(TASK_TYPES lhs, TASK_TYPES rhs) {
	if (lhs.type != rhs.type)
		return false;

	switch (lhs.type) {
	case HP: return Compare_HPT(
		lhs.task_details.highptask,
		rhs.task_details.highptask);
		break;
	case LP: return Compare_LPT(
		lhs.task_details.lowptask,
		rhs.task_details.lowptask);
		break;
	case MP: return Compare_MPT(
		lhs.task_details.mediumptask,
		rhs.task_details.mediumptask);
		break;
	default:	fprintf(stderr, "unhandled case");
		return false;
	}

}

TASK_TYPES Copy_Task(TASK_TYPES src) {
	TASK_TYPES dst = { 0 };

	dst.type = src.type;

	switch (src.type) {
	case HP: dst.task_details.highptask = Copy_HPT(src.task_details.highptask);
		break;
	case MP: dst.task_details.mediumptask = Copy_MPT(src.task_details.mediumptask);
		break;
	case LP:dst.task_details.lowptask = Copy_LPT(src.task_details.lowptask);
		break;
	default: fprintf(stderr, "error comparing types\n");
		exit(EXIT_FAILURE);
	}

	return dst;
}



void Print_Tasks(TASK_TYPES data) {
	switch (data.type) {
	case HP:	Print_HighP_Tasks(data.task_details.highptask);
		break;
	case MP:	Print_MidP_Tasks(data.task_details.mediumptask);
		break;
	case LP:	Print_LowP_Tasks(data.task_details.lowptask);
		break;
	default:	fprintf(stderr, "invalid Participant type\n");
		break;
	}
}



void Delete_Tasks(TASK_TYPES data) {
	
}