//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: puzzling
// A celestial puzzle of the solar system.
// Unravel the enigma to witness the cosmic dance.

#include <stdio.h>
#include <stdlib.h>

// Celestial bodies, an ethereal ensemble.
typedef struct {
    char * name;
    long long int mass;
    long long int x, y, z;
} Planet;

// The cosmic stage, where celestial bodies reside.
typedef struct {
    Planet * planets;
    int numPlanets;
} SolarSystem;

// Gravity's unwavering embrace, shaping celestial paths.
double gravity(Planet a, Planet b) {
    return 6.674e-11 * a.mass * b.mass / (a.x - b.x) / (a.x - b.x) + (a.y - b.y) / (a.y - b.y) + (a.z - b.z) / (a.z - b.z);
}

// Celestial mechanics, unraveling the enigmatic dance.
void movePlanets(SolarSystem * system, double dt) {
    for (int i = 0; i < system->numPlanets; i++) {
        Planet * planet = &system->planets[i];
        for (int j = 0; j < system->numPlanets; j++) {
            if (i == j) continue;
            Planet * otherPlanet = &system->planets[j];
            double force = gravity(*planet, *otherPlanet);
            planet->x += force * dt * (otherPlanet->x - planet->x) / (planet->mass + otherPlanet->mass);
            planet->y += force * dt * (otherPlanet->y - planet->y) / (planet->mass + otherPlanet->mass);
            planet->z += force * dt * (otherPlanet->z - planet->z) / (planet->mass + otherPlanet->mass);
        }
    }
}

// Unveiling the cosmic ballet, a celestial display.
void printSolarSystem(SolarSystem * system) {
    printf("Celestial Symphony:\n");
    for (int i = 0; i < system->numPlanets; i++) {
        Planet * planet = &system->planets[i];
        printf("%s (%.2lf, %.2lf, %.2lf)\n", planet->name, planet->x, planet->y, planet->z);
    }
}

// The genesis of our celestial ensemble.
void createSolarSystem(SolarSystem * system) {
    system->numPlanets = 8;
    system->planets = malloc(sizeof(Planet) * system->numPlanets);

    // Sun, the radiant heart of our system.
    system->planets[0].name = "Sun";
    system->planets[0].mass = 1.989e30;
    system->planets[0].x = 0;
    system->planets[0].y = 0;
    system->planets[0].z = 0;

    // Mercury, the fleet-footed messenger.
    system->planets[1].name = "Mercury";
    system->planets[1].mass = 0.33e24;
    system->planets[1].x = 5.79e10;
    system->planets[1].y = 0;
    system->planets[1].z = 0;

    // Venus, the veiled beauty.
    system->planets[2].name = "Venus";
    system->planets[2].mass = 4.87e24;
    system->planets[2].x = 1.08e11;
    system->planets[2].y = 0;
    system->planets[2].z = 0;

    // Earth, our vibrant abode.
    system->planets[3].name = "Earth";
    system->planets[3].mass = 5.97e24;
    system->planets[3].x = 1.50e11;
    system->planets[3].y = 0;
    system->planets[3].z = 0;

    // Mars, the crimson wanderer.
    system->planets[4].name = "Mars";
    system->planets[4].mass = 0.642e24;
    system->planets[4].x = 2.28e11;
    system->planets[4].y = 0;
    system->planets[4].z = 0;

    // Jupiter, the colossal giant.
    system->planets[5].name = "Jupiter";
    system->planets[5].mass = 1.899e27;
    system->planets[5].x = 7.78e11;
    system->planets[5].y = 0;
    system->planets[5].z = 0;

    // Saturn, the ringed enigma.
    system->planets[6].name = "Saturn";
    system->planets[6].mass = 5.68e26;
    system->planets[6].x = 1.43e12;
    system->planets[6].y = 0;
    system->planets[6].z = 0;

    // Uranus, the tilted world.
    system->planets[7].name = "Uranus";
    system->planets[7].mass = 8.68e25;
    system->planets[7].x = 2.87e12;
    system->planets[7].y = 0;
    system->planets[7].z = 0;
}

// The conductor's baton, orchestrating the celestial dance.
int main() {
    SolarSystem system;
    createSolarSystem(&system);
    for (int i = 0; i < 1000; i++) {
        movePlanets(&system, 1000);
    }
    printSolarSystem(&system);
    return 0;
}