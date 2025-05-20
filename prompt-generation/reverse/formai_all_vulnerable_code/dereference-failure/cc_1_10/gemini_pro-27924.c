//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the Earth
#define M_EARTH 5.972e24

// Define the radius of the Earth
#define R_EARTH 6.371e6

// Define the time step
#define DT 1.0

// Define the number of particles
#define N 1000

// Define the particle structure
typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double m;
} particle;

// Initialize the particles
void initialize_particles(particle *particles) {
    for (int i = 0; i < N; i++) {
        // Generate a random position within a sphere of radius R_EARTH
        particles[i].x = (2 * R_EARTH * ((double)rand() / (double)RAND_MAX)) - R_EARTH;
        particles[i].y = (2 * R_EARTH * ((double)rand() / (double)RAND_MAX)) - R_EARTH;
        particles[i].z = (2 * R_EARTH * ((double)rand() / (double)RAND_MAX)) - R_EARTH;

        // Generate a random velocity
        particles[i].vx = (200 * ((double)rand() / (double)RAND_MAX)) - 100;
        particles[i].vy = (200 * ((double)rand() / (double)RAND_MAX)) - 100;
        particles[i].vz = (200 * ((double)rand() / (double)RAND_MAX)) - 100;

        // Set the mass
        particles[i].m = 1.0;
    }
}

// Update the positions and velocities of the particles
void update_particles(particle *particles) {
    for (int i = 0; i < N; i++) {
        // Update the positions
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
        particles[i].z += particles[i].vz * DT;

        // Update the velocities
        for (int j = 0; j < N; j++) {
            if (i != j) {
                // Calculate the distance between the two particles
                double dx = particles[i].x - particles[j].x;
                double dy = particles[i].y - particles[j].y;
                double dz = particles[i].z - particles[j].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);

                // Calculate the force between the two particles
                double f = G * particles[i].m * particles[j].m / (r * r);

                // Calculate the acceleration of the first particle due to the second particle
                double ax = f * dx / r;
                double ay = f * dy / r;
                double az = f * dz / r;

                // Update the velocity of the first particle
                particles[i].vx += ax * DT;
                particles[i].vy += ay * DT;
                particles[i].vz += az * DT;
            }
        }
    }
}

// Main function
int main() {
    // Allocate memory for the particles
    particle *particles = (particle *)malloc(N * sizeof(particle));

    // Initialize the particles
    initialize_particles(particles);

    // Update the particles for a number of time steps
    for (int t = 0; t < 1000; t++) {
        // Update the particles
        update_particles(particles);

        // Print the positions of the particles
        for (int i = 0; i < N; i++) {
            printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
        }

        // Print a newline
        printf("\n");
    }

    // Free the memory allocated for the particles
    free(particles);

    return 0;
}