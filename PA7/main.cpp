#include "BST.h"
#include "BSTNode.h"
#include <conio.h>

int main(void) 
{
	BST B;
	int i = 0 ,x = 0;
	while (i <= 3) {
		cout << "Welcome to CIA Text to Morse Converter" << endl;
		cout << " 1) Print Tree" << endl;
		cout << " 2) Print Tree by Level" << endl;
		cout << " 3) Convert Text To Morse" << endl;
		cout << " 4) Close" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			B.printinOrder();
			_sleep(1000);
			system("cls");
			break;
		case 2:
			B.print();
			_sleep(1000);
			system("cls");
			break;
		case 3:
			B.Converter();
			break;
		case 4:
			break;
		}

	}
}