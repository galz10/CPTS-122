#include "BST.h"


///////////////////////////////////////// BST ///////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : BST() -- Constructor
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////

BST::BST(TransNode * rootN)
{
	root = rootN;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function :  ~BST() -- Destructor
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
BST::~BST()
{
	destroy();
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : getRoot() 
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node * BST::getRoot()
{
	return root;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : setRoot()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::setRoot(TransNode *& ptemp)
{
	root = ptemp;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : insertRec()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::insertRec(TransNode *& ptemp)
{
	insert(ptemp,this->root);
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : inOrderTravs()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::inOrderTravs()
{
	inOrderTravs(root);
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : findMax()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
TransNode & BST::findMax() const
{
	TransNode *pTemp;
	pTemp = (TransNode*)root;
	while (pTemp->GetRight() != nullptr)
	{
		pTemp = (TransNode*)pTemp->GetRight();
	}
	return *pTemp;
	
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : findMin()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
TransNode & BST::findMin() const
{
	TransNode *pTemp;
	pTemp = (TransNode*)root;
	while (pTemp->GetLeft() != nullptr)
	{
		pTemp = (TransNode*)pTemp->GetLeft();
	}
	return *pTemp;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : inOrderTravs()
///
///---------------------------------FROM LAB-----------------------------------
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::inOrderTravs(Node *& node)
{
	if (node->GetLeft() != nullptr) 
	{
		inOrderTravs(node->GetLeft());
	}
	node->printData();
	if (node->GetRight() != nullptr) 
	{
		inOrderTravs(node->GetRight());
	}

}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : insert()
///
///---------------------------------FROM LAB-----------------------------------
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::insert(TransNode *& ptemp, Node *& node)
{
	if (node != nullptr)
	{
		if (ptemp->getUnits() > (dynamic_cast<TransNode*>(node)->getUnits()))
		{
			insert(ptemp, node->GetRight());
		}
		else if (ptemp->getUnits() < (dynamic_cast<TransNode*>(node)->getUnits()))
		{
			insert(ptemp, node->GetLeft());
		}
	}
	else if (node == nullptr)
	{
		node = ptemp;
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : destroy()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::destroy()
{
	delete root;
}


///////////////////////////////////////// DataAnaylsis ///////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : Run() -- DayaAnalysi
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void DataAnalysis::Run()
{
	if (!CSV.is_open()) 
	{
		parseF();
		CSV.close();
		cout << "_______________" << endl << endl;
		cout << "  Sold Tree  " << endl;
		cout << "_______________" << endl << endl;
		mTSold.inOrderTravs();

		cout << "__________________" << endl << endl;
		cout << "  Purchased Tree  " << endl;
		cout << "__________________" << endl << endl;
		MTPurch.inOrderTravs();

		trends();
	}
}


///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : openF() -- DayaAnalysis
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void DataAnalysis::openF()
{
	CSV.open("text.csv");

	if (!CSV.is_open()) 
	{
		cout << "Error with opening file" << endl;
	}
	
}


///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : parseF() -- DayaAnalysi
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void DataAnalysis::parseF()
{
	openF();
	string line;
	string item = "";
	string type = "";
	getline(CSV, line);
	int Unit = 0;
	while(!CSV.eof())
	{
		getline(CSV, line);
		parseL(type, item, line, Unit);
		TransNode *newNode = new TransNode(type,Unit);
		SortedInsert(type,newNode);	
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : parsL -- DataAnalysis
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void DataAnalysis::parseL(string & type, string & item, string & line, int & units)
{
	string temp,temp1;
	stringstream str(line);
	getline(str, temp, ',');
	units = stoi(temp);
	getline(str, item, ',');
	getline(str, type, ',');
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : trends() -- DataAnalysis
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void DataAnalysis::trends()
{
	cout << "_______________" << endl<<endl;
	cout << "  Data Trends" << endl;
	cout << "_______________" << endl << endl;
	TransNode Cur;
	Cur = this->mTSold.findMin();
	cout << "Least Sold : ";
	Cur.printData();
	Cur = this->mTSold.findMax();
	cout << "Most Sold: ";
	Cur.printData();
	Cur = this->MTPurch.findMin();
	cout << "Least Purchases : ";
	Cur.printData();
	Cur = this->MTPurch.findMax();
	cout << "Most Purchases : ";
	Cur.printData();
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : SortedInsert() 
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void DataAnalysis::SortedInsert(string type, TransNode *& pTemp)
{
	if (type == "Sold")
	{
		this->mTSold.insertRec(pTemp);
	}
	else if (type == "Purchased")
	{
		this->MTPurch.insertRec(pTemp);
	}
	else 
	{
		delete pTemp;
	}
}
