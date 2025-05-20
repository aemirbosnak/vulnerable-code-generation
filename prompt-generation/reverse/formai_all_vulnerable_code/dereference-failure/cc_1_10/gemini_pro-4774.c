//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system data structures
typedef struct Star {
    char name[32];
    int num_planets;
    struct Planet *planets;
} Star;

typedef struct Planet {
    char name[32];
    int size; // in Earth diameters
    int population; // in billions
} Planet;

// Procedural generation functions
Star *generate_star() {
    Star *star = malloc(sizeof(Star));
    strcpy(star->name, "HD 123456");
    star->num_planets = rand() % 10 + 1;
    star->planets = malloc(sizeof(Planet) * star->num_planets);
    for (int i = 0; i < star->num_planets; i++) {
        Planet *planet = &star->planets[i];
        strcpy(planet->name, "Kepler-452b");
        planet->size = rand() % 10 + 1;
        planet->population = rand() % 100 + 1;
    }
    return star;
}

// Main function
int main() {
    srand(time(NULL));

    // Generate a star system
    Star *star = generate_star();

    // Print the star system data
    printf("Star name: %s\n", star->name);
    printf("Number of planets: %d\n", star->num_planets);
    for (int i = 0; i < star->num_planets; i++) {
        Planet *planet = &star->planets[i];
        printf("Planet name: %s\n", planet->name);
        printf("Planet size: %d Earth diameters\n", planet->size);
        printf("Planet population: %d billion\n", planet->population);
    }

    // Free the memory allocated for the star system
    free(star->planets);
    free(star);

    return 0;
}