//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass;
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
} Planet;

// Create a planet
Planet *createPlanet(double mass, double x, double y, double z, double vx, double vy, double vz) {
    Planet *planet = malloc(sizeof(Planet));
    planet->mass = mass;
    planet->x = x;
    planet->y = y;
    planet->z = z;
    planet->vx = vx;
    planet->vy = vy;
    planet->vz = vz;
    return planet;
}

// Free a planet
void freePlanet(Planet *planet) {
    free(planet);
}

// Calculate the force between two planets
void calculateForce(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * p1->mass * p2->mass / (r * r);
    p1->vx += f * dx / r;
    p1->vy += f * dy / r;
    p1->vz += f * dz / r;
    p2->vx -= f * dx / r;
    p2->vy -= f * dy / r;
    p2->vz -= f * dz / r;
}

// Update the position and velocity of a planet
void updatePlanet(Planet *planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
    planet->z += planet->vz * dt;
}

// Simulate the motion of a system of planets
void simulate(Planet *planets[], int numPlanets, double dt) {
    for (int i = 0; i < numPlanets; i++) {
        for (int j = i + 1; j < numPlanets; j++) {
            calculateForce(planets[i], planets[j]);
        }
    }
    for (int i = 0; i < numPlanets; i++) {
        updatePlanet(planets[i], dt);
    }
}

// Print the position and velocity of a planet
void printPlanet(Planet *planet) {
    printf("Planet:\n");
    printf("  Mass: %.2f\n", planet->mass);
    printf("  Position: (%.2f, %.2f, %.2f)\n", planet->x, planet->y, planet->z);
    printf("  Velocity: (%.2f, %.2f, %.2f)\n", planet->vx, planet->vy, planet->vz);
}

// Main function
int main() {
    // Create a system of planets
    Planet *planets[] = {
        createPlanet(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0), // Sun
        createPlanet(0.000003003, 0.3871, 0.0, 0.0, 0.0, 12.44, 0.0), // Mercury
        createPlanet(0.000003229, 0.7233, 0.0, 0.0, 0.0, 21.74, 0.0), // Venus
        createPlanet(0.000005974, 1.0000, 0.0, 0.0, 0.0, 29.78, 0.0), // Earth
        createPlanet(0.000000330, 1.5237, 0.0, 0.0, 0.0, 24.08, 0.0), // Mars
        createPlanet(0.000018982, 5.2033, 0.0, 0.0, 0.0, 13.07, 0.0), // Jupiter
        createPlanet(0.000056853, 9.5370, 0.0, 0.0, 0.0, 9.69, 0.0), // Saturn
        createPlanet(0.000086861, 19.1914, 0.0, 0.0, 0.0, 6.83, 0.0), // Uranus
        createPlanet(0.000102441, 30.0689, 0.0, 0.0, 0.0, 5.43, 0.0), // Neptune
    };
    int numPlanets = sizeof(planets) / sizeof(planets[0]);

    // Simulate the motion of the planets
    double dt = 1000; // Time step (seconds)
    for (int i = 0; i < 10000; i++) {
        simulate(planets, numPlanets, dt);
    }

    // Print the position and velocity of each planet
    for (int i = 0; i < numPlanets; i++) {
        printPlanet(planets[i]);
    }

    // Free the planets
    for (int i = 0; i < numPlanets; i++) {
        freePlanet(planets[i]);
    }

    return 0;
}