#include <stdio.h>

int main ( void ){
    int X, Y;
    printf("Input X: !_");
    scanf( "%d", &X );
    printf("Input Y: !_");
    scanf( "%d", &Y );

    X = X + Y;
    Y = X - Y;
    X = X - Y;

    printf( "X is %d\nY is %d\n", X, Y );
    return 0;
}