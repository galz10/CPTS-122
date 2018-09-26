#include "Queue.h"

Queue::Queue()
{
	this->pHead == nullptr;
	this->pTail == nullptr;
}

bool Queue::isEmpty()
{
	int i; 
	if (this->pHead == nullptr && this->pTail == nullptr){
		i = 1;
	}
	else { i = 0; }

	return i ;
}


bool Queue::enQueue(Data  * const newPerson)
{
	QueueNode *pMem = nullptr;

	pMem = new QueueNode(newPerson);

	bool success = false;

	if (isEmpty() == 1)
	{
		//empty queue
		this->pHead = this->pTail = pMem;
		success = true;
	}
	else
	{
		this->pTail->setNextPtr(pMem);
		this->pTail = pMem;
		success = true;
	}
	

	return success;
}

//Data Queue::deQueue()
//{
//	Data *d1;
//
//	// if one node in the queue
//	if (this->pHead == this->pTail)
//	{
//		d1 = this->pHead->getpData();
//		delete this->pHead; // this ->mptail is a dangling pointer 
//		this->pHead = this->pTail = nullptr;
//	}
//	else// more than 1 node in queue
//	{
//		QueueNode *pTemp = nullptr;
//		pTemp = this->pHead;
//		d1 = this->pHead->getpData();
//		this->pHead = this->pHead->getpData();
//		delete pTemp;
//
//	}
//	return *d1;
//}

QueueNode::QueueNode()
{

}

QueueNode::QueueNode(Data *const pData)
{
	this->pData = pData;
	this->pNext = nullptr;
}

void QueueNode::setNextPtr( QueueNode * const  newNextPtr)
{
	QueueNode q;
	q.pNext= newNextPtr->pNext;
}

QueueNode const * QueueNode::getNextPtr()
{
	return this->pNext;
}

Data * QueueNode::getpData()
{
	Data *d1;
	d1 = pData;

	return d1;
}

QueueNode::~QueueNode()
{
	cout << "Inside destructor for Node!" << endl;

}

Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
	sum = 0;
}

int Data::getCostNumb()
{
	return customerNumber;
}

int Data::getSerTime()
{
	return serviceTime;
}

int Data::getTotTime()
{
	return totalTime;
}

int Data::getSum()
{
	return 0;
}

void Data::setcot(int numb)
{
	
	customerNumber = numb;
}

void Data::setSerTime(int numb)
{
	serviceTime = numb;
	
}

void Data::settotTime(int time)
{
	totalTime = time;
}

void Data::setsum(int x)
{
	sum = x;
}


//void Queue::deQueue(Queue *queue)
//
//{
//
//	QueueNode *prev = NULL, *curr = queue->pHead;
//	if (curr->getNextPtr() == NULL)
//	{
//		queue->pHead = queue->pTail = NULL;
//	}
//	else{
//		while (curr->getNextPtr() != NULL)
//		{
//			prev = curr;
//			curr = curr->getNextPtr();
//		}
//		prev->getNextPtr() = NULL;
//		queue->pTail = prev;
//		free(curr);
//
//	}

//}

void printQueue(Data d[10000], int x) 
{
	Queue q;
	cout <<"Costumer "<< d[x].getCostNumb() << endl;
	cout << "Service Time is :" << d[x].getSerTime()<<" Minutes"<< endl;
	cout <<"Total Time is : "<<d[x].getTotTime()<<" Minutes"<< endl << endl;
}