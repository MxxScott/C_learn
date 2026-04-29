#include <stdio.h>
#include <math.h>

int main ( void ) {
    // Declaring variables
    float Rate, Principal, Amount;
    int T;

    // prompting input
    printf( "Enter the Principal: \n!_" );
    scanf( "%f", &Principal );

    printf( "Enter the Interest Rate: \n!_" );
    scanf( "%f", &Rate );

    printf( "Enter the number of times the interest is compounded: \n!_" );
    scanf( "%d", &T );

    Amount = Principal * pow( 1 + Rate/T,T );

    printf( "Interest Rate\t\t%.2f%%\n", Rate );
    printf( "Times Compounded\t%d\n", T );
    printf( "Principal\t\t$%.2f\n", Principal );
    printf( "Interest\t\t$%.2f\n", Principal * Rate );
    printf( "Final balance\t\t$%.2f\n", Amount );
    puts("Thank You!!!");
}