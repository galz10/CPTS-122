#include"DietPlan.h"
DietPlan::DietPlan()
{
	calGoals = 0.0;
	Date = "\0";
	planName = "Diet Plan";
}

void DietPlan::setPlanDate(string date)
{
	Date = date;
}

void DietPlan::editGoal()
{
	double value11 = 0.0;
	string val1 = "\0", value = "\0";
	cout << "What do you want to set the calorie goal to ? " << endl;
	cin >> value11;
	DietPlan::setGoal(value11);
	cout << "What do you want to set the plans name? " << endl;
	cin >> value;
	DietPlan::setPlanName(value);
	cout << "What do you want to set the date to? " << endl;
	cin >> val1;
	DietPlan::setPlanDate(val1);
}


DietPlan::DietPlan(DietPlan &Copy)
{
	calGoals = Copy.calGoals;
	Date = Copy.Date;
	planName = Copy.planName;
}
string DietPlan::getName()
{
	planName = planName;
	return planName;
}
string DietPlan::getDate()
{
	Date = Date;
	return Date;
}
void DietPlan::setGoal(double value)
{
	calGoals = value;
}

void DietPlan::setPlanName(string name)
{
	planName = name;
}

DietPlan::~DietPlan()
{
	//cout << "In the destructor" << endl;
}

double DietPlan::getGoal()
{
	calGoals = calGoals;
	return calGoals;
}

