//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system structure
typedef struct star_system {
    char *name;
    int num_planets;
    struct planet *planets;
} star_system;

// Planet structure
typedef struct planet {
    char *name;
    int size;
    int population;
    int resources;
} planet;

// Generate a random star system
star_system *generate_star_system() {
    // Allocate memory for the star system
    star_system *system = malloc(sizeof(star_system));

    // Generate a random name for the star system
    system->name = malloc(10);
    for (int i = 0; i < 9; i++) {
        system->name[i] = 'a' + rand() % 26;
    }
    system->name[9] = '\0';

    // Generate a random number of planets in the star system
    system->num_planets = rand() % 10 + 1;

    // Allocate memory for the planets in the star system
    system->planets = malloc(sizeof(planet) * system->num_planets);

    // Generate a random name, size, population, and resources for each planet in the star system
    for (int i = 0; i < system->num_planets; i++) {
        system->planets[i].name = malloc(10);
        for (int j = 0; j < 9; j++) {
            system->planets[i].name[j] = 'a' + rand() % 26;
        }
        system->planets[i].name[9] = '\0';

        system->planets[i].size = rand() % 1000 + 1;
        system->planets[i].population = rand() % 1000000 + 1;
        system->planets[i].resources = rand() % 10000 + 1;
    }

    // Return the star system
    return system;
}

// Print a star system
void print_star_system(star_system *system) {
    // Print the name of the star system
    printf("Star system: %s\n", system->name);

    // Print the number of planets in the star system
    printf("Number of planets: %d\n", system->num_planets);

    // Print the planets in the star system
    for (int i = 0; i < system->num_planets; i++) {
        printf("Planet %d:\n", i + 1);
        printf("  Name: %s\n", system->planets[i].name);
        printf("  Size: %d\n", system->planets[i].size);
        printf("  Population: %d\n", system->planets[i].population);
        printf("  Resources: %d\n", system->planets[i].resources);
    }
}

// Free the memory allocated for a star system
void free_star_system(star_system *system) {
    // Free the memory allocated for the star system's name
    free(system->name);

    // Free the memory allocated for the planets in the star system
    for (int i = 0; i < system->num_planets; i++) {
        free(system->planets[i].name);
    }
    free(system->planets);

    // Free the memory allocated for the star system
    free(system);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random star system
    star_system *system = generate_star_system();

    // Print the star system
    print_star_system(system);

    // Free the memory allocated for the star system
    free_star_system(system);

    return 0;
}