#include <stdio.h>

//function main begins program execution
int main ( void ){

    int x;
    printf("Enter numeric value ");
    scanf("%d", &x);

    switch (x)
    {
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default:
            printf("Wrong Day");
            break;
    }
    return 0; //indicate program ended succesfully

}  //end main function