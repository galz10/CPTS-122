
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


void readFile(FILE *infile, FitbitData F[1440]);
double totalCalories(FitbitData F[1440]);
double totalDistance(FitbitData F[1440]);
int totalFloors(FitbitData F[1440]);
int totalSteps(FitbitData F[1440]);
int avrgHearRate(FitbitData F[1440]);
int maxSteps(FitbitData F[1440]);
void worstSleep(char *start, char *end, FitbitData F[1441]);

#endif