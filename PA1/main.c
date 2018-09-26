#include "functions.h"
int main(int argc, char *argv[])
{
	FitbitData F[1441];
	// open files
	FILE *Infile = {NULL};
	FILE *Outfile = { NULL };
	Infile = fopen("data.csv", "r");
	Outfile = fopen("Resualt.csv", "w");

	double Cals = 0.0, Dist = 0.0;
	char start[10], end[10];
	int Floors = 0, Steps = 0, heartRate = 0, MaxSteps = 0;

	//checks if infile is open
	if(Infile != NULL)
	{
		
		readFile(Infile, F);
		Cals = totalCalories(F);
		Dist = totalDistance(F);
		Floors = totalFloors(F);
		Steps = totalSteps(F);
		heartRate = avrgHearRate(F);
		MaxSteps = maxSteps(F);
		worstSleep(start, end, F);

		printf("Total Calories : %lf\n", Cals);
		printf("Total Distance : %lf\n", Dist);
		printf("Total Floors : %d\n", Floors);
		printf("Total Steps : %d\n", Steps);
		printf("Average Heart Rate : %d\n", heartRate);
		printf("Max Steps Taken in a Min : %d\n", MaxSteps);
		printf("The period of worst sleep was between %s and %s\n", start, end);


		fprintf(Outfile,"Total Calories : %lf\n", Cals);
		fprintf(Outfile,"Total Distance : %lf\n", Dist);
		fprintf(Outfile,"Total Floors : %d\n", Floors);
		fprintf(Outfile,"Total Steps : %d\n", Steps);
		fprintf(Outfile,"Average Heart Rate : %d\n", heartRate);
		fprintf(Outfile,"Max Steps Taken in a Min : %d\n", MaxSteps);
		fprintf(Outfile,"The period of worst sleep was between %s and %s\n", start, end);
	}
	else
	{
		printf("File Was Not Read");
	}

	fclose(Infile);
	fclose(Outfile);

	
}