#include <stdio.h>

int main ( void ){
    // declaration and initialization
    int counter = 0;  // Counts the number of grades entered
    int grade;        // Stores the current grade input
    int total = 0;    // Accumulates the sum of grades
    float average;   // Stores the calculated average

    // Prompt the user to enter the first grade
    printf( "Input the first grade (Enter -1 to break)\n!_" );
    scanf( "%d", &grade );

    // Check if the user wants to terminate immediately
    if ( grade == -1){
        puts( "Program Terminated!!!" );  // Use puts for simple string output
        return 0; // Exit the program successfully
    }
    else{
        // Loop to continuously take grade inputs until -1 is entered
        while ( grade != -1 ){
            total += grade;    // Add the current grade to the total
            counter++;       // Increment the grade counter
            printf( "Input the next grade (Enter -1 to break)\n!_" );
            scanf( "%d", &grade );  // Read the next grade
        }
    }

    // Calculate the average after the loop finishes
    // Cast total to float to ensure accurate division
    average = (float) total / counter;  

    // Print the calculated average
    printf( "The average of the grades is %f", average );
    
    return 0; // Indicate successful program completion (good practice to always include this)
}