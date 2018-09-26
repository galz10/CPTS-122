#include"FitnessAppWrapper.h"
#include "DietPlan.h"
#include"ExcercisePlan.h"

void FitnessAppWrapper::runApp()
{
	displayMenu();
}

void FitnessAppWrapper::displayDailyPlan(fstream & fileStream, DietPlan & plan)
{
	DietPlan p1;
	p1 = load1DailyPlan(fileStream, plan);
	cout << " " << endl;
	cout << p1.getName() << endl;
	cout <<"Calorie Goal :"<<p1.getGoal()<<endl;
	cout << "Date :"<<p1.getDate() << endl;
	cout << " " << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[])
{
	int i = 0;
	for (; i <= 6; ++i) 
	{
		displayDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::display1DailyPlan(fstream & fileStream, ExcercisePlan & plan)
{
	ExcercisePlan e1;
	e1 = load2DailyPlan(fileStream, plan);
	cout << " " << endl;
	cout << e1.getName() << endl;
	cout << "Step Goal :"<<e1.getGoal() << endl;
	cout << "Date :"<<e1.getDate() << endl;
	cout << " " << endl;
}

void FitnessAppWrapper::display1WeeklyPlan(fstream & fileStream, ExcercisePlan weeklyPlan[])
{
	int i = 0;
	for (; i <= 6; ++i)
	{
		display1DailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream & fileStream, DietPlan& plan)
{
	fileStream << " " << endl;
	fileStream << plan.getName() << endl;
	fileStream << plan.getGoal() << endl;
	fileStream << plan.getDate() << endl;
	fileStream << " " << endl;
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream & fileStream, ExcercisePlan & plan)
{
	fileStream << " " << endl;
	fileStream << plan.getName() << endl;
	fileStream << plan.getGoal() << endl;
	fileStream << plan.getDate() << endl;
	fileStream << " " << endl;
}



void FitnessAppWrapper::storeWeeklyPlan(std::ofstream & fileStream, DietPlan plan[])
{
	int i = 0;
	fileStream.clear();
	fileStream << "Diet Plan Output" << endl;
	for (; i <= 6; ++i) 
	{
		storeDailyPlan(fileStream,plan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream & fileStream, ExcercisePlan plan[])
{
	int i = 0;
	fileStream.clear();
	fileStream << "Excercise Plan Output" << endl;
	for (; i <= 6; ++i)
	{
		storeDailyPlan(fileStream, plan[i]);
	}
}

int FitnessAppWrapper::displayMenu()
{
	DietPlan d1, d2[10];
	ExcercisePlan e1,e2[10];
	int value = 0, i = 0;
	fstream fs,es;
	std::ofstream file, exfile;
	file.open("DietOut.txt");
	exfile.open("ExcerciseOut.txt");
	fs.open("DietPlan.txt");
	es.open("ExcercisePlan.txt");
	while (value <= 8) {
		cout << "Main Menu" << endl;
		cout << "  1) Load Weekly Diet Plan From File" << endl;
		cout << "  2) Load Weekly Excercise Plan From File" << endl;
		cout << "  3) Store Weekly Diet Plan From File" << endl;
		cout << "  4) Store Weekly Excercise Plan From File" << endl;
		cout << "  5) Display Weekly Diet Plan" << endl;
		cout << "  6) Display Weekly Exercise Plan" << endl;
		cout << "  7) Edit daily Diet Plan" << endl;
		cout << "  8) Edit weekly Diet Plan" << endl;
		cout << "  9) Exit" << endl;
		cin >> value;
		switch (value)
		{
		case 1:load1WeeklyPlan(fs, d2);
			cout << "Weekly Diet Plan Loaded!" << endl;
			cout << "Press anykey to continue!" << endl;
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 2:load2WeeklyPlan(es, e2);
			cout << "Weekly Excercise Plan Loaded!" << endl;
			cout << "Press anykey to continue!" << endl;
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 3:storeWeeklyPlan(file,d2);
			cout << "Succesfully Stored!" << endl;
			cout << "Press anykey to continue!" << endl;
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 4:storeWeeklyPlan(exfile, e2);
			cout << "Succesfully Stored!" << endl;
			cout << "Press anykey to continue!" << endl;
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 5:displayWeeklyPlan(fs, d2);
			cout << "Press anykey to continue!" << endl;
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 6:display1WeeklyPlan(es, e2);
			cout << "Press anykey to continue!" << endl;
			cin.ignore();
			cin.get();
			system("cls");
			break;
		case 7:d2->editGoal();
			break;
		case 8:e2->editGoal();
			break;
		case 9:
			es.close();
			fs.close();
			file.close();
			exfile.close();
			return 0;
			break;
		};
		value = 0;
	}

}


DietPlan & load1DailyPlan(fstream & fileStream, DietPlan & plan)
{
	int i = 0;
	if (plan.getGoal() == 0) {
		string sent;
		getline(fileStream, sent);
		plan .setPlanName(sent);
		getline(fileStream, sent);
		plan.setGoal(std::stof(sent));
		getline(fileStream, sent);
		plan.setPlanDate(sent);
		getline(fileStream, sent);
	}

	return plan;
}

ExcercisePlan & load2DailyPlan(fstream & fileStream, ExcercisePlan &plan)
{
	if (plan.getGoal() == 0) 
	{
		string sent;
		getline(fileStream, sent);
		plan.setPlanName(sent);
		getline(fileStream, sent);
		plan.setGoal(std::stof(sent));
		getline(fileStream, sent);
		plan.setDate(sent);
		getline(fileStream, sent);
	}
	return plan;
}

DietPlan & load1WeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[])
{
	int i = 0;
	for (; i <= 6; ++i) 
	{
		load1DailyPlan(fileStream, weeklyPlan[i]);
	}

	return weeklyPlan[i];
}

ExcercisePlan & load2WeeklyPlan(fstream & fileStream, ExcercisePlan weeklyPlan[])
{
	int i = 0;
	for (; i <= 6; ++i)
	{
		load2DailyPlan(fileStream, weeklyPlan[i]);
	}

	return weeklyPlan[i];
}
