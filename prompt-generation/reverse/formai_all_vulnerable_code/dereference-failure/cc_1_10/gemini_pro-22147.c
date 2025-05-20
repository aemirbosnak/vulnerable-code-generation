//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system struct
struct star_system {
    char name[32];
    int num_planets;
    struct planet *planets;
};

// Planet struct
struct planet {
    char name[32];
    int type;  // 0=terrestrial, 1=gas giant
    int size;  // 0=small, 1=medium, 2=large
    int resources;  // 0=none, 1=few, 2=many
};

// Generate a random star system
struct star_system *generate_star_system() {
    // Allocate memory for the star system
    struct star_system *system = malloc(sizeof(struct star_system));

    // Generate a random name for the star system
    int name_length = rand() % 10 + 5;
    for (int i = 0; i < name_length; i++) {
        system->name[i] = 'A' + rand() % 26;
    }
    system->name[name_length] = '\0';

    // Generate a random number of planets for the star system
    system->num_planets = rand() % 10 + 1;

    // Allocate memory for the planets in the star system
    system->planets = malloc(sizeof(struct planet) * system->num_planets);

    // Generate random planets for the star system
    for (int i = 0; i < system->num_planets; i++) {
        // Generate a random name for the planet
        int name_length = rand() % 10 + 5;
        for (int j = 0; j < name_length; j++) {
            system->planets[i].name[j] = 'A' + rand() % 26;
        }
        system->planets[i].name[name_length] = '\0';

        // Generate a random type for the planet
        system->planets[i].type = rand() % 2;

        // Generate a random size for the planet
        system->planets[i].size = rand() % 3;

        // Generate a random number of resources for the planet
        system->planets[i].resources = rand() % 3;
    }

    // Return the star system
    return system;
}

// Print the star system
void print_star_system(struct star_system *system) {
    // Print the star system name
    printf("Star system: %s\n", system->name);

    // Print the planets in the star system
    for (int i = 0; i < system->num_planets; i++) {
        // Print the planet name
        printf("Planet: %s\n", system->planets[i].name);

        // Print the planet type
        if (system->planets[i].type == 0) {
            printf("Type: Terrestrial\n");
        } else {
            printf("Type: Gas giant\n");
        }

        // Print the planet size
        if (system->planets[i].size == 0) {
            printf("Size: Small\n");
        } else if (system->planets[i].size == 1) {
            printf("Size: Medium\n");
        } else {
            printf("Size: Large\n");
        }

        // Print the planet resources
        if (system->planets[i].resources == 0) {
            printf("Resources: None\n");
        } else if (system->planets[i].resources == 1) {
            printf("Resources: Few\n");
        } else {
            printf("Resources: Many\n");
        }

        printf("\n");
    }
}

// Free the memory allocated for the star system
void free_star_system(struct star_system *system) {
    // Free the memory allocated for the planets in the star system
    free(system->planets);

    // Free the memory allocated for the star system
    free(system);
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Generate a random star system
    struct star_system *system = generate_star_system();

    // Print the star system
    print_star_system(system);

    // Free the memory allocated for the star system
    free_star_system(system);

    return 0;
}