//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100
#define MAX_ROLLS 1000000

typedef struct {
    int num_sides;
    int num_dice;
    int num_rolls;
    int *rolls;
} dice_t;

dice_t *dice_create(int num_sides, int num_dice, int num_rolls) {
    dice_t *dice = malloc(sizeof(dice_t));
    dice->num_sides = num_sides;
    dice->num_dice = num_dice;
    dice->num_rolls = num_rolls;
    dice->rolls = malloc(sizeof(int) * num_rolls);
    return dice;
}

void dice_roll(dice_t *dice) {
    srand(time(NULL));
    for (int i = 0; i < dice->num_rolls; i++) {
        int roll = rand() % dice->num_sides + 1;
        dice->rolls[i] = roll;
    }
}

void dice_print(dice_t *dice) {
    printf("Number of sides: %d\n", dice->num_sides);
    printf("Number of dice: %d\n", dice->num_dice);
    printf("Number of rolls: %d\n", dice->num_rolls);
    printf("Rolls:\n");
    for (int i = 0; i < dice->num_rolls; i++) {
        printf("%d ", dice->rolls[i]);
    }
    printf("\n");
}

void dice_destroy(dice_t *dice) {
    free(dice->rolls);
    free(dice);
}

int main() {
    dice_t *dice = dice_create(6, 3, 5);
    dice_roll(dice);
    dice_print(dice);
    dice_destroy(dice);

    return 0;
}