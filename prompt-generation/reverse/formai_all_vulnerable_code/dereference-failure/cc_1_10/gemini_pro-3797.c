//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Structure to represent a star system
typedef struct {
    char *name;
    int num_planets;
    int num_moons;
    int resources;
} StarSystem;

// Function to generate a random star system
StarSystem *generate_star_system() {
    // Allocate memory for the star system
    StarSystem *star_system = malloc(sizeof(StarSystem));

    // Generate a random name for the star system
    star_system->name = malloc(MAX_SIZE * sizeof(char));
    int name_length = rand() % MAX_SIZE;
    for (int i = 0; i < name_length; i++) {
        star_system->name[i] = rand() % 26 + 'a';
    }
    star_system->name[name_length] = '\0';

    // Generate a random number of planets for the star system
    star_system->num_planets = rand() % 10 + 1;

    // Generate a random number of moons for the star system
    star_system->num_moons = rand() % 10 + 1;

    // Generate a random number of resources for the star system
    star_system->resources = rand() % 100 + 1;

    // Return the star system
    return star_system;
}

// Function to print a star system
void print_star_system(StarSystem *star_system) {
    printf("Star system: %s\n", star_system->name);
    printf("Number of planets: %d\n", star_system->num_planets);
    printf("Number of moons: %d\n", star_system->num_moons);
    printf("Number of resources: %d\n", star_system->resources);
}

// Function to free the memory allocated for a star system
void free_star_system(StarSystem *star_system) {
    free(star_system->name);
    free(star_system);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random star system
    StarSystem *star_system = generate_star_system();

    // Print the star system
    print_star_system(star_system);

    // Free the memory allocated for the star system
    free_star_system(star_system);

    return 0;
}