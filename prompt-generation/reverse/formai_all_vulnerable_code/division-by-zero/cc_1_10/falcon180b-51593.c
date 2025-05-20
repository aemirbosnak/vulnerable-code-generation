//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, roll, total = 0;
    char playAgain;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of dice and sides from the user
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do each of the dice have? ");
    scanf("%d", &numSides);

    // Roll the dice and calculate the total
    for (int i = 0; i < numDice; i++) {
        roll = rand() % numSides + 1; // rand() generates a random number between 0 and RAND_MAX, so we add 1 to get a number between 1 and numSides
        printf("You rolled a %d on dice %d.\n", roll, i+1); // We add 1 to i because arrays are zero-indexed
        total += roll; // Add the roll to the total
    }

    // Print the total
    printf("Your total is: %d\n", total);

    // Ask the user if they want to play again
    printf("Do you want to roll the dice again? (y/n) ");
    scanf(" %c", &playAgain);

    // Loop until the user decides to quit
    while (playAgain == 'y' || playAgain == 'Y') {
        // Reset the total
        total = 0;

        // Roll the dice and calculate the total
        for (int i = 0; i < numDice; i++) {
            roll = rand() % numSides + 1;
            printf("You rolled a %d on dice %d.\n", roll, i+1);
            total += roll;
        }

        // Print the total
        printf("Your total is: %d\n", total);

        // Ask the user if they want to play again
        printf("Do you want to roll the dice again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    return 0;
}