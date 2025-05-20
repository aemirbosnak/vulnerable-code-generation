//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

int main() {
    int numDice, numRolls;
    int *dice;
    int i, j;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    dice = (int *) malloc(numDice * sizeof(int));

    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % 6 + 1;
    }

    printf("You rolled: ");
    for (i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &j);

    while (j == 'y' || j == 'Y') {
        printf("Enter the number of rolls: ");
        scanf("%d", &numRolls);

        for (i = 0; i < numRolls; i++) {
            for (int k = 0; k < numDice; k++) {
                dice[k] = rand() % 6 + 1;
            }

            printf("Roll %d: ", i + 1);
            for (int k = 0; k < numDice; k++) {
                printf("%d ", dice[k]);
            }
            printf("\n");
        }

        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &j);
    }

    free(dice);

    return 0;
}