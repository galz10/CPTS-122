///////////////////////////////////////////////////////////////////////////////
/// \file         Node.h
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Stack.h"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::getline;
using std::stringstream;




class Node
{
	friend class AbsentList;
public:
	Node(string line);
	~Node();
	string getStdInf();
	string getRctAbs();
	string getAbs();
	int getNumAbs();
	void addAb();

private:
	Node *pNext;
	int numAbs;
	int Record;
	int ID;
	string Program;
	string Name;
	string Units;
	string Email;
	string ClassRanking;
	Stack <string>* absences;
};
