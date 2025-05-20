//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <omp.h>

#define G 6.674e-11 // Gravitational constant (m^3 kg^-1 s^-2)

typedef struct {
    double mass; // Mass (kg)
    double x;    // X-coordinate (m)
    double y;    // Y-coordinate (m)
    double vx;   // X-velocity (m/s)
    double vy;   // Y-velocity (m/s)
} Planet;

typedef struct {
    int num_planets;  // Number of planets
    Planet *planets;  // Array of Planet structures
} PlanetSystem;

// Function to calculate the force between two planets
void calculateForce(PlanetSystem *system, int i, int j) {
    double dx = system->planets[j].x - system->planets[i].x;
    double dy = system->planets[j].y - system->planets[i].y;
    double r = sqrt(dx * dx + dy * dy);
    double force = G * system->planets[i].mass * system->planets[j].mass / (r * r);

    // Calculate the direction of the force
    double theta = atan2(dy, dx);

    // Add the force to the planets
    system->planets[i].vx += force * cos(theta) / system->planets[i].mass;
    system->planets[i].vy += force * sin(theta) / system->planets[i].mass;
}

// Function to update the positions and velocities of the planets
void updatePlanets(PlanetSystem *system, double dt) {
    // Calculate the force between each pair of planets
    for (int i = 0; i < system->num_planets; i++) {
        for (int j = i + 1; j < system->num_planets; j++) {
            calculateForce(system, i, j);
        }
    }

    // Update the positions and velocities of the planets
    for (int i = 0; i < system->num_planets; i++) {
        system->planets[i].x += system->planets[i].vx * dt;
        system->planets[i].y += system->planets[i].vy * dt;
    }
}

// Function to print the positions and velocities of the planets
void printPlanets(PlanetSystem *system) {
    for (int i = 0; i < system->num_planets; i++) {
        printf("Planet %d: (%f, %f) v=(%f, %f)\n", i, system->planets[i].x, system->planets[i].y, system->planets[i].vx, system->planets[i].vy);
    }
}

int main() {
    // Create a planet system with 3 planets
    PlanetSystem system;
    system.num_planets = 3;
    system.planets = malloc(sizeof(Planet) * system.num_planets);
    system.planets[0].mass=1e24;
    system.planets[0].x = 0.;
    system.planets[0].y = 0.;
    system.planets[0].vx = 0.;
    system.planets[0].vy = 0.;
    system.planets[1].mass=5e23;
    system.planets[1].x=1e11;
    system.planets[1].y=0.;
    system.planets[1].vx=0.;
    system.planets[1].vy=100.;
    system.planets[2].mass=1e22;
    system.planets[2].x=-1e11;
    system.planets[2].y=0.;
    system.planets[2].vx=0.;
    system.planets[2].vy=-100.;

    // Simulate the planet system for 10000 time steps
    double dt = 1000.;
    for (int i = 0; i < 10000; i++) {
        updatePlanets(&system, dt);
    }

    // Print the final positions and velocities of the planets
    printPlanets(&system);

    return 0;
}