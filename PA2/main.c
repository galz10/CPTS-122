#include "source.h"

int main(void) {
	int index = 0,success = 0;
	// open files
	Records *Head = NULL ;
	Records **pHead = &Head;
	Records *pCure = Head;
	FILE *Infile = { NULL };
	FILE *Outfile = { NULL };
	Infile = fopen("data.csv", "r+");

	if (Infile != NULL)
	{
		printf("Success\n");
		while (index != 11) {
			index = mainMenu();
			switch (index)
			{
			case 1: insertAtFront(&Head, Infile);
				system("cls");
				break;
			case 2:store(Infile,Head);
				system("cls");
				break;
			case 3:print(Head);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:edit(Head);
				break;
			case 7:
				break;
			case 8:rate(Head);
				break;
			case 9:play(Head);
				break;
			case 10:
				break;
			case 11:Exit(Head, Infile);
				return 0;
				break;
			}
		}
	}
	else
	{
		printf("File Did not properly open!\n ");
	}
}