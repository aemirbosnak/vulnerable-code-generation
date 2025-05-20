//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

// Define the structure of a star system.
typedef struct starSystem {
    char *name;             // The name of the star system.
    int numPlanets;        // The number of planets in the star system.
    struct planet *planets; // An array of planets in the star system.
} starSystem;

// Define the structure of a planet.
typedef struct planet {
    char *name;             // The name of the planet.
    double mass;            // The mass of the planet (in Earth masses).
    double radius;          // The radius of the planet (in Earth radii).
    double distance;        // The distance of the planet from its star (in AU).
    double eccentricity;    // The eccentricity of the planet's orbit.
    double inclination;     // The inclination of the planet's orbit (in degrees).
    double semiMajorAxis;  // The semi-major axis of the planet's orbit (in AU).
} planet;

// Generate a random star system.
starSystem *generateStarSystem() {
    // Create a new star system.
    starSystem *starSystem = malloc(sizeof(starSystem));

    // Generate a random name for the star system.
    starSystem->name = malloc(10);
    for (int i = 0; i < 10; i++) {
        starSystem->name[i] = 'a' + rand() % 26;
    }

    // Generate a random number of planets in the star system.
    starSystem->numPlanets = rand() % 10;

    // Create an array of planets in the star system.
    starSystem->planets = malloc(starSystem->numPlanets * sizeof(planet));

    // Generate random planets for the star system.
    for (int i = 0; i < starSystem->numPlanets; i++) {
        // Generate a random name for the planet.
        starSystem->planets[i].name = malloc(10);
        for (int j = 0; j < 10; j++) {
            starSystem->planets[i].name[j] = 'a' + rand() % 26;
        }

        // Generate a random mass for the planet.
        starSystem->planets[i].mass = rand() % 10;

        // Generate a random radius for the planet.
        starSystem->planets[i].radius = rand() % 10;

        // Generate a random distance for the planet.
        starSystem->planets[i].distance = rand() % 10;

        // Generate a random eccentricity for the planet.
        starSystem->planets[i].eccentricity = rand() / RAND_MAX;

        // Generate a random inclination for the planet.
        starSystem->planets[i].inclination = rand() / RAND_MAX;

        // Generate a random semi-major axis for the planet.
        starSystem->planets[i].semiMajorAxis = rand() % 10;
    }

    // Return the star system.
    return starSystem;
}

// Print a star system.
void printStarSystem(starSystem *starSystem) {
    // Print the name of the star system.
    printf("Name: %s\n", starSystem->name);

    // Print the number of planets in the star system.
    printf("Number of planets: %d\n", starSystem->numPlanets);

    // Print the planets in the star system.
    for (int i = 0; i < starSystem->numPlanets; i++) {
        // Print the name of the planet.
        printf("Planet %d: %s\n", i + 1, starSystem->planets[i].name);

        // Print the mass of the planet.
        printf("Mass: %f Earth masses\n", starSystem->planets[i].mass);

        // Print the radius of the planet.
        printf("Radius: %f Earth radii\n", starSystem->planets[i].radius);

        // Print the distance of the planet from its star.
        printf("Distance: %f AU\n", starSystem->planets[i].distance);

        // Print the eccentricity of the planet's orbit.
        printf("Eccentricity: %f\n", starSystem->planets[i].eccentricity);

        // Print the inclination of the planet's orbit.
        printf("Inclination: %f degrees\n", starSystem->planets[i].inclination);

        // Print the semi-major axis of the planet's orbit.
        printf("Semi-major axis: %f AU\n", starSystem->planets[i].semiMajorAxis);

        // Print a newline.
        printf("\n");
    }
}

// Free a star system.
void freeStarSystem(starSystem *starSystem) {
    // Free the name of the star system.
    free(starSystem->name);

    // Free the planets in the star system.
    for (int i = 0; i < starSystem->numPlanets; i++) {
        // Free the name of the planet.
        free(starSystem->planets[i].name);
    }
    free(starSystem->planets);

    // Free the star system.
    free(starSystem);
}

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Generate a random star system.
    starSystem *starSystem = generateStarSystem();

    // Print the star system.
    printStarSystem(starSystem);

    // Free the star system.
    freeStarSystem(starSystem);

    return 0;
}