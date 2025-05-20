//FormAI DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
/* 
 * Name: Claude Shannon Style Dice Roller
 * Description: A sophisticated program that allows users to roll virtual dice and display the results
 * Author: Your Name Here
 * Date: Today
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice;
    int numSides;
    int i, j, k;

    srand(time(NULL));

    printf("Welcome to the Claude Shannon Style Dice Roller program!\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);
    printf("How many sides does each die have?\n");
    scanf("%d", &numSides);

    int rolls[numDice][numSides];

    // Roll the dice and store the results
    printf("\nRolling the dice...\n");
    for (i = 0; i < numDice; i++) {
        for (j = 0; j < numSides; j++) {
            rolls[i][j] = rand() % numSides + 1;
        }
    }

    // Display the results of the rolls
    printf("\nHere are the results of your rolls:\n\n");
    for (i = 0; i < numDice; i++) {
        printf("Dice %d: ", i+1);
        for (j = 0; j < numSides; j++) {
            printf("%d", rolls[i][j]);
            if (j != numSides-1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    // Calculate and display the total for each die
    printf("\nHere are the totals for each of your dice:\n\n");
    for (i = 0; i < numDice; i++) {
        int total = 0;
        for (j = 0; j < numSides; j++) {
            total += rolls[i][j];
        }
        printf("Total for Dice %d: %d\n", i+1, total);
    }

    printf("\nThank you for using this Claude Shannon Style Dice Roller program! Goodbye!\n");

    return 0;
}