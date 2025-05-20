//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_sides;
    int *sides;
    int num_dice;
    int *results;
} dice_t;

void init_dice(dice_t *dice, int num_dice, int num_sides) {
    dice->num_dice = num_dice;
    dice->num_sides = num_sides;
    dice->sides = malloc(num_sides * sizeof(int));
    dice->results = malloc(num_dice * sizeof(int));
    for (int i = 0; i < num_sides; i++) {
        dice->sides[i] = i + 1;
    }
}

void roll_dice(dice_t *dice) {
    for (int i = 0; i < dice->num_dice; i++) {
        dice->results[i] = rand() % dice->num_sides;
    }
}

void print_dice(dice_t *dice) {
    for (int i = 0; i < dice->num_dice; i++) {
        printf("%d", dice->results[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    dice_t dice;
    int num_dice, num_sides;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides for each dice: ");
    scanf("%d", &num_sides);

    init_dice(&dice, num_dice, num_sides);

    printf("Rolling the dice...\n");
    roll_dice(&dice);

    printf("The results are:\n");
    print_dice(&dice);

    return 0;
}