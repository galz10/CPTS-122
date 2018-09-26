#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Node
{
public:
	Node(string data = "", Node *pLeft = nullptr,Node*pRight = nullptr);
	virtual ~Node();
	void SetData(string input);
	string GetData();
	void setLeft(Node*& leftP);
	Node*& GetLeft();
	void setRight(Node*& rightP);
	Node*& GetRight();

	virtual void printData() = 0;
protected:
	Node* pRight;
	string Data; 
	Node* pLeft;

};
