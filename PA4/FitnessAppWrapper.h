#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include<ostream>
#include "DietPlan.h"
#include"ExcercisePlan.h"

//fstr.open(txt)
using std::fstream;
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
using std::getline;


class FitnessAppWrapper
{
public:

	void runApp();
	void displayDailyPlan(fstream &fileStream, DietPlan &plan);
	void displayWeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[]);
	void display1DailyPlan(fstream &fileStream, ExcercisePlan &plan);
	void display1WeeklyPlan(fstream & fileStream, ExcercisePlan weeklyPlan[]);
	void storeDailyPlan(std::ofstream &fileStream, DietPlan &plan);
	void storeDailyPlan(std::ofstream &fileStream, ExcercisePlan &plan);
	void storeWeeklyPlan(std::ofstream &fileStream, DietPlan plan[]);
	void storeWeeklyPlan(std::ofstream &fileStream, ExcercisePlan plan[]);
	int displayMenu();
private:
};

DietPlan& load1DailyPlan(fstream &fileStream, DietPlan &plan);
ExcercisePlan& load2DailyPlan(fstream &fileStream, ExcercisePlan &plan);
DietPlan &load1WeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[]);
ExcercisePlan &load2WeeklyPlan(fstream & fileStream, ExcercisePlan weeklyPlan[]);