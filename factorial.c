#include <stdio.h>

// Declare nf outside function so it wont be redeclared when function is recalled
int nf;
// factorial function prototype
int factorial ( int n );

//function main begins program execution
int main ( void ){
    // declare the variable for storing the number entered
    int num;
    // Request non-negative integers from user
    puts( "This program will calculate the factorial of the entered number!!" );
    do{
    printf( "Enter Non-Negative integer:\n!_" );
    scanf( "%d",&num );
    nf = factorial(num);
    if( nf == -1 ){
        puts( "!!!Invalid Entry!!!" );
    }
    } while( nf == -1 );
    printf( "%d! = %d\n", num, nf );

    return 0; //indicate program ended succesfully

}  //end main function

// function for finding the factorial
int factorial ( int n ){
    //Verification of non-negative integer
    if( n < 0 ){
        return -1;            
    }
    else if ( n == 0 ){
        return 0;
    }
    else{
        // solving for n! = n · (n - 1) · (n - 2) · … · 1
        // starting by making n! = n
        nf = n;
        // while is not equal to 1 continue to multiply n! by (n - 1)
        while ( n != 1 ){
            // subtract 1 from n and store it in n
            n--;
            // multiply n! by n and store it in n!
            nf *= n;
        }
        return nf;
    }
}