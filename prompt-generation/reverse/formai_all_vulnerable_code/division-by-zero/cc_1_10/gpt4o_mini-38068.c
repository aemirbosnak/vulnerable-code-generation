//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numDice, int numSides);
void displayResults(int *results, int numRolls);
void calculateStatistics(int *results, int numRolls);
void displaySeparator();

int main() {
    int numDice, numSides, rollAgain = 1;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    printf("Welcome to the Dice Roller Program!\n");

    while (rollAgain) {
        // Input number of dice and sides
        printf("Enter the number of dice to roll: ");
        scanf("%d", &numDice);
        printf("Enter the number of sides per die: ");
        scanf("%d", &numSides);

        // Roll the dice
        rollDice(numDice, numSides);

        // Ask user if they want to roll again
        printf("Would you like to roll again? (1 for yes, 0 for no): ");
        scanf("%d", &rollAgain);
        displaySeparator();
    }

    printf("Thank you for using the Dice Roller Program!\n");
    return 0;
}

void rollDice(int numDice, int numSides) {
    int *results = malloc(numDice * sizeof(int));
    int total = 0;
    
    if (results == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Rolling %d dice with %d sides...\n", numDice, numSides);

    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numSides) + 1; // Generate a random die roll
        total += results[i];
        printf("Die %d: %d\n", i + 1, results[i]);
    }

    // Display results and statistics
    printf("Total roll: %d\n", total);
    calculateStatistics(results, numDice);

    // Free allocated memory
    free(results);
}

void calculateStatistics(int *results, int numRolls) {
    float avg = 0.0;

    for (int i = 0; i < numRolls; i++) {
        avg += results[i];
    }
    avg /= numRolls;

    printf("Average roll: %.2f\n", avg);
}

void displaySeparator() {
    printf("\n--------------------------------------------------\n\n");
}