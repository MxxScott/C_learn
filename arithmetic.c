/***********************
Author: C.Adjetey
Program: Chapter 2 PC 2.16 Arithmetic
Date:19/10/2023
*************************/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	// declaration of variables
	int sum, product, quotient, difference, remainder;
	int firstNum, secondNum;

	// accepting inputs
	printf("Enter the first number: ");
	scanf("%d", &firstNum);

	printf("Enter the second number: ");
	scanf("%d", &secondNum);

	// computation
	sum = firstNum + secondNum;
	product = firstNum * secondNum;
	quotient = firstNum / secondNum;
	difference = firstNum - secondNum;
	remainder = firstNum % secondNum;

	// displaying of results
	putchar('\n'); // this is just giving a space before displaying results
	printf("The sum of %d and %d is: %d\n", firstNum, secondNum, sum);
	printf("The product of %d and %d is: %d\n", firstNum, secondNum, product);
	printf("The difference of %d and %d is: %d\n", firstNum, secondNum, difference);
	printf("The quotient of %d and %d is: %d\n", firstNum, secondNum, quotient);
	printf("The remainder of %d and %d is: %d\n", firstNum, secondNum, remainder);
	puts("Thank you!");

	return 0;
}
