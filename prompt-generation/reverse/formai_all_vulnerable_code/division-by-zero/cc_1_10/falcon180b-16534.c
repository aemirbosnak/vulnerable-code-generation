//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice;
    int numSides;
    int numRolls;
    int *dice;
    int i, j, k;
    int max, min, sum, count;
    float avg;
    char playAgain;

    // Initialize random seed
    srand(time(NULL));

    // Prompt user for number of dice, sides per dice, and number of rolls
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls);

    // Allocate memory for dice array
    dice = (int *) malloc(numDice * sizeof(int));

    // Roll the dice
    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            dice[j] = rand() % numSides + 1;
            printf("Roll %d: %d\n", i+1, dice[j]);
        }
        printf("\n");
    }

    // Calculate statistics
    max = dice[0];
    min = dice[0];
    sum = 0;
    count = 0;
    for (i = 0; i < numDice; i++) {
        if (dice[i] > max) {
            max = dice[i];
        }
        if (dice[i] < min) {
            min = dice[i];
        }
        sum += dice[i];
        count++;
    }
    avg = (float) sum / count;

    // Print statistics
    printf("\nStatistics:\n");
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Average: %.2f\n", avg);

    // Ask user if they want to play again
    printf("\nDo you want to play again? (y/n) ");
    scanf(" %c", &playAgain);

    // Free memory and exit program
    free(dice);
    return 0;
}