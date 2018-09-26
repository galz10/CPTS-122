#pragma once
#include "BSTNode.h"


class TransNode : public Node
{
public:
	TransNode(const string data = "", int units= 0);
	int getUnits();
	void setUnits(int units);
	void printData();
private:
	int Units;
};