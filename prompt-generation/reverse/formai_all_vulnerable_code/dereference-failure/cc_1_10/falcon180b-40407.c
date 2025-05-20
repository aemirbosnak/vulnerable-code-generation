//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define some constants
#define G 6.674e-11 // Gravitational constant
#define E 1.602e-19 // Electric charge
#define PI 3.14159265358979323846 // Pi

// Define some functions
void simulate_universe() {
    int num_particles = 1000;
    double *positions = malloc(num_particles * sizeof(double));
    double *velocities = malloc(num_particles * sizeof(double));
    double *masses = malloc(num_particles * sizeof(double));
    double *charges = malloc(num_particles * sizeof(double));

    // Initialize the particles
    for (int i = 0; i < num_particles; i++) {
        positions[i] = rand() % 1000;
        velocities[i] = rand() % 1000;
        masses[i] = rand() % 1000;
        charges[i] = rand() % 1000;
    }

    // Simulate the universe
    for (int i = 0; i < 1000; i++) {
        // Calculate the gravitational force
        for (int j = 0; j < num_particles; j++) {
            double dx = positions[j] - positions[i];
            double dy = velocities[j] - velocities[i];
            double r = sqrt(dx*dx + dy*dy);
            double f = G * masses[i] * masses[j] / pow(r, 2);
            velocities[i] += f * dx / masses[i];
            velocities[j] -= f * dx / masses[j];
        }

        // Calculate the electric force
        for (int j = 0; j < num_particles; j++) {
            double dx = positions[j] - positions[i];
            double dy = velocities[j] - velocities[i];
            double r = sqrt(dx*dx + dy*dy);
            double f = E * charges[i] * charges[j] / pow(r, 2);
            velocities[i] += f * dx / masses[i];
            velocities[j] -= f * dx / masses[j];
        }

        // Update the positions
        for (int j = 0; j < num_particles; j++) {
            positions[j] += velocities[j];
        }
    }

    // Free the memory
    free(positions);
    free(velocities);
    free(masses);
    free(charges);
}

int main() {
    srand(time(NULL));
    simulate_universe();
    return 0;
}