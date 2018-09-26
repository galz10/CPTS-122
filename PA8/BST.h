#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include "Transaction.h"

using std::ifstream;
using std::stringstream;
using std::getline;


class BST
{
public: 
	BST(TransNode *rootN = nullptr);
	~BST();
	Node *getRoot();
	void setRoot(TransNode *&ptemp);
	void insertRec(TransNode *&ptemp);
	void inOrderTravs();
	TransNode & findMax() const;
	TransNode & findMin() const;

private:
	Node *root;
	void insert(TransNode *&ptemp, Node *&node);
	void inOrderTravs(Node *&node);
	void destroy();
};


class DataAnalysis
{

public:
	void Run();
private:
	void openF();
	void parseF();
	void parseL(string &type,string &item,string &line,int &units);
	void trends();
	void SortedInsert(string type,TransNode *&pTemp);
	BST mTSold;
	BST MTPurch;
	ifstream CSV;
};