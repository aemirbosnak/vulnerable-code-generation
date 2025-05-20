//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    char *dice_str;
} dice_t;

void roll_dice(dice_t *dice) {
    int i, j, sum = 0;
    for (i = 0; i < dice->num_dice; i++) {
        sum += rand() % dice->num_sides + 1;
    }
    printf("You rolled %d on %d %s-sided dice.\n", sum, dice->num_dice, dice->dice_str);
}

int main() {
    dice_t dice;
    int choice, num_dice, num_sides;
    char *dice_str;

    // Roll a single die
    printf("Welcome to the Retro Dice Roller!\n");
    printf("How many sides does your die have? ");
    scanf("%d", &num_sides);
    dice.num_dice = 1;
    dice.num_sides = num_sides;
    dice.dice_str = "die";
    roll_dice(&dice);

    // Roll multiple dice
    printf("\nHow many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides do the dice have? ");
    scanf("%d", &num_sides);
    dice.num_dice = num_dice;
    dice.num_sides = num_sides;
    dice.dice_str = "dice";
    roll_dice(&dice);

    // Choose from different types of dice
    printf("\nChoose a type of dice:\n");
    printf("1. d4\n2. d6\n3. d8\n4. d10\n5. d12\n6. d20\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            num_sides = 4;
            dice.dice_str = "d4";
            break;
        case 2:
            num_sides = 6;
            dice.dice_str = "d6";
            break;
        case 3:
            num_sides = 8;
            dice.dice_str = "d8";
            break;
        case 4:
            num_sides = 10;
            dice.dice_str = "d10";
            break;
        case 5:
            num_sides = 12;
            dice.dice_str = "d12";
            break;
        case 6:
            num_sides = 20;
            dice.dice_str = "d20";
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    roll_dice(&dice);

    return 0;
}