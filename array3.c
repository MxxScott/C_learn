#include <stdio.h>

//function main begins program execution
int main ( void ){
    int s[10];
    for ( int j = 0; j <= 9; j++){
        s[j] = 2 + 2 * j;
    }
        puts( "Element\tValue" );
    for( int j = 0; j <= 9; j++ ){
        printf( "%4d%7d\n", j, s[j] );
    }
    return 0; //indicate program ended succesfully

}  //end main function