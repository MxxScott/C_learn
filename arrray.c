#include <stdio.h>

//function main begins program execution
int main ( void ){
    // declare array "arr"
    int arr[10];
    // for loop to set all elements to 0
    for( int i = 0; i <= 9; i++){
        arr[i] = 0;
    }
    // Display Table
    puts( "Element\tValue" );
    for( int i = 0; i <= 9; i++){
        printf( "%4d%7d\n", i, arr[i] );
    }
    return 0; //indicate program ended succesfully

}  //end main function