//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000
#define MAX_ROLLS 1000000

typedef struct {
    int num_dice;
    int num_sides;
    int num_rolls;
    int *rolls;
} DiceRoller;

void init_diceroller(DiceRoller *roller) {
    roller->num_dice = 1;
    roller->num_sides = 6;
    roller->num_rolls = 1;
    roller->rolls = malloc(roller->num_dice * roller->num_rolls * sizeof(int));
}

void free_diceroller(DiceRoller *roller) {
    free(roller->rolls);
}

void roll_dice(DiceRoller *roller) {
    srand(time(NULL));
    for (int i = 0; i < roller->num_dice; i++) {
        for (int j = 0; j < roller->num_rolls; j++) {
            roller->rolls[i * roller->num_rolls + j] = rand() % roller->num_sides + 1;
        }
    }
}

void print_rolls(DiceRoller *roller) {
    for (int i = 0; i < roller->num_dice; i++) {
        for (int j = 0; j < roller->num_rolls; j++) {
            printf("%d ", roller->rolls[i * roller->num_rolls + j]);
        }
        printf("\n");
    }
}

int main() {
    DiceRoller roller;
    init_diceroller(&roller);
    roll_dice(&roller);
    print_rolls(&roller);
    free_diceroller(&roller);
    return 0;
}