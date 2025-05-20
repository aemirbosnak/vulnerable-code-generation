//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice;
    int num_sides;
    int roll_count = 0;
    int total_rolls = 0;
    int highest_roll = 0;
    int lowest_roll = 999;
    int *dice_rolls = NULL;
    char repeat;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of dice from the user
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    // Get the number of sides on each die
    printf("How many sides on each die? ");
    scanf("%d", &num_sides);

    // Allocate memory for the dice rolls
    dice_rolls = (int *)malloc(num_dice * sizeof(int));

    // Roll the dice and display the results
    while (1) {
        printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
        for (int i = 0; i < num_dice; i++) {
            dice_rolls[i] = rand() % num_sides + 1;
            total_rolls += dice_rolls[i];
            if (dice_rolls[i] > highest_roll) {
                highest_roll = dice_rolls[i];
            }
            if (dice_rolls[i] < lowest_roll) {
                lowest_roll = dice_rolls[i];
            }
        }
        printf("Total rolls: %d\n", total_rolls);
        printf("Highest roll: %d\n", highest_roll);
        printf("Lowest roll: %d\n", lowest_roll);
        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &repeat);
        if (repeat!= 'y') {
            break;
        }
        roll_count++;
    }

    // Free the memory allocated for the dice rolls
    free(dice_rolls);

    return 0;
}