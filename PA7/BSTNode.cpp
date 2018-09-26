#include "BSTNode.h"

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  Node
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node::Node(string text, string morse,Node *Left, Node *Right)
{
	right = Right;
	left = Left;
	Morse = morse;
	Text = text;

}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  ~Node
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node::~Node()
{
	// In Binary Tree Node Destructor
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  GetLeft
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node *& Node::GetLeft()
{
	return left;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  SetLeft
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::SetLeft(Node *& New)
{
	left = New;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  GetMorse
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
string Node::GetMorse() const
{
	return Morse;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  SetMorse
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::SetMorse(string Char)
{
	Morse = Char;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  GetText
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
string Node::GetText() const
{
	return Text;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  SetText
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::SetText(string Char)
{
	Text = Char;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  GetRight
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node *& Node::GetRight()
{
	return right;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BSTNode.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  SetRight
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void Node::SetRight(Node *& New)
{
	right = New;
}

