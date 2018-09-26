///////////////////////////////////////////////////////////////////////////////
/// \file         Stack.h
/// \author       Gal Zahavi
/// \date         
/// \brief        This application is an attendance tracker
///
///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FROM LAB 9 ~~~~~~~~~~~~~~~~~~~~~~~
///
///       
/// REVISION HISTORY:
/// \date  3/20/18 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	int getSize();
	bool push(T &newItem);
	bool pop(T &poppedItem);
	bool peek(T &item);

	bool isEmpty();

private:
	int mSize; 
	int mMaxSize; 
	T *mTop; 
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; 
	mMaxSize = 100;
	mTop = new T[100]; 
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; 
}


template <class T>
int Stack<T>::getSize()
{
	return mSize;
}


template <class T>
bool Stack<T>::push(T &newItem)
{
	if (mSize <= mMaxSize)
	{
		mTop[mSize] = newItem;
		++mSize;
		return true;
	}
	cout << "stack full" << endl;
	return false;

}


template <class T>
bool Stack<T>::pop(T &poppedItem)
{
	if (!isEmpty())
	{
		mSize--;
		poppedItem = mTop[mSize];
		return true;
	}
	cout << "Stack is Empty" << endl;
	return false;
}


template <class T>
bool Stack<T>::peek(T &item)
{
	T* pCur = mTop;
	if (!isEmpty())
	{
		item = *pCur;
		return true;
	}

	return false;
}


template <class T>
bool Stack<T>::isEmpty()
{
	if (mSize <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
