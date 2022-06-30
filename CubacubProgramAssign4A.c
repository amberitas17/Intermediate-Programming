/* Height and Weight Coversion Program(with loops and functions)
Written by: Amber Clarisse Cubacub
Date Written: 03/12/22 */
#include <stdio.h>
#include <stdlib.h>
//declaring functions
void menu(int *choice); //choice menu
void height(float feet, float inch, float *inches, float *meter, float *cm); //calculate and entering the height conversion
void heightOutput(float inches, float meter, float cm);//sees the output of the height conversion
void weight(float pound, float ounce, float *ounce2, float *kilograms, float *grams); //calculate and entering the weight conversion
void weightOutput(float ounce2, float kilograms, float grams);//sees the output of the weight conversion

int main(void) {
	//declaring the 
	int choice;
	float feet, inch, inches, meter, cm, pound, ounce, ounce2, kg, gm;
	//looping the choices
	menu(&choice);
	do{//declaring the menu with the choice
		switch (choice) {
          	case 1:
             	height(feet, inch, &inches, &meter, &cm);
             	heightOutput(inches, meter, cm);
             	//this will prompt the user to continue
				menu(&choice);
				break;
           	case 2:
             	weight(pound, ounce, &ounce2, &kg, &gm);
             	weightOutput(ounce2, kg, gm);
             	//this will prompt the user to continue
				menu(&choice);
				break;
           	case 3:
			   printf("Thank you for using our program");
			   exit(0);
			   break;
           	default:
           		//error trap
             	printf("Error: Incorrect choice. Please input a number from 1-3\n");
             	menu(&choice);
             	break;
       }
    }while(choice<=3);
}
//the menu for choice function
void menu(int *choice){
	int choices;
		printf("\nMain Menu \n");
		printf("[1] Height Conversion\n");
		printf("[2] Weight Conversion\n");
		printf("[3] Exit\n");
		printf("\nYour Choice: ");
		scanf("%d", &choices);
		*choice = choices;//this will be the storing the choice number
}

//height calculation and input
void height (float feet, float inch, float *inches, float *meter, float *cm){
	float inh, mtr, centi;
	
	//entering user the feet and inches
	printf("\nPlease enter your height in feet and inches:\n");
	printf("Feet: ");
	scanf("%f", &feet);
	printf("\nInches: ");
	scanf("%f", &inch);
	//error trap
	if (feet <= 0 || inch <= 0){
		printf("Please enter higher than 0");
		main();
	}
	//height to inches computation
	inh = (feet * 12) + inch;
	//height to meter computation
	mtr = inh * 0.0254;
	//height to centimeter computation
	centi = mtr * 100;
	//storing the inches, meter, and cm to the next function
	*inches = inh;
	*meter = mtr;
	*cm = centi;
}

//output of height conversion via the stored pointers
void heightOutput (float inches, float meter, float cm){
	printf("\nYour equivalent height in:\n");
	printf("\nInches: %.4f ", inches);
	printf("\nMeters: %.4f ", meter);
	printf("\nCentimeters: %.4f \n", cm);
}

//weight calculation and input
void weight(float pound, float ounce, float *ounce2, float *kilograms, float *grams){
	float oz, kilo, gms, oz2;
	
	//entering user the pound and ounces
	printf("\nPlease enter your weight in pound and ounce:\n");
	printf("Pound: ");
	scanf("%f", &pound);
	printf("\nOunce: ");
	scanf("%f", &ounce);
	//error trap 
	if (pound <= 0 || ounce <= 0){
		printf("Please enter higher than 0");
		main();
	}
	//weight to ounce computation
	oz = (pound * 16) + ounce;
	// converting weight to pounds to get the kilograms
	oz2 = pound + (ounce / 16);
	// converting weight to kilograms
	kilo = oz2 / 2.2046226218;
	// converting weight to grams
	gms = oz2 * 453.59237;
	//storing the ounce, kilograms, and grams to the next function
	*ounce2 = oz;
	*kilograms = kilo;
	*grams = gms;
}

//output of weight conversion via the stored pointers
void weightOutput(float ounce2, float kilograms, float grams){
	printf("\nYour equivalent weight in:\n");
	printf("\nOunces: %.4f ", ounce2);
	printf("\nKilograms: %.4f ", kilograms);
	printf("\nGrams: %.4f \n", grams);
}
