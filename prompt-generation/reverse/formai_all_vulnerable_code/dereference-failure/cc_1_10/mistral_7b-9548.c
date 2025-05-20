//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_DICE 5
#define SIDES 6
#define SEED 1337

typedef struct {
    int sides;
    int value;
} Dice;

void srand_xorshift128star(unsigned long seed) {
    seed ^= seed >> 12;
    seed ^= seed << 25;
    seed ^= seed >> 13;
    seed *= 0x853c49e6748fea9b;
}

unsigned long rand_xorshift128star() {
    static unsigned long s = SEED;

    s ^= s >> 12;
    s *= 0x853c49e6748fea9b;
    return s;
}

Dice* generate_dice(int num_dice, int sides) {
    Dice* dice = (Dice*)calloc(num_dice, sizeof(Dice));

    for (int i = 0; i < num_dice; i++) {
        dice[i].sides = sides;
        dice[i].value = 0;
    }

    return dice;
}

void roll_dice(Dice* dice) {
    for (int i = 0; i < NUM_DICE; i++) {
        dice[i].value = 1 + (rand_xorshift128star() % dice[i].sides);
    }
}

void print_dice(const char* prefix, Dice* dice, int num_dice) {
    printf("%s", prefix);

    for (int i = 0; i < num_dice; i++) {
        printf("D%d: %d ", i + 1, dice[i].value);
    }

    printf("\n");
}

int main() {
    srand_xorshift128star(SEED);

    Dice* dice = generate_dice(NUM_DICE, SIDES);

    roll_dice(dice);

    print_dice("Roll: ", dice, NUM_DICE);

    free(dice);

    return 0;
}