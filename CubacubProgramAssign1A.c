/* CQPA Calculator Program
Written by: Amber Clarisse Cubacub
Date Written: 02/18/22 */
#include <stdio.h>

int main(void) {
	//declaring the variables
	float unit1, unit2, unit3, unit4, unit5, sumunit;
	float prodgrade1, prodgrade2, prodgrade3, prodgrade4, prodgrade5;
	float totalgrade, grade1, grade2, grade3, grade4, grade5, cqpa;
	
	//The main program will enter the grades and units
	printf("Please input the grades and corresponding units for 5 courses.\n\n");
	printf("Grade for Course 1: "); 
	scanf("%f", &grade1);
	printf("\nCredit Units for Course 1: ");
	scanf("%f", &unit1);
	printf("\n\nGrade for Course 2: ");
	scanf("%f", &grade2);
	printf("\nCredit Units for Course 2: ");
	scanf("%f", &unit2);
	printf("\n\nGrade for Course 3: ");
	scanf("%f", &grade3);
	printf("\nCredit Units for Course 3: ");
	scanf("%f", &unit3);
	printf("\n\nGrade for Course 4: ");
	scanf("%f", &grade4);
	printf("\nCredit Units for Course 4: ");
	scanf("%f", &unit4);
	printf("\n\nGrade for Course 5: ");
	scanf("%f", &grade5);
	printf("\nCredit Units for Course 5: ");
	scanf("%f", &unit5);
	
	//multiplying the grade and the unit of each course
	prodgrade1 = grade1 * unit1;
	prodgrade2 = grade2 * unit2;
	prodgrade3 = grade3 * unit3;
	prodgrade4 = grade4 * unit4;
	prodgrade5 = grade5 * unit5;
	
	//adding the units per courses
	sumunit = unit1+ unit2 + unit3 + unit4 + unit5;
	
	//total of the products of the grade and the unit
	totalgrade = prodgrade1 + prodgrade2 + prodgrade3 + prodgrade4 + prodgrade5;
	
	//CQPA computation which the total product of the grade and unit will divide by the sum of the units
	cqpa = totalgrade / sumunit;
	
	//showing the CQPA
	printf("\n\nYour CQPA is: %.2f", cqpa);
	return 0;
}
