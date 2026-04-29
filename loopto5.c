#include <stdio.h>

//function main begins program execution
int main ( void )
{
    for ( int i = 1; i <= 10; i++ ){
        if ( i == 5 ){
            break;
        }
        printf("%d", i);
    }
        for ( int i = 1; i <= 10; i++ ){
        if ( i == 5 ){
            continue;
        }
        printf("%d", i);
    }
    return 0; //indicate program ended succesfully

}  //end main function