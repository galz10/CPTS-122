#include "functions.h"

/*************************************************************
* Function: read_file                                       *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Reads data and puts it into the struct       *
* Input parameters: a file and a struct                     *
* Returns: Nothing                                          *
*************************************************************/

void readFile(FILE *infile, FitbitData F[1440])
{
	int i = 0, floors = 0, steps = 0, heartrate = 0, sleeprate = 0;
	char Data[1440] = {"\0"};
	double Cals = 0.0, dist = 0.0;
	fgets(Data, 1440, infile);
	while (!feof(infile))
	{
		fgets(Data, 1440, infile);
		char *pTemp = strtok(Data, ",");
		strcpy(F[i].minute, pTemp);
		pTemp = strtok(NULL, ",");
		if (pTemp != NULL)
		{
			Cals = atof(pTemp);
			F[i].calories = Cals;
		}
		pTemp = strtok(NULL,",");
		if (pTemp != NULL)
		{
			dist = atof(pTemp);
			F[i].distance = dist;
		}
		pTemp = strtok(NULL, ",");
		if (pTemp != NULL)
		{
			floors = atoi(pTemp);
			F[i].floors = floors;
		}
		pTemp = strtok(NULL, ",");
		if (pTemp != NULL)
		{
			heartrate = atoi(pTemp);
			F[i].heartRate = heartrate;
		}
		pTemp = strtok(NULL, ",");
		if (pTemp != NULL)
		{
			steps = atoi(pTemp);
			F[i].steps = steps;
		}
		pTemp = strtok(NULL, ",");
		if (pTemp != NULL)
		{
			sleeprate = atoi(pTemp);
			F[i].sleepLevel = sleeprate;
		}
		++i;
	}
}
/*************************************************************
* Function: totalCalories                                   *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Calculates the total calories by iterating   *
* through  the calorie struct ands sums them up             *
* Input parameters: the struct where cals are stored        *
* Returns: tot cals                                         *
*************************************************************/
double totalCalories(FitbitData F[1440]) 
{
	int i = 0;
	double sum = 0.0, temp = 0.0;

	for (; i < 1440; i++)
	{
		temp = F[i].calories;
		sum = temp + sum;
	}
	return sum;
}
/*************************************************************
* Function: totalDistance                                   *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Calculates the total distance by iterating   *
* through the distance struct ands sums them up             *
* Input parameters: the struct where dist is stored         *
* Returns: tot dist                                         *
*************************************************************/
double totalDistance(FitbitData F[1440]) 
{
	int i = 0;
	double sum = 0.0, temp = 0.0;

	for (; i < 1440; i++)
	{
		temp = F[i].distance;
		sum = temp + sum;
	}
	return sum;
}
/*************************************************************
* Function: totalFloors                                     *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Calculates the total floors walked by        *
* iterating through the floors struct ands sums them up     *
* Input parameters: the struct where floors are stored      *
* Returns:tot floors                                        *
*************************************************************/
int totalFloors(FitbitData F[1440]) 
{
	int i = 0,sum = 0, temp = 0;

	for (; i < 1440; i++)
	{
		temp = F[i].floors;
		sum = temp + sum;
	}
	return sum;
}
/*************************************************************
* Function: totalSteps                                      *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Calculates the total steps by iterating      *
* through  the step struct ands sums them up                *
* Input parameters: the struct where steps are stored       *
* Returns:tot steps                                         *
*************************************************************/
int totalSteps(FitbitData F[1440]) 
{
	int i = 0, sum = 0, temp = 0;

	for (; i < 1440; i++)
	{
		temp = F[i].steps;
		sum = temp + sum;
	}
	return sum;
}
/*************************************************************
* Function: avrgHeartRate                                   *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Calculates the avrg heart rate by iterating  *
* through  the heart struct devides the sum by the amount   *
* of data                                                   *
* Input parameters: the struct where heart rates are stored *
* Returns: heart rate                                       *
*************************************************************/
int avrgHearRate(FitbitData F[1440])
{
	int i = 0, sum = 0, temp = 0, avrg = 0, index =0;


	for (i =0; i < 1440; i++)
	{
		temp = F[i].heartRate;
		if (temp == 0)
		{
			++index;
		}

		temp = F[i].heartRate;
		sum = temp + sum;
	}
	index = 1440 - index;
	avrg = sum / index;
	return avrg;
}
/*************************************************************
* Function: maxSteps                                        *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: Calculates the max steps in a minute         *
* Input parameters: the struct where steps are stored       *
* Returns: steps                                            *
*************************************************************/
int maxSteps(FitbitData F[1440])
{
	int max = 0, i = 0;
	for (; i<1440; i++)
	{
		if (F[i].steps >= max)
		{
			max = F[i].steps;
		}

	}
	return max;


}
/*************************************************************
* Function: worstSleep                                      *
* Date Created: 1/24/2018                                   *
* Date Last Modified:                                       *
* Description: calculates worst sleep                       *
* Input parameters: start time , end time , the struct where*
* sleep is stored in                                        *
* Returns: start and end                                    *
*************************************************************/
void worstSleep(char *start, char *end, FitbitData F[1441])
{
	int i = 0, sum = 0, startT = 0,endT = 0, max = 0, i2 = 0;
	for (; i<1441; i++)
	{
		i2 = i;
		if (F[i2].sleepLevel > 1 && F[i2].sleepLevel != 0){
	
			for (;F[i2].sleepLevel > 1;i2++)
			{
				sum = sum + F[i2].sleepLevel;
			}
			if (sum > max)
			{
				endT = i2;
				max = sum;
			}
		}
	}
	strncpy(start, F[max].minute, 9);
	strncpy(end, F[endT].minute, 9);
	
}