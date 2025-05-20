//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6
#define NUM_DICE 3

typedef struct {
    int sides;
    int *roll;
} Die;

void create_die(Die *d) {
    d->sides = NUM_SIDES;
    d->roll = calloc(NUM_DICE, sizeof(int));
}

void roll_dice(Die *d) {
    int i;
    for (i = 0; i < NUM_DICE; i++) {
        d->roll[i] = rand() % d->sides + 1;
    }
}

void print_roll(Die d) {
    int i;
    printf("\nA brave knight doth cast %d dice, each with %d sides,\n", NUM_DICE, NUM_SIDES);
    printf("and prayeth unto the gods for a favourable outcome.\n");
    printf("The rolls of this noble knight be:\n");
    for (i = 0; i < NUM_DICE; i++) {
        printf("Die %d rolled a %d.\n", i + 1, d.roll[i]);
    }
}

int main() {
    Die knight_dice[NUM_DICE];

    srand(time(NULL));

    int i;
    for (i = 0; i < NUM_DICE; i++) {
        create_die(&knight_dice[i]);
    }

    for (i = 0; i < 3; i++) {
        roll_dice(&knight_dice[i]);
    }

    for (i = 0; i < NUM_DICE; i++) {
        print_roll(knight_dice[i]);
    }

    for (i = 0; i < NUM_DICE; i++) {
        free(knight_dice[i].roll);
    }

    return 0;
}