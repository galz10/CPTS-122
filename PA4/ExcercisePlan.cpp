#include"ExcercisePlan.h"

ExcercisePlan::ExcercisePlan()
{
	stepGoals = 0;
	planName = "Excercise Plan";
	Date = "\0";
}

ExcercisePlan::ExcercisePlan(ExcercisePlan & Copy)
{
	stepGoals = Copy.stepGoals;
	planName = Copy.planName;
	Date = Copy.Date;
}

ExcercisePlan::~ExcercisePlan()
{
	//cout << "In the Destructor" << endl;
}

int ExcercisePlan::getGoal()
{
	return stepGoals;
}

string ExcercisePlan::getDate()
{
	return Date;
}

string ExcercisePlan::getName()
{
	return planName;
}

void ExcercisePlan::setGoal(int value)
{
	stepGoals = value;
}

void ExcercisePlan::setPlanName(string name)
{
	planName = name;
}

void ExcercisePlan::setDate(string date)
{
	Date = date;
}

void ExcercisePlan::editGoal()
{
	double value11 = 0.0;
	string val1, value;
	cout << "What do you want to set the step goals to ? " << endl;
	cin >> value11;
	ExcercisePlan::setGoal(value11);
	cout << "What do you want to set the plans name? " << endl;
	cin >> value;
	ExcercisePlan::setPlanName(value);
	cout << "What do you want to set the date to? " << endl;
	cin >> val1;
	ExcercisePlan::setDate(val1);
}
