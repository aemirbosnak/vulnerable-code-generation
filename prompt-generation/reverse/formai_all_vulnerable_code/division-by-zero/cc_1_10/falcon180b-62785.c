//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 1000000
#define MAX_DIMENSIONS 10
#define MAX_UNIVERSE_SIZE 1000

int main() {
    int num_trials;
    int num_dimensions;
    int num_aliens;
    int universe_size;
    int num_invasions = 0;

    srand(time(NULL));

    // Get user input
    printf("Enter the number of trials: ");
    scanf("%d", &num_trials);

    printf("Enter the number of dimensions in the universe: ");
    scanf("%d", &num_dimensions);

    printf("Enter the number of aliens in the universe: ");
    scanf("%d", &num_aliens);

    printf("Enter the size of the universe: ");
    scanf("%d", &universe_size);

    // Initialize universe
    int **universe = (int **) malloc(num_dimensions * sizeof(int *));
    for (int i = 0; i < num_dimensions; i++) {
        universe[i] = (int *) malloc(universe_size * sizeof(int));
        for (int j = 0; j < universe_size; j++) {
            universe[i][j] = 0;
        }
    }

    // Place aliens in universe
    for (int i = 0; i < num_aliens; i++) {
        int x = rand() % universe_size;
        int y = rand() % num_dimensions;
        universe[y][x] = 1;
    }

    // Simulate invasions
    for (int trial = 0; trial < num_trials; trial++) {
        int x = rand() % universe_size;
        int y = rand() % num_dimensions;

        // Check if alien is present at this location
        if (universe[y][x] == 1) {
            num_invasions++;
        }
    }

    // Calculate probability of alien invasion
    double probability = (double) num_invasions / (num_trials * num_aliens);

    printf("The probability of an alien invasion is %.2f%%\n", probability * 100.0);

    for (int i = 0; i < num_dimensions; i++) {
        free(universe[i]);
    }
    free(universe);

    return 0;
}