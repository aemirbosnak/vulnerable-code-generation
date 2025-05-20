//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PARTICLES 1000
#define PARTICLE_SIZE 0.01
#define MAX_ITERATIONS 1000

typedef struct Particle {
    double x, y, z;
    double vx, vy, vz;
} Particle;

void initialize_particles(Particle *particles) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = (double)rand() / RAND_MAX;
        particles[i].y = (double)rand() / RAND_MAX;
        particles[i].z = (double)rand() / RAND_MAX;

        particles[i].vx = (double)rand() / RAND_MAX;
        particles[i].vy = (double)rand() / RAND_MAX;
        particles[i].vz = (double)rand() / RAND_MAX;
    }
}

void simulate_particles(Particle *particles) {
    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        for (int i = 0; i < NUM_PARTICLES; i++) {
            double ax = 0, ay = 0, az = 0;

            for (int j = 0; j < NUM_PARTICLES; j++) {
                if (i != j) {
                    double dx = particles[i].x - particles[j].x;
                    double dy = particles[i].y - particles[j].y;
                    double dz = particles[i].z - particles[j].z;

                    double distance = sqrt(dx * dx + dy * dy + dz * dz);

                    ax += (particles[j].vx * dx + particles[j].vy * dy + particles[j].vz * dz) / distance;
                    ay += (particles[j].vx * dy + particles[j].vy * dx + particles[j].vz * dz) / distance;
                    az += (particles[j].vx * dz + particles[j].vy * dz + particles[j].vz * dx) / distance;
                }
            }

            particles[i].vx += ax * PARTICLE_SIZE;
            particles[i].vy += ay * PARTICLE_SIZE;
            particles[i].vz += az * PARTICLE_SIZE;

            particles[i].x += particles[i].vx * PARTICLE_SIZE;
            particles[i].y += particles[i].vy * PARTICLE_SIZE;
            particles[i].z += particles[i].vz * PARTICLE_SIZE;
        }
    }
}

int main() {
    Particle *particles = (Particle *)malloc(NUM_PARTICLES * sizeof(Particle));

    initialize_particles(particles);
    simulate_particles(particles);

    free(particles);

    return 0;
}