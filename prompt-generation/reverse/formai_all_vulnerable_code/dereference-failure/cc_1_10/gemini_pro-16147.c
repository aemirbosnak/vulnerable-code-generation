//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the universe.
#define UNIVERSE_SIZE 100

// Define the possible types of celestial bodies.
#define CELESTIAL_BODY_TYPE_STAR 0
#define CELESTIAL_BODY_TYPE_PLANET 1
#define CELESTIAL_BODY_TYPE_MOON 2

// Define the structure of a celestial body.
typedef struct {
    int type;
    char *name;
    double mass;
    double radius;
    double distance_from_sun;
    double orbital_period;
} celestial_body;

// Create a new celestial body.
celestial_body *create_celestial_body(int type, char *name, double mass, double radius, double distance_from_sun, double orbital_period) {
    celestial_body *body = malloc(sizeof(celestial_body));
    body->type = type;
    body->name = name;
    body->mass = mass;
    body->radius = radius;
    body->distance_from_sun = distance_from_sun;
    body->orbital_period = orbital_period;
    return body;
}

// Generate a random universe.
void generate_universe(celestial_body *universe[UNIVERSE_SIZE]) {
    // Set the random seed.
    srand(time(NULL));

    // Create the sun.
    universe[0] = create_celestial_body(CELESTIAL_BODY_TYPE_STAR, "Sun", 1.989e30, 6.9634e8, 0.0, 0.0);

    // Create the planets.
    for (int i = 1; i < 9; i++) {
        char *name = malloc(10);
        sprintf(name, "Planet %d", i);
        double mass = (rand() % 1000000000000000000) / 1e24;
        double radius = (rand() % 1000000000) / 1e6;
        double distance_from_sun = (rand() % 1000000000000) / 1e12;
        double orbital_period = (rand() % 1000000000) / 1e6;
        universe[i] = create_celestial_body(CELESTIAL_BODY_TYPE_PLANET, name, mass, radius, distance_from_sun, orbital_period);
    }

    // Create the moons.
    for (int i = 9; i < UNIVERSE_SIZE; i++) {
        char *name = malloc(10);
        sprintf(name, "Moon %d", i - 8);
        double mass = (rand() % 1000000000000000) / 1e21;
        double radius = (rand() % 1000000000) / 1e6;
        double distance_from_sun = (rand() % 1000000000000) / 1e12;
        double orbital_period = (rand() % 1000000000) / 1e6;
        universe[i] = create_celestial_body(CELESTIAL_BODY_TYPE_MOON, name, mass, radius, distance_from_sun, orbital_period);
    }
}

// Print the universe.
void print_universe(celestial_body *universe[UNIVERSE_SIZE]) {
    for (int i = 0; i < UNIVERSE_SIZE; i++) {
        printf("%s\n", universe[i]->name);
        printf("  Type: %d\n", universe[i]->type);
        printf("  Mass: %e kg\n", universe[i]->mass);
        printf("  Radius: %e km\n", universe[i]->radius);
        printf("  Distance from sun: %e km\n", universe[i]->distance_from_sun);
        printf("  Orbital period: %e years\n", universe[i]->orbital_period);
        printf("\n");
    }
}

// Free the universe.
void free_universe(celestial_body *universe[UNIVERSE_SIZE]) {
    for (int i = 0; i < UNIVERSE_SIZE; i++) {
        free(universe[i]);
    }
}

// Main function.
int main() {
    // Create the universe.
    celestial_body *universe[UNIVERSE_SIZE];
    generate_universe(universe);

    // Print the universe.
    print_universe(universe);

    // Free the universe.
    free_universe(universe);

    return 0;
}