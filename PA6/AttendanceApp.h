///////////////////////////////////////////////////////////////////////////////
/// \file         AttendanceApp.h
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "AbsentList.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::getline;

class AttendanceApp
{
public:
	AttendanceApp();
	~AttendanceApp();
	void run();

private:
	int DisplayMenu();
	bool ImportList(string name);
	bool StoreList(string name);
	AbsentList list;
	ifstream inFile;
	ofstream outFile;

};
