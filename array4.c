#include <stdio.h>

//function main begins program execution
int main(void) {
    int frequency[11] = {0}; // Initialize all elements to 0

    int score, result;

    for (int i = 1; i <= 40; i++) {
        do {
            printf("Enter rating %d (1 to 10): ", i);
            result = scanf("%d", &score); // Check scanf's return value

            // Input validation: Check both range and scanf success
            if (result != 1 || score < 1 || score > 10) {
                puts("Invalid Entry! Please enter a number between 1 and 10.");
                // Clear the input buffer to prevent an infinite loop on bad input
                while (getchar() != '\n');  
                continue; // Go to the next iteration of the do-while loop
            }

            frequency[score]++; // Increment the appropriate frequency counter
            break; // Exit the do-while loop if input is valid

        } while (1); // Loop continues until a valid input is received
    }

    puts("Rating\tFrequency");
    for (int j = 1; j <= 10; j++) { // Loop through all possible ratings (1-10)
        printf("%d\t%d\n", j, frequency[j]);
    }
    return 0; //indicate program ended succesfully
} //end main function