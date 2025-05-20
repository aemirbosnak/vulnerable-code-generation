//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Structure to represent a planet
typedef struct planet {
    char *name;
    int size;
    int population;
    int resources;
} planet_t;

// Structure to represent a spaceship
typedef struct spaceship {
    char *name;
    int size;
    int speed;
    int fuel;
} spaceship_t;

// Function to create a new planet
planet_t *create_planet(char *name, int size, int population, int resources) {
    planet_t *planet = malloc(sizeof(planet_t));
    planet->name = malloc(strlen(name) + 1);
    strcpy(planet->name, name);
    planet->size = size;
    planet->population = population;
    planet->resources = resources;
    return planet;
}

// Function to create a new spaceship
spaceship_t *create_spaceship(char *name, int size, int speed, int fuel) {
    spaceship_t *spaceship = malloc(sizeof(spaceship_t));
    spaceship->name = malloc(strlen(name) + 1);
    strcpy(spaceship->name, name);
    spaceship->size = size;
    spaceship->speed = speed;
    spaceship->fuel = fuel;
    return spaceship;
}

// Function to generate a random planet
planet_t *generate_random_planet() {
    // Generate a random name
    char name[10];
    for (int i = 0; i < 10; i++) {
        name[i] = 'a' + rand() % 26;
    }
    name[9] = '\0';

    // Generate a random size
    int size = rand() % 1000 + 1;

    // Generate a random population
    int population = rand() % 1000000 + 1;

    // Generate a random number of resources
    int resources = rand() % 100000 + 1;

    // Create a new planet
    return create_planet(name, size, population, resources);
}

// Function to generate a random spaceship
spaceship_t *generate_random_spaceship() {
    // Generate a random name
    char name[10];
    for (int i = 0; i < 10; i++) {
        name[i] = 'a' + rand() % 26;
    }
    name[9] = '\0';

    // Generate a random size
    int size = rand() % 100 + 1;

    // Generate a random speed
    int speed = rand() % 100 + 1;

    // Generate a random amount of fuel
    int fuel = rand() % 1000 + 1;

    // Create a new spaceship
    return create_spaceship(name, size, speed, fuel);
}

// Function to print a planet
void print_planet(planet_t *planet) {
    printf("Planet: %s\n", planet->name);
    printf("Size: %d\n", planet->size);
    printf("Population: %d\n", planet->population);
    printf("Resources: %d\n", planet->resources);
}

// Function to print a spaceship
void print_spaceship(spaceship_t *spaceship) {
    printf("Spaceship: %s\n", spaceship->name);
    printf("Size: %d\n", spaceship->size);
    printf("Speed: %d\n", spaceship->speed);
    printf("Fuel: %d\n", spaceship->fuel);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random planet
    planet_t *planet = generate_random_planet();

    // Generate a random spaceship
    spaceship_t *spaceship = generate_random_spaceship();

    // Print the planet
    print_planet(planet);

    // Print the spaceship
    print_spaceship(spaceship);

    // Free the memory allocated for the planet and spaceship
    free(planet->name);
    free(planet);
    free(spaceship->name);
    free(spaceship);

    return 0;
}