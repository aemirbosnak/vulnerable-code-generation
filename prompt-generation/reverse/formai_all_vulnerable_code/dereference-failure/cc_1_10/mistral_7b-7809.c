//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 3
#define NUM_SIDES 6

typedef struct {
    int sides;
    int *roll;
} DiceSet;

void generate_dice_roll(DiceSet *dice) {
    int i;
    for (i = 0; i < dice->sides; i++) {
        dice->roll[i] = rand() % (dice->sides + 1);
    }
}

void print_dice_roll(DiceSet *dice) {
    int i;
    printf("Dice roll result:\n");
    for (i = 0; i < dice->sides; i++) {
        printf("Die %d: %d\n", i + 1, dice->roll[i]);
    }
}

int main(void) {
    DiceSet holmes_dice, watson_dice;
    srand(time(NULL));

    holmes_dice.sides = NUM_SIDES;
    holmes_dice.roll = malloc(NUM_SIDES * sizeof(int));

    watson_dice.sides = NUM_SIDES;
    watson_dice.roll = malloc(NUM_SIDES * sizeof(int));

    generate_dice_roll(&holmes_dice);
    generate_dice_roll(&watson_dice);

    printf("Sherlock Holmes roll:\n");
    print_dice_roll(&holmes_dice);

    printf("Dr. Watson roll:\n");
    print_dice_roll(&watson_dice);

    int sum_holmes = 0, sum_watson = 0;
    for (int i = 0; i < NUM_SIDES; i++) {
        sum_holmes += holmes_dice.roll[i];
        sum_watson += watson_dice.roll[i];
    }

    printf("Total points for Sherlock Holmes: %d\n", sum_holmes);
    printf("Total points for Dr. Watson: %d\n", sum_watson);

    if (sum_holmes > sum_watson) {
        printf("Sherlock Holmes wins this round!\n");
    } else if (sum_holmes < sum_watson) {
        printf("Dr. Watson wins this round!\n");
    } else {
        printf("It's a tie!\n");
    }

    free(holmes_dice.roll);
    free(watson_dice.roll);

    return 0;
}