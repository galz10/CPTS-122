#include "Queue.h"
#include <fstream>

int main(void) 
{

	Data d[10000];
	Queue fast, normal;
	int i = 0, a = 0, x = 0, t = 0,t1 = 0 ;
	
	cout << "Welcome to the Grocery Store Line Simulator" << endl;
	cout << "1) Simulate Fast Line" << endl;
	cout << "2) Simulate Normal Line" << endl;
	cin >> i;
	std::srand(std::time(nullptr));

	switch (i)
	{
	case 1:
		cout << "How Many Hours would you like to simulate" << endl;
		cin >> a;
		x = 1;
		a = a * 8;
		t1 = 0;
		for (; x < a; ++x) 
		{
			for (t = 0;t == 0;) 
			{
				t = rand() % 5;
			}
			d[x].setcot(x);
			d[x].setSerTime(t);
			d[x].settotTime(t + t1);
			printQueue(d, x);
			t1 = d[x].getTotTime();

		}
		break;
	case 2:
		cout << "How Many Hours would you like to simulate" << endl;
		cin >> a;
		x = 1;
		a = a * 4;
		t1 = 0;
		for (; x < a; ++x)
		{
			for(t=0;t<3;)
			{
				t = rand() % 8;
			}
			d[x].setcot(x);
			d[x].setSerTime(t);
			d[x].settotTime(t + t1);
			printQueue(d, x);
			t1 = d[x].getTotTime();
		}
		break;
	};

	return 0;
}