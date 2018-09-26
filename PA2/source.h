#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct duration
{
	unsigned int min;
	unsigned int sec;
}Duration;

typedef struct node
{
	struct node *pNext;
	struct node *pPrev;
} Node;

typedef struct records
{
	char Artist[100];
	char Album[100];
	char Song[100];
	char Genre[100];
	int Played;
	int Rating;
	Duration time;
	struct node N;
}Records;


int mainMenu(void);
Records *readFile(FILE *infile);
void store(FILE *infile, Records *pHead);
void print(Records *Head);
void edit(Records *Head);
void rate(Records *Head);
void play(Records *Head);
void Exit(Records *Head, FILE *infile);