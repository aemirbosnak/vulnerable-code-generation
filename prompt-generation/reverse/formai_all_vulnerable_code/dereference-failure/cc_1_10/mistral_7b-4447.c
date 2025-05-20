//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6
#define NUM_DICE 3
#define MIN_ROLL 1
#define MAX_ROLL NUM_SIDES

typedef struct {
    int sides;
    int *num;
} DiceSet;

void roll(DiceSet *dice) {
    int i;
    for (i = 0; i < dice->sides; i++) {
        dice->num[0] = rand() % (dice->sides + 1);
    }
    for (i = 1; i < NUM_DICE; i++) {
        roll(dice);
        int j;
        for (j = 0; j < dice->sides; j++) {
            if (dice->num[i * dice->sides + j] < dice->num[i * dice->sides]) {
                int temp = dice->num[i * dice->sides + j];
                dice->num[i * dice->sides + j] = dice->num[i * dice->sides];
                dice->num[i * dice->sides] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    DiceSet dice;
    dice.sides = NUM_SIDES;
    dice.num = malloc(NUM_DICE * NUM_SIDES * sizeof(int));
    roll(&dice);
    for (int i = 0; i < NUM_DICE * NUM_SIDES; i++) {
        printf("%d ", dice.num[i]);
        if (i % NUM_SIDES == NUM_SIDES - 1) {
            printf("\n");
            if (i < NUM_DICE * NUM_SIDES - 1) {
                printf("+ ");
            }
        }
    }
    free(dice.num);
    return 0;
}