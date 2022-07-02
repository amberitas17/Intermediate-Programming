/* Manipulating One Array of Structures Program(with loops and functions)
Written by: Amber Clarisse Cubacub
Date Written: 03/23/22 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define SIZE 10

//declaring array of structures
typedef struct student {
	char fname[20];
	char lname[20];
	char degree[10];
	char year[7];
} st;

int Data_Entry(st studrec[SIZE], int i); //adding students
void Display(st studerec[SIZE], int i); //displaying all the students
void Display_deg(st studerec[SIZE], int i); //displaying the students by using degree
void Display_year(st studerec[SIZE], int i); //displaying the students using year
void update(st studrec[SIZE], int i); // searching and updating students
void del(st studrec[SIZE], int i, int *del1); //searching and deleting students
void gotoxy(short x, short y); //designing the frontend output

int main(void){
	
	//declaring the variables
	int i =0;
	int choice;
	int remove=0;
	st studrec[SIZE]; //structure declaration
	char ans;
	do{
		//menu 
		system("cls");
		printf("\nWelcome to Student Records\n");
		printf("\n [1] Add Student");
		printf("\n [2] Search and Update Student");
		printf("\n [3] Search and Delete Student");
		printf("\n [4] Display Student according to Degree");
		printf("\n [5] Display Student according to Year");
		printf("\n [6] Display All Students");
		printf("\n [7] Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				//repeating the add student if the user want to add a student
				do{
					i = Data_Entry(studrec, i);
					printf("\nAnother: ");
					scanf(" %c", &ans);
				} while ((ans == 'y') && (i != SIZE));
				break;
			case 2:
				update(studrec, i);
				break;
			case 3:
				del(studrec, i, &remove);
				/*the delete function will store the data (remove) in order to delete the data entered
				by the user*/
				i = remove;
				break;
			case 4:
				Display_deg(studrec, i);
				break;
			case 5:
				Display_year(studrec, i);
				break;
			case 6:
				Display(studrec, i);
				break;
			case 7:
				printf("\nThank you for using the program");
				exit(0);
				break;
			default:
				printf("Error: Incorrect choice. Please input a number from 1-7\n");
             	main();
             	break;
				
		}
	} while (choice<=7);
	getch();
}

//adding function
int Data_Entry(st studrec[SIZE], int i){
	char fn[20], ln[20];
	char deg1[10];
	char year1[7];
	//forms
	system("cls");
	printf("Enter info for the student %d", i+1);//adding student i+1
	fflush(stdin);
	printf("\nFirst Name: ");
	gets(fn);
	strcpy(studrec[i].fname, fn);
	printf("Last Name: ");
	gets(ln);
	strcpy(studrec[i].lname, ln);
	printf("Degree: ");
	gets(deg1);
	strcpy(studrec[i].degree, deg1);
	printf("Year: ");
	gets(year1);
	strcpy(studrec[i].year, year1);
	printf("\n The data is successfully added");
	getch();
	i++; //to add the data
	return i;
}

void update(st studrec[SIZE], int i){
	int found = 0, j, k, found1 = 0;
	char lastname[20], new_deg[10], new_year[5], firstname[20];
	int result = 0, result2 = 0, result3 = 0;
	char cont;
	int count = 0; //counting the number of students that entered
	
	system("cls");
	puts("\n\nEnter last name to search: ");
	fflush(stdin);	
	gets(lastname);
	//if the user searched the student via search
	for (j = 0; j < i; j++){
		result = strcmpi(studrec[j].lname,lastname);
		if (result == 0){
			found = 1;
			printf("\nLast name: %s", studrec[j].lname);
			printf("\nFirst name: %s", studrec[j].fname);
			printf("\nDegree: %s", studrec[j].degree);
			printf("\nYear: %s", studrec[j].year);
			count++;
			getch();
		}
	}
	//if the user searched the student that is not found
		if (found == 0){
			printf("The record does not exist.");
			getch();
		}
	//if the search result has one result
	if (count == 1){
		for (j = 0; j < i; j++){
			result = strcmpi(studrec[j].lname,lastname);
			if (result == 0){
				found1++; //this will determine what data will the user edit
				printf("\nDo you want to update the student?");
				scanf("%c", &cont);
					if (cont == 'y' || cont == 'Y'){
						printf("----------------------\n");
						puts("Enter New Degree: ");
						gets(new_deg);
						gets(new_deg);
						strcpy(studrec[j].degree, new_deg);
						puts("Enter New Year Level: ");
						gets(new_year);
						strcpy(studrec[j].year, new_year);
					}
					else if (cont == 'n' || cont == 'N'){
						return;
					}	
			}
		}
	}
	//if the user enters the last name that is same
	if (count > 1)
	{
		puts("\n\nEnter first name to search: ");
		fflush(stdin);	
		gets(firstname);
		for (k = 0; k < i; k++){
			//determining the first and last name
			result2 = strcmpi(studrec[k].fname,firstname);
			result3 = strcmpi(studrec[k].lname,lastname);
			if (result2 == 0 && result3 == 0){
				found = 1;
				printf("\nLast name: %s", studrec[k].lname);
				printf("\nFirst name: %s", studrec[k].fname);
				printf("\nDegree: %s", studrec[k].degree);
				printf("\nYear: %s", studrec[k].year);
				count++;
			}
			if (result2 == 0 && result3 == 0){
				found1++;
				printf("\nDo you want to update the student?");
				scanf("%c", &cont);
					if (cont == 'y' || cont == 'Y'){
						printf("----------------------\n");
						puts("Enter New Degree: ");
						gets(new_deg);
						gets(new_deg);
						strcpy(studrec[k].degree, new_deg);
						puts("Enter New Year Level: ");
						gets(new_year);
						strcpy(studrec[k].year, new_year);
					}
					else if (cont == 'n' || cont == 'N'){
						return;
					}	
			}
		}
			if (found == 0){
				printf("The record does not exist.");
				getch();
			}
	}
}

//deleting data
void del(st studrec[SIZE], int i, int *del1){
	int found = 0, j, k, found1;
	char lastname[20], firstname[20];
	int result=0, result2=0, result3=0;
	char cont;
	int count = 0;
	char temp [20];
	 
	system("cls");
	puts("\n\nEnter last name to search: ");
	fflush(stdin);	
	gets(lastname);
	//searching the data to be deleted
	for (j = 0; j < i; j++){
		result = strcmpi(studrec[j].lname,lastname);
		if (result == 0){
			found = 1;
			printf("Last name: %s", studrec[j].lname);
			printf("\nFirst name: %s", studrec[j].fname);
			printf("\nDegree: %s", studrec[j].degree);
			printf("\nYear: %s", studrec[j].year);
			count++;
		}
	}
	//if the search result has one found
	if (count == 1){
		for (j = 0; j < i; j++){
			result = strcmpi(studrec[j].lname,lastname);
			if (result == 0){
				printf("\nDo you want to delete the student?");
				scanf("%c", &cont);
				if (cont == 'y' || cont == 'Y'){
					strcpy(temp,studrec[0].lname);
					strcpy(studrec[0].lname,studrec[j].lname);
					strcpy(studrec[j].lname,temp);
					for (j = 0; j <= i; j++) {
						studrec[j] = studrec[j + 1];
					}
					i--; //deleting the array
					getch();
				}
				else if (cont == 'n' || cont == 'N'){
					return;
				}	

			}
		}
	}
	//if two or more results have the same surnames
	if (count > 1){
		puts("\n\nEnter first name to search: ");
		fflush(stdin);	
		gets(firstname);
		for (k = 0; k < i; k++){
			//determining first and last names
			result2 = strcmpi(studrec[k].fname,firstname);
			result3 = strcmpi(studrec[k].lname,lastname);
			if (result2 == 0 && result3 == 0){
				found = 1;
				printf("\nLast name: %s", studrec[k].lname);
				printf("\nFirst name: %s", studrec[k].fname);
				printf("\nDegree: %s", studrec[k].degree);
				printf("\nYear: %s", studrec[k].year);
				count++;
			}
			if (result2 == 0 && result3 == 0){
				found1++;
				printf("\nDo you want to delete the student?");
				scanf("%c", &cont);
					if (cont == 'y' || cont == 'Y'){
						strcpy(temp,studrec[0].lname);
						strcpy(studrec[0].lname,studrec[j].lname);
						strcpy(studrec[j].lname,temp);
						for (j = 0; j < i; j++) {
							studrec[j] = studrec[j + 1];
						}
						i--;
						getch();
					}
					else if (cont == 'n' || cont == 'N'){
						return;
					}	
			}
		}
	}
	//if the search result was not found
	if (found == 0){
				printf("The record does not exist.");
				getch();
			}
	//storing the data
	*del1 = i;
}

//displaying results according to degree
void Display_deg(st studrec[SIZE], int i){
	int j, x1, x2, x3, y, result=0, found=0;
	char deg2[10];
     system("cls");
     puts("\n\nEnter degree to search: ");
	 fflush(stdin);	
     gets(deg2);
	for (j = 0; j < i; j++){
		result = strcmpi(studrec[j].degree,deg2);
		if (result == 0){
			found = 1;
			printf("Last name: %s", studrec[j].lname);
			printf("\nFirst name: %s", studrec[j].fname);
			printf("\nDegree: %s", studrec[j].degree);
			printf("\nYear: %s", studrec[j].year);
			getch();
		}
		if (found == 0){
			printf("The record does not exist.");
			getch();
		}
	}  
     getch();
}

//displaying according to year
void Display_year(st studrec[SIZE], int i){
	int j, x1, x2, x3, y, found=0, result=0;
	char yr[5];
     system("cls");
     puts("\n\nEnter degree to search: ");
	 fflush(stdin);	
     gets(yr);
	for (j = 0; j < i; j++){
		result = strcmpi(studrec[j].year,yr);
		if (result == 0){
			found = 1;
			printf("\nLast name: %s", studrec[j].lname);
			printf("\nFirst name: %s", studrec[j].fname);
			printf("\nDegree: %s", studrec[j].degree);
			printf("\nYear: %s", studrec[j].year);
			getch();
		}
		if (found == 0){
			printf("The record does not exist.");
			getch();
		}
	}  
     getch();
}

//displaying all the data
void Display(st studrec[SIZE], int i){
	int j, x1, x2, x3, y;
     
     system("cls");
     gotoxy(1,3); printf("Name");
     gotoxy(1,4); printf("-----------");
     gotoxy(18,3); printf("Degree");
     gotoxy(18,4); printf("-------");
     gotoxy(30,3); printf("Year");
     gotoxy(30,4); printf("-----");
     
     x1 = 1;
     x2 = 18;
     x3 = 28;
     y = 5;
     for (j=0; j < i; j++){
         gotoxy(x1, y); printf("%s, %s", studrec[j].lname, studrec[j].fname);
         gotoxy(x2, y); printf("%s", studrec[j].degree);
         gotoxy(x3, y); printf("%s", studrec[j].year);
         y++;
     }    
     getch();
}

//fixing the table
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
