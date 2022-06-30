/* Manipulating One Array Program(with loops and functions)
Written by: Amber Clarisse Cubacub
Date Written: 03/23/22 */
#include <stdio.h>
#include <stdlib.h>
#define	MAX 20 //defining that the maximum array is 20 arrays
//declaring functions
void input (int array1[MAX]); //input arrays
void calculatearray (int array1[MAX], int *sum, int *large, int *small, int *ave); //calculating the arrays original
void outputarray1 (int array1[MAX], int sum, int large, int small, int ave); //output of the original array
void calculateeven (int array1[MAX], int *sum3, int *large3, int *small3, int *ave3); //calculating the even arrays
void outputarray2 (int array1[MAX], int sum3, int large3, int small3, int ave3); //output of the even arrays
void calculateodd (int array1[MAX], int *sum4, int *large4, int *small4, int *ave4); //calculating of the odd arrays
void outputarray3 (int array1[MAX], int sum4, int large4, int small4, int ave4); //output of the odd arrays

int main(void){
	//declaring the variables
	int array1[MAX] = {0};
	int sum, large, small, ave;
	int sum3, large3, small3, ave3;
	int sum4, large4, small4, ave4;
	//functions
	input(array1);
	calculatearray(array1, &sum, &large, &small, &ave);
	outputarray1(array1, sum, large, small, ave);
	calculateeven(array1, &sum3, &large3, &small3, &ave3);
	outputarray2(array1, sum3, large3, small3, ave3);
	calculateodd(array1, &sum4, &large4, &small4, &ave4);
	outputarray3(array1, sum4, large4, small4, ave4);
}

//input 
void input (int array1[MAX]){
	int i,j,x,temp,counter=0;
	char ans = 'y';
	//loop for the input
	do{
		//for loop inside the array input
		for(i = 0; i < MAX; i++){
			//if the ans is Y or y, then it will loop the program until user says n or N
			if(ans == 'y' || ans == 'Y'){
					system("cls"); //clears the program
					printf("Enter a number: ");
					scanf("%d", &array1[i]); //inputting integers into arrays
					printf("Numbers entered: ");
						//making the numbers entered into ascending order
						for(i = 0; i < MAX; i++){
							for(j = i + 1; j < MAX; j++){
								if(array1[i] > array1[j]){
									temp = array1[i];
									array1[i]= array1[j];
									array1[j] = temp;
								}
							}
						}			
					//pasting the array into ascending order
					for (i = 0; i <= MAX; i++){
						if(array1[i] != 0){
							printf("%d\t", array1[i]);
						}
					}
					//prompting the user into continuing to enter an array
					printf("\nDo you want to continue: ");
					scanf("%s", &ans);
					counter++; //increasing the array into the maximum
				}
				//error trapping for full array space
				else{
					printf("\nCannot accommodate any more inputs. The array is full.");
					getch();
					system("cls");
					return;
				}
			//prompting the user to end the loop
			if (ans == 'n' || ans == 'N'){
				printf("Please wait for a moment...\n");
				getch();
				return;
			}
		}
	}while(ans == 'y' || ans == 'Y');
}

//calculate original array
void calculatearray(int array1[MAX], int *sum, int *large, int *small, int *ave){
	int i,s, j, l = array1[0];
	float sum1=0 , avg, counter = 0;
	//looking for larger numbers
	for (i = 0; i < MAX; i++){	
		if (array1[i] > l) {
			l = array1[i];
	    }
  	}    
  	//initializing smaller and larger numbers
   s = l;
   
   //looking for smaller numbers
   for (i = 0; i < MAX; i++) {         
       if(array1[i] != 0){
	   		if(array1[i] < s){
				s = array1[i]; 
			}
		}
    }      
    //sum of the arrays
    for(i = 0; i < MAX; i++){
    	if(array1[i] != 0){
          sum1 = sum1 + array1[i];
			counter ++; //increasing the numbers
		}
	}
	avg = sum1 / counter; //average of the arrays
    
    //storing the sum, average, smaller, and larger numbers
    *sum = sum1;
    *large = l;
    *small = s;
    *ave = avg;
}

//output array 1 original
void outputarray1 (int array1[MAX], int sum, int large, int small, int ave){
	int i;
	printf("Array 1 (Original): \n");
	printf("The numbers are: ");
	//displaying the previous input
	for (i=0; i<MAX; i++){
		if(array1[i] != 0){
			printf("%d\t", array1[i]);
		}
	}
	printf("\nThe largest number: %d", large);
	printf("\nThe smallest number: %d", small);
	printf("\nThe sum: %d", sum);
	printf("\nThe average: %d", ave);
	getch();
}

//calculate even
void calculateeven(int array1[MAX], int *sum3, int *large3, int *small3, int *ave3){
	int i, s, j, 
	int l = array1[0], even1;
	float sum1=0 , avg, counter = 0;
	//looking for larger even numbers
	for (i=0; i < MAX; i++){
	    if ((array1[i]  % 2) == 0){
			if(array1[i] != 0){
				if (array1[i] > l){
					l = array1[i];
				}
	    	}
			
		}
	}
	//initializing smaller and larger numbers
	s = l;
	
	//looking for even smaller numbers
	for (i=0; i < MAX; i++){
	    if ((array1[i]  % 2) == 0){
			if(array1[i] != 0){
				if (array1[i] < s){
					s = array1[i];
				}
	    	}
			
		}
	}
	//sum of the even arrays    
    for(i = 0; i < MAX; i++){
    	if(array1[i]%2 == 0){
    		if(array1[i] != 0){
          		sum1 = sum1 + array1[i];
				counter ++; //increasing the numbers
			}
		}
	}
	avg = sum1 / counter; //average of the even numbers
    
    //storing the sum, average, smaller, and larger numbers
    *sum3 = sum1;
    *large3 = l;
    *small3 = s;
    *ave3 = avg;
}

//output array 2 even
void outputarray2 (int array1[MAX], int sum3, int large3, int small3, int ave3){
	int i;
	printf("\nArray 2 (even): \n");
	printf("The numbers are: ");
	//displaying the previous input but even numbers
	for (i=0; i<MAX; i++){
		 if ((array1[i]  % 2) == 0) {
			if(array1[i] != 0){
				printf("%d\t", array1[i]);
			}
		}
	}
	printf("\nThe largest number: %d", large3);
	printf("\nThe smallest number: %d", small3);
	printf("\nThe sum: %d", sum3);
	printf("\nThe average: %d", ave3);
	getch();
}

//calculate odd
void calculateodd (int array1[MAX], int *sum4, int *large4, int *small4, int *ave4){
	int i, s, j, l = array1[0], even1;
	float sum1=0 , avg, counter = 0;
	//looking for larger odd numbers
	for (i=0; i < MAX; i++){
	    if ((array1[i]  % 2) != 0){
			if(array1[i] != 0){
				if (array1[i] > l){
					l = array1[i];
				}
	    	}
			
		}
	}
	//initializing smaller and larger numbers
	s = l;
	
	//looking for odd smaller numbers
	for (i=0; i < MAX; i++){
	    if ((array1[i]  % 2) != 0){
			if(array1[i] != 0){
				if (array1[i] < s){
					s = array1[i];
				}
	    	}
			
		}
	}
	//sum of the odd numbers   
    for(i = 0; i < MAX; i++){
    	if(array1[i]%2 != 0){
    		if(array1[i] != 0){
          		sum1 = sum1 + array1[i];
				counter ++; //increasing the numbers
			}
		}
	}
	avg = sum1 / counter; //average of the numbers
    
    //storing the sum, average, smaller, and larger numbers
    *sum4 = sum1;
    *large4 = l;
    *small4 = s;
    *ave4 = avg;
}

void outputarray3 (int array1[MAX], int sum4, int large4, int small4, int ave4){
	int i;
	printf("\nArray 3 (odd): \n");
	printf("The numbers are: ");
	//displaying the previous input in odd
	for (i=0; i<MAX; i++){
		if ((array1[i]  % 2) != 0) {
			if(array1[i] != 0){
				printf("%d\t", array1[i]);
			}
		}
	}
	printf("\nThe largest number: %d", large4);
	printf("\nThe smallest number: %d", small4);
	printf("\nThe sum: %d", sum4);
	printf("\nThe average: %d", ave4);
	getch();
}
