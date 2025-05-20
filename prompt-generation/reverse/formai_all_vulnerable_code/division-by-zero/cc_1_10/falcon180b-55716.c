//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

// Struct to hold dice info
typedef struct {
    int num_sides;
    char *name;
} dice_t;

// Function to roll a single die
int roll_die(dice_t die) {
    return rand() % die.num_sides + 1;
}

// Function to roll multiple dice and return the sum
int roll_dice(dice_t *dice, int num_dice) {
    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        sum += roll_die(dice[i]);
    }
    return sum;
}

// Function to print a single die roll
void print_die_roll(dice_t die, int roll) {
    printf("%s: %d\n", die.name, roll);
}

// Function to print multiple die rolls
void print_dice_rolls(dice_t *dice, int num_dice, int *rolls) {
    for (int i = 0; i < num_dice; i++) {
        printf("%s: %d\n", dice[i].name, rolls[i]);
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Define dice
    dice_t d6 = {6, "d6"};
    dice_t d8 = {8, "d8"};
    dice_t d10 = {10, "d10"};
    dice_t d12 = {12, "d12"};
    dice_t d20 = {20, "d20"};

    // Roll dice
    int rolls[MAX_DICE];
    for (int i = 0; i < MAX_DICE; i++) {
        rolls[i] = roll_dice(&d6, 1);
        printf("Roll %d: ", i+1);
        print_die_roll(d6, rolls[i]);
    }

    // Roll multiple dice
    rolls[0] = roll_dice(&d6, 2);
    rolls[1] = roll_dice(&d8, 3);
    rolls[2] = roll_dice(&d10, 1);
    rolls[3] = roll_dice(&d12, 2);
    rolls[4] = roll_dice(&d20, 1);
    printf("\nMultiple rolls:\n");
    print_dice_rolls(&d6, 2, rolls);
    print_dice_rolls(&d8, 3, rolls+2);
    print_dice_rolls(&d10, 1, rolls+5);
    print_dice_rolls(&d12, 2, rolls+6);
    print_dice_rolls(&d20, 1, rolls+8);

    return 0;
}