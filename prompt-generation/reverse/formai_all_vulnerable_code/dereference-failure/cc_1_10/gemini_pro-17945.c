//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.67408e-11 // m^3 kg^-1 s^-2

// Define the mass of the Earth
#define M_EARTH 5.972e24 // kg

// Define the radius of the Earth
#define R_EARTH 6.371e6 // m

// Define the number of planets
#define N_PLANETS 100

// Define the planet's properties
typedef struct {
    double mass; // kg
    double radius; // m
    double x; // m
    double y; // m
    double z; // m
    double vx; // m/s
    double vy; // m/s
    double vz; // m/s
} Planet;

// Initialize the planets
void initializePlanets(Planet planets[], int n) {
    for (int i = 0; i < n; i++) {
        planets[i].mass = (double)rand() / (double)RAND_MAX * 1e24; // kg
        planets[i].radius = (double)rand() / (double)RAND_MAX * 1e6; // m
        planets[i].x = (double)rand() / (double)RAND_MAX * 1e12; // m
        planets[i].y = (double)rand() / (double)RAND_MAX * 1e12; // m
        planets[i].z = (double)rand() / (double)RAND_MAX * 1e12; // m
        planets[i].vx = (double)rand() / (double)RAND_MAX * 1e3; // m/s
        planets[i].vy = (double)rand() / (double)RAND_MAX * 1e3; // m/s
        planets[i].vz = (double)rand() / (double)RAND_MAX * 1e3; // m/s
    }
}

// Calculate the gravitational force between two planets
void calculateGravitationalForce(Planet p1, Planet p2, double *fx, double *fy, double *fz) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * p1.mass * p2.mass / (r * r);
    *fx = f * dx / r;
    *fy = f * dy / r;
    *fz = f * dz / r;
}

// Update the planets' positions and velocities
void updatePlanets(Planet planets[], int n, double dt) {
    for (int i = 0; i < n; i++) {
        double fx = 0.0;
        double fy = 0.0;
        double fz = 0.0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            calculateGravitationalForce(planets[i], planets[j], &fx, &fy, &fz);
        }
        planets[i].vx += fx * dt / planets[i].mass;
        planets[i].vy += fy * dt / planets[i].mass;
        planets[i].vz += fz * dt / planets[i].mass;
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
        planets[i].z += planets[i].vz * dt;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified the number of planets
    if (argc != 2) {
        printf("Usage: %s <number of planets>\n", argv[0]);
        return 1;
    }

    // Get the number of planets from the user
    int n = atoi(argv[1]);

    // Initialize the planets
    Planet planets[n];
    initializePlanets(planets, n);

    // Simulate the planets' motion for 10000 time steps
    double dt = 1e3; // s
    for (int i = 0; i < 10000; i++) {
        updatePlanets(planets, n, dt);
    }

    // Print the planets' positions and velocities
    for (int i = 0; i < n; i++) {
        printf("Planet %d:\n", i);
        printf("  Position: (%f, %f, %f) m\n", planets[i].x, planets[i].y, planets[i].z);
        printf("  Velocity: (%f, %f, %f) m/s\n", planets[i].vx, planets[i].vy, planets[i].vz);
    }

    return 0;
}