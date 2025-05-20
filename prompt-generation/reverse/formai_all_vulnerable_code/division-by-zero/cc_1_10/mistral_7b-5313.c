//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 6
#define MAX_ROLLS 100

int main() {
    int num_dice, num_sides, num_rolls, dice_roll, total = 0;

    printf("Welcome to the Multivariable Dice Roller!\n");
    printf("Enter the number of dice (up to %d): ", MAX_DICE);
    scanf("%d", &num_dice);

    if (num_dice > MAX_DICE) {
        printf("Error: Too many dice.\n");
        return 1;
    }

    printf("Enter the number of sides on each die (up to %d): ", MAX_SIDES);
    scanf("%d", &num_sides);

    if (num_sides > MAX_SIDES) {
        printf("Error: Too many sides.\n");
        return 1;
    }

    printf("Enter the number of rolls (up to %d): ", MAX_ROLLS);
    scanf("%d", &num_rolls);

    if (num_rolls > MAX_ROLLS) {
        printf("Error: Too many rolls.\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < num_rolls; i++) {
        for (int j = 0; j < num_dice; j++) {
            dice_roll = rand() % num_sides + 1;
            total += dice_roll;
            printf("Dice %d roll: %d\n", j + 1, dice_roll);
        }
        printf("\n");
    }

    printf("Total: %d\n", total);

    return 0;
}