/* Height and Weight Coversion Program(with loops)
Written by: Amber Clarisse Cubacub
Date Written: 03/04/22 */
#include <stdio.h>

int main(void) {
	//declaring the variables
	int choice;
	float feet, inches1, inches2, pounds;
	float meter, pound2, cm, ounce, ounce2, kg, grams;
	
	//declaring the do while
	do{
		//menu program
		printf("\nMain Menu \n");
		printf("[1] Height Conversion\n");
		printf("[2] Weight Conversion\n");
		printf("[3] Exit\n");
		printf("\nYour Choice: ");
		scanf("%d", &choice);
		
		//Height choice
		if(choice==1){
				printf("\nPlease enter your height in feet and inches:\n");
				printf("Feet: ");
				scanf("%f", &feet);
				printf("\nInches: ");
				scanf("%f", &inches1);
				
				//height to inches computation
				inches2 = (feet * 12) + inches1;
				//height to meter computation
				meter = inches2 * 0.0254;
				//height to centimeter computation
				cm = meter * 100;
				
				printf("\nYour equivalent height in:\n");
				printf("\nInches: %.4f ", inches2);
				printf("\nMeters: %.4f ", meter);
				printf("\nCentimeters: %.4f \n", cm);
			}
			
			//Weight conversion
			else if(choice==2){
				printf("\nPlease enter your weight in pounds and ounces: \n");
				printf("Pounds: ");
				scanf("%f", &pounds);
				printf("\nOunces: ");
				scanf("%f", &ounce);
				
				//weight to ounce computation
				ounce2 = (pounds * 16) + ounce;
				// converting weight to pounds to get the kilograms
				pound2 = pounds + (ounce / 16);
				// converting weight to kilograms
				kg = pound2 *  0.45359237;
				// converting weight to grams
				grams = kg * 1000;
				
				printf("\nYour equivalent weight in:");
				printf("\nOunces: %.4f", ounce2);
				printf("\nKilograms: %.4f", kg);
				printf("\nGrams: %.4f \n", grams);
			}
			
			//Exit choice
			else if(choice==3){
				printf("\nExiting the program...");
				break; //breaking the loop
			}
			
			else{
				//error message 
				printf("\nError: Incorrect choice. Please input a number from 1-3.");
			}
//the while loop will represent if the choice entry is incorrect
}while(choice!=3);
	return 0;
}
