// EndOfTermProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char fname[1500];
	char age[500];
	char country[500];
	char year[120];
	char sport[1500];
	char gold[30];
	char silver[30];
	char bronze[30];
	char total[30];
}data;
data datas[8613];

FILE *fptr;


void option1(char athlete[]);
void option2(char sport[]);
void option3(char country[]);
void option4(char sport[], int year);
void openandreadfile(char* name);
void getChoice();
void handleChoice();




int choice = 0;

void main()

{
	char filename[70] = "D:\\My NUI\\CT103\\EndOfTermProject\\olympics.txt";
	int i = 0;
	openandreadfile(filename);


	getChoice();



}
void openandreadfile(char* name)
{
	const char s[3] = "\t";
	const char t[2] = " ";
	int k = 0;
	int j = 0;
	char temp[6000];
	int i = 0;
	char *token;
	fptr = fopen(name, "r");
	if (fptr == NULL)
	{
		printf("error!");

	}

	while (j <8613) {
		fgets(temp, 6000, fptr);
		token = strtok(temp, s);
		strcpy(datas[j].fname, token);
		token = strtok(NULL, s);
		strcpy(datas[j].age, token);
		token = strtok(NULL, s);
		strcpy(datas[j].country, token);
		token = strtok(NULL, s);
		strcpy(datas[j].year, token);
		token = strtok(NULL, s);
		strcpy(datas[j].sport, token);
		token = strtok(NULL, s);
		strcpy(datas[j].gold, token);
		token = strtok(NULL, s);
		strcpy(datas[j].silver, token);
		token = strtok(NULL, s);
		strcpy(datas[j].bronze, token);
		token = strtok(NULL, s);
		strcpy(datas[j].total, token);
		j++;
	}

}




void option1(char athlete[])
{
	int i = 0;
	int numGold = 0;
	int numSilver = 0;
	int numBronze = 0;
	int athlateFound = 0;
	for (i = 0; i < 8613; i++) {
		if (strcmp(datas[i].fname, athlete) == 0) {
			numGold = numGold + atoi(datas[i].gold);
			numSilver = numSilver + atoi(datas[i].silver);
			numBronze = numBronze + atoi(datas[i].bronze);
			athlateFound = 1;
		}
	}
	if (athlateFound == 0) {
		printf("Error: Athlete Name not found\n");
	}
	else {

		printf("Athlete %s won %d gold, %d silver and %d bronze medals\n", athlete, numGold, numSilver, numBronze);
	}
	printf("\n\n");
	getChoice();
}

void option2(char sport[]) {
	char athlete[1000][100];//up to 1000 athlethes with up to 100 characters in their names
	int athleteMedals[1000];// up to 1000 athlete's total medal numbers
	int i = 0; // iterate over entire datas array
	int j = 0; //iterate over the athletes attay to check whether it already contains the current athlete
	int currentAthlete = 0;
	int currentMedals = 0;


	for (i = 0; i < 8613; i++) { //for each line in the array
		int found = 0;
		if (strcmp(datas[i].sport, sport) == 0) { //if the name of the sport matches the name of the sport in the current line of the array
												  //if (currentAthlete > 0) { //if the athletes array already contains one or more names
			for (j = 0; j <= currentAthlete; j++) {
				if (strcmp(athlete[j], datas[i].fname) == 0) {
					//add the current total to the existing total
					athleteMedals[j] += atoi(datas[i].total);//add the current row's total to the total medals recorded in athletes array for this particular athlete
					found = 1;
				}
			}
			if (found == 0) {
				strcpy(athlete[currentAthlete], datas[i].fname);//add the current athlete to the athletes array
				athleteMedals[currentAthlete] = atoi(datas[i].total);//set the current athletes medal total 
				currentAthlete++;
			}
		}
	}


	printf("%s won %d medals", athlete[0], athleteMedals[0]);



	// sort descending with bubble sort
	int c = 0, d = 0;
	for (c = 0; c < (currentAthlete - 1); c++)
	{
		for (d = 0; d < currentAthlete - c - 1; d++)
		{
			if (athleteMedals[d] < athleteMedals[d + 1]) /* For decreasing order use < */
			{

				int swap = athleteMedals[d];
				athleteMedals[d] = athleteMedals[d + 1];
				athleteMedals[d + 1] = swap;


				char temp[50];
				strcpy(temp, athlete[d]);
				strcpy(athlete[d], athlete[d + 1]);
				strcpy(athlete[d + 1], temp);
			}
		}
	}

	printf("Athletes with the most medals for the sport %s\n", sport);
	for (i = 0; i < currentAthlete; i++) {
		printf("%s won %d medals\n", athlete[i], athleteMedals[i]);
	}
	printf("\n\n");
	getChoice();
}

void option3(char country[]) {
	char sports[1000][100];//up to 1000 sports with up to 100 characters in their names
	int totalMedals[1000];// up to 1000 total medal numbers
	int i = 0; // iterate over entire datas array
	int j = 0; //iterate over the spors array to check whether it already contains the current sport
	int currentSport = 0;

	for (i = 0; i < 8613; i++) { 
		int found = 0;
		if (strcmp(datas[i].country, country) == 0) {
			for (j = 0; j <= currentSport; j++) {
				if (strcmp(sports[j], datas[i].sport) == 0) {//if the name of the sport is already in the sports array									 //add the current total to the existing total
					totalMedals[j] += atoi(datas[i].total);//add the current row's total to the total medals recorded in athletes array for this particular athlete
					found = 1;
				}
			}
			if (found == 0) {
				strcpy(sports[currentSport], datas[i].sport);//add the current athlete to the athletes array
				totalMedals[currentSport] = atoi(datas[i].total);//set the current athletes medal total atoi(ascii to integer)
				currentSport++;
			}
		}
	}

	printf("List of medals by sport for %s\n", country);
	int k = 0;
	for (k = 0; k < currentSport; k++) {
		printf("%d medals in %s\n", totalMedals[k], sports[k]);
	}
	printf("\n\n");
	getChoice();
}


void option4(char sport[], int year)
{
	printf("\nIn %s in the year %d\n", sport, year);
	int goldIndex = 0;
	int silverIndex = 0;
	int bronzeIndex = 0;
	int i = 0;
	while (i < 8613) {
		if (strcmp(datas[i].sport, sport) == 0 && atoi(datas[i].year) == year) {
			if (atoi(datas[i].gold) != 0) {
				goldIndex = i;
				printf("\n%s Won gold\n", datas[goldIndex].fname);
			}
		}
		i++;
	}
	for (int j = 0; j < 8613; j++) {
		if (strcmp(datas[j].sport, sport) == 0 && atoi(datas[j].year) == year) {
			if (atoi(datas[j].silver) != 0) {
				silverIndex = j;
				printf("\n%s Won silver\n", datas[silverIndex].fname);
			}
		}
	}
	for (int k = 0; k < 8613; k++) {
		if (strcmp(datas[k].sport, sport) == 0 && atoi(datas[k].year) == year) {
			if (atoi(datas[k].bronze) != 0) {
				bronzeIndex = k;
				printf("\n%s Won bronze\n", datas[bronzeIndex].fname);
			}
		}

	}
	printf("\n\n");
	choice = 0;
	getChoice();

}
void getChoice() {

	printf("Enter your choice.\n");
	printf("Choice 1 is number and type of medals won by a particular athlete\n");
	printf("Option 2 is athletes with the most medals in a particular sport\n");
	printf("Option 3 number of medals won by sport for a particular country\n");
	printf("Option 4 results for a particular sport in a particular year\n");
	printf("Option 5 Exit\n");
	scanf("%d", &choice);
	handleChoice();
	return;
}

void handleChoice() {




	if (choice == 1) {
		char athlete[100];
		char athleteLname[50];
		char space[2] = { ' ' };

		printf("Enter the athlete's first name: ");
		scanf(" %[^\n]s", athlete);
		printf("Enter the athlete's last name: ");
		scanf(" %[^\n]s", athleteLname);
		strcat(athlete, space);
		strcat(athlete, athleteLname);
		option1(athlete);
	}

	if (choice == 2) {
		char sport[50];
		printf("Enter the sport: ");
		scanf(" %[^\n]s", sport);
		option2(sport);
		return;
	}

	if (choice == 3) {
		char country[50];
		printf("Enter the country: ");
		scanf(" %[^\n]s", country);
		option3(country);
	}

	if (choice == 4) {
		int year = 0;
		char sport[50];
		printf("Enter the sport:\n ");
		scanf(" %[^\n]s %s", sport);
		printf("Enter the year:\n ");
		scanf("%d", &year);
		option4(sport, year);
	}
	if (choice == 5) {
		return;
	}

}
