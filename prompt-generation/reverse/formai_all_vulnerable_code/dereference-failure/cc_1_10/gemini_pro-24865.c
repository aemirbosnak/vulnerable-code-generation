//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defines the gravitational constant
#define G 6.674e-11

// Structure to represent a particle
typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double m; // Mass
} Particle;

// Function to calculate the force between two particles
void calculateForce(Particle *p1, Particle *p2) {
    // Calculate the distance between the particles
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    // Calculate the force using the gravitational constant
    double f = G * p1->m * p2->m / (r*r);

    // Calculate the unit vector in the direction of the force
    double ux = dx / r;
    double uy = dy / r;
    double uz = dz / r;

    // Calculate the force vector
    p1->vx += f * ux / p1->m;
    p1->vy += f * uy / p1->m;
    p1->vz += f * uz / p1->m;
    p2->vx -= f * ux / p2->m;
    p2->vy -= f * uy / p2->m;
    p2->vz -= f * uz / p2->m;
}

// Function to update the positions of the particles
void updatePositions(Particle *p, double dt) {
    // Update the positions of the particles using the velocity and time step
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// Main function
int main() {
    // Define the number of particles
    int n = 1000;

    // Allocate memory for the particles
    Particle *particles = malloc(n * sizeof(Particle));

    // Initialize the particles
    for (int i = 0; i < n; i++) {
        // Randomize the position of the particles within a cube of side length 100
        particles[i].x = (rand() / (double)RAND_MAX) * 100;
        particles[i].y = (rand() / (double)RAND_MAX) * 100;
        particles[i].z = (rand() / (double)RAND_MAX) * 100;

        // Randomize the velocity of the particles within a range of -10 to 10
        particles[i].vx = (rand() / (double)RAND_MAX) * 20 - 10;
        particles[i].vy = (rand() / (double)RAND_MAX) * 20 - 10;
        particles[i].vz = (rand() / (double)RAND_MAX) * 20 - 10;

        // Set the mass of the particles to 1
        particles[i].m = 1;
    }

    // Define the time step
    double dt = 0.001;

    // Run the simulation for a number of time steps
    for (int t = 0; t < 100000; t++) {
        // Calculate the force between each pair of particles
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                calculateForce(&particles[i], &particles[j]);
            }
        }

        // Update the positions of the particles
        for (int i = 0; i < n; i++) {
            updatePositions(&particles[i], dt);
        }
    }

    // Free the memory allocated for the particles
    free(particles);

    return 0;
}