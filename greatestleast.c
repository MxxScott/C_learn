#include <stdio.h>

//function main begins program execution
int main ( void ){

    // Declare variables to store the greatest, least, and current input number.
    int greatest, least, num;

    // Display the program title.
    puts( "Greatest-Least Program" );

    // Prompt the user to enter the first number.
    printf( "Input the first number (Enter -99 to break)\n!_" );

    // Read the first number from the user.
    scanf( "%d", &num );

    // Check if the first input is the sentinel value (-99).
    if( num != -99 ){
        // If not -99, initialize greatest and least with the first number.
        greatest = num;
        least = num;

        // Enter a loop that continues until the user enters -99.
        while ( num != -99 ){
            // Check if the current number is greater than the current greatest.
            if( num > greatest ){
                // If so, update greatest.
                greatest = num;
            }
            // Otherwise, check if the current number is less than the current least.
            else if( num < least ){
                // If so, update least.
                least = num;
            }

            // Prompt the user to enter the next number.
            printf( "Input the next number (Enter -99 to break)\n!_" );
            // Read the next number.
            scanf( "%d", &num );
        }

        // After the loop finishes (when the user enters -99), print the results.
        printf( "The greatest number in the provided series is %d\n", greatest );
        printf( "The least number in the provided series is %d\n", least );
    }
    // If the first input was -99, no valid numbers were entered.
    else{
        puts("No valid numbers were provided!!");
    }

    // Indicate that the program ended successfully.
    return 0; 

}  //end main function