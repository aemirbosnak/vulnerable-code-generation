//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define G 6.67408e-11

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
} Particle;

int main() {
    int n = 10;
    Particle *particles = malloc(n * sizeof(Particle));

    // Initialize particles
    for (int i = 0; i < n; i++) {
        particles[i].mass = 1.0;
        particles[i].x = rand() % 100;
        particles[i].y = rand() % 100;
        particles[i].z = rand() % 100;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].vz = 0.0;
        particles[i].ax = 0.0;
        particles[i].ay = 0.0;
        particles[i].az = 0.0;
    }

    // Calculate forces and accelerations
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double dz = particles[j].z - particles[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * particles[i].mass * particles[j].mass / (r * r);
            particles[i].ax += f * dx / r;
            particles[i].ay += f * dy / r;
            particles[i].az += f * dz / r;
            particles[j].ax -= f * dx / r;
            particles[j].ay -= f * dy / r;
            particles[j].az -= f * dz / r;
        }
    }

    // Update velocities and positions
    for (int i = 0; i < n; i++) {
        particles[i].vx += particles[i].ax * 0.01;
        particles[i].vy += particles[i].ay * 0.01;
        particles[i].vz += particles[i].az * 0.01;
        particles[i].x += particles[i].vx * 0.01;
        particles[i].y += particles[i].vy * 0.01;
        particles[i].z += particles[i].vz * 0.01;
    }

    // Print particle positions
    for (int i = 0; i < n; i++) {
        printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
    }

    free(particles);
    return 0;
}