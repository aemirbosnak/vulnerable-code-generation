//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

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
    int num_particles = 100;
    Particle *particles = malloc(num_particles * sizeof(Particle));

    // Initialize the particles
    for (int i = 0; i < num_particles; i++) {
        particles[i].mass = 1.0;
        particles[i].x = rand() % 1000;
        particles[i].y = rand() % 1000;
        particles[i].z = rand() % 1000;
        particles[i].vx = rand() % 10;
        particles[i].vy = rand() % 10;
        particles[i].vz = rand() % 10;
    }

    // Calculate the acceleration of each particle
    calculate_acceleration(particles, particles, num_particles);

    // Print the acceleration of each particle
    for (int i = 0; i < num_particles; i++) {
        printf("Particle %d: Acceleration (x, y, z) = (%f, %f, %f)\n", i, particles[i].vx, particles[i].vy, particles[i].vz);
    }

    free(particles);

    return 0;
}