#include <stdio.h>
#define SIZE 5
int stack[ SIZE ];
int top = -1;

int pop();
int push( int value );

//function main begins program execution
int main ( void ){
    int option, value;
    int end = 1;
    puts("!!Stack Created!!");
    puts("!!Stack Size is 5!!");
    while ( end ){
        puts( "\nChoose action:" );
        puts( "1. Push" );
        puts( "2. Pop" );
        puts( "3. Print Stack" );
        printf( "4. Exit\n\n!_" );
        scanf("%d", &option);
        switch ( option )
        {
        case 1:
            printf("Push value: !_");
            scanf( "%d", &value );
            if ( !push(value) ){
                printf("%d has been pushed to stack index %d successfully!!\n", value, top );
            }
            break;
        
        case 2:
            value = stack [top];
            if ( !pop() ){
                printf("%d has been popped from stack index %d successfully!!\n", value, top + 1 );
            }
            break;

        case 3:
            printf("\tIndex\tValue\n");
            for( int i = 0; i <= top; i++ ){
                printf("\t%d\t%d\n", i, stack[i]);
            }
            break;

        case 4:
            end--;
            break;

        default:
            break;
        }
    }
    return 0;
}  //end main function

int push( int value ){
    if ( top == SIZE - 1 ){
        printf("Stack Overflow!!!\a\n");
        return 1;
    }else {
        stack[ top + 1 ] = value ;
        top++;
    }
    return 0;
}

int pop(){
    if ( top > -1 ){
        stack[ top ] = 0;
        top--;
    }
    else{
        printf("Stack is Empty!!!\a\n");
        return 1;
    }
    return 0;
}
