//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_rolls, num_dice, num_sides, max_rolls = 100, i, j, roll, total = 0;
    char choice;
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    printf("How many rolls would you like to make? ");
    scanf("%d", &num_rolls);

    for (i = 1; i <= num_rolls; i++) {
        printf("\nRoll %d:\n", i);
        printf("How many dice would you like to roll? ");
        scanf("%d", &num_dice);

        if (num_dice > 100) {
            printf("Sorry, you can only roll up to 100 dice at a time.\n");
            num_dice = 100;
        }

        printf("How many sides would you like on each die? ");
        scanf("%d", &num_sides);

        if (num_sides > 1000) {
            printf("Sorry, each die can have up to 1000 sides.\n");
            num_sides = 1000;
        }

        total = 0;
        for (j = 1; j <= num_dice; j++) {
            roll = rand() % num_sides + 1;
            printf("Die %d rolled a %d.\n", j, roll);
            total += roll;
        }

        if (total > max_rolls) {
            printf("New high score! Total roll: %d\n", total);
            max_rolls = total;
        } else if (total == max_rolls) {
            printf("Tie for high score! Total roll: %d\n", total);
        }

        printf("\nPress any key to continue...\n");
        choice = getchar();
    }

    return 0;
}