//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_sides;
    int num_dice;
    int *results;
} dice_roll_t;

void roll_dice(dice_roll_t *roll) {
    srand(time(NULL));
    roll->results = (int *)malloc(roll->num_dice * sizeof(int));
    for (int i = 0; i < roll->num_dice; ++i) {
        roll->results[i] = rand() % roll->num_sides + 1;
    }
}

void print_roll(dice_roll_t *roll) {
    printf("Rolling %d %dd%d:\n", roll->num_dice, roll->num_sides, roll->num_sides);
    for (int i = 0; i < roll->num_dice; ++i) {
        printf("%d ", roll->results[i]);
    }
    printf("\n");
}

void free_roll(dice_roll_t *roll) {
    free(roll->results);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <num_dice> <num_sides> <num_rolls>\n", argv[0]);
        return 1;
    }

    int num_dice = atoi(argv[1]);
    int num_sides = atoi(argv[2]);
    int num_rolls = atoi(argv[3]);

    if (num_dice <= 0 || num_sides <= 0 || num_rolls <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    dice_roll_t roll;
    roll.num_sides = num_sides;
    roll.num_dice = num_dice;
    roll.results = (int *)malloc(num_dice * sizeof(int));

    for (int i = 0; i < num_rolls; ++i) {
        roll_dice(&roll);
        print_roll(&roll);
    }

    free_roll(&roll);

    return 0;
}