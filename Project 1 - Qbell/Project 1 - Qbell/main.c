/*	ENG175IN	Summer 2020
 *
 *	Author:	Quynn Bell
 *
 *	Date Created:	29th of June 2020
 *
 *	Copyright @Qbell.	All Rights Reserved.
 *
 *	Program Function: Quadratic Formula Calculator. Takes in values a, b, and c in order to calculate the value or values of x which make the expression true.
 */

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>



char userRestart;

int main(void) {

	// user defined variables
	long double valueA;
	long double valueB;
	long double valueC;
	long double valueX1; 
	long double valueX2;
	long double discriminant;

	// characters used for verifying or changing input
	char valueVerify;
	char valueChange;

	// start of the do...while loop for restarting program
	do {

		
		// printing menu / user interface
		printf("Program: Quadratic Formula Calculator\n\n");
		printf("Quadratic Equation (Standard Form):\tax^2 + bx + c = 0\n\n");
		printf("Please enter a value for variable a: ");
			scanf("%lf", &valueA);
		printf("Please enter a value for variable b: ");
			scanf("%lf", &valueB);
		printf("Please enter a value for variable c: ");
			scanf("%lf", &valueC);
		printf("\nYou entered:\na = %.2lf\nb = %.2lf\nc = %.2lf\n\n", valueA, valueB, valueC);
		printf("Are these values correct? (Y / N) ");
			scanf(" %c", &valueVerify);

		
		// verifying user answer is either y or n. looping until answer is either y or n.
		while ((valueVerify != 'Y') && (valueVerify != 'y') && (valueVerify != 'N') && (valueVerify != 'n')) {
			printf("Invalid Entry. Please resubmit answer (Y / N): ");
				scanf(" %c", &valueVerify);
		}


		// when user enters n, the user will be asked to specify which variable is wrong
		while ((valueVerify == 'n') || (valueVerify == 'N')) {
			printf("Which value is incorrect? (a,b,c): ");
				scanf(" %c", &valueChange);
				

			// checking user input and having user re enter that value
			switch (valueChange) {

				case 'a':

					printf("Please re-enter a value for variable a: ");
						scanf("%lf", &valueA);
					printf("\nYou entered:\na = %.2lf\nb = %.2lf\nc = %.2lf\n\n", valueA, valueB, valueC);
					printf("Are these values correct? (Y / N) ");
					scanf(" %c", &valueVerify);
					break;

				case 'b':

					printf("Please re-enter a value for variable b: ");
					scanf("%lf", &valueB);
					printf("\nYou entered:\na = %.2lf\nb = %.2lf\nc = %.2lf\n\n", valueA, valueB, valueC);
					printf("Are these values correct? (Y / N) ");
					scanf(" %c", &valueVerify);
					break;

				case 'c':

					printf("Please re-enter a value for variable c: ");
					scanf("%lf", &valueC);
					printf("\nYou entered:\na = %.2lf\nb = %.2lf\nc = %.2lf\n\n", valueA, valueB, valueC);
					printf("Are these values correct? (Y / N) ");
					scanf(" %c", &valueVerify);
					break;

				default:

					printf("Invalid Entry. Please Try Again.\n");
					break;
			}
		}
		
		// computations
		discriminant = (pow(valueB, 2)) - (4 * valueA * valueC);

		// printing discriminant answer
		printf("\n\nThe discriminant is calculated to be: %.2lf\n\n", discriminant);
        
		// computations based on discriminant calculated above
		if (discriminant == 0) {
			valueX1 = (-(valueB)) / (2 * valueA);
			printf("One Real Solution\n");
			printf("x = %.3lf\n\n", valueX1);
			
		} else if (discriminant > 0) {
			valueX1 = ((-(valueB)) - sqrt(discriminant)) / (2 * valueA);
			valueX2 = ((-(valueB)) + sqrt(discriminant)) / (2 * valueA);
			printf("Two Real Solutions\n");
			printf("x = %.3lf and %.3lf\n\n", valueX1, valueX2);
			
		} else if (discriminant < 0) {
			valueX1 = ((-(valueB)) / (2 * valueA));
			valueX2 = ((-(valueB)) / (2 * valueA));
			discriminant = (sqrt(-(discriminant)) / (2 * valueA));
			printf("Two Imaginary Solutions\n");
			printf("x = %.3lf + %.3lfi and %.3lf - %.3lfi\n\n", valueX1, discriminant, valueX2, discriminant);
			
		}

	
		// asking user if they want to restart program
		printf("Do you wish to restart the program? (Y / N) ");
			scanf(" %c", &userRestart);
	

		// checking and validating user's response is either Y or N
		while ((userRestart != 'N') && (userRestart != 'n') && (userRestart != 'Y') && (userRestart != 'y')) {
			printf("Invalid Entry. Please enter Yes or No (Y / N) ");
				scanf(" %c", &userRestart);
		}


		// if user wants to exit, break from loop an exit. else continue the loop.
		if ((userRestart == 'N') || (userRestart == 'n')) {
			printf("\nGoodbye.\n\n");
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			return 0;
			break;
		}
		else {
			// user defined variables
			valueA = 0.00;
			valueB = 0.00;
			valueC = 0.00;
			valueX1 = 0.00;
			valueX2 = 0.00;
			discriminant = 0.00;
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			continue;
		}

	} while ((userRestart == 'Y') || (userRestart == 'y'));  // will restart loop if user entered Y.
}