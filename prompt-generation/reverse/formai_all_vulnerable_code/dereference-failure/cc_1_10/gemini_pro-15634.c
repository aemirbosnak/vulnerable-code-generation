//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the maximum size of the universe
#define UNIVERSE_SIZE 1000

// Define the number of planets in the universe
#define NUM_PLANETS 100

// Define the structure of a planet
typedef struct {
    char name[20];
    int size;
    int population;
    int resources;
} Planet;

// Define the structure of the universe
typedef struct {
    Planet planets[NUM_PLANETS];
} Universe;

// Create a new universe
Universe* create_universe() {
    Universe* universe = malloc(sizeof(Universe));
    for (int i = 0; i < NUM_PLANETS; i++) {
        // Generate a random name for the planet
        sprintf(universe->planets[i].name, "Planet %d", i);

        // Generate a random size for the planet
        universe->planets[i].size = rand() % 1000;

        // Generate a random population for the planet
        universe->planets[i].population = rand() % 1000000;

        // Generate a random amount of resources for the planet
        universe->planets[i].resources = rand() % 1000000;
    }

    return universe;
}

// Destroy the universe
void destroy_universe(Universe* universe) {
    free(universe);
}

// Print the universe
void print_universe(Universe* universe) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %s\n", universe->planets[i].name);
        printf("Size: %d\n", universe->planets[i].size);
        printf("Population: %d\n", universe->planets[i].population);
        printf("Resources: %d\n\n", universe->planets[i].resources);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new universe
    Universe* universe = create_universe();

    // Print the universe
    print_universe(universe);

    // Destroy the universe
    destroy_universe(universe);

    return 0;
}