#include "AbsentList.h"

AbsentList::AbsentList()
{
}

AbsentList::~AbsentList()
{
	// Inside Destructor

}
///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	   load()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AbsentList::load(ifstream & inf)
{
	string line;
	while (!inf.eof())
	{
		getline(inf, line);
		Node *pNew = new Node(line);
		insertFront(pNew);
		//cout << pNew->Name << endl;
	}
	cout << "Everything Loaded Correclty!!" << endl;
	return false;
}


///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  insertFront()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AbsentList::insertFront(Node * newData)
{
	Node *pTemp = this->pHead;
	bool success = false;                   

	if (pTemp != nullptr)
	{
		this->pHead = newData;
		this->pHead->pNext = pTemp;
		success = true;
	}

	return success;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	   store()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AbsentList::store(ofstream & outf)
{
	int i = 0;
	Node *pTemp = this->pHead;
	for(i = 0;i<10;i++)
	{
		outf << "Record : " << pTemp->Record << endl << "ID : " << pTemp->ID << endl << "Name : " << pTemp->Name << endl << "Email : " << pTemp->Email << endl << " Units : " << pTemp->Units << endl << "Program : " << pTemp->Program << endl << "Class Ranking : " << pTemp->ClassRanking << endl << endl << endl;
		pTemp = pTemp->pNext;
	}
	cout << "Everything Stored Correctly!!" << endl;
	return true;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  allAbs()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AbsentList::allAbs(int min)
{
	string out = " ";
	Node *pTemp = this->pHead;
	while (pTemp != nullptr)
	{	
		out = pTemp->getStdInf();
		cout << "Student Information" << endl;
		cout << out << endl;
		out = pTemp->getAbs();
		cout << "All Absenceses" << endl;
		cout << out << endl;
		pTemp = pTemp->pNext;
		return true;
	}
	return false;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  RecAbs()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AbsentList::RecAbs()
{
	string out = " ";
	Node *pTemp = this->pHead;
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		out = pTemp->getStdInf();
		cout << "Student Information" << endl;
		cout << out << endl;
		out = pTemp->getRctAbs();
		cout << "Recent Absenceses" << endl;
		cout << out << endl;
		pTemp = pTemp->pNext;
		
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         AbsentList.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
/// \function	  markAbs()
/// \description         
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool AbsentList::markAbs()
{
	int i = 0,x=0;
	Node *pTemp = this->pHead;
	for(x = 0; x<10;x++)
	{
		cout << "Student : " << pTemp->Name << endl << "ID" << pTemp->ID << endl << "Was He/She Present Today ?" << endl << "  1) Yes"<<endl<<"  2)No"<<endl;
		cin >> i;
		switch (i)
		{
		case 1:pTemp->addAb();
			break;
		case 2:pTemp->pNext;
			break;
		}
		
		pTemp = pTemp->pNext;

	}
	return true;
}

