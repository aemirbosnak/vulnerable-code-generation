//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

typedef struct {
    int num_sides;
    int *values;
} die_t;

typedef struct {
    int num_dice;
    die_t *dice;
} roll_t;

void init_die(die_t *die, int num_sides) {
    die->num_sides = num_sides;
    die->values = malloc(num_sides * sizeof(int));
    for (int i = 0; i < num_sides; i++) {
        die->values[i] = i + 1;
    }
}

void init_roll(roll_t *roll, int num_dice, int num_sides) {
    roll->num_dice = num_dice;
    roll->dice = malloc(num_dice * sizeof(die_t));
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], num_sides);
    }
}

void roll_dice(roll_t *roll) {
    srand(time(NULL));
    for (int i = 0; i < roll->num_dice; i++) {
        int value = rand() % roll->dice[i].num_sides + 1;
        printf("Dice %d rolled a %d\n", i + 1, value);
    }
}

void free_roll(roll_t *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        free(roll->dice[i].values);
    }
    free(roll->dice);
}

int main() {
    roll_t roll;
    init_roll(&roll, 3, 6); // Initialize 3 six-sided dice
    roll_dice(&roll); // Roll the dice
    free_roll(&roll); // Free the memory used by the dice
    return 0;
}