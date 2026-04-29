#include <stdio.h>

//function main begins program execution
int main ( void ){
    int arr[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

    puts( "Element\tValue" );
    for( int i = 0; i <= 9; i++ ){
        printf( "%4d%7d\n", i, arr[ i ] );
    }

    return 0; //indicate program ended succesfully

}  //end main function