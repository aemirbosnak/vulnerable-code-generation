//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the number of years to simulate
#define YEARS 10000

// Define the probability of an alien invasion in any given year
#define PROBABILITY 0.000001

// Define the maximum number of alien invasions that can occur in a year
#define MAX_INVASIONS 10

// Define the structure of an alien invasion
typedef struct {
    int year;
    int num_invaders;
} invasion_t;

// Define the function to generate a random number between 0 and 1
double rand_double() {
    return (double)rand() / (double)RAND_MAX;
}

// Define the function to simulate an alien invasion
invasion_t simulate_invasion() {
    invasion_t invasion;

    // Generate a random year for the invasion
    invasion.year = rand() % YEARS;

    // Generate a random number of invaders
    invasion.num_invaders = rand() % MAX_INVASIONS;

    return invasion;
}

// Define the function to print the results of the simulation
void print_results(invasion_t* invasions, int num_invasions) {
    printf("Alien Invasion Simulation Results\n");
    printf("--------------------------------\n");
    printf("Total number of simulations: %d\n", YEARS);
    printf("Total number of alien invasions: %d\n", num_invasions);
    printf("Average number of alien invasions per year: %.2f\n", (double)num_invasions / YEARS);
    printf("Maximum number of alien invasions in a year: %d\n", MAX_INVASIONS);
    printf("\n");
    printf("List of alien invasions:\n");
    for (int i = 0; i < num_invasions; i++) {
        printf("Year: %d, Number of Invaders: %d\n", invasions[i].year, invasions[i].num_invaders);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array to store the alien invasions
    invasion_t* invasions = malloc(sizeof(invasion_t) * YEARS);

    // Simulate the alien invasions
    int num_invasions = 0;
    for (int i = 0; i < YEARS; i++) {
        if (rand_double() < PROBABILITY) {
            invasions[num_invasions++] = simulate_invasion();
        }
    }

    // Print the results of the simulation
    print_results(invasions, num_invasions);

    // Free the memory allocated for the alien invasions
    free(invasions);

    return 0;
}