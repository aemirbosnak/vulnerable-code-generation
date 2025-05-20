//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
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

void update_particles(Particle *particles, int num_particles) {
    for (int i = 0; i < num_particles; i++) {
        double ax = 0.0;
        double ay = 0.0;
        double az = 0.0;

        for (int j = 0; j < num_particles; j++) {
            if (i != j) {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;

                double distance = sqrt(dx * dx + dy * dy + dz * dz);

                double force = G * particles[j].mass * particles[i].mass / distance * distance;

                ax += force * dx / particles[i].mass;
                ay += force * dy / particles[i].mass;
                az += force * dz / particles[i].mass;
            }
        }

        particles[i].vx += ax * 0.01;
        particles[i].vy += ay * 0.01;
        particles[i].vz += az * 0.01;
    }
}

int main() {
    int num_particles = 100;

    Particle *particles = malloc(num_particles * sizeof(Particle));

    for (int i = 0; i < num_particles; i++) {
        particles[i].mass = rand() % 1000;
        particles[i].x = rand() % 1000;
        particles[i].y = rand() % 1000;
        particles[i].z = rand() % 1000;
        particles[i].vx = rand() % 1000;
        particles[i].vy = rand() % 1000;
        particles[i].vz = rand() % 1000;
    }

    int num_steps = 100000;

    for (int step = 0; step < num_steps; step++) {
        update_particles(particles, num_particles);
    }

    free(particles);

    return 0;
}