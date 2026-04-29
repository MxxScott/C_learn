// fibonaci sequence
#include <stdio.h>
int n; 
int fibonacci( int n );

//function main begins program execution
int main ( void ){
    printf( "Enter number of first terms for fibonacci sequence:\n!_" );
    scanf( "%d", &n );
    fibonacci( n );
    return 0; //indicate program ended succesfully

}  //end main function

int fibonacci( int n ){
    int tn_2 = 0;
    int tn = 1;
    int temp = 0;
    printf( "%d ", temp );
    temp = 1;
    for ( int i = 1; i <= n; i++ ){
        printf( "%d ", temp );
        temp = tn;
        tn += tn_2;
        tn_2 = temp;
        temp = tn;
    }
    return 0;
}