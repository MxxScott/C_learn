#include <stdio.h>

//function main begins program execution
int main ( void )
{
    int counter = 1;

    do{
        printf( "%d ", counter );
    } while ( ++counter <= 10 );
    
    return 0; //indicate program ended succesfully

}  //end main function