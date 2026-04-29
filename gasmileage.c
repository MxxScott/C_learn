#include <stdio.h>

int main ( void ){
    // Declare variables to store:
    int inst;         // Number of gas tanks
    int milestemp;    // Miles driven for the current tank (temporary)
    int gallonstemp;   // Gallons used for the current tank (temporary)
    int miles = 0;    // Total miles driven (initialized to 0)
    int gallons = 0;   // Total gallons used (initialized to 0)
    int count = 0;     // Tank counter
    float avgmls, avggal, avgmpg; // Variables for calculated averages

    // Prompt user for the number of gas tanks
    printf("Enter Number of Tanks:\n!_");
    scanf("%d", &inst);

    // Loop through each tank to gather miles and gallons data
    for ( int i = inst; i >= 1; i-- ){
        count++; 
        printf("Tank %d\n", count );

        // Get miles driven for the current tank
        printf("Input Miles Driven for Tank %d:\n!_", count );
        scanf("%d", &milestemp);
        miles += milestemp; // Add miles for the current tank to the total

        // Get gallons used for the current tank
        printf("Input Gallons used for Tank %d:\n!_", count );
        scanf("%d", &gallonstemp);
        gallons += gallonstemp; // Add gallons for the current tank to the total
    }

    // Calculate averages
    avgmls = (float)miles / inst;       // Average miles per tank
    avggal = (float)gallons / inst;     // Average gallons per tank
    avgmpg = avgmls / avggal;           // Average miles per gallon

    // Display the final result
    printf("The average miles per gallon for all the tanks combined is %.2f\n", avgmpg);
}