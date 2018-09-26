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

class DietPlan
{
public :
	// constructor
	DietPlan();
	
	// copy constructor
	DietPlan(DietPlan &Copy);

	//destructor
	~DietPlan();

	double getGoal();

	string getName();
	string getDate();

	void setGoal(double value);

	void setPlanName(string name);
	
	void setPlanDate(string date);

	void editGoal();



private:
		int calGoals;
		string planName;
		string Date;
	
};
