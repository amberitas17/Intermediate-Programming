/* Manipulating Doubly Linked Lists
Written by: Amber Clarisse Cubacub
Date Written: 05/26/22 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *nd;
struct node {
     int petnum;
     char animal [20];
     char breed [20];
     char gender[20];
     int age;
     char ownname[50];
     nd left, right; 
} NODE;

//nd functions to be able to point in the struct node
nd CreateList(int i, int *add ,nd head);
void SearchPet(nd head);
void DisplayList(nd head);
nd UpdatePet(nd head);
nd DeletePet(nd head);
void sort_increasing(nd head);

int main(void){
	nd head = NULL; // if head is NULL
	char choice;
	int i, pos;
	int count = 0;

	do{
		//menu 
		system("cls");
		printf("\nWelcome to Pet Records\n");
		printf("\n [1] Add Pet");
		printf("\n [2] Search Pet");
		printf("\n [3] Search and Update Pet Info");
		printf("\n [4] Search and Delete Pet Info");
		printf("\n [5] Display All Pet Info");
		printf("\n [6] Exit\n");
		scanf("%d", &choice);
		
		if(choice == 1){	
			i = count;
			head = CreateList(i,&count,head);	//counting the lists 
		}
		else if(choice == 2){
			SearchPet(head);
			getch();
		}
		else if(choice == 3){
			//edit
			UpdatePet(head);
			getch();
		}
			else if(choice == 4){
			//delete
			//head will direct to delete function
			head = DeletePet(head);
			getch();
		}
		else if(choice == 5){
			sort_increasing(head);
			DisplayList(head);
			getch();
		}
		else if(choice == 6){
			//exiting
			exit(0);
		}
	
	} while (choice != 6);
}

nd CreateList(int i, int *add, nd head){
     nd h = NULL;
	 nd p = NULL;
	 nd temp = NULL;
	 nd q = NULL;
	 nd ptr = NULL;
	 int count = i;
	
	if (count == 0){
	 	head = NULL;
	}
	//creating a list
	h = malloc(sizeof(NODE)); 
     printf("Enter a Pet Number: ");
     scanf("%d", &(h->petnum));
     printf("\nEnter a type of Animal:");
     fflush(stdin);
     gets(h->animal);
     printf("\nEnter a type of breed:");
     fflush(stdin);
     gets(h->breed);
     printf("\nEnter gender:");
     fflush(stdin);
     gets(h->gender);
     printf("\nEnter Pet's Age': ");
     fflush(stdin);
	 scanf("%d", &(h->age));
     printf("\nEnter Owner Name:");
     fflush(stdin);
     gets(h->ownname);
     
  
	if(head == NULL){
		head = h;	
		head->left = NULL;
		head->right = NULL;	
	}
		
	else{
		p = head; 
		// this for inserting to the end of the list
		while (p->right != NULL) {
			p = p->right;  
		}
			if(h->petnum > p->petnum){
				
				p->right = h;
				h->left =  p;				
				h->right = NULL; 
			}
			else{
			
				temp = head;
				q = head;
				// inserting in the middle
	  			while (temp != NULL && (q->petnum < h->petnum && temp->petnum < h->petnum)){
					q = temp;
					temp = temp -> right;
				}
				q->right = h;
				h->left = q;
	  			h->right= temp;
				temp->left=h;
			}	
	}
	//letting go of the pointers
		h = NULL;
		p = NULL;
		temp = NULL;
		q = NULL;
		free(h);
		free(p);
		free(temp);
		free(q);
		//adding the lists
		count++;
		*add = count;
		return head;
}
void SearchPet(nd head){
     nd h = head, ptr;
     int choose, found = 0;
     char breedsearch[30], animalsearch[20];
     //choosing the breed or animal
     printf("Please choose breed or animal");
     printf("\n 1-by breed");
     printf("\n 2-by animal\n");
     scanf("%d", &choose);
     //if the user chooses breed
     if (choose == 1){
     	ptr = h;
     	printf("\nBreed to search: ");
     	fflush(stdin);
        gets(breedsearch);
        while (ptr != NULL){
        	//if it is same as breed search
			if (strcmpi(ptr->breed,breedsearch) == 0){
				found = 1;
				break;
			}
			else	
				ptr = ptr->right;
		}
     
	 	if (found == 0){
		    printf("The list is empty.");
     	}
		else{
			//showing the lists
            printf("Pet Number: %d\n", ptr->petnum);
            printf("Type of Animal: %s\n", ptr->animal);
            printf("Breed: %s\n", ptr->breed);
            printf("Gender: %s\n", ptr->gender);
            printf("Age: %d\n", ptr->age);
            printf("Owner's name: %s\n", ptr->ownname);
            if (ptr->right==NULL){
            	printf("\n No right node/next node");
			}
			else{
				printf("Pet Number: %d\n", ptr->right->petnum);
            	printf("Type of Animal: %s\n", ptr->right->animal);
            	printf("Breed: %s\n", ptr->right->breed);
            	printf("Gender: %s\n", ptr->right->gender);
            	printf("Age: %d\n", ptr->right->age);
            	printf("Owner's name: %s\n", ptr->right->ownname);
			}
			if (ptr->left==NULL){
				printf("\n No right node/next node");
			}
			else{
				printf("Pet Number: %d\n", ptr->left->petnum);
            	printf("Type of Animal: %s\n", ptr->left->animal);
            	printf("Breed: %s\n", ptr->left->breed);
            	printf("Gender: %s\n", ptr->left->gender);
            	printf("Age: %d\n", ptr->left->age);
            	printf("Owner's name: %s\n", ptr->left->ownname);	
			}
        }
    }
	//if the user chooses animal	
     if (choose == 2) 
	 {
     	ptr = h;
     	printf("\nAnimal to search: ");
     	fflush(stdin);
        gets(animalsearch);
     	while (ptr != NULL){
     		//if it is same as breed search
			if (strcmpi(ptr->breed,breedsearch) == 0){
				found = 1;
				break;
			}
			else	
				ptr = ptr->right;
		}
     
	 	if (found == 0){
		    printf("The list is empty.");
     	}
		else{
			//showing the lists
            printf("Pet Number: %d\n", ptr->petnum);
            printf("Type of Animal: %s\n", ptr->animal);
            printf("Breed: %s\n", ptr->breed);
            printf("Gender: %s\n", ptr->gender);
            printf("Age: %d\n", ptr->age);
            printf("Owner's name: %s\n", ptr->ownname);
            if (ptr->right==NULL){
            	printf("\n No right node/next node");
			}
			else{
				printf("Pet Number: %d\n", ptr->right->petnum);
            	printf("Type of Animal: %s\n", ptr->right->animal);
            	printf("Breed: %s\n", ptr->right->breed);
            	printf("Gender: %s\n", ptr->right->gender);
            	printf("Age: %d\n", ptr->right->age);
            	printf("Owner's name: %s\n", ptr->right->ownname);
			}
			if (ptr->left==NULL){
				printf("\n No right node/next node");
			}
			else{
				printf("Pet Number: %d\n", ptr->left->petnum);
            	printf("Type of Animal: %s\n", ptr->left->animal);
            	printf("Breed: %s\n", ptr->left->breed);
            	printf("Gender: %s\n", ptr->left->gender);
            	printf("Age: %d\n", ptr->left->age);
            	printf("Owner's name: %s\n", ptr->left->ownname);	
			}
        }
	}
}

//traversing the lists
void DisplayList(nd head){
	nd p, q;
    if (head == NULL){
		printf("The list is empty.");
	}
	else{
		p = head;
		//showing left and right lists
		while (p != NULL){	
			q = p;
			printf("Pet Number: %d\n", p->petnum);
        	printf("Type of animal: %s\n", p->animal);
        	printf("Type of breed: %s\n", p->breed);
        	printf("Gender: %s\n", p->gender);
        	printf("Age: %d\n", p->age);
        	printf("Owner Name: %s\n", p->ownname);
        	p = p->right;
        }
        while (q != NULL){
        	printf("Pet Number: %d\n", q->petnum);
        	printf("Type of animal: %s\n", q->animal);
        	printf("Type of breed: %s\n", q->breed);
        	printf("Gender: %s\n", q->gender);
        	printf("Age: %d\n", q->age);
        	printf("Owner Name: %s\n", q->ownname);
        	q = q->left;
		}
	}
	getch();
}
nd UpdatePet(nd head){
     nd h = head, ptr;
     int cnt = 0, found = 0, choose;
     int age;
     char name[50], bred [20], animal2[20], gender1[20];
     char breedsearch[20], anisearch[20];
     printf("Please choose breed or animal");
     printf("\n 1-by breed");
     printf("\n 2-by animal\n");
     scanf("%d", &choose);
     if (choose == 1){
		ptr = h;
		 printf("\nBreed to search: ");
     	fflush(stdin);
        gets(breedsearch);
		while (ptr != NULL){
			found = 1;
			//updating the data via breed search
			if(strcmpi(ptr->breed,breedsearch) == 0){
            	printf("Record with pet number %s Found !!!\n", breedsearch);
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
        	ptr = ptr->right;//going to the right
	 	}
	 }
	 if (choose == 2){
		ptr = h;
		 printf("\nAnimal to search: ");
     	fflush(stdin);
        gets(anisearch);
		while (ptr != NULL){
			found = 1;
			//updating the data via animal search
			if(strcmpi(ptr->animal,anisearch) == 0){
            	printf("Record with pet number %s Found !!!\n", anisearch);
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
        	ptr = ptr->right;//going to the right
	 	}
	 }
}

nd DeletePet(nd head){
     nd h = head, ptr, temp, q;
     int cnt = 0;
     int choose;
     char answer, breedsearch[20], anisearch[20];
     printf("Please choose breed or animal");
     printf("\n 1-by breed");
     printf("\n 2-by animal\n");
     scanf("%d", &choose);
     
     if (choose == 1)
	 {
		ptr = h;
		printf("\nBreed to search: ");
     	fflush(stdin);
        gets(breedsearch);
		while(ptr!=NULL)
		{
			if(strcmpi(ptr->breed,breedsearch) == 0)
			{
	           	printf("Record with pet breed %s Found !!!\n", breedsearch);
			}
			ptr=ptr->right;
		}
		printf("Do you want to delete?\n");
	    scanf("%c", &answer);
	    if (answer == 'y' || answer == 'Y')
		{
			ptr = h;
			printf("Deleting this node.");
			if(h->right==NULL) //if only one node left
			{
				if (strcmpi(ptr->breed,breedsearch) == 0)
				{	
					h->right=NULL;
					h->left =NULL;
					h = NULL;
					getch();
				}
			}
			else if(h->right!=NULL)//if more than 1 node left and item to delete is the beginning
			{
				if (strcmpi(ptr->breed,breedsearch)== 0)
				{
					h = ptr->right;
					ptr->right=NULL;
					ptr->left =NULL;
					getch();
				}
			}
			
			else
			{
				ptr = h;
				while(ptr->right != NULL) // if item to delete is in the end
				{
					ptr=ptr->right;
				}
				if (strcmpi(ptr->breed,breedsearch) == 0)
				{
					ptr->left->right = NULL;
					ptr->left = NULL;
					ptr = NULL;
				}
				else // delete beginning of the list
				{
					temp = h;
					while (temp != NULL && (strcmpi(ptr->breed,breedsearch) != 0))
					{
						temp = temp -> right;
					}
					temp->left->right=temp->right;
					temp->right->left=temp->left;
					temp->right=NULL;
					temp->left=NULL;
					temp = NULL;
				}
			}	
    	}
    	else
		{
			getch();
		}
	}
	if (choose == 2)
	{
		ptr = h;
		printf("\nAnimal to search: ");
     	fflush(stdin);
        gets(anisearch);
		while(ptr!=NULL)
		{
			if(strcmpi(ptr->animal,anisearch) == 0)
			{
	           	printf("Record with pet breed %s Found !!!\n", breedsearch);
			}
			ptr=ptr->right;
		}
		printf("Do you want to delete?\n");
	    scanf("%c", &answer);
	    if (answer == 'y' || answer == 'Y')
		{
			ptr = h;
			printf("Deleting this node.");
			if(h->right==NULL) //if only one node left
			{
				if (strcmpi(ptr->animal,anisearch) == 0)
				{	
					h->right=NULL;
					h->left =NULL;
					h = NULL;
					getch();
				}
			}
			else if(h->right!=NULL)//if more than 1 node left and item to delete is the beginning
			{
				if (strcmpi(ptr->animal,anisearch)== 0)
				{
					h = ptr->right;
					ptr->right=NULL;
					ptr->left =NULL;
					getch();
				}
			}
			
			else
			{
				ptr = h;
				while(ptr->right != NULL) // if item to delete is in the end
				{
					ptr=ptr->right;
				}
				if (strcmpi(ptr->animal,anisearch) == 0)
				{
					ptr->left->right = NULL;
					ptr->left = NULL;
					ptr = NULL;
				}
				else // delete beginning of the list
				{
					temp = h;
					while (temp != NULL && (strcmpi(ptr->animal,anisearch) != 0))
					{
						temp = temp -> right;
					}
					temp->left->right=temp->right;
					temp->right->left=temp->left;
					temp->right=NULL;
					temp->left=NULL;
					temp = NULL;
				}
			}	
    	}
    	else
		{
			getch();
		}
    }
    return h;
}

void sort_increasing(nd head){
	 struct node *current = NULL, *index = NULL; 
	 nd temp = head;
	  if(head == NULL) {  
        return;  
    }  
    else {  
        //Current will point to head  
        for(current = head; current->right != NULL; current = current->right) {  
            //index will point to node next to current  
            for(index = current->right; index != NULL; index = index->right) {  
                //if current's data is greater than index's data, swap the data of current and index  
                if(current->petnum > index->petnum) {  
                    temp = current->petnum;  
                    current->petnum = index->petnum;  
                    index->petnum = temp;  
                }  
            }  
        }  
    }  
}
