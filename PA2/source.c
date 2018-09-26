#include "source.h"
/*************************************************************
* Function: mainMenu										*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
int mainMenu(void)
{
	int i = 0;
	printf("Welcome To Main Menu\nPick one \n 1) Load\n 2) Store\n 3) Display\n 4) Insert\n 5) Delete\n 6) Edit\n 7) Sort\n 8) Rate\n 9) Play\n 10) Shuffle\n 11) Exit\n\n");
	scanf("%d",&i);
	return i;
}

/*************************************************************
* Function: read_file                                       *
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description: Reads data and puts it into the struct       *
* Input parameters: a file and a struct                     *
* Returns: Nothing                                          *
*************************************************************/
Records *readFile(FILE *infile)
{
	Records *Node = (Records*)malloc(sizeof(Records));
	char Data[1000] = { "\0", };
	int i = 0,x =0;
	int ArtistLine = 0;
	char * pTemp = NULL;

	fgets(Data, 1000, infile);
	ArtistLine = strlen(Data);
	pTemp = strtok(Data, "\"");
	x = strlen(pTemp);
	if (strlen(pTemp)== ArtistLine)
		{
			pTemp = strtok(Data, ",");
			strcpy(Node->Artist, pTemp);
		}
	else
		{
			strcpy(Node->Artist, pTemp);
		}
	pTemp = strtok(NULL, ",");
	if (pTemp != NULL)
		{
			strcpy(Node->Album, pTemp);
		}
		pTemp = strtok(NULL, ",");
	if (pTemp != NULL)
		{
			strcpy(Node->Song, pTemp);
		}
		pTemp = strtok(NULL, ",");
	if (pTemp != NULL)
		{
			strcpy(Node->Genre, pTemp);
		}
		pTemp = strtok(NULL, ":");
	if (pTemp != NULL)
		{
			Node->time.min = atoi(pTemp);
			pTemp = strtok(NULL, ",");
			Node->time.sec = atoi(pTemp);
		}
		pTemp = strtok(NULL, ",");
	if (pTemp != NULL)
		{
			Node->Played = atoi(pTemp);
		}
		pTemp = strtok(NULL, ",");
	if (pTemp != NULL)
		{
			Node->Rating = atoi(pTemp);
		}

		++i;
		Node->N.pNext= NULL;
		Node->N.pPrev = NULL;
		

	return Node;
}
/*************************************************************
* Function: insertAtFront									*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
int insertAtFront(Records **pHead, FILE *infile) // list operation
{
	int success = 0;

	while (!feof(infile))
	{
		if (*pHead == NULL) // we allocated space for a Node and initialized it
		{
		Records *newNode = readFile(infile);
		*pHead = newNode;
		newNode->N.pNext = NULL;
		newNode->N.pPrev = NULL;
		success = 1;
		}
		else
		{

			Records *newNode = readFile(infile);
			Records *pTemp = *pHead;
			newNode->N.pNext = pTemp; 
			*pHead = newNode;
			newNode->N.pPrev = NULL;
			pTemp->N.pPrev = newNode;

		}

	}
	printf("All Files Were Loaded Correctly!\n");
	printf("Press Any Key to Continue\n");
	return success;
}
/*************************************************************
* Function: store   										*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
void store(FILE *infile, Records *pHead) 
{
	Records *pCur = pHead;
	
	while(pCur->N.pNext != NULL)
	{
		pCur = pCur->N.pNext;
	}
	while (pCur->N.pPrev != NULL)
	{
		fprintf(infile, "\n\nUPDATED DATA\n\n", pCur->Artist);
		fprintf(infile,"Artist : %s\n", pCur->Artist);
		fprintf(infile,"Album : %s\n", pCur->Album);
		fprintf(infile, "Song : %s\n", pCur->Song);
		fprintf(infile, "Genre : %s\n", pCur->Genre);
		fprintf(infile, "Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
		fprintf(infile, "Played : %d\n", pCur->Played);
		fprintf(infile, "Rating : %d\n\n", pCur->Rating);
		pCur = pCur->N.pPrev;
	}

}
/*************************************************************
* Function: print   										*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
void print(Records *Head)
{
	Records *pCur = Head;
	Records *pPrev = NULL;
	int i = 0;
	char artist[100] = { '\0' };
	printf("Do you Want to Print the Whole List or Print a Specific Artist ( 1 or 2) \n");
	scanf("%d", &i);

	switch (i)
	{
	case 1:
		while (pCur != NULL)
	{
		printf("Artist : %s\n", pCur->Artist);
		printf("Album : %s\n", pCur->Album);
		printf("Song : %s\n", pCur->Song);
		printf("Genre : %s\n", pCur->Genre);
		printf("Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
		printf("Played : %d\n", pCur->Played);
		printf("Rating : %d\n", pCur->Rating);
		printf("\n");
		pCur = pCur->N.pNext;
	}
		break;
	case 2: // if they want a specific artist
		printf("What Artist Do you want to print ?");
		scanf("%s", artist);
			while (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->N.pNext;
				if (pCur != NULL)
				{
					if (strcmp(pCur->Artist, artist) == 0)
					{
						printf("\nArtist : %s\n", pCur->Artist);
						printf("Album : %s\n", pCur->Album);
						printf("Song : %s\n", pCur->Song);
						printf("Genre : %s\n", pCur->Genre);
						printf("Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
						printf("Played : %d\n", pCur->Played);
						printf("Rating : %d\n\n", pCur->Rating);
						
					}
				}
			}
		break;
	}

}
/*************************************************************
* Function: edit     										*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
void edit(Records *Head) 
{
	Records *pCur = Head;
	Records *pPrev = NULL;
	int i = 0;
	int key;
	char artist[100] = { '\0' }, album[100] = { '\0' },song[100] = { '\0' },genre[100] = { '\0' },played[100] = { '\0' };

	printf("What Artist Do you Want to Edit ?\n");
	scanf("%s",&artist);
		while (pCur != NULL && strcmp(pCur->Artist, artist) != 0)
		{
			pPrev = pCur;
			pCur = pCur->N.pNext;
		}
		if (pPrev != NULL && pCur != NULL)
		{
			printf("What Do you Want to Edit (\n 1) Artist \n 2)Album \n 3) Song \n 4) Genre \n 5)Times Played \n) ?\n");
			scanf("%d",&key);
			switch (key)
			{
			case 1: printf("What do you want to change the artist too?\n");
				scanf("%s", &artist);
				strcpy(pCur->Artist, artist);
				break;
			case 2:printf("What do you want to change the Album too?\n");
				scanf("%s", &album);
				strcpy(pCur->Album, album);
				break;
			case 3:printf("What do you want to change the Song too?\n");
				scanf("%s", &song);
				strcpy(pCur->Song, song);
				break;
			case 4:printf("What do you want to change the Genre too?\n");
				scanf("%s", &genre);
				strcpy(pCur->Genre, genre);
				break;
			case 5:printf("What do you want to change the times played too?\n");
				scanf("%s", &played);
				strcpy(pCur->Played, played);
				break;
			}

			printf("Artist : %s\n", pCur->Artist);
			printf("Album : %s\n", pCur->Album);
			printf("Song : %s\n", pCur->Song);
			printf("Genre : %s\n", pCur->Genre);
			printf("Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
			printf("Played : %d\n", pCur->Played);
			printf("Rating : %d\n", pCur->Rating);
			pPrev->N.pNext = pCur->N.pNext;
		

	}
}
/*************************************************************
* Function: rate     										*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
void rate(Records *Head)
{
	Records *pCur = Head;
	Records *pPrev = NULL;
	char key[100] = { '\0' };
	char song[100] = { '\0' };

	printf("What song do you want to reRate ?\n");
	scanf("%s", &song);
	while (pCur != NULL && strcmp(pCur->Song, song) != 0)
	{
		pPrev = pCur;
		pCur = pCur->N.pNext;
	}
	if (pPrev != NULL && pCur != NULL)
	{

		printf("What do you want to change the rating to ( 1- 5) ?\n");
		scanf("%s",&key);
		strcpy(pCur->Rating, atoi(key));
		
	}

	printf("Artist : %s\n", pCur->Artist);
	printf("Album : %s\n", pCur->Album);
	printf("Song : %s\n", pCur->Song);
	printf("Genre : %s\n", pCur->Genre);
	printf("Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
	printf("Played : %d\n", pCur->Played);
	printf("Rating : %d\n", pCur->Rating);
	pPrev->N.pNext = pCur->N.pNext;

}
/*************************************************************
* Function: play											*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
void play(Records *Head)
{
	Records *pCur = Head;
	Records *pPrev = NULL;
	char song[100] = { "\0" };
	int i = 0;
	printf("What Artist do you want to play ?\n");
	scanf("%s", &song);
	while (pCur != NULL)
	{
		pPrev = pCur;
		pCur = pCur->N.pNext;
		if (pCur != NULL) {
			if ((strcmp(pCur->Artist, song) == 0))
			{
				printf("Artist : %s\n", pCur->Artist);
				printf("Album : %s\n", pCur->Album);
				printf("Song : %s\n", pCur->Song);
				printf("Genre : %s\n", pCur->Genre);
				printf("Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
				printf("Played : %d\n", pCur->Played);
				printf("Rating : %d\n\n\n", pCur->Rating);
				i = 1;
				_sleep(1000);
			}
		}
	}
	pCur = Head;
	while (pCur != NULL) {
			
			if (strcmp(pCur->Artist, song) != 0)
			{
				printf("Artist : %s\n", pCur->Artist);
				printf("Album : %s\n", pCur->Album);
				printf("Song : %s\n", pCur->Song);
				printf("Genre : %s\n", pCur->Genre);
				printf("Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
				printf("Played : %d\n", pCur->Played);
				printf("Rating : %d\n\n\n", pCur->Rating);
				_sleep(1000);
			}
			pPrev = pCur;
			pCur = pCur->N.pNext;
		}
	
	
}

/*************************************************************
* Function: exit											*
* Date Created: 1/31/2018                                   *
* Date Last Modified:                                       *
* Description:							                    *
* Returns: Nothing                                          *
*************************************************************/
void Exit(Records *Head, FILE *infile) 
{
	Records *pCur = Head;

	while (pCur->N.pNext != NULL)
	{
		pCur = pCur->N.pNext;
	}
	while (pCur->N.pPrev != NULL)
	{
		fprintf(infile, "\n\nUPDATED CLOSING DATA\n\n\n\n\n", pCur->Artist);
		fprintf(infile, "Artist : %s\n", pCur->Artist);
		fprintf(infile, "Album : %s\n", pCur->Album);
		fprintf(infile, "Song : %s\n", pCur->Song);
		fprintf(infile, "Genre : %s\n", pCur->Genre);
		fprintf(infile, "Duration:  %d:%d\n", pCur->time.min, pCur->time.sec);
		fprintf(infile, "Played : %d\n", pCur->Played);
		fprintf(infile, "Rating : %d\n\n", pCur->Rating);
		pCur = pCur->N.pPrev;
	}
}

//int deleteSong(Records **pHead, Records Key)
//{
//	Node *pCur = NULL, *pPrev = NULL;
//	int success = 0;
//
//	pCur = *pHead;
//	while (pCur != NULL && strcmp(Key.Artist, pCur->key.Artist3) != 0)
//	{
//		pPrev = pCur;
//		pCur = pCur->pNext;
//	}
//	if (pPrev != NULL && pCur != NULL) // remove a student that's not at the front of the list
//	{
//		pPrev->pNext = pCur->pNext;
//		free(pCur);
//		success = 1;
//	}
//	else if (pPrev == NULL && pCur != NULL) // removing student at front
//	{
//		*pList = pCur->pNext;
//		free(pCur);
//		success = 1;
//	}
//	else // didnt find student
//	{
//		printf("Artist Was Not Found!");
//
//	}
//	return success;
//
//}

