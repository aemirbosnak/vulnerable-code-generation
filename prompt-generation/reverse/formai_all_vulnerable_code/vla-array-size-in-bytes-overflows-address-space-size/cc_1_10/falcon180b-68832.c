//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numDice, sides;
    char rollAgain;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("How many sides should each die have? ");
    scanf("%d", &sides);

    int dice[numDice];
    for (int i = 0; i < numDice; i++) {
        dice[i] = rand() % sides + 1;
    }

    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");

    printf("Would you like to roll again? (y/n) ");
    scanf(" %c", &rollAgain);

    while (rollAgain == 'y' || rollAgain == 'Y') {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides should each die have? ");
        scanf("%d", &sides);

        for (int i = 0; i < numDice; i++) {
            dice[i] = rand() % sides + 1;
        }

        printf("You rolled: ");
        for (int i = 0; i < numDice; i++) {
            printf("%d ", dice[i]);
        }
        printf("\n");

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &rollAgain);
    }

    return 0;
}