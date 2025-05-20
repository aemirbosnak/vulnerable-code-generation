//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_PLANETS 8

// Structure to represent a Planet
typedef struct {
    char name[20];
    float distanceFromSun; // in million kilometers
    float orbitalPeriod;    // in Earth days
    float radius;           // in kilometers
} Planet;

// Function to initialize planets
void initPlanets(Planet planets[]) {
    // Initialize each planet with name, distance from the Sun, orbital period, and radius
    Planet temp[NUM_PLANETS] = {
        {"Mercury", 57.91, 88, 2439.7},
        {"Venus", 108.2, 225, 6051.8},
        {"Earth", 149.6, 365.25, 6371.0},
        {"Mars", 227.9, 687, 3389.5},
        {"Jupiter", 778.3, 4331, 69911.0},
        {"Saturn", 1427.0, 10747, 58232.0},
        {"Uranus", 2871.0, 30589, 25362.0},
        {"Neptune", 4497.1, 59800, 24622.0}
    };
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i] = temp[i];
    }
}

// Function to simulate the orbits of planets
void simulateOrbits(Planet planets[]) {
    printf("Simulating the Solar System:\n");
    for (int day = 1; day <= 365; day++) {
        printf("\nDay %d:\n", day);
        for (int i = 0; i < NUM_PLANETS; i++) {
            // Calculate sunlight hours based on the day of the year
            // Rough estimate: longer years for outer planets
            float sunlightHours = (12.0 * (planets[i].orbitalPeriod / 365.0)) * (day % (int)(planets[i].orbitalPeriod));
            printf("%s is %0.2f million kilometers from the Sun. Daylight: %0.2f hours.\n", 
                planets[i].name, 
                planets[i].distanceFromSun, 
                sunlightHours);
        }
        usleep(500000); // Sleep for 0.5 seconds to simulate time passing
    }
}

int main() {
    Planet planets[NUM_PLANETS];

    // Initialize planets
    initPlanets(planets);

    // Start simulation
    simulateOrbits(planets);

    return 0;
}