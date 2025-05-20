//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
    int num_dice, num_sides, max_num_sides = 1000;
    int *dice_rolls, total_rolls = 0, i;
    bool valid_input = false;
    char input_buffer[100];
    srand(time(NULL));

    while (!valid_input) {
        printf("Enter the number of dice (1-10): ");
        fgets(input_buffer, 100, stdin);
        num_dice = atoi(input_buffer);

        if (num_dice < 1 || num_dice > 10) {
            printf("Invalid input. Please enter a number between 1 and 10.\n");
        } else {
            valid_input = true;
        }
    }

    while (!valid_input) {
        printf("Enter the number of sides on each die (1-1000): ");
        fgets(input_buffer, 100, stdin);
        num_sides = atoi(input_buffer);

        if (num_sides < 1 || num_sides > max_num_sides) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", max_num_sides);
        } else {
            valid_input = true;
        }
    }

    dice_rolls = (int *)malloc(num_dice * sizeof(int));

    for (i = 0; i < num_dice; i++) {
        dice_rolls[i] = rand() % num_sides + 1;
        total_rolls += dice_rolls[i];
    }

    printf("You rolled %d dice with %d sides each:\n", num_dice, num_sides);

    for (i = 0; i < num_dice; i++) {
        printf("%d ", dice_rolls[i]);
    }

    printf("\nTotal roll: %d\n", total_rolls);

    free(dice_rolls);

    return 0;
}