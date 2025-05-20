//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIDE 4
#define MAX_SIDE 6
#define NUM_DICE 3

typedef struct {
    int sides;
    int *faces;
} Die;

void initialize_die(Die *dice, int num_dice, int sides) {
    int i;

    if (num_dice > 0 && sides > MIN_SIDE && sides <= MAX_SIDE) {
        dice->sides = sides;
        dice->faces = (int *) calloc(sides, sizeof(int));

        for (i = 0; i < sides; i++) {
            dice->faces[i] = i + 1;
        }
    } else {
        printf("Invalid parameters for Die initialization.\n");
        exit(EXIT_FAILURE);
    }
}

void roll_die(Die *dice, int *roll) {
    int roll_value;

    if (dice != NULL) {
        roll_value = rand() % (dice->sides + 1);
        *roll = dice->faces[roll_value];
    } else {
        printf("Invalid Die parameter for Rolling.\n");
        exit(EXIT_FAILURE);
    }
}

void roll_dice(Die *dice, int num_rolls, int *rolls) {
    int i, roll;

    if (num_rolls > 0) {
        for (i = 0; i < num_rolls; i++) {
            roll_die(dice, &rolls[i]);
            printf("Roll #%d: %d\n", i + 1, rolls[i]);
        }
    } else {
        printf("Invalid number of Rolls.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    srand(time(NULL));

    Die my_dice;
    int rolls[NUM_DICE];

    initialize_die(&my_dice, NUM_DICE, 6);
    roll_dice(&my_dice, 10, rolls);

    free(my_dice.faces);
    return 0;
}