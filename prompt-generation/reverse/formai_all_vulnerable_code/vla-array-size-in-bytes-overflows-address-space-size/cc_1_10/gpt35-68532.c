//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, num_sides;

    printf("Welcome to the Mind-Bending Dice Roller program!\n");
    printf("Please enter the number of dice you want to roll: ");
    scanf("%d", &num_dice);
    printf("Please enter the number of sides each die should have: ");
    scanf("%d", &num_sides);

    printf("\nRolling %d %d-sided dice...\n\n", num_dice, num_sides);

    srand(time(NULL));

    int rolls[num_dice];
    int i, j, temp_sum;

    for (i = 0; i < num_dice; i++) {
        rolls[i] = rand() % num_sides + 1;
    }

    printf("Your rolls are: ");
    for (i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }

    // Bubble sort the rolls
    for (i = 0; i < num_dice - 1; i++) {
        for (j = 0; j < num_dice - 1 - i; j++) {
            if (rolls[j] > rolls[j+1]) {
                temp_sum = rolls[j];
                rolls[j] = rolls[j+1];
                rolls[j+1] = temp_sum;
            }
        }
    }

    // Calculate the sum of the rolls
    int sum = 0;
    for (i = 0; i < num_dice; i++) {
        sum += rolls[i];
    }

    printf("\n\nYour rolls, sorted in ascending order, are: ");
    for (i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }

    printf("\n\nThe sum of your rolls is: %d\n", sum);

    printf("\nThank you for using Mind-Bending Dice Roller!\n");

    return 0;
}