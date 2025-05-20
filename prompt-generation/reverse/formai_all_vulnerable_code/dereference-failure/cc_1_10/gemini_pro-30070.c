//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the parameters of the simulation
#define NUM_STARS 1000000
#define NUM_PLANETS 10
#define PROB_LIFE 0.1
#define PROB_INTELLIGENCE 0.01
#define PROB_INVASION 0.001

// Define the data structures for the simulation
typedef struct {
    int x;
    int y;
    int z;
} star_t;

typedef struct {
    int star_index;
    int x;
    int y;
    int z;
    int has_life;
    int has_intelligence;
    int has_invaded;
} planet_t;

// Initialize the simulation
void init_simulation(star_t *stars, planet_t *planets) {
    // Initialize the stars
    for (int i = 0; i < NUM_STARS; i++) {
        stars[i].x = rand() % 10000;
        stars[i].y = rand() % 10000;
        stars[i].z = rand() % 10000;
    }

    // Initialize the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].star_index = rand() % NUM_STARS;
        planets[i].x = stars[planets[i].star_index].x + rand() % 1000;
        planets[i].y = stars[planets[i].star_index].y + rand() % 1000;
        planets[i].z = stars[planets[i].star_index].z + rand() % 1000;
        planets[i].has_life = (rand() % 100) < (PROB_LIFE * 100);
        planets[i].has_intelligence = (rand() % 100) < (PROB_INTELLIGENCE * 100);
        planets[i].has_invaded = 0;
    }
}

// Run the simulation
void run_simulation(star_t *stars, planet_t *planets) {
    // Iterate over the planets
    for (int i = 0; i < NUM_PLANETS; i++) {
        // Check if the planet has life and intelligence
        if (planets[i].has_life && planets[i].has_intelligence) {
            // Check if the planet has invaded
            if (!planets[i].has_invaded) {
                // Calculate the probability of invasion
                double prob_invasion = PROB_INVASION * (1.0 - exp(-pow(planets[i].x - stars[planets[i].star_index].x, 2) / 100000.0));

                // Check if the planet invades
                if ((rand() % 100) < (prob_invasion * 100)) {
                    planets[i].has_invaded = 1;
                }
            }
        }
    }
}

// Print the results of the simulation
void print_results(star_t *stars, planet_t *planets) {
    // Count the number of planets that have invaded
    int num_invaded = 0;
    for (int i = 0; i < NUM_PLANETS; i++) {
        if (planets[i].has_invaded) {
            num_invaded++;
        }
    }

    // Print the results
    printf("Number of stars: %d\n", NUM_STARS);
    printf("Number of planets: %d\n", NUM_PLANETS);
    printf("Probability of life: %f\n", PROB_LIFE);
    printf("Probability of intelligence: %f\n", PROB_INTELLIGENCE);
    printf("Probability of invasion: %f\n", PROB_INVASION);
    printf("Number of planets that have invaded: %d\n", num_invaded);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Allocate memory for the stars and planets
    star_t *stars = malloc(sizeof(star_t) * NUM_STARS);
    planet_t *planets = malloc(sizeof(planet_t) * NUM_PLANETS);

    // Initialize the simulation
    init_simulation(stars, planets);

    // Run the simulation
    run_simulation(stars, planets);

    // Print the results of the simulation
    print_results(stars, planets);

    // Free the memory allocated for the stars and planets
    free(stars);
    free(planets);

    return 0;
}