#include <stdio.h>

// Function main begins program execution
int main(void) {
    int floor, OccupySuites;
    int totalSuitesOccupied = 0;
    int count = 0;
    int TOTAL_SUITES = 120; // Total number of suites in the hotel
    float OccupancyRate;

    // Loop through floors 10 to 16 (excluding floor 13)
    for (floor = 10; floor <= 16; floor++) {
        // Skip floor 13
        if ( floor == 13 ) {
            continue; 
        } else {
            // Input validation loop
            count = 0;
            do {
                if (count > 0) {
                    puts("Input is not in the range 0 to 20!!"); // Error message
                }
                printf("Input the number of suites occupied on the %dth floor\n!_", floor); // Input prompt
                scanf("%d", &OccupySuites);  // Read the number of occupied suites
                count++;
            } while (OccupySuites < 0 || OccupySuites > 20); // Check if input is valid

            totalSuitesOccupied += OccupySuites; // Add occupied suites to the total
        }
    }

    // Calculate occupancy rate
    OccupancyRate = ((float)totalSuitesOccupied / (float)TOTAL_SUITES) * 100;

    // Output results
    printf("\nThe hotel has %d suites!\n", TOTAL_SUITES);
    printf("%d of the suites are occupied!\n", totalSuitesOccupied);
    printf("Which is %.2f%% of the total number of suites!!\n", OccupancyRate);

    return 0; // Indicate program ended successfully
} // End main function