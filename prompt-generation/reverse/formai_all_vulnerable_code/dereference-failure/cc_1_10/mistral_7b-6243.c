//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE 1
#define MAX_DICE 6
#define MIN_ROLLS 1
#define MAX_ROLLS 10

void roll_dice(int num_dice, int sides, int rolls, int *results) {
    for (int dice = 0; dice < num_dice; dice++) {
        for (int roll = 0; roll < rolls; roll++) {
            results[roll + dice * rolls] = rand() % sides + 1;
        }
    }
}

void print_results(int num_dice, int sides, int rolls, int *results) {
    printf("Rolling %d %d-sided dice %d times...\n", num_dice, sides, rolls);
    fflush(stdout);

    for (int i = 0; i < rolls * num_dice; i++) {
        printf("%d ", results[i]);
        if ((i + 1) % (rolls) == 0) {
            printf("\n");
        }
    }

    printf("Done.\n");
}

int main(int argc, char *argv[]) {
    int num_dice = argc > 1 ? atoi(argv[1]) : 1;
    int sides = argc > 2 ? atoi(argv[2]) : 6;
    int rolls = argc > 3 ? atoi(argv[3]) : 1;

    if (num_dice < MIN_DICE || sides < MIN_DICE || rolls < MIN_ROLLS || rolls > MAX_ROLLS) {
        fprintf(stderr, "Invalid arguments. Usage: %s [num_dice] [sides] [rolls]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int *results = calloc(rolls * num_dice, sizeof(int));
    if (results == NULL) {
        perror("Failed to allocate memory for results.");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    roll_dice(num_dice, sides, rolls, results);
    print_results(num_dice, sides, rolls, results);

    free(results);
    return EXIT_SUCCESS;
}