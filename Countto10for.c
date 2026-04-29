#include <stdio.h>

//function main begins program execution
int main ( void ){
    int counter;

    /*initialization, repitition condition, and increment
    are all included in the for statement header*/
    for ( counter = 1; counter <= 10; counter++ ){
        printf( "%d\n", counter );
    } //end for
    
    return 0; //indicate program ended succesfully

}  //end main function