//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
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

void calculate_force(Particle *particle, Particle **particles) {
    double dx, dy, dz;
    double distance;
    double force_magnitude;
    double force_direction;

    for (int i = 0; i < *particles; i++) {
        if (particle != particles[i]) {
            dx = particles[i]->x - particle->x;
            dy = particles[i]->y - particle->y;
            dz = particles[i]->z - particle->z;

            distance = sqrt(dx * dx + dy * dy + dz * dz);

            force_magnitude = G * particle->mass * particles[i]->mass / distance * distance;

            force_direction = atan2(dy, dx) * 180.0 / M_PI;

            particle->vx += force_magnitude * cos(force_direction) * 0.01;
            particle->vy += force_magnitude * sin(force_direction) * 0.01;
        }
    }
}

int main() {
    int num_particles = 100;
    Particle *particles = malloc(num_particles * sizeof(Particle));

    // Initialize particles
    for (int i = 0; i < num_particles; i++) {
        particles[i].mass = 1.0;
        particles[i].x = rand() % 1000;
        particles[i].y = rand() % 1000;
        particles[i].z = rand() % 1000;
        particles[i].vx = rand() % 10;
        particles[i].vy = rand() % 10;
        particles[i].vz = rand() % 10;
    }

    // Calculate forces between particles
    calculate_force(particles, &num_particles);

    // Simulate particle motion
    for (int i = 0; i < num_particles; i++) {
        particles[i].x += particles[i].vx * 0.01;
        particles[i].y += particles[i].vy * 0.01;
        particles[i].z += particles[i].vz * 0.01;
    }

    // Print particle positions
    for (int i = 0; i < num_particles; i++) {
        printf("Particle %d: (x, y, z) = (%f, %f, %f)\n", i, particles[i].x, particles[i].y, particles[i].z);
    }

    free(particles);

    return 0;
}