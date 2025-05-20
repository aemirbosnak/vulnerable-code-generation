//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Gravitational constant
const double G = 6.67408e-11;

// Mass of the Earth in kg
const double EARTH_MASS = 5.972e24;

// Radius of the Earth in meters
const double EARTH_RADIUS = 6.371e6;

// Time step in seconds
const double DT = 1.0;

// Number of particles
const int N = 1000;

// Define a particle
typedef struct {
    double x, y, z; // Position in meters
    double vx, vy, vz; // Velocity in meters per second
    double m; // Mass in kilograms
} particle;

// Initialize the particles
void init_particles(particle *p) {
    for (int i = 0; i < N; i++) {
        // Generate a random position within the Earth's radius
        p[i].x = (drand48() - 0.5) * EARTH_RADIUS;
        p[i].y = (drand48() - 0.5) * EARTH_RADIUS;
        p[i].z = (drand48() - 0.5) * EARTH_RADIUS;

        // Generate a random velocity
        p[i].vx = (drand48() - 0.5) * 100;
        p[i].vy = (drand48() - 0.5) * 100;
        p[i].vz = (drand48() - 0.5) * 100;

        // Set the mass to 1 kg
        p[i].m = 1.0;
    }
}

// Calculate the force on a particle due to gravity
void calc_force(particle *p, double *fx, double *fy, double *fz) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Calculate the distance between the particles
            double dx = p[i].x - p[j].x;
            double dy = p[i].y - p[j].y;
            double dz = p[i].z - p[j].z;
            double r = sqrt(dx*dx + dy*dy + dz*dz);

            // Calculate the force
            double f = G * p[i].m * p[j].m / (r*r);

            // Add the force to the particle
            fx[i] += f * dx / r;
            fy[i] += f * dy / r;
            fz[i] += f * dz / r;
        }
    }
}

// Update the positions and velocities of the particles
void update_particles(particle *p, double *fx, double *fy, double *fz) {
    for (int i = 0; i < N; i++) {
        // Update the position
        p[i].x += p[i].vx * DT;
        p[i].y += p[i].vy * DT;
        p[i].z += p[i].vz * DT;

        // Update the velocity
        p[i].vx += fx[i] * DT / p[i].m;
        p[i].vy += fy[i] * DT / p[i].m;
        p[i].vz += fz[i] * DT / p[i].m;
    }
}

// Main function
int main() {
    // Allocate memory for the particles
    particle *p = malloc(N * sizeof(particle));

    // Initialize the particles
    init_particles(p);

    // Allocate memory for the forces
    double *fx = malloc(N * sizeof(double));
    double *fy = malloc(N * sizeof(double));
    double *fz = malloc(N * sizeof(double));

    // Main simulation loop
    for (int t = 0; t < 1000; t++) {
        // Calculate the force on each particle
        calc_force(p, fx, fy, fz);

        // Update the positions and velocities of the particles
        update_particles(p, fx, fy, fz);
    }

    // Free the memory
    free(p);
    free(fx);
    free(fy);
    free(fz);

    return 0;
}