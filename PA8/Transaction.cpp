#include "Transaction.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         Transaction.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function :	TransNode() --Constructor
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
TransNode::TransNode(const string data, int units):Node(data)
{
	Units = units;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         Transaction.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : getUnits()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
int TransNode::getUnits()
{
	return Units;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         Transaction.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : setUnits()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void TransNode::setUnits(int units)
{
	Units = units;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         Transaction.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : printData()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void TransNode::printData()
{
	cout << "Units:  " << getUnits()<< " |  "<< " Data: " << GetData() << endl;
}
