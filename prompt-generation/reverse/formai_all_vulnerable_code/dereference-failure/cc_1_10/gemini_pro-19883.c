//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
// Embark on a quest through the vast realms of Procedural Space

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define celestial bodies and their properties
typedef struct Star {
    char *name;
    float mass, luminosity;
    int planets;
} Star;

typedef struct Planet {
    char *name;
    float mass, radius, distance;
    int moons;
} Planet;

typedef struct SolarSystem {
    Star star;
    Planet *planets;
    int num_planets;
} SolarSystem;

// Generate a random universe with stars and planets
SolarSystem *generate_universe(int num_stars, int max_planets) {
    // Allocate memory for the universe
    SolarSystem *universe = malloc(sizeof(SolarSystem) * num_stars);

    // Seed random number generator
    srand(time(NULL));

    // Create each star in the universe
    for (int i = 0; i < num_stars; i++) {
        // Generate star properties
        universe[i].star.name = malloc(20);
        sprintf(universe[i].star.name, "Star %d", i + 1);
        universe[i].star.mass = (float)rand() / RAND_MAX * 1000; // Solar masses
        universe[i].star.luminosity = (float)rand() / RAND_MAX * 10000; // Solar luminosities
        universe[i].star.planets = rand() % max_planets + 1; // Number of planets

        // Allocate memory for planets in this star system
        universe[i].planets = malloc(sizeof(Planet) * universe[i].star.planets);

        // Create each planet in this star system
        for (int j = 0; j < universe[i].star.planets; j++) {
            // Generate planet properties
            universe[i].planets[j].name = malloc(20);
            sprintf(universe[i].planets[j].name, "Planet %d", j + 1);
            universe[i].planets[j].mass = (float)rand() / RAND_MAX * 100; // Earth masses
            universe[i].planets[j].radius = (float)rand() / RAND_MAX * 10000; // Earth radii
            universe[i].planets[j].distance = (float)rand() / RAND_MAX * 100000; // AU
            universe[i].planets[j].moons = rand() % 10; // Number of moons
        }
    }

    return universe;
}

// Print information about a star system
void print_solar_system(SolarSystem *system) {
    printf("Star: %s\n", system->star.name);
    printf("Mass: %.2f solar masses\n", system->star.mass);
    printf("Luminosity: %.2f solar luminosities\n", system->star.luminosity);
    printf("Planets: %d\n", system->star.planets);
    for (int i = 0; i < system->star.planets; i++) {
        printf("\tPlanet: %s\n", system->planets[i].name);
        printf("\t\tMass: %.2f Earth masses\n", system->planets[i].mass);
        printf("\t\tRadius: %.2f Earth radii\n", system->planets[i].radius);
        printf("\t\tDistance: %.2f AU\n", system->planets[i].distance);
        printf("\t\tMoons: %d\n", system->planets[i].moons);
    }
}

// Free the memory allocated for the universe
void free_universe(SolarSystem *universe, int num_stars) {
    for (int i = 0; i < num_stars; i++) {
        free(universe[i].star.name);
        for (int j = 0; j < universe[i].star.planets; j++) {
            free(universe[i].planets[j].name);
        }
        free(universe[i].planets);
    }
    free(universe);
}

int main() {
    // Generate a universe with 10 stars and a maximum of 5 planets per star
    SolarSystem *universe = generate_universe(10, 5);

    // Print information about each star system
    for (int i = 0; i < 10; i++) {
        print_solar_system(&universe[i]);
        printf("\n");
    }

    // Free the memory allocated for the universe
    free_universe(universe, 10);

    return 0;
}