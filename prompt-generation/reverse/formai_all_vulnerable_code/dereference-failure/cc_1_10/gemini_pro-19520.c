//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of particles and the number of iterations
#define N 100000
#define ITERATIONS 10000

// Define the gravitational constant
#define G 6.674e-11

// Define the particle structure
typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

// Initialize the particles
void initializeParticles(Particle *particles) {
    for (int i = 0; i < N; i++) {
        // Generate a random mass between 1 and 100
        particles[i].mass = (double)rand() / (double)RAND_MAX * 100.0 + 1.0;

        // Generate a random position between -100 and 100
        particles[i].x = (double)rand() / (double)RAND_MAX * 200.0 - 100.0;
        particles[i].y = (double)rand() / (double)RAND_MAX * 200.0 - 100.0;
        particles[i].z = (double)rand() / (double)RAND_MAX * 200.0 - 100.0;

        // Generate a random velocity between -10 and 10
        particles[i].vx = (double)rand() / (double)RAND_MAX * 20.0 - 10.0;
        particles[i].vy = (double)rand() / (double)RAND_MAX * 20.0 - 10.0;
        particles[i].vz = (double)rand() / (double)RAND_MAX * 20.0 - 10.0;
    }
}

// Calculate the gravitational force between two particles
void calculateForce(Particle *particle1, Particle *particle2, double *fx, double *fy, double *fz) {
    // Calculate the distance between the particles
    double dx = particle2->x - particle1->x;
    double dy = particle2->y - particle1->y;
    double dz = particle2->z - particle1->z;
    double distance = sqrt(dx * dx + dy * dy + dz * dz);

    // Calculate the gravitational force
    double force = G * particle1->mass * particle2->mass / (distance * distance);

    // Calculate the force components
    *fx = force * dx / distance;
    *fy = force * dy / distance;
    *fz = force * dz / distance;
}

// Update the velocities and positions of the particles
void updateParticles(Particle *particles, double dt) {
    for (int i = 0; i < N; i++) {
        // Calculate the total force on the particle
        double fx = 0.0;
        double fy = 0.0;
        double fz = 0.0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            calculateForce(&particles[i], &particles[j], &fx, &fy, &fz);
        }

        // Update the particle's velocity
        particles[i].vx += fx / particles[i].mass * dt;
        particles[i].vy += fy / particles[i].mass * dt;
        particles[i].vz += fz / particles[i].mass * dt;

        // Update the particle's position
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
        particles[i].z += particles[i].vz * dt;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize the random number generator
    srand(time(NULL));

    // Allocate memory for the particles
    Particle *particles = (Particle *)malloc(N * sizeof(Particle));

    // Initialize the particles
    initializeParticles(particles);

    // Start the timer
    clock_t start = clock();

    // Run the simulation for the specified number of iterations
    for (int i = 0; i < ITERATIONS; i++) {
        // Update the velocities and positions of the particles
        updateParticles(particles, 0.001);
    }

    // Stop the timer
    clock_t end = clock();

    // Print the simulation time
    printf("Simulation time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free the memory allocated for the particles
    free(particles);

    return 0;
}