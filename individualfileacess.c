#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function main begins program execution
int main(void) {
    FILE *filePtr;

    // Open file for writing
    filePtr = fopen("students.txt", "w");
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int ID;
    float grade;
    char name[100];
    int count = 0;

    // Initial records
    while (1) {
        printf("Enter Student ID (-1 to stop): ");
        scanf("%d", &ID);
        if (ID == -1) break;

        // Clear the input buffer
        getchar(); // To consume the newline left by scanf

        printf("Enter Student Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character from the input

        printf("Enter Grade: ");
        scanf("%f", &grade);

        count++;
        fprintf(filePtr, "%d\t%s\t%.1f\n", ID, name, grade);
    }

    fclose(filePtr);

    // Reading and displaying file contents
    filePtr = fopen("students.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nContents of the file:\n");
    printf("ID\tName\t\tGrade\n");
    char line[200];
    while (fgets(line, sizeof(line), filePtr)) {
        printf("%s", line); // Print each line from the file
    }

    fclose(filePtr);

    // Append new records
    filePtr = fopen("students.txt", "a");
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nAppend New Records:\n");
    while (1) {
        printf("Enter Student ID (-1 to stop): ");
        scanf("%d", &ID);
        if (ID == -1) break;

        // Clear the input buffer
        getchar(); // To consume the newline left by scanf

        printf("Enter Student Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character from the input

        printf("Enter Grade: ");
        scanf("%f", &grade);

        count++;
        fprintf(filePtr, "%d\t%s\t%.1f\n", ID, name, grade);
    }

    fclose(filePtr);

    // Reopen file to read and display updated contents
    filePtr = fopen("students.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nUpdated File Contents:\n");
    printf("ID\tName\t\tGrade\n");

    int totalStudents = 0;
    float totalGrades = 0.0, topGrade = 0.0;
    char topStudent[100] = "";
    while (fgets(line, sizeof(line), filePtr)) {
        int tempID;
        char tempName[100];
        float tempGrade;

        sscanf(line, "%d\t%[^\t]\t%f", &tempID, tempName, &tempGrade);

        totalStudents++;
        totalGrades += tempGrade;

        if (tempGrade > topGrade) {
            topGrade = tempGrade;
            strcpy(topStudent, tempName);
        }

        printf("%s", line); // Print each line
    }

    fclose(filePtr);

    // Display statistics
    printf("\nTotal Students: %d\n", totalStudents);
    printf("Average Grade: %.2f\n", totalGrades / totalStudents);
    printf("Top Student: %s with Grade %.1f\n", topStudent, topGrade);

    return 0;
}
