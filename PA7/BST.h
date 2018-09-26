#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BSTNode.h"

using std::fstream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;


class BST {

public:
	BST(Node *Root = nullptr, string Text = "", string Morse = "");
	~BST();
	void fingTarget(string &target);
	void insert(Node *&New);
	void Converter();
	void printinOrder();
	void print();

private:
	Node *makeNode(string morse,string text);
	bool CreatBST(fstream &input);
	string cnvrtText(fstream &input);
	bool cnvrtMorToText(string &input);
	bool insert(Node *&New, Node *&pTree);
	bool findTarget(string &target,Node *&pTree);
	void printInOrder(Node *& pTree);
	void print(Node *&pTree);
	void printLevel(Node *&pTree, int i);

	string Morse;
	string Text;
	Node *root;

};