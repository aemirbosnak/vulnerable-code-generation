//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define SIDES_PER_DICE 6
#define MIN_ROLL 1
#define MAX_ROLL NUM_DICE * SIDES_PER_DICE

typedef struct {
    int sides;
    int *rolls;
} Dice;

void init_dice(Dice *dice) {
    dice->sides = SIDES_PER_DICE;
    dice->rolls = (int *) malloc(NUM_DICE * sizeof(int));
}

void roll_dice(Dice *dice) {
    srand(time(NULL));
    for (int i = 0; i < NUM_DICE; i++) {
        dice->rolls[i] = rand() % (dice->sides + 1);
    }
}

void print_rolls(const Dice *dice) {
    printf("Rolls:\n");
    for (int i = 0; i < NUM_DICE; i++) {
        printf("Dice %d rolled a %d\n", i + 1, dice->rolls[i]);
    }
    printf("\nTotal: %d\n", sum_array(dice->rolls, NUM_DICE));
}

int sum_array(const int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    Dice dice;
    init_dice(&dice);
    roll_dice(&dice);
    print_rolls(&dice);
    free(dice.rolls);
    return 0;
}