///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.h
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Node.h" 
#include <string>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;


class AbsentList
{
public:
	AbsentList();
	~AbsentList();
	bool insertFront(Node * newNode);
	bool load(ifstream & inf);
	bool store(ofstream & outf);
	bool allAbs(int min);
	bool RecAbs();
	bool markAbs();

private:
	Node* pHead;

};