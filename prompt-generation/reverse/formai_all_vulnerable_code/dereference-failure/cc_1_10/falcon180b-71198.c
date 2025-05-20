//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j;
    int *dice;
    int sum = 0;
    int maxRoll = 0;
    int minRoll = 999;
    int totalRolls = 0;
    float avgRoll = 0;
    srand(time(NULL));

    // Get number of dice and sides from user
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    // Allocate memory for dice array
    dice = (int *) malloc(numDice * sizeof(int));

    // Roll the dice and calculate the sum
    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % numSides + 1;
        sum += dice[i];
        if (dice[i] > maxRoll) {
            maxRoll = dice[i];
        }
        if (dice[i] < minRoll) {
            minRoll = dice[i];
        }
    }

    // Print the results
    printf("Rolled %d dice with %d sides each:\n", numDice, numSides);
    for (i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
    printf("Total: %d\n", sum);
    printf("Max roll: %d\n", maxRoll);
    printf("Min roll: %d\n", minRoll);

    // Calculate and print average roll
    avgRoll = (float) sum / numDice;
    printf("Average roll: %.2f\n", avgRoll);

    // Free memory
    free(dice);

    return 0;
}