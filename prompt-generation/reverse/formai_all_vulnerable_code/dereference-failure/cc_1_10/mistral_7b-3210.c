//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE 1
#define MAX_DICE 10
#define MIN_SIDES 2
#define MAX_SIDES 100
#define MIN_ROLLS 1

void roll_dice(int num_dice, int sides, int rolls, int *results) {
    srand(time(NULL));
    for (int i = 0; i < rolls; i++) {
        for (int j = 0; j < num_dice; j++) {
            results[i * num_dice + j] = rand() % sides + 1;
        }
    }
}

void print_results(int num_dice, int sides, int rolls, int *results) {
    printf("\nRolling %d %d-sided dice %d times:\n", num_dice, sides, rolls);
    for (int i = 0; i < rolls * num_dice; i++) {
        printf("D%d: %d\n", num_dice, results[i]);
    }
}

int main(int argc, char *argv[]) {
    int num_dice, sides, rolls, results_size;
    int *results;

    if (argc < 4 || (argc > 5 && argc != 6)) {
        printf("Usage: %s <number of dice> <sides on each die> <number of rolls> [<roll result>]\n", argv[0]);
        return 1;
    }

    num_dice = atoi(argv[1]);
    sides = atoi(argv[2]);
    rolls = atoi(argv[3]);

    if (argc == 4) {
        results_size = rolls * num_dice;
        results = (int *)malloc(results_size * sizeof(int));
        roll_dice(num_dice, sides, rolls, results);
        print_results(num_dice, sides, rolls, results);
        free(results);
    } else {
        int roll_result = atoi(argv[5]);
        results_size = rolls * num_dice + 1;
        results = (int *)malloc(results_size * sizeof(int));
        roll_dice(num_dice, sides, rolls, results);
        results[rolls * num_dice] = roll_result;
        print_results(num_dice, sides, rolls, results);
        free(results);
    }

    return 0;
}