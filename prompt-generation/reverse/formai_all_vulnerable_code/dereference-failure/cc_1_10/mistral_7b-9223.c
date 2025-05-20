//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_DIE_SIDE 1
#define MAX_DIE_SIDE 6
#define NUM_DICE 3

// Function to check if the input is valid
int is_valid_input(int num_dice, int *sides, int num_sides) {
    int i;

    if (num_dice <= 0 || num_sides <= MIN_DIE_SIDE || num_sides > MAX_DIE_SIDE) {
        fprintf(stderr, "Invalid input: num_dice = %d, num_sides = %d\n", num_dice, num_sides);
        return 0;
    }

    for (i = 0; i < num_dice; i++) {
        if (sides[i] <= 0 || sides[i] > num_sides) {
            fprintf(stderr, "Invalid input: sides[%d] = %d\n", i, sides[i]);
            return 0;
        }
    }

    return 1;
}

// Function to roll dice
void roll_dice(int num_dice, int *sides, int num_sides) {
    int i, result;
    time_t seed;

    if (!is_valid_input(num_dice, sides, num_sides)) {
        return;
    }

    // Seed the random number generator with the current time
    seed = time(NULL);
    srand(seed);

    for (i = 0; i < num_dice; i++) {
        // Generate a random number between 1 and the number of sides
        result = rand() % (num_sides + 1);

        // Print the result
        printf("Die %d rolled a %d\n", i + 1, result);
    }
}

// Main function
int main(int argc, char *argv[]) {
    int num_dice, i;
    int sides[NUM_DICE];
    int num_sides = MAX_DIE_SIDE;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_dice> [sides1 [sides2 ... [sidesN]]]\n", argv[0]);
        return 1;
    }

    num_dice = atoi(argv[1]);

    for (i = 2; i < argc; i++) {
        sides[i - 2] = atoi(argv[i]);
    }

    roll_dice(num_dice, sides, num_sides);

    return 0;
}