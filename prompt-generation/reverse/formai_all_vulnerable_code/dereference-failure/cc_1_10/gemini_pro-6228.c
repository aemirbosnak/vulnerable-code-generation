//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_MIN 1
#define DICE_MAX 6
#define DICE_COUNT 5

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a single die
int roll_die() {
    return rand_range(DICE_MIN, DICE_MAX);
}

// Function to roll multiple dice
int* roll_dice(int count) {
    int* results = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        results[i] = roll_die();
    }
    return results;
}

// Function to print the results of rolling multiple dice
void print_results(int* results, int count) {
    printf("Rolled %d dice:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Roll multiple dice
    int* results = roll_dice(DICE_COUNT);

    // Print the results
    print_results(results, DICE_COUNT);

    // Free the allocated memory
    free(results);

    return 0;
}