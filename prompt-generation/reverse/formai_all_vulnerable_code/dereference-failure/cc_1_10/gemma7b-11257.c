//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of planets in the universe
#define MAX_PLANETS 1000

// Define the structure of a planet
typedef struct Planet {
    char name[20];
    int x, y, z;
    int population;
    struct Planet* next;
} Planet;

// Function to create a new planet
Planet* CreatePlanet(char* name, int x, int y, int z, int population) {
    Planet* newPlanet = malloc(sizeof(Planet));
    strcpy(newPlanet->name, name);
    newPlanet->x = x;
    newPlanet->y = y;
    newPlanet->z = z;
    newPlanet->population = population;
    newPlanet->next = NULL;
    return newPlanet;
}

// Function to add a new planet to the universe
void AddPlanet(Planet* universe, char* name, int x, int y, int z, int population) {
    Planet* newPlanet = CreatePlanet(name, x, y, z, population);
    if (universe == NULL) {
        universe = newPlanet;
    } else {
        universe->next = newPlanet;
        universe = newPlanet;
    }
}

// Function to generate the universe
void GenerateUniverse(Planet* universe) {
    // Seed the random number generator
    srand(time(NULL));

    // Create a number of planets
    for (int i = 0; i < MAX_PLANETS; i++) {
        AddPlanet(universe, "Planet", rand() % 1000, rand() % 1000, rand() % 1000, rand() % 10000);
    }
}

int main() {
    // Create the universe
    Planet* universe = NULL;

    // Generate the universe
    GenerateUniverse(universe);

    // Print the planets
    Planet* currentPlanet = universe;
    while (currentPlanet) {
        printf("Name: %s\n", currentPlanet->name);
        printf("x: %d, y: %d, z: %d\n", currentPlanet->x, currentPlanet->y, currentPlanet->z);
        printf("Population: %d\n", currentPlanet->population);
        printf("\n");
        currentPlanet = currentPlanet->next;
    }

    return 0;
}