#include <stdio.h>

int main ( void ){
    int X, Y, temp;
    printf("Input X: !_");
    scanf( "%d", &X );
    printf("Input Y: !_");
    scanf( "%d", &Y );
    temp = X;
    X = Y;
    Y = temp;
    printf( "X is %d\nY is %d\n", X, Y );
    return 0;
}