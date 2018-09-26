#pragma once

#include <iostream>
#include <fstream>
#include <string>


using std::fstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class Node {

public:
	Node(string text = " " , string morse = "" , Node *Left = nullptr, Node *Right = nullptr);
	~Node();
	
	string GetMorse() const;
	string GetText() const;
	Node *&GetRight();
	Node *&GetLeft();

	void SetMorse(string Char);
	void SetText(string Char);
	void SetRight(Node *&New);
	void SetLeft(Node *&New);



private:
	Node *left;
	Node *right;
	string Text;
	string Morse;
};