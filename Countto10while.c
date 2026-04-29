#include <stdio.h>

//function main begins program execution
int main ( void ){

    int counter = 2; //initialization

    while ( counter <= 10 ){ //repitition condition
        printf ( "%d\n", counter ); //display counter
        counter += 2; //increment by 2
    } //end while

    return 0; //indicate program ended succesfully

} //end main function