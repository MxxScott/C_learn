#include <stdio.h>

//function main begins program execution
int main ( void ){
    int n = 1;
    int odd = 0;
    int even = 0;
    do{
        if( n <= 0 ){
            puts("Error!! Enter positive integer!!");
        }
        printf("Input n: !_");
        scanf( "%d", &n );
    }while( n <= 0 );

    
    for ( int i = 1; i <= n; i++ ){
        odd += ((2 * i) - 1);
        even += (2 * i);
    }
    printf("Sum of first odd integers is %d\n", odd);
    printf("Sum of first even integers is %d\n", even);

   
    return 0;
}  //end main function