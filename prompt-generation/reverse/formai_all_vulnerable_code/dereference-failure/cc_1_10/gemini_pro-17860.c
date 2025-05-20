//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
// Embark on a cosmic odyssey in serene solitude.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Celestial bodies.
typedef struct {
    char name[32];
    double mass;
    double radius;
    double temperature;
} CelestialBody;

// Galactic map.
CelestialBody *map;
int mapSize;

// Initialize the galactic map.
void initMap() {
    srand(time(NULL));

    mapSize = 100;
    map = malloc(mapSize * sizeof(CelestialBody));

    for (int i = 0; i < mapSize; i++) {
        sprintf(map[i].name, "Celestial Body %d", i);
        map[i].mass = (rand() % 1000000) / 1000.0;
        map[i].radius = (rand() % 1000000) / 1000.0;
        map[i].temperature = (rand() % 1000000) / 1000.0;
    }
}

// Explore the cosmic abyss.
void explore() {
    int currentLocation = rand() % mapSize;

    while (currentLocation != -1) {
        CelestialBody *currentBody = &map[currentLocation];

        printf("Approaching %s...\n", currentBody->name);
        printf("Mass: %.3lf solar masses\n", currentBody->mass);
        printf("Radius: %.3lf solar radii\n", currentBody->radius);
        printf("Temperature: %.3lf Kelvin\n", currentBody->temperature);

        printf("Input a location (0-%d), or press -1 to exit: ", mapSize - 1);
        scanf("%d", &currentLocation);
    }
}

int main() {
    initMap();
    explore();
    return 0;
}