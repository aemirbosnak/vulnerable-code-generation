//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, maxRoll, i, j;
    int diceArray[100];
    char playAgain;

    printf("Welcome to the Dice Roller!\n\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("How many sides do the dice have? ");
    scanf("%d", &numSides);

    srand(time(NULL));

    for (i = 0; i < numDice; i++) {
        diceArray[i] = rand() % numSides + 1;
    }

    printf("\nYour dice rolls:\n");
    for (i = 0; i < numDice; i++) {
        printf("%d ", diceArray[i]);
    }

    printf("\nWould you like to roll again? (y/n) ");
    scanf(" %c", &playAgain);

    while (playAgain == 'y' || playAgain == 'Y') {
        printf("\n\nHow many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        srand(time(NULL));

        for (i = 0; i < numDice; i++) {
            diceArray[i] = rand() % numSides + 1;
        }

        printf("\nYour dice rolls:\n");
        for (i = 0; i < numDice; i++) {
            printf("%d ", diceArray[i]);
        }

        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    return 0;
}