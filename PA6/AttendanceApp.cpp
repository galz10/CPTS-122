#include "AttendanceApp.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  AttendanceApp.cpp
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
AttendanceApp::AttendanceApp()
{
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  ~AttendanceApp()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
AttendanceApp::~AttendanceApp()
{
	//In destructor
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  DisplayMenu();
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
int AttendanceApp::DisplayMenu()
{
	int i;
	cout << "Welcome to Attendence Tracker" << endl;
	cout << " 1) Load Course List" << endl;
	cout << " 2) Load Master List" << endl;
	cout << " 3) Store Master List" << endl;
	cout << " 4) Mark Absences" << endl;
	cout << " 5) Edit Absences" << endl;
	cout << " 6) Generate Report" << endl;
	cout << " 7) Exit" << endl;
	cin >> i;

	return i;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  ImportList();
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AttendanceApp::ImportList(string name)
{
	if (!inFile.is_open())
	{
		inFile.open(name);
		list.load(inFile);
		return true;
	}
	else if (inFile.is_open())
	{
		list.load(inFile);
		return true;
	}
	else
	{
		cout << "ERROR CHECK FILE !!" << endl;
		return false;
	}
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  StoreList()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AttendanceApp::StoreList(string name)
{
	if (!outFile.is_open())
	{
		outFile.open(name);
		list.store(outFile);
		return true;
	}
	else if (outFile.is_open())
	{
		list.store(outFile);
		return true;
	}
	else
	{
		cout << "ERROR CHECK FILE !!" << endl;
		return false;
	}

}
///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  run();
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void AttendanceApp::run()
{
	int i = 0, x =0;
	while (i <=6)
	{
		i = DisplayMenu();
		switch (i)
		{
		case 1:ImportList("ClassList.csv");
			_sleep(1000);
			system("cls");
			break;
		case 2:ImportList("masterList.csv");
			_sleep(1000);
			system("cls");
			break;
		case 3:StoreList("masterList.csv");
			_sleep(1000);
			system("cls");
			break;
		case 4:list.markAbs();
			break;
		case 5:cout << "???Currently Under Development???" << endl;
			_sleep(1000);
			system("cls");
			break;
		case 6:
			cout << "Welcome to Sub Attendence Tracker Menu" << endl;
			cout << " 1) Generate Report for All Student" << endl;
			cout << " 2) Load Master List" << endl;
			cin >> x;

			switch (x)
			{
			case 1:list.RecAbs();
				break;
			case 2:
				cout << "Generate a Report of students that have been absent for 1 - 180 days : how many days ?" << endl;
				cin >> x;
				list.allAbs(x);
				break;
			}
		
		}
	}
}