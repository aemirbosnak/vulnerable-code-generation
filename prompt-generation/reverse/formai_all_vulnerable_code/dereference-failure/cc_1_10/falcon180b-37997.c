//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRIALS 1000000
#define NUM_ALIENS 1000

int main() {
    int i, j;
    int num_invasions = 0;
    int num_trials = 0;
    int *alien_locations;
    int *invasion_results;

    // Allocate memory for alien locations and invasion results
    alien_locations = (int *)malloc(NUM_ALIENS * sizeof(int));
    invasion_results = (int *)malloc(NUM_ALIENS * sizeof(int));

    // Initialize alien locations to -1
    for (i = 0; i < NUM_ALIENS; i++) {
        alien_locations[i] = -1;
    }

    // Simulate invasions
    srand(time(NULL));
    while (num_trials < NUM_TRIALS) {
        // Choose a random alien
        i = rand() % NUM_ALIENS;

        // Choose a random location for the alien
        do {
            j = rand() % 1000;
        } while (alien_locations[j]!= -1);

        alien_locations[i] = j;

        // Check if the alien is invading
        if (j == 0) {
            num_invasions++;
        }

        num_trials++;
    }

    // Print results
    printf("Number of invasions: %d\n", num_invasions);
    printf("Percentage of invasions: %.2f%%\n", (float)num_invasions / NUM_TRIALS * 100);

    // Free memory
    free(alien_locations);
    free(invasion_results);

    return 0;
}