//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_ROLLS 10000

typedef struct {
    int num_sides;
    int num_rolls;
    int *rolls;
} Dice;

void init_dice(Dice *dice, int num_sides, int num_rolls) {
    dice->num_sides = num_sides;
    dice->num_rolls = num_rolls;
    dice->rolls = (int *) malloc(num_rolls * sizeof(int));
}

void roll_dice(Dice *dice) {
    for (int i = 0; i < dice->num_rolls; i++) {
        dice->rolls[i] = rand() % dice->num_sides + 1;
    }
}

void print_rolls(Dice *dice) {
    for (int i = 0; i < dice->num_rolls; i++) {
        printf("%d ", dice->rolls[i]);
    }
    printf("\n");
}

int main() {
    int num_dice, num_sides, num_rolls;
    int **dice_rolls;
    int max_rolls = 0;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    dice_rolls = (int **) malloc(num_dice * sizeof(int *));

    for (int i = 0; i < num_dice; i++) {
        printf("Enter the number of sides and rolls for dice %d: ", i+1);
        scanf("%d %d", &num_sides, &num_rolls);

        dice_rolls[i] = (int *) malloc(num_rolls * sizeof(int));
        init_dice(&dice_rolls[i][0], num_sides, num_rolls);
        roll_dice(&dice_rolls[i][0]);

        if (num_rolls > max_rolls) {
            max_rolls = num_rolls;
        }
    }

    printf("Rolling %d dice with %d sides each:\n", num_dice, max_rolls);

    for (int i = 0; i < num_dice; i++) {
        print_rolls(&dice_rolls[i][0]);
    }

    for (int i = 0; i < num_dice; i++) {
        free(dice_rolls[i]);
    }
    free(dice_rolls);

    return 0;
}