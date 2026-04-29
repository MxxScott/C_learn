#include <stdio.h>
#define SIZE 10

//function main begins program execution
int main ( void ){
    int s[SIZE];
    for ( int j = 0; j < SIZE; j++){
        s[j] = 2 + 2 * j;
    }
        puts( "Element\tValue" );
    for( int j = 0; j < SIZE; j++ ){
        printf( "%4d%7d\n", j, s[j] );
    }
    return 0; //indicate program ended succesfully

}  //end main function