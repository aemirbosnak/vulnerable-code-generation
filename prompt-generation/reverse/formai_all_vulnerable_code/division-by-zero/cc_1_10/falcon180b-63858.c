//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int *results;
} RollResults;

void roll_dice(RollResults *results) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < results->num_dice; i++) {
        results->results[i] = rand() % results->num_sides + 1;
    }
}

void print_results(RollResults *results) {
    int i;

    printf("Rolling %d dice with %d sides:\n", results->num_dice, results->num_sides);

    for (i = 0; i < results->num_dice; i++) {
        printf("%d ", results->results[i]);
    }

    printf("\n");
}

int main() {
    RollResults results;
    int num_dice, num_sides;

    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    results.num_dice = num_dice;
    results.num_sides = num_sides;
    results.results = malloc(num_dice * sizeof(int));

    if (results.results == NULL) {
        printf("Error: could not allocate memory for results.\n");
        return 1;
    }

    roll_dice(&results);
    print_results(&results);

    free(results.results);

    return 0;
}