//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, roll;
    int *diceArray = NULL;
    char playAgain;

    do {
        printf("Enter the number of dice: ");
        scanf("%d", &numDice);

        if (numDice <= 0) {
            printf("Invalid number of dice. Please try again.\n");
            continue;
        }

        printf("Enter the number of sides on each dice: ");
        scanf("%d", &numSides);

        if (numSides <= 0) {
            printf("Invalid number of sides. Please try again.\n");
            continue;
        }

        diceArray = (int *) malloc(numDice * sizeof(int));

        for (i = 0; i < numDice; i++) {
            diceArray[i] = rand() % numSides + 1;
        }

        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);

        for (i = 0; i < numDice; i++) {
            printf("Dice %d: %d\n", i+1, diceArray[i]);
        }

        printf("\nTotal: %d\n", total(diceArray, numDice));

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    free(diceArray);

    return 0;
}

int total(int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}