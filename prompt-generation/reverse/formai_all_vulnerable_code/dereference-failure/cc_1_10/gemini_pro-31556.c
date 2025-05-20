//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void init_rand() {
    srand(time(NULL));
}

// Generate a random number between 0 and max
int rand_int(int max) {
    return rand() % (max + 1);
}

// Generate a random planet
struct planet {
    char *name;
    int size;
    int population;
    int resources;
};

struct planet *generate_planet() {
    // Allocate memory for the planet
    struct planet *planet = malloc(sizeof(struct planet));

    // Generate a random name for the planet
    planet->name = malloc(10);
    for (int i = 0; i < 9; i++) {
        planet->name[i] = 'a' + rand_int(25);
    }
    planet->name[9] = '\0';

    // Generate a random size for the planet
    planet->size = rand_int(100);

    // Generate a random population for the planet
    planet->population = rand_int(1000000);

    // Generate a random amount of resources on the planet
    planet->resources = rand_int(1000000);

    // Return the planet
    return planet;
}

// Print the planet
void print_planet(struct planet *planet) {
    printf("Name: %s\n", planet->name);
    printf("Size: %d\n", planet->size);
    printf("Population: %d\n", planet->population);
    printf("Resources: %d\n", planet->resources);
    printf("\n");
}

// Generate a random solar system
struct solar_system {
    char *name;
    int num_planets;
    struct planet **planets;
};

struct solar_system *generate_solar_system() {
    // Allocate memory for the solar system
    struct solar_system *solar_system = malloc(sizeof(struct solar_system));

    // Generate a random name for the solar system
    solar_system->name = malloc(10);
    for (int i = 0; i < 9; i++) {
        solar_system->name[i] = 'a' + rand_int(25);
    }
    solar_system->name[9] = '\0';

    // Generate a random number of planets in the solar system
    solar_system->num_planets = rand_int(10);

    // Allocate memory for the planets in the solar system
    solar_system->planets = malloc(sizeof(struct planet *) * solar_system->num_planets);

    // Generate the planets in the solar system
    for (int i = 0; i < solar_system->num_planets; i++) {
        solar_system->planets[i] = generate_planet();
    }

    // Return the solar system
    return solar_system;
}

// Print the solar system
void print_solar_system(struct solar_system *solar_system) {
    printf("Name: %s\n", solar_system->name);
    printf("Number of planets: %d\n", solar_system->num_planets);
    for (int i = 0; i < solar_system->num_planets; i++) {
        print_planet(solar_system->planets[i]);
    }
    printf("\n");
}

// Free the memory allocated for the planet
void free_planet(struct planet *planet) {
    free(planet->name);
    free(planet);
}

// Free the memory allocated for the solar system
void free_solar_system(struct solar_system *solar_system) {
    free(solar_system->name);
    for (int i = 0; i < solar_system->num_planets; i++) {
        free_planet(solar_system->planets[i]);
    }
    free(solar_system->planets);
    free(solar_system);
}

// Main function
int main() {
    // Initialize the random number generator
    init_rand();

    // Generate a random solar system
    struct solar_system *solar_system = generate_solar_system();

    // Print the solar system
    print_solar_system(solar_system);

    // Free the memory allocated for the solar system
    free_solar_system(solar_system);

    return 0;
}