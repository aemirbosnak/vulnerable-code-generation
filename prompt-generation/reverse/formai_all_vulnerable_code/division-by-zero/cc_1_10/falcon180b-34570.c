//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 3
#define NUM_SIDES 6

int roll_dice(int num_dice, int num_sides) {
    int rolls[num_dice];
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = rand() % num_sides + 1;
    }
    return rolls[0];
}

int main() {
    srand(time(NULL));
    int num_dice = NUM_DICE;
    int num_sides = NUM_SIDES;
    int num_rolls = 0;
    int total_rolls = 0;
    int max_rolls = 0;
    int min_rolls = 9999;
    int sum_rolls = 0;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? (1-%d)\n", num_dice);
    scanf("%d", &num_dice);

    printf("How many sides do you want on each die? (2-%d)\n", num_sides);
    scanf("%d", &num_sides);

    printf("How many times do you want to roll the dice? (1-%d)\n", num_dice * num_sides);
    scanf("%d", &num_rolls);

    for (int i = 0; i < num_rolls; i++) {
        int roll = roll_dice(num_dice, num_sides);
        total_rolls += roll;
        if (roll > max_rolls) {
            max_rolls = roll;
        }
        if (roll < min_rolls) {
            min_rolls = roll;
        }
        sum_rolls += roll;
    }

    printf("You rolled the dice %d times.\n", num_rolls);
    printf("The total of all rolls is: %d\n", total_rolls);
    printf("The highest roll was: %d\n", max_rolls);
    printf("The lowest roll was: %d\n", min_rolls);
    printf("The average roll was: %.2f\n", (float)sum_rolls / num_rolls);

    return 0;
}