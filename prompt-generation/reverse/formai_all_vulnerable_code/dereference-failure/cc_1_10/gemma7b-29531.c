//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct Particle {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle;

void calculate_acceleration(Particle *particle, Particle **particles, int num_particles) {
    for (int i = 0; i < num_particles; i++) {
        if (particle != particles[i]) {
            double dx = particles[i]->x - particle->x;
            double dy = particles[i]->y - particle->y;
            double dz = particles[i]->z - particle->z;
            double distance = sqrt(dx * dx + dy * dy + dz * dz);
            double acceleration = G * particles[i]->mass / distance * distance;
            particle->vx += acceleration * dx / particle->mass;
            particle->vy += acceleration * dy / particle->mass;
            particle->vz += acceleration * dz / particle->mass;
        }
    }
}

int main() {
    // Define the number of particles
    int num_particles = 10;

    // Create an array of particles
    Particle *particles = malloc(num_particles * sizeof(Particle));

    // Initialize the particles
    for (int i = 0; i < num_particles; i++) {
        particles[i].mass = 1.0;
        particles[i].x = i;
        particles[i].y = 0.0;
        particles[i].z = 0.0;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].vz = 0.0;
    }

    // Calculate the acceleration of each particle
    calculate_acceleration(particles, particles, num_particles);

    // Print the acceleration of each particle
    for (int i = 0; i < num_particles; i++) {
        printf("Particle %d: acceleration (x, y, z) = (%f, %f, %f)\n", i, particles[i].vx, particles[i].vy, particles[i].vz);
    }

    // Free the memory allocated for the particles
    free(particles);

    return 0;
}