//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system types
#define TYPE_NONE 0
#define TYPE_SUN 1
#define TYPE_PLANET 2
#define TYPE_MOON 3

// Star system properties
typedef struct {
    int type;
    char *name;
    int radius;
    int mass;
    int temperature;
    int num_moons;
} StarSystem;

// Galaxy properties
typedef struct {
    int width;
    int height;
    int num_stars;
    StarSystem **stars;
} Galaxy;

// Seed random number generator
void initRand() {
    srand(time(NULL));
}

// Generate a random star system
StarSystem *genStarSystem() {
    StarSystem *system = malloc(sizeof(StarSystem));

    system->type = rand() % 4;
    system->name = malloc(10);
    sprintf(system->name, "Sys%d", rand());
    system->radius = rand() % 1000000;
    system->mass = rand() % 1000000000;
    system->temperature = rand() % 10000;
    system->num_moons = rand() % 10;

    return system;
}

// Generate a galaxy
Galaxy *genGalaxy(int width, int height) {
    Galaxy *galaxy = malloc(sizeof(Galaxy));

    galaxy->width = width;
    galaxy->height = height;
    galaxy->num_stars = rand() % 100;
    galaxy->stars = malloc(galaxy->num_stars * sizeof(StarSystem *));

    for (int i = 0; i < galaxy->num_stars; i++) {
        galaxy->stars[i] = genStarSystem();
    }

    return galaxy;
}

// Print a star system
void printStarSystem(StarSystem *system) {
    printf("%s (%d, %d, %d, %d, %d)\n", system->name, system->type, system->radius, system->mass, system->temperature, system->num_moons);
}

// Print a galaxy
void printGalaxy(Galaxy *galaxy) {
    for (int i = 0; i < galaxy->num_stars; i++) {
        printStarSystem(galaxy->stars[i]);
    }
}

// Free a star system
void freeStarSystem(StarSystem *system) {
    free(system->name);
    free(system);
}

// Free a galaxy
void freeGalaxy(Galaxy *galaxy) {
    for (int i = 0; i < galaxy->num_stars; i++) {
        freeStarSystem(galaxy->stars[i]);
    }
    free(galaxy->stars);
    free(galaxy);
}

// Main function
int main() {
    initRand();

    Galaxy *galaxy = genGalaxy(10, 10);

    printGalaxy(galaxy);

    freeGalaxy(galaxy);

    return 0;
}