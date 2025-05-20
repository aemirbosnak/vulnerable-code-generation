//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass; // Mass of the planet (kg)
    double radius; // Radius of the planet (m)
    double x, y, z; // Position of the planet (m)
    double vx, vy, vz; // Velocity of the planet (m/s)
} Planet;

typedef struct {
    int num_planets; // Number of planets in the simulation
    Planet *planets; // Array of planets
} SolarSystem;

// Initialize the solar system with a given number of planets
void init_solar_system(SolarSystem *solar_system, int num_planets) {
    solar_system->num_planets = num_planets;
    solar_system->planets = malloc(sizeof(Planet) * num_planets);

    // Initialize each planet with random mass, radius, and position
    for (int i = 0; i < num_planets; i++) {
        solar_system->planets[i].mass = (double)rand() / RAND_MAX * 1e24;
        solar_system->planets[i].radius = (double)rand() / RAND_MAX * 1e6;
        solar_system->planets[i].x = (double)rand() / RAND_MAX * 1e12;
        solar_system->planets[i].y = (double)rand() / RAND_MAX * 1e12;
        solar_system->planets[i].z = (double)rand() / RAND_MAX * 1e12;

        // Initialize each planet with zero velocity
        solar_system->planets[i].vx = 0.0;
        solar_system->planets[i].vy = 0.0;
        solar_system->planets[i].vz = 0.0;
    }
}

// Calculate the gravitational force between two planets
void calculate_gravitational_force(Planet *planet1, Planet *planet2, double *fx, double *fy, double *fz) {
    // Calculate the distance between the two planets
    double dx = planet2->x - planet1->x;
    double dy = planet2->y - planet1->y;
    double dz = planet2->z - planet1->z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);

    // Calculate the gravitational force between the two planets
    *fx = G * planet1->mass * planet2->mass * dx / (r * r * r);
    *fy = G * planet1->mass * planet2->mass * dy / (r * r * r);
    *fz = G * planet1->mass * planet2->mass * dz / (r * r * r);
}

// Update the velocities and positions of the planets in the solar system
void update_solar_system(SolarSystem *solar_system, double dt) {
    // Calculate the gravitational force between each pair of planets
    for (int i = 0; i < solar_system->num_planets; i++) {
        for (int j = i + 1; j < solar_system->num_planets; j++) {
            double fx, fy, fz;
            calculate_gravitational_force(&solar_system->planets[i], &solar_system->planets[j], &fx, &fy, &fz);

            // Update the velocities of the two planets
            solar_system->planets[i].vx += dt * fx / solar_system->planets[i].mass;
            solar_system->planets[i].vy += dt * fy / solar_system->planets[i].mass;
            solar_system->planets[i].vz += dt * fz / solar_system->planets[i].mass;

            solar_system->planets[j].vx -= dt * fx / solar_system->planets[j].mass;
            solar_system->planets[j].vy -= dt * fy / solar_system->planets[j].mass;
            solar_system->planets[j].vz -= dt * fz / solar_system->planets[j].mass;
        }
    }

    // Update the positions of the planets
    for (int i = 0; i < solar_system->num_planets; i++) {
        solar_system->planets[i].x += dt * solar_system->planets[i].vx;
        solar_system->planets[i].y += dt * solar_system->planets[i].vy;
        solar_system->planets[i].z += dt * solar_system->planets[i].vz;
    }
}



int main() {
    // Initialize the solar system with 10 planets
    SolarSystem solar_system;
    init_solar_system(&solar_system, 10);

    // Simulate the solar system for 1000 time steps
    double dt = 1e3; // Timestep (s)
    for (int i = 0; i < 1000; i++) {
        update_solar_system(&solar_system, dt);
    }

    // Print the positions of the planets
    for (int i = 0; i < solar_system.num_planets; i++) {
        printf("Planet %d: (%.2f, %.2f, %.2f)\n", i, solar_system.planets[i].x, solar_system.planets[i].y, solar_system.planets[i].z);
    }

    // Free the memory allocated for the planets
    free(solar_system.planets);

    return 0;
}