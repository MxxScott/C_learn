// class average program with counter-controlled repitition
#include <stdio.h>

// function main begins program execution
int main ( void )
{
    int counter;    //number of grade to be entered next
    int grade;  //grade value
    int total;  //sum of grades input by user
    int average;    //average of grades

    //initiaization phase
    total = 0;  //initialize total
    counter = 1;    //initialize loop counter

    // Processing phase
    while ( counter <= 10 ){  //loop 10 times
        printf( "Enter grade: " );  //prompt for input
        scanf( "%d", &grade );   //read grade from user
        total = total + grade;  //add grade to total
        counter = counter + 1;  //increment counter
    }//end while

    // termination phase
    average = total / 10; //integer division

    printf ( "Class average is %d\n", average ); //display result

    return 0; //indicate program ended succesfully

 }  //end meain function