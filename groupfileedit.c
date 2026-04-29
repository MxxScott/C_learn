#include <stdio.h>
#include <string.h>

int main( void ){
    FILE *filePtr;
    filePtr = fopen("data.txt", "w");
    if( filePtr == NULL ){
        printf( "Error opening file.\n" );
        return 1;
    }
    char input[100];
    printf( "Enter text(type 'exit' to stop):\n" );
    while(1){
        fgets( input, sizeof(input), stdin);
        if (strcmp(input, "exit\n")==0) break;
        fprintf(filePtr, "%s", input);
    }
    fclose(filePtr);
    
    filePtr = fopen("data.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    printf("\nContents of the file:\n");
    while (fgets(input, sizeof(input), filePtr) != NULL) {
        printf("%s", input);
    }
    fclose(filePtr);

    return 0;
}