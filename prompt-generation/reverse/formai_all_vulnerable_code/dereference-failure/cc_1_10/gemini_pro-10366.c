//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 100
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 200

// Define a planet structure
typedef struct Planet {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double distance;
    int type;
} Planet;

// Define the types of planets
enum PlanetType {
    PLANET_TYPE_NONE,
    PLANET_TYPE_GAS,
    PLANET_TYPE_ICE,
    PLANET_TYPE_ROCK
};

// Create a new planet
Planet* createPlanet(char* name, char* description, double distance, int type) {
    Planet* planet = malloc(sizeof(Planet));
    strncpy(planet->name, name, MAX_NAME_LENGTH);
    strncpy(planet->description, description, MAX_DESCRIPTION_LENGTH);
    planet->distance = distance;
    planet->type = type;
    return planet;
}

// Print the details of a planet
void printPlanet(Planet* planet) {
    printf("Name: %s\n", planet->name);
    printf("Description: %s\n", planet->description);
    printf("Distance: %f\n", planet->distance);
    switch (planet->type) {
        case PLANET_TYPE_NONE:
            printf("Type: None\n");
            break;
        case PLANET_TYPE_GAS:
            printf("Type: Gas\n");
            break;
        case PLANET_TYPE_ICE:
            printf("Type: Ice\n");
            break;
        case PLANET_TYPE_ROCK:
            printf("Type: Rock\n");
            break;
    }
    printf("\n");
}

// Generate a random planet
Planet* generateRandomPlanet() {
    char* names[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    char* descriptions[] = {
        "A rocky planet with a thin atmosphere.",
        "A hot, dense planet with a thick atmosphere.",
        "A blue planet with a thin atmosphere and liquid water.",
        "A red planet with a thin atmosphere and a dusty surface.",
        "A gas giant with a thick atmosphere.",
        "A gas giant with a thin atmosphere and a ring system.",
        "A gas giant with a thick atmosphere and a ring system.",
        "A gas giant with a thin atmosphere and a ring system.",
        "A dwarf planet with a thin atmosphere and a rocky surface."
    };
    int types[] = {PLANET_TYPE_ROCK, PLANET_TYPE_ROCK, PLANET_TYPE_ROCK, PLANET_TYPE_ROCK, PLANET_TYPE_GAS, PLANET_TYPE_GAS, PLANET_TYPE_GAS, PLANET_TYPE_GAS, PLANET_TYPE_NONE};

    int nameIndex = rand() % (sizeof(names) / sizeof(char*));
    int descriptionIndex = rand() % (sizeof(descriptions) / sizeof(char*));
    int typeIndex = rand() % (sizeof(types) / sizeof(int));

    return createPlanet(names[nameIndex], descriptions[descriptionIndex], rand() % 1000, types[typeIndex]);
}

// Create a list of planets
Planet** createPlanetList(int numPlanets) {
    Planet** planets = malloc(sizeof(Planet*) * numPlanets);
    for (int i = 0; i < numPlanets; i++) {
        planets[i] = generateRandomPlanet();
    }
    return planets;
}

// Print the list of planets
void printPlanetList(Planet** planets, int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        printPlanet(planets[i]);
    }
}

// Free the list of planets
void freePlanetList(Planet** planets, int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        free(planets[i]);
    }
    free(planets);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a list of planets
    Planet** planets = createPlanetList(MAX_PLANETS);

    // Print the list of planets
    printPlanetList(planets, MAX_PLANETS);

    // Free the list of planets
    freePlanetList(planets, MAX_PLANETS);

    return 0;
}