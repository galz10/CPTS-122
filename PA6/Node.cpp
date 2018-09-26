#include "Node.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function     ~Node()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node::~Node()
{
	// Inside Deconstructor
}

///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  Node()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////

Node::Node(string line)
{
	string input = " ",first = "",last = "";
	numAbs = 0;
	int i = 1,index = 0;
	stringstream newLine(line);
	//Number of Record
	getline(newLine, input, ',');
	Record = stoi(input);
	++index;
	//ID
	getline(newLine, input, ',');
	ID = stoi(input);
	++index;
	//name
	while (i <= 2) 
	{
		if (i == 1)
		{
			getline(newLine, first, ',');
			++i;
		}
		else if(i == 2)
		{
			getline(newLine, last, ',');
			++i;
		}
	}
	++index;
	//email
	Name = first + " " + last;
	getline(newLine, Email, ',');
	++index;
	//program
	getline(newLine, input, ',');
	Units = stoi(input);
	getline(newLine, Program, ',');
	++index;
	//class ranking
	getline(newLine, ClassRanking, ',');
	absences = new Stack<string>;
	getline(newLine, input, ' ');
	absences->push(input);
	++numAbs;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  getStdInf()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
 string Node::getStdInf()
{
	stringstream stream;
	string studentInfo = " ";
	stream << "Record : " << Record << endl << "ID : " << ID << endl << "Name : " << Name << endl << "Email : " << Email << endl << " Units : " << Units << endl << "Program : " << Program << endl << "Class Ranking : " << ClassRanking << endl;
	studentInfo = stream.str();
	return studentInfo;
}
 ///////////////////////////////////////////////////////////////////////////////
 /// \file         Node.cpp
 /// \author       Gal Zahavi
 /// \date         
 /// \brief        This application is an attendance tracker
 /// \function	  getNumAbs()
 /// \description         
 ///       
 /// REVISION HISTORY:
 /// \date  3/20/18 
 ///            
 ///////////////////////////////////////////////////////////////////////////////
 int Node::getNumAbs()
 {
	 return numAbs;
 }
 ///////////////////////////////////////////////////////////////////////////////
 /// \file         Node.cpp
 /// \author       Gal Zahavi
 /// \date         
 /// \brief        This application is an attendance tracker
 /// \function	   getRctAbs()
 /// \description         
 ///       
 /// REVISION HISTORY:
 /// \date  3/20/18 (created)
 ///            
 ///////////////////////////////////////////////////////////////////////////////
string Node::getRctAbs()
{
	string Abs= " ";
	absences->peek(Abs);
	return Abs;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  getAbs()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
string Node::getAbs()
{
	Stack<string>* tmp = new Stack<string>;
	string Temp = "",allabs = "";
	stringstream stream;
	while (!absences->isEmpty())
	{
		absences->pop(Temp);
		stream << ',' << Temp;
		tmp->push(Temp);
	}
	while (!tmp->isEmpty())
	{
		tmp->pop(Temp);
		absences->push(Temp);
	}
	allabs = stream.str();
	delete(tmp);
	return allabs;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         Node.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	   addAbs()
/// \description         
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM PROFESSOR ANDY ~~~~~~~~~~~~~~~~~~~~~~~
///
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::addAb()
{
	//from Professor Andy
	stringstream stream;
	string date;
	// retrieved from stackoverflow
	//- http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;
	date = stream.str();
	absences->push(date);
	++numAbs;
}
