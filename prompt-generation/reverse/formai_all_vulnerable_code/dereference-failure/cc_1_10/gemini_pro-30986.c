//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: detailed
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
#define DT 1

// Define the number of particles
#define N 1000

// Define the particle structure
typedef struct {
    double m; // Mass
    double x; // X-coordinate
    double y; // Y-coordinate
    double z; // Z-coordinate
    double vx; // X-velocity
    double vy; // Y-velocity
    double vz; // Z-velocity
} particle_t;

// Initialize the particles
void init_particles(particle_t *particles) {
    for (int i = 0; i < N; i++) {
        // Generate a random mass between 1 and 100
        particles[i].m = 1 + 99 * (double)rand() / (double)RAND_MAX;

        // Generate a random position within a sphere of radius R_EARTH
        double r = R_EARTH * sqrt((double)rand() / (double)RAND_MAX);
        double theta = 2 * M_PI * (double)rand() / (double)RAND_MAX;
        double phi = acos(2 * (double)rand() / (double)RAND_MAX - 1);
        particles[i].x = r * sin(phi) * cos(theta);
        particles[i].y = r * sin(phi) * sin(theta);
        particles[i].z = r * cos(phi);

        // Generate a random velocity between -100 and 100
        particles[i].vx = -100 + 200 * (double)rand() / (double)RAND_MAX;
        particles[i].vy = -100 + 200 * (double)rand() / (double)RAND_MAX;
        particles[i].vz = -100 + 200 * (double)rand() / (double)RAND_MAX;
    }
}

// Update the positions and velocities of the particles
void update_particles(particle_t *particles) {
    for (int i = 0; i < N; i++) {
        // Calculate the force on the particle due to gravity
        double fx = 0;
        double fy = 0;
        double fz = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double dz = particles[j].z - particles[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * particles[i].m * particles[j].m / (r * r);
            fx += f * dx / r;
            fy += f * dy / r;
            fz += f * dz / r;
        }

        // Update the velocity of the particle
        particles[i].vx += fx / particles[i].m * DT;
        particles[i].vy += fy / particles[i].m * DT;
        particles[i].vz += fz / particles[i].m * DT;

        // Update the position of the particle
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
        particles[i].z += particles[i].vz * DT;
    }
}

// Draw the particles
void draw_particles(particle_t *particles) {
    for (int i = 0; i < N; i++) {
        printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Allocate memory for the particles
    particle_t *particles = malloc(N * sizeof(particle_t));

    // Initialize the particles
    init_particles(particles);

    // Update the particles for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        update_particles(particles);
    }

    // Draw the particles
    draw_particles(particles);

    // Free the memory for the particles
    free(particles);

    return 0;
}