//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 4
#define SIDES_PER_DICE 6
#define MAX_ROLLS 10

typedef struct {
    int rolls[NUM_DICE];
    int total;
} RollResult;

void roll_dice(RollResult *result) {
    int i;
    for (i = 0; i < NUM_DICE; ++i) {
        result->rolls[i] = rand() % SIDES_PER_DICE + 1;
    }
    result->total = 0;
    for (i = 0; i < NUM_DICE; ++i) {
        result->total += result->rolls[i];
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    RollResult roll_result;
    int i, rolls_to_take;

    if (argc > 1) {
        rolls_to_take = atoi(argv[1]);
        if (rolls_to_take > MAX_ROLLS) {
            printf("Error: Cannot roll more than %d dice at once.\n", MAX_ROLLS);
            return 1;
        }
    } else {
        rolls_to_take = 1;
    }

    printf("Rolling the dice %d times in a dimly lit, neon-lit cyberpunk alleyway...\n", rolls_to_take);
    for (i = 0; i < rolls_to_take; ++i) {
        roll_dice(&roll_result);
        printf("Roll %d: ", i + 1);
        int j;
        for (j = 0; j < NUM_DICE; ++j) {
            printf("%d ", roll_result.rolls[j]);
        }
        printf("Total: %d\n", roll_result.total);
    }

    return 0;
}