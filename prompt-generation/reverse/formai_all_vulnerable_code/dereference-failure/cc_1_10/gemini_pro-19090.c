//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the parameters of the simulation
#define NUM_ALIENS 1000
#define NUM_DAYS 365
#define PROB_INVASION 0.01

// Define the data structures used to store the simulation results
typedef struct {
    int day;
    int num_aliens;
} invasion_event;

typedef struct {
    int num_invasions;
    invasion_event* invasions;
} simulation_results;

// Function to generate a random number between 0 and 1
double rand_double() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to simulate an alien invasion
simulation_results simulate_invasion() {
    // Create an array to store the invasion events
    invasion_event* invasions = malloc(sizeof(invasion_event) * NUM_DAYS);

    // Initialize the number of invasions to 0
    int num_invasions = 0;

    // Simulate each day of the year
    for (int day = 0; day < NUM_DAYS; day++) {
        // Generate a random number to determine if an invasion will occur
        double rand = rand_double();

        // If the random number is less than the probability of invasion, then an invasion will occur
        if (rand < PROB_INVASION) {
            // Increment the number of invasions
            num_invasions++;

            // Add the invasion event to the array
            invasions[num_invasions - 1].day = day;
            invasions[num_invasions - 1].num_aliens = NUM_ALIENS;
        }
    }

    // Create a simulation results structure to store the results
    simulation_results results;
    results.num_invasions = num_invasions;
    results.invasions = invasions;

    // Return the simulation results
    return results;
}

// Function to print the simulation results
void print_results(simulation_results results) {
    // Print the number of invasions
    printf("Number of invasions: %d\n", results.num_invasions);

    // Print the invasion events
    for (int i = 0; i < results.num_invasions; i++) {
        printf("Invasion on day %d with %d aliens\n", results.invasions[i].day, results.invasions[i].num_aliens);
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate the alien invasion
    simulation_results results = simulate_invasion();

    // Print the simulation results
    print_results(results);

    // Free the memory allocated for the invasion events
    free(results.invasions);

    return 0;
}