//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a "Planet" with a name and a mass
typedef struct {
    char *name;
    double mass;
} Planet;

// Define a function to allocate memory for a planet
Planet *planet_alloc(const char *name, double mass) {
    // Check if the input name is valid
    if (name == NULL || strlen(name) == 0) {
        fprintf(stderr, "Error: invalid name\n");
        return NULL;
    }

    // Allocate memory for the planet struct
    Planet *planet = malloc(sizeof(Planet));
    if (planet == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for planet\n");
        return NULL;
    }

    // Set the name and mass of the planet
    planet->name = strdup(name);
    planet->mass = mass;

    return planet;
}

// Define a function to deallocate memory for a planet
void planet_free(Planet *planet) {
    if (planet == NULL) {
        fprintf(stderr, "Error: invalid planet\n");
        return;
    }

    // Free the memory for the planet struct
    free(planet->name);
    free(planet);
}

// Define a function to print the details of a planet
void print_planet(Planet *planet) {
    if (planet == NULL) {
        fprintf(stderr, "Error: invalid planet\n");
        return;
    }

    printf("Planet: %s (%f kg)\n", planet->name, planet->mass);
}

int main() {
    // Create a planet and print its details
    Planet *earth = planet_alloc("Earth", 5.97237e24);
    if (earth == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for Earth\n");
        return 1;
    }
    print_planet(earth);

    // Create another planet and print its details
    Planet *mars = planet_alloc("Mars", 6.4185e23);
    if (mars == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for Mars\n");
        return 1;
    }
    print_planet(mars);

    // Free the memory for the planets
    planet_free(earth);
    planet_free(mars);

    return 0;
}