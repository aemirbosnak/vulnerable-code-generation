//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_dice;
    int num_sides;
    int roll_count;
    int total_rolls = 0;
    int total_sum = 0;
    int max_roll = 0;
    int min_roll = 999;
    int* rolls = NULL;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides should each die have? ");
    scanf("%d", &num_sides);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &roll_count);

    rolls = (int*) malloc(num_dice * sizeof(int));

    for (int i = 0; i < roll_count; i++) {
        for (int j = 0; j < num_dice; j++) {
            rolls[j] = rand() % num_sides + 1;
            total_rolls++;
            if (rolls[j] > max_roll) {
                max_roll = rolls[j];
            }
            if (rolls[j] < min_roll) {
                min_roll = rolls[j];
            }
            total_sum += rolls[j];
        }
        printf("\nRoll %d:\n", i + 1);
        for (int j = 0; j < num_dice; j++) {
            printf("%d ", rolls[j]);
        }
        printf("\nTotal rolls: %d\n", total_rolls);
        printf("Max roll: %d\n", max_roll);
        printf("Min roll: %d\n", min_roll);
        printf("Total sum: %d\n\n", total_sum);
        total_rolls = 0;
        total_sum = 0;
        max_roll = 0;
        min_roll = 999;
    }

    free(rolls);
    return 0;
}