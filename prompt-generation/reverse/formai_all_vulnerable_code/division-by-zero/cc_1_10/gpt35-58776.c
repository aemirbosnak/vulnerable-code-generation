//FormAI DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the random seed based on the current time
    srand(time(NULL));

    // Welcome message for the user
    printf("Welcome to the Statistical Dice Roller!\n");

    // Get the number of dice rolls from the user
    int numRolls = 0;
    printf("How many rolls would you like to simulate?\n");
    scanf("%d", &numRolls);

    // Get the number of dice sides from the user
    int numSides = 0;
    printf("How many sides does the dice have?\n");
    scanf("%d", &numSides);

    // Initialize an array to hold the roll results
    int results[1000] = {0};

    // Roll the dice the requested number of times and record the results
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % numSides + 1;
        results[roll]++;
    }

    // Print out the results of each roll
    printf("\nRoll Results:\n");
    for (int i = 1; i <= numSides; i++) {
        printf("%d: %d\n", i, results[i]);
    }

    // Calculate the mean and standard deviation of the roll results
    double sum = 0;
    for (int i = 1; i <= numSides; i++) {
        sum += i * results[i];
    }
    double mean = sum / numRolls;

    double variance = 0;
    for (int i = 1; i <= numSides; i++) {
        variance += (i - mean) * (i - mean) * results[i];
    }
    variance /= numRolls;
    double stdDev = sqrt(variance);

    // Print out the mean and standard deviation
    printf("\nMean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stdDev);

    return 0;
}