//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Universe parameters
#define UNIVERSE_SIZE 1000 // in parsecs
#define NUM_STARS 1000
#define NUM_PLANETS 10000

// Star parameters
#define STAR_MASS_MIN 0.1 // in solar masses
#define STAR_MASS_MAX 100.0 // in solar masses
#define STAR_RADIUS_MIN 0.1 // in solar radii
#define STAR_RADIUS_MAX 100.0 // in solar radii
#define STAR_TEMPERATURE_MIN 2000 // in Kelvin
#define STAR_TEMPERATURE_MAX 50000 // in Kelvin

// Planet parameters
#define PLANET_MASS_MIN 0.001 // in Earth masses
#define PLANET_MASS_MAX 10.0 // in Earth masses
#define PLANET_RADIUS_MIN 0.1 // in Earth radii
#define PLANET_RADIUS_MAX 10.0 // in Earth radii
#define PLANET_TEMPERATURE_MIN 100 // in Kelvin
#define PLANET_TEMPERATURE_MAX 500 // in Kelvin

// Generate a random number between min and max
#define RAND(min, max) ((min) + (rand() / (RAND_MAX / ((max) - (min)))))

// Star structure
typedef struct {
    double mass; // in solar masses
    double radius; // in solar radii
    double temperature; // in Kelvin
    int num_planets; // number of planets orbiting the star
} star;

// Planet structure
typedef struct {
    double mass; // in Earth masses
    double radius; // in Earth radii
    double temperature; // in Kelvin
    double distance_from_star; // in AU
    double orbital_period; // in years
} planet;

// Universe structure
typedef struct {
    star *stars; // array of stars
    planet *planets; // array of planets
} universe;

// Create a new universe
universe *create_universe() {
    universe *u = malloc(sizeof(universe));
    u->stars = malloc(NUM_STARS * sizeof(star));
    u->planets = malloc(NUM_PLANETS * sizeof(planet));
    return u;
}

// Generate a random star
star generate_star() {
    star s;
    s.mass = RAND(STAR_MASS_MIN, STAR_MASS_MAX);
    s.radius = RAND(STAR_RADIUS_MIN, STAR_RADIUS_MAX);
    s.temperature = RAND(STAR_TEMPERATURE_MIN, STAR_TEMPERATURE_MAX);
    s.num_planets = 0;
    return s;
}

// Generate a random planet
planet generate_planet(star *star) {
    planet p;
    p.mass = RAND(PLANET_MASS_MIN, PLANET_MASS_MAX);
    p.radius = RAND(PLANET_RADIUS_MIN, PLANET_RADIUS_MAX);
    p.temperature = RAND(PLANET_TEMPERATURE_MIN, PLANET_TEMPERATURE_MAX);
    p.distance_from_star = RAND(0.1, 10.0); // in AU
    p.orbital_period = sqrt(pow(p.distance_from_star, 3) / star->mass); // in years
    return p;
}

// Populate the universe with stars and planets
void populate_universe(universe *u) {
    for (int i = 0; i < NUM_STARS; i++) {
        u->stars[i] = generate_star();
        for (int j = 0; j < u->stars[i].num_planets; j++) {
            u->planets[i * NUM_PLANETS + j] = generate_planet(&u->stars[i]);
        }
    }
}

// Print the universe to the console
void print_universe(universe *u) {
    for (int i = 0; i < NUM_STARS; i++) {
        printf("Star %d:\n", i + 1);
        printf("  Mass: %.2f solar masses\n", u->stars[i].mass);
        printf("  Radius: %.2f solar radii\n", u->stars[i].radius);
        printf("  Temperature: %.2f Kelvin\n", u->stars[i].temperature);
        printf("  Number of planets: %d\n", u->stars[i].num_planets);
        for (int j = 0; j < u->stars[i].num_planets; j++) {
            printf("  Planet %d:\n", j + 1);
            printf("    Mass: %.2f Earth masses\n", u->planets[i * NUM_PLANETS + j].mass);
            printf("    Radius: %.2f Earth radii\n", u->planets[i * NUM_PLANETS + j].radius);
            printf("    Temperature: %.2f Kelvin\n", u->planets[i * NUM_PLANETS + j].temperature);
            printf("    Distance from star: %.2f AU\n", u->planets[i * NUM_PLANETS + j].distance_from_star);
            printf("    Orbital period: %.2f years\n", u->planets[i * NUM_PLANETS + j].orbital_period);
        }
    }
}

// Free the memory allocated for the universe
void free_universe(universe *u) {
    free(u->stars);
    free(u->planets);
    free(u);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new universe
    universe *u = create_universe();

    // Populate the universe with stars and planets
    populate_universe(u);

    // Print the universe to the console
    print_universe(u);

    // Free the memory allocated for the universe
    free_universe(u);

    return 0;
}