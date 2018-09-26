#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>


using std::cin;
using std::cout;
using std::endl;
using std::string;

class Data
{
public: 
	Data();
	int getCostNumb();
	int getSerTime();
	int getTotTime();
	int getSum();
	void setcot(int numb);	
	void setSerTime(int numb);
	void settotTime(int time);
	void setsum(int x);
	



private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;// totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
	int sum;
}; 
// This memory needs to be allocated on the heap!

class QueueNode
{
public: 
	QueueNode();
	QueueNode( Data * const pData);
	void setNextPtr( QueueNode *  const newNextPtr);
	QueueNode const * getNextPtr();
	Data * getpData();
	~QueueNode();


private:
	Data *pData;    // The memory for Data will need to be allocated on the heap as well!
	QueueNode *pNext;
};

class Queue
{
public:
	Queue();
	bool isEmpty();
	//int deQueue();
	bool enQueue(Data * const newPerson);
	Data deQueue();
	Data d;

private:
	QueueNode *pHead;
	QueueNode *pTail;
};

void printQueue(Data d[10000], int x);
