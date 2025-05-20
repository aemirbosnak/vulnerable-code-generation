//FormAI DATASET v1.0 Category: Physics simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 6.6743e-11

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Particle; 

void simulate(int N, Particle *particles, double dt, int steps) {
    int i, j, k;
    double fx, fy, fz, dx, dy, dz, dist;
    for (k = 0; k < steps; k++) {
        for (i = 0; i < N; i++) {
            fx = 0.0;
            fy = 0.0;
            fz = 0.0;
            for (j = 0; j < N; j++) {
                if (i == j) continue;
                dx = particles[j].x - particles[i].x;
                dy = particles[j].y - particles[i].y;
                dz = particles[j].z - particles[i].z;
                dist = sqrt(dx * dx + dy * dy + dz * dz);
                if (dist < 0.001) continue;
                fx += GRAVITY * particles[i].mass * particles[j].mass * dx / (dist * dist * dist);
                fy += GRAVITY * particles[i].mass * particles[j].mass * dy / (dist * dist * dist);
                fz += GRAVITY * particles[i].mass * particles[j].mass * dz / (dist * dist * dist);
            }
            particles[i].vx += fx * dt / particles[i].mass;
            particles[i].vy += fy * dt / particles[i].mass;
            particles[i].vz += fz * dt / particles[i].mass;
        }
        for (i = 0; i < N; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
            particles[i].z += particles[i].vz * dt;
        }
    }
}

int main() {
    int N = 10;
    double dt = 0.01;
    int steps = 100;
    Particle *particles = malloc(N * sizeof(Particle));
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        particles[i].mass = (double) rand() / (double) RAND_MAX * 10.0;
        particles[i].x = (double) rand() / (double) RAND_MAX * 100.0 - 50.0;
        particles[i].y = (double) rand() / (double) RAND_MAX * 100.0 - 50.0;
        particles[i].z = (double) rand() / (double) RAND_MAX * 100.0 - 50.0;
        particles[i].vx = (double) rand() / (double) RAND_MAX * 10.0 - 5.0;
        particles[i].vy = (double) rand() / (double) RAND_MAX * 10.0 - 5.0;
        particles[i].vz = (double) rand() / (double) RAND_MAX * 10.0 - 5.0;
    }
    simulate(N, particles, dt, steps);
    for (i = 0; i < N; i++) {
        printf("Particle %d\n", i);
        printf("Mass: %f\n", particles[i].mass);
        printf("Position: %f, %f, %f\n", particles[i].x, particles[i].y, particles[i].z);
        printf("Velocity: %f, %f, %f\n", particles[i].vx, particles[i].vy, particles[i].vz);
    }
    free(particles);
    return 0;
}