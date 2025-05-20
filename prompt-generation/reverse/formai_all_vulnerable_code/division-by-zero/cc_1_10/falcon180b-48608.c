//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, sides, roll_count, max_rolls;
    int dice_rolls[100];
    char play_again;

    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides do the dice have? ");
    scanf("%d", &sides);

    printf("Rolling %d %d-sided dice...\n", num_dice, sides);
    for (int i = 0; i < num_dice; i++) {
        dice_rolls[i] = rand() % sides + 1; // Roll the dice and store the result in an array
    }

    printf("Your rolls:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice_rolls[i]);
    }
    printf("\n");

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &play_again);

    while (play_again == 'y' || play_again == 'Y') {
        num_dice = 0;
        sides = 0;

        printf("How many dice do you want to roll? ");
        scanf("%d", &num_dice);
        printf("How many sides do the dice have? ");
        scanf("%d", &sides);

        printf("Rolling %d %d-sided dice...\n", num_dice, sides);
        for (int i = 0; i < num_dice; i++) {
            dice_rolls[i] = rand() % sides + 1;
        }

        printf("Your rolls:\n");
        for (int i = 0; i < num_dice; i++) {
            printf("%d ", dice_rolls[i]);
        }
        printf("\n");

        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &play_again);
    }

    return 0;
}