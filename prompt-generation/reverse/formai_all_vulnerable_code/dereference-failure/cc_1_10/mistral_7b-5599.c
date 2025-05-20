//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDE_COUNT 6
#define DICE_COUNT 4

struct Die {
    int sides[SIDE_COUNT];
};

typedef struct Die Die;

Die *createDice() {
    Die *dice = malloc(DICE_COUNT * sizeof(Die));

    for (int i = 0; i < DICE_COUNT; i++) {
        for (int j = 0; j < SIDE_COUNT; j++) {
            dice[i].sides[j] = j + 1;
        }
    }

    return dice;
}

void rollDice(Die *dice) {
    srand(time(NULL));

    for (int i = 0; i < DICE_COUNT; i++) {
        int roll = rand() % SIDE_COUNT;
        printf("Die %d rolled a %d\n", i + 1, dice[i].sides[roll]);
        dice[i].sides[roll] = -dice[i].sides[roll]; // Mark as rolled
    }
}

void printDice(Die *dice) {
    for (int i = 0; i < DICE_COUNT; i++) {
        printf("Die %d: ", i + 1);
        for (int j = 0; j < SIDE_COUNT; j++) {
            if (dice[i].sides[j] > 0)
                printf("%2d ", dice[i].sides[j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

int main() {
    Die *dice = createDice();
    rollDice(dice);
    printf("Current state of the dice:\n");
    printDice(dice);

    free(dice);
    return 0;
}