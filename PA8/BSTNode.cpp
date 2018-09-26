#include "BSTNode.h"

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function :  Node()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node::Node(string data,Node *pLeft1, Node* pRight1)
{
	pLeft = pLeft1;
	Data = data;
	pRight = pRight1;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : ~Node()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node::~Node()
{
	//in destructor
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : SetData()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::SetData(string input)
{
	Data = input;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : GetData()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
string Node::GetData()
{
	return Data;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : GetRight()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node *& Node::GetRight()
{
	return pRight;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : GetLeft()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node *& Node::GetLeft()
{
	return pLeft;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : setLeft()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::setLeft(Node *& leftP)
{
	pLeft = leftP;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a BST places data into BST tree ans sorts it 
/// 
///	\function : setRight()
///
/// REVISION HISTORY:
/// \date  4/12/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::setRight(Node*& rightP)
{
	pRight = rightP;
}
