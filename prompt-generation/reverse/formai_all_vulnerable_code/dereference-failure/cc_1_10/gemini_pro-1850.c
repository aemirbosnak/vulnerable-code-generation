//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of planets in the galaxy
#define NUM_PLANETS 100

// Define the maximum number of moons per planet
#define MAX_MOONS 10

// Define the maximum number of resources per planet
#define MAX_RESOURCES 5

// Define the structure of a planet
typedef struct {
    char name[20];
    int num_moons;
    char moons[MAX_MOONS][20];
    int num_resources;
    char resources[MAX_RESOURCES][20];
} planet_t;

// Define the structure of a spaceship
typedef struct {
    char name[20];
    int speed;
    int fuel;
    int cargo_capacity;
} spaceship_t;

// Create a new planet
planet_t *create_planet() {
    // Allocate memory for the planet
    planet_t *planet = malloc(sizeof(planet_t));

    // Generate a random name for the planet
    for (int i = 0; i < 20; i++) {
        planet->name[i] = (rand() % 26) + 'a';
    }

    // Generate a random number of moons for the planet
    planet->num_moons = rand() % MAX_MOONS;

    // Generate random names for the moons
    for (int i = 0; i < planet->num_moons; i++) {
        for (int j = 0; j < 20; j++) {
            planet->moons[i][j] = (rand() % 26) + 'a';
        }
    }

    // Generate a random number of resources for the planet
    planet->num_resources = rand() % MAX_RESOURCES;

    // Generate random names for the resources
    for (int i = 0; i < planet->num_resources; i++) {
        for (int j = 0; j < 20; j++) {
            planet->resources[i][j] = (rand() % 26) + 'a';
        }
    }

    // Return the planet
    return planet;
}

// Create a new spaceship
spaceship_t *create_spaceship() {
    // Allocate memory for the spaceship
    spaceship_t *spaceship = malloc(sizeof(spaceship_t));

    // Generate a random name for the spaceship
    for (int i = 0; i < 20; i++) {
        spaceship->name[i] = (rand() % 26) + 'a';
    }

    // Generate a random speed for the spaceship
    spaceship->speed = rand() % 100;

    // Generate a random fuel capacity for the spaceship
    spaceship->fuel = rand() % 100;

    // Generate a random cargo capacity for the spaceship
    spaceship->cargo_capacity = rand() % 100;

    // Return the spaceship
    return spaceship;
}

// Print the information about a planet
void print_planet(planet_t *planet) {
    // Print the name of the planet
    printf("Planet: %s\n", planet->name);

    // Print the number of moons the planet has
    printf("Number of moons: %d\n", planet->num_moons);

    // Print the names of the moons
    for (int i = 0; i < planet->num_moons; i++) {
        printf("Moon %d: %s\n", i + 1, planet->moons[i]);
    }

    // Print the number of resources the planet has
    printf("Number of resources: %d\n", planet->num_resources);

    // Print the names of the resources
    for (int i = 0; i < planet->num_resources; i++) {
        printf("Resource %d: %s\n", i + 1, planet->resources[i]);
    }
}

// Print the information about a spaceship
void print_spaceship(spaceship_t *spaceship) {
    // Print the name of the spaceship
    printf("Spaceship: %s\n", spaceship->name);

    // Print the speed of the spaceship
    printf("Speed: %d\n", spaceship->speed);

    // Print the fuel capacity of the spaceship
    printf("Fuel: %d\n", spaceship->fuel);

    // Print the cargo capacity of the spaceship
    printf("Cargo capacity: %d\n", spaceship->cargo_capacity);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new planet
    planet_t *planet = create_planet();

    // Create a new spaceship
    spaceship_t *spaceship = create_spaceship();

    // Print the information about the planet
    print_planet(planet);

    // Print the information about the spaceship
    print_spaceship(spaceship);

    //free memory
    free(planet);
    free(spaceship);

    return 0;
}