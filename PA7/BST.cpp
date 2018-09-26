#include "BST.h"
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  BST
/// \description         constructor
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
BST::BST(Node *Root, string Text, string Morse)
{
	Morse = Morse;
	Text = Text;
	root = Root;

	fstream catalog("MorseCatalog.txt");

	if(catalog.is_open())
	{
		CreatBST(catalog);
		catalog.close();
	}
	else 
	{
		cout << "!!!Error Please Check Your File!!!" << endl;
	
	}
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  ~BST
/// \description   Destructor 
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
BST::~BST()
{
	// In Binary Tree Destructor
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  findTarget
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::fingTarget(string & target)
{
	target = toupper(target[0]);
	findTarget(target,this->root);
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  insert
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::insert(Node *& New)
{
	insert(New, this->root);
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  converter
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::Converter()
{
	Morse = " ";
	fstream textF("file.txt");
	if (textF.is_open()) 
	{
		Text = cnvrtText(textF);
		cnvrtMorToText(Text);
		cout << "Inputed Text : "<<Text << endl;
		cout << "Morse : "<<Morse << endl;
	}

	textF.close();
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  print
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::print()
{
	print(root);
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  makeNode
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
Node * BST::makeNode(string morse, string text)
{
	Node *nNode = new Node;
	nNode->SetText(text);
	nNode->SetMorse(morse);
	return nNode;
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  CreatBST
/// \description         
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM BST LAB ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool BST::CreatBST(fstream & input)
{
	string text = "";
	string morse = "";

	for (;input;) 
	{
		input >> text;
		input >> morse;

		if (morse != ""&& text != "") 
		{

			Node *nNode = makeNode(morse, text);
			if (nNode != nullptr) 
			{
				insert(nNode,this->root);
			}
		}
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  PrintInOrder
/// \description         
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM BST LAB ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::printinOrder()
{
	printInOrder(root);
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  ConvertText 
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
string BST::cnvrtText(fstream & input)
{
	string text = "", line = "";
	while (input)
	{
		getline(input, line);
		if (line == "")
		{
			line.back();
		}
		else
		{
			text = text + line;
		}
	}
	return text;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  ConvertMorseToText
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool BST::cnvrtMorToText(string & input)
{
	int in = input.length();
	for (int i = 0; i < in; ++i) 
	{
		string cur(1, input[i]);

		if (input[i] == '*') 
		{
			Morse = Morse + "\n";

		}
		else if (input[i] == ' ') 
		{
			Morse = Morse + " ";
			
		}
		else 
		{
			this->fingTarget(cur);
		}
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  Insert
/// \description         
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM BST LAB ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool BST::insert(Node *& New, Node *& pTree)
{
	if(pTree == nullptr)
	{
		pTree = New;
	}
	else if (pTree->GetText() > New->GetText())
	{
		insert(New, (pTree->GetRight()));
	}
	else if (pTree->GetText() < New->GetText())
	{
		insert(New,(pTree->GetLeft()));
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  findTarget
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
bool BST::findTarget(string & target, Node *& pTree)
{
	if (pTree == nullptr)
	{
		Morse = Morse + "%";
	}
	else if (pTree != nullptr)
	{
		if (target == pTree->GetText())
		{
			Morse = Morse + (pTree->GetMorse() + " ");
		}
		else if (target < pTree->GetText())
		{
			findTarget(target, pTree->GetRight());
		}
		else if (target > pTree->GetText())
		{
			findTarget(target, pTree->GetLeft());

		}
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  printInOrder
/// \description         
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM BST LAB ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::printInOrder(Node *& pTree)
{
	if (pTree != nullptr) 
	{
		printInOrder(pTree->GetLeft());
		cout << pTree->GetText()<<" "<< pTree->GetMorse()<< endl;;
		printInOrder(pTree->GetRight());
	}
}

///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  print
/// \description         
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM BST LAB ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::print(Node *& pTree)
{
	int max = 10;
	for (int i = 1; i <= max; i++) {
		printLevel(pTree, i);
	}
}
///////////////////////////////////////////////////////////////////////////////
/// \file         BST.cpp
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is a morse code converter
/// \function	  printLevel
/// \description         
///       
/// REVISION HISTORY:
/// \date  4/2/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////
void BST::printLevel(Node *& pTree, int i)
{
	if (pTree != nullptr)
	{
		if (i == 1)
		{
			cout << pTree->GetText() << endl;
		}
		else if (i > 1)
		{
			printLevel((pTree->GetLeft()), i - 1);
			printLevel((pTree->GetRight()), i - 1);
		}
	}
	else
	{
		return;
	}
}

