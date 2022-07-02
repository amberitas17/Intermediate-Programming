/* Manipulating Singly Linked Lists
Written by: Amber Clarisse Cubacub
Date Written: 05/06/22 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

//declaring the structures with the linked list node
struct node {
     int petnum;
     char animal [20];
     char breed [20];
     char gender[20];
     int age;
     char ownname[50];
     struct node *next; 
} NODE;
struct node *head;

void CreateList(); //to create the list 
void SearchPet();//to search pet via breed or animal
void UpdatePet(); // to update pet information
void DeletePet(int ind); //deleting the list
void display(); // displaying the lists


int main(void){
 //two heads for null node
	char choice;
	int count;
	int i;
	system("cls");
	do{
		//menu
		printf("\nWelcome to Pet Records\n");
		printf("\n [1] Add Pet");
		printf("\n [2] Search Pet");
		printf("\n [3] Search and Update Pet Info");
		printf("\n [4] Search and Delete Pet Info");
		printf("\n [5] Display All Pet Info");
		printf("\n [6] Exit\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				CreateList();
				break;
				
			case 2:
				SearchPet();
				getch();
				break;

			case 3:
				UpdatePet();
				break;

			case 4:
				DeletePet(i);
				break;

			case 5:
				display();
				break;

			case 6:
				printf("\nThank you for using the program");
				exit(0);
				break;	
									
//			default:
//				printf("Error: Incorrect choice. Please input a number from 1-6\n");
//             	break;
             	
				
		}
	} while (choice != 6);
	getch();
}

//create list of pets
void CreateList(){
	 struct node *h, *p;
	 //creating new node
     h = (struct node*)malloc(sizeof(NODE));
     //if h is not null
     if (h != NULL){
     	printf("Enter a Pet Number: ");
     scanf("%d", &h->petnum);
     printf("\nEnter a type of Animal:");
     scanf("%s", &h->animal);
     printf("\nEnter a type of breed:");
     scanf("%s", &h->breed);
     printf("\nEnter gender:");
     scanf("%s", &h->gender);
     printf("\nEnter Pet's Age': ");
     scanf("%d", &h->age);
     printf("\nEnter Owner Name:");
     scanf("%s", &h->ownname);
     
     //if the head is null
     if (head == NULL){
		//making a node
		//making a next null node
		h->next = NULL; 
		head = h;
		// redirecting the head to h
	}
	else{
		p = head;  //p is head
		// move until next node is null
		while (p->next != NULL) {
			p = p->next;
		}
		//creating a node
		p->next = h;
		h->next = NULL; 
		
	}
	 }
}

void SearchPet(){
     struct node *q;
     int cnt = 0;
     int choose;
     char breedsearch[30], animalsearch[20];
     
     //choose breed or animal search
     printf("Please choose breed or animal");
     printf("\n 1-by breed");
     printf("\n 2-by animal\n");
     scanf("%d", &choose);
     
     //if the user choose breed for searching
     if (choose == 1) {
     	q = head;
     	printf("\nBreed to search: ");
     	fflush(stdin);
        gets(breedsearch);
        //if the node is null
     	if (q == NULL)
         printf("The list is empty.");
     	else{
     		//found results
          while (q != NULL){
            if(stricmp(q->breed,breedsearch)==0){
				//found = 1;
            	printf("Pet Number: %d\n", q->petnum);
            	printf("Type of Animal: %s\n", q->animal);
            	printf("Breed: %s\n", q->breed);
            	printf("Gender: %s\n", q->gender);
            	printf("Age: %d\n", q->age);
            	printf("Owner's name: %s\n", q->ownname);
        	}
        	cnt++;
			q= q->next;
          }
     	}	
	 }
	 //if the user uses animal for searching
     if (choose == 2) {
     	printf("\nAnimal to search: ");
     	fflush(stdin);
        gets(animalsearch);
        //if the node is null
     	if (q == NULL)
         printf("The list is empty.");
     	else{
     		//found results
          while (q != NULL){
            if(stricmp(q->animal,animalsearch)==0){
            	printf("Pet Number: %d\n", q->petnum);
            	printf("Type of Animal: %s\n", q->animal);
            	printf("Breed: %s\n", q->breed);
            	printf("Gender: %s\n", q->gender);
            	printf("Age: %d\n", q->age);
            	printf("Owner's name: %s\n", q->ownname);
        	}
        	cnt++;
			q = q->next;  
          }
     	}
	 }
}

//update pet info
void UpdatePet(){
     struct node *ptr;
     int cnt = 0;
     int petno;
     char name[50], bred [30], animal2[10], gender1;
     //if the head is null
     if (head == NULL)
		printf("The list is empty.");
	else
	{
		ptr = head;//head is ptr
		 printf("\nNumber to search: ");//pet number
        scanf("%d", &petno);
		while (ptr != NULL){
			//results
			if(ptr->petnum==petno){
            	printf("Record with pet number %d Found !!!\n", petno);
            	printf("Enter new animal: ");
            	scanf("%s", ptr->animal);
            	printf("Enter new breed: ");
            	scanf("%s", ptr->breed);
            	printf("Enter new gender: ");
            	scanf("%s",ptr->gender);
            	printf("Enter new age: ");
            	scanf("%d",&ptr->age);
            	printf("Enter new Owner name: ");
            	scanf("%s",ptr->ownname);
            	printf("Updation Successful!!!\n");
        }
        ptr = ptr->next;
		}
		
	}
     
}

//delete pet information
void DeletePet(int ind){
     struct node *temp, *ptr, *h;
     int i, cnt;
     int petno;
     char answer;
     ptr = head;
     //if ptr is null list
     if (ptr == NULL)
		printf("The list is empty.");
	else{
		//search via the pet number
		printf("\nNumber to search: ");
        scanf("%d", &petno);
		while (ptr != NULL){
			if(ptr->petnum==petno){
            	printf("Record with pet number %d Found !!!\n", petno);
            	printf("Do you want to delete?\n");
            	scanf(" %c", &answer);
            	
            	if (answer == 'y' || answer == 'Y'){
            		if (ind == 0){
            			printf("\n Deleted successfully");
            			//deleting the node that is part of the node
            			ptr = ptr -> next;
            			temp->next = NULL;
            			free(temp);
					}
					else{
						for (i=0;i < ind;i++){
							temp=temp->next;
						}
						h = temp -> next;
						temp->next = temp->next->next;
						h->next = NULL;
						free(h);
					}
				}
				else{
					getch();
				}
        	}
        	else{
				printf("\n Can't found pet number");
			}
        	cnt++;
        	ptr = ptr -> next;
		}
	}
     
}

//display list
void display(){
	struct node *p;
     p = head;
     //int cnt = 0;
     if (p == NULL){
     	printf("The list is empty.");
	 }		
	else{
		//p is head
		while (p != NULL){	
			printf("\nPet Number: %d\n", p->petnum);
        	printf("Type of animal: %s\n", p->animal);
        	printf("Type of breed: %s\n", p->breed);
        	printf("Gender: %s\n", p->gender);
        	printf("Age: %d\n", p->age);
        	printf("Owner Name: %s", p->ownname);
        	p = p->next;//next list
        	//cnt++;
        }
	}   
}
