//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system struct
typedef struct star_system {
    char *name;
    int num_planets;
    int num_moons;
    struct star_system *next;
} star_system;

// Planet struct
typedef struct planet {
    char *name;
    int size;
    int population;
    struct planet *next;
} planet;

// Moon struct
typedef struct moon {
    char *name;
    int size;
    struct moon *next;
} moon;

// Function to create a new star system
star_system *create_star_system(char *name, int num_planets, int num_moons) {
    star_system *new_system = malloc(sizeof(star_system));
    new_system->name = name;
    new_system->num_planets = num_planets;
    new_system->num_moons = num_moons;
    new_system->next = NULL;
    return new_system;
}

// Function to create a new planet
planet *create_planet(char *name, int size, int population) {
    planet *new_planet = malloc(sizeof(planet));
    new_planet->name = name;
    new_planet->size = size;
    new_planet->population = population;
    new_planet->next = NULL;
    return new_planet;
}

// Function to create a new moon
moon *create_moon(char *name, int size) {
    moon *new_moon = malloc(sizeof(moon));
    new_moon->name = name;
    new_moon->size = size;
    new_moon->next = NULL;
    return new_moon;
}

// Function to print the star system
void print_star_system(star_system *system) {
    printf("Star system: %s\n", system->name);
    printf("Number of planets: %d\n", system->num_planets);
    printf("Number of moons: %d\n", system->num_moons);
    printf("\n");
}

// Function to print the planet
void print_planet(planet *planet) {
    printf("Planet: %s\n", planet->name);
    printf("Size: %d\n", planet->size);
    printf("Population: %d\n", planet->population);
    printf("\n");
}

// Function to print the moon
void print_moon(moon *moon) {
    printf("Moon: %s\n", moon->name);
    printf("Size: %d\n", moon->size);
    printf("\n");
}

// Function to free the star system
void free_star_system(star_system *system) {
    free(system->name);
    free(system);
}

// Function to free the planet
void free_planet(planet *planet) {
    free(planet->name);
    free(planet);
}

// Function to free the moon
void free_moon(moon *moon) {
    free(moon->name);
    free(moon);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new star system
    star_system *system = create_star_system("Sol", 8, 15);

    // Create a new planet
    planet *planet = create_planet("Earth", 12756, 7900000000);

    // Create a new moon
    moon *moon = create_moon("Luna", 3475);

    // Print the star system
    print_star_system(system);

    // Print the planet
    print_planet(planet);

    // Print the moon
    print_moon(moon);

    // Free the star system
    free_star_system(system);

    // Free the planet
    free_planet(planet);

    // Free the moon
    free_moon(moon);

    return 0;
}