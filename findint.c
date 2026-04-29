#include <stdio.h>
#include <string.h>

int main ( void ){
    long number;
    char asString[15];

    printf( "Enter 30 digit integer:\n!_" );
    scanf( "%ld", &number );
    // printf( "%ld", number );

    snprintf( asString, sizeof(asString), "%ld", number );
    
    printf( "%c", &asString[15] );
    for ( int i = 0; i < 15; i++)
    {
        printf( "%c\n", asString[i] );
    }
    
}