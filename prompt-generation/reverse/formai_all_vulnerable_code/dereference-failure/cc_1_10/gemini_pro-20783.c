//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a planet
typedef struct {
    char *name;
    int size;
    int population;
    int resources;
} Planet;

// Array of planets
Planet planets[] = {
    {"Earth", 10, 100000000, 100},
    {"Mars", 5, 100000, 50},
    {"Jupiter", 20, 10000000, 1000},
    {"Saturn", 15, 1000000, 500},
    {"Uranus", 10, 100000, 200},
    {"Neptune", 12, 100000, 300}
};

// Function to generate a random planet
Planet generate_planet() {
    // Get a random size for the planet
    int size = rand() % 20 + 1;

    // Get a random population for the planet
    int population = rand() % 100000000 + 1;

    // Get a random amount of resources for the planet
    int resources = rand() % 1000 + 1;

    // Create a new planet
    Planet planet;
    planet.name = malloc(10);
    sprintf(planet.name, "Planet %d", rand() % 10000 + 1);
    planet.size = size;
    planet.population = population;
    planet.resources = resources;

    // Return the new planet
    return planet;
}

// Function to print a planet
void print_planet(Planet planet) {
    printf("Name: %s\n", planet.name);
    printf("Size: %d\n", planet.size);
    printf("Population: %d\n", planet.population);
    printf("Resources: %d\n\n", planet.resources);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number of planets
    int num_planets = rand() % 100 + 1;

    // Create an array of planets
    Planet *planets = malloc(sizeof(Planet) * num_planets);

    // Generate the planets
    for (int i = 0; i < num_planets; i++) {
        planets[i] = generate_planet();
    }

    // Print the planets
    for (int i = 0; i < num_planets; i++) {
        print_planet(planets[i]);
    }

    // Free the memory allocated for the planets
    for (int i = 0; i < num_planets; i++) {
        free(planets[i].name);
    }
    free(planets);

    return 0;
}