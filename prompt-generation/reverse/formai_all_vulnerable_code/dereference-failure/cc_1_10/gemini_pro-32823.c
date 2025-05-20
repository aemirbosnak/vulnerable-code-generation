//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// Simulation parameters
#define NUM_PLANETS 100
#define GRAVITATIONAL_CONSTANT 1e-3
#define TIMESTEP 0.01
#define SIMULATION_TIME 100

// Planet structure
typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Planet;

// Initialize planets
void init_planets(Planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].mass = rand() % 1000;
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 1000;
        planets[i].z = rand() % 1000;
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].vz = 0;
    }
}

// Calculate gravitational force between two planets
void calculate_force(Planet *planets, int i, int j) {
    double dx = planets[j].x - planets[i].x;
    double dy = planets[j].y - planets[i].y;
    double dz = planets[j].z - planets[i].z;

    double r2 = dx * dx + dy * dy + dz * dz;
    double r = sqrt(r2);

    double force = GRAVITATIONAL_CONSTANT * planets[i].mass * planets[j].mass / r2;

    // Update forces
    planets[i].vx -= force * dx / r;
    planets[i].vy -= force * dy / r;
    planets[i].vz -= force * dz / r;

    planets[j].vx += force * dx / r;
    planets[j].vy += force * dy / r;
    planets[j].vz += force * dz / r;
}

// Update planet positions
void update_positions(Planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * TIMESTEP;
        planets[i].y += planets[i].vy * TIMESTEP;
        planets[i].z += planets[i].vz * TIMESTEP;
    }
}

// Main simulation loop
int main() {
    // Initialize planets
    Planet *planets = malloc(sizeof(Planet) * NUM_PLANETS);
    init_planets(planets);

    // Run simulation
    for (double t = 0; t < SIMULATION_TIME; t += TIMESTEP) {
        // Calculate forces
        for (int i = 0; i < NUM_PLANETS; i++) {
            for (int j = i + 1; j < NUM_PLANETS; j++) {
                calculate_force(planets, i, j);
            }
        }

        // Update positions
        update_positions(planets);
    }

    // Print final planet positions
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("(%f, %f, %f)\n", planets[i].x, planets[i].y, planets[i].z);
    }

    // Free memory
    free(planets);

    return 0;
}