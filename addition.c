// Addition Program
#include <stdio.h>

// Execution function begins
int main ( void ){
    int integer1;//Declaration of first integer
    int integer2;//Declaration of second integer
    int integer3;//Declaration of third integer
    int integer4;//Declaration of fourth integer

    printf( "Enter the first integer\n" );//prompt the user to enter the first integer
    scanf( "%d", integer1 );//store the entered integer into a variable 

    printf( "Enter the second integer\n" );//prompt the user to enter the second integer
    scanf( "%d", integer2 );//store the entered integer into a variable 
    
    printf( "Enter the third integer\n" );//prompt the user to enter the third integer
    scanf( "%d", integer3 );//store the entered integer into a variable 

    printf( "Enter the fourth integer\n" );//prompt the user to enter the fourth integer
    scanf( "%d", integer4 );//store the entered integer into a variable

    int sum; //variable to store sum
    sum = integer1 + integer2 + integer3 + integer4; //assign total to sum

    printf( "Sum is %d\n", sum );//print sum
}