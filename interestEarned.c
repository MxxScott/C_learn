/*********************
Program: Interest earned
Date: 23/10/23
Author: C.Adjetey
*********************/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//declaration
	float principal, interestRate, interest, balance;
	int timesCompund;
	
	//accepting user input
	printf("Enter the principal: ");
	scanf("%f", &principal);
	
	printf("Enter the interest rate: ");
	scanf("%f", &interestRate);
	
	printf("Enter the number times compunded: ");
	scanf("%d", &timesCompund);
	
	//computation
	balance = principal * pow(1 + interestRate / timesCompund, timesCompund);
	interest = balance -  principal;
	
	//displaying
	printf("%-20s %10.2f%s\n", "Interest Rate:", interestRate * 100,"%");
	printf("%-20s  %10d\n", "Times Compounded:", timesCompund);
	printf("%-20s $%10.2f\n", "Principal:", principal);
	printf("%-20s $%10.2f\n", "Interest:", interest);
	printf("%-20s $%10.2f\n", "Final balance:", balance);
	
	
	
	return 0;
}
