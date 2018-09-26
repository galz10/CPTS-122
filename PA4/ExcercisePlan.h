#pragma once
#include <iostream>
#include <string>
#include <fstream>

//fstr.open(txt)

using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;

class ExcercisePlan
{
public:
	// constructor
	ExcercisePlan();

	//copy constructor
	ExcercisePlan(ExcercisePlan &Copy);

	//destructor
	~ExcercisePlan();

	int getGoal();
	string getDate();
	string getName();
	void setGoal(int value);
	void setPlanName(string name);
	void setDate(string date);
	void editGoal();

private:
	int stepGoals;
	string planName;
	string Date;
};