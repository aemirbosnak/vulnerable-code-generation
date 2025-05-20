//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for rand() and srand()

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int numDice, sidesPerDie, totalSides, roll, i, j;
    char rollAgain;

    // prompt user for number of dice and number of sides per die
    printf("Welcome to the Immersive Dice Roller!\n");
    printf("Please enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Please enter the number of sides per die: ");
    scanf("%d", &sidesPerDie);

    // calculate total number of sides
    totalSides = numDice * sidesPerDie;

    // roll the dice
    int diceValues[numDice];
    for (i = 0; i < numDice; i++) {
        diceValues[i] = rand() % sidesPerDie + 1;
    }

    // display the results
    printf("\nYou rolled %d dice with %d sides each:\n", numDice, sidesPerDie);
    for (i = 0; i < numDice; i++) {
        printf("Die %d rolled a %d\n", i+1, diceValues[i]);
    }

    // ask user if they want to roll again
    printf("\nDo you want to roll again? (y/n): ");
    scanf(" %c", &rollAgain);

    while (rollAgain == 'y' || rollAgain == 'Y') {
        // reset variables
        numDice = 0;
        sidesPerDie = 0;
        totalSides = 0;
        roll = 0;

        // prompt user for new number of dice and sides per die
        printf("\nRolling again...\n");
        printf("Please enter the number of dice: ");
        scanf("%d", &numDice);
        printf("Please enter the number of sides per die: ");
        scanf("%d", &sidesPerDie);

        // calculate total number of sides
        totalSides = numDice * sidesPerDie;

        // roll the dice
        for (i = 0; i < numDice; i++) {
            diceValues[i] = rand() % sidesPerDie + 1;
        }

        // display the results
        printf("\nYou rolled %d dice with %d sides each:\n", numDice, sidesPerDie);
        for (i = 0; i < numDice; i++) {
            printf("Die %d rolled a %d\n", i+1, diceValues[i]);
        }

        // ask user if they want to roll again
        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &rollAgain);
    }

    return 0;
}