//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Particle;

void update_velocities(Particle *particles, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = particles[j].x - particles[i].x;
            double dy = particles[j].y - particles[i].y;
            double d = sqrt(dx * dx + dy * dy);
            double force = G * particles[i].mass * particles[j].mass / (d * d);
            double theta = atan2(dy, dx);
            particles[i].vx += force * cos(theta) / particles[i].mass;
            particles[i].vy += force * sin(theta) / particles[i].mass;
            particles[j].vx -= force * cos(theta) / particles[j].mass;
            particles[j].vy -= force * sin(theta) / particles[j].mass;
        }
    }
}

void update_positions(Particle *particles, int n, double dt) {
    for (int i = 0; i < n; i++) {
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
    }
}

int main() {
    int n = 100;
    Particle *particles = malloc(sizeof(Particle) * n);
    for (int i = 0; i < n; i++) {
        particles[i].mass = 1;
        particles[i].x = rand() % 1000;
        particles[i].y = rand() % 1000;
        particles[i].vx = 0;
        particles[i].vy = 0;
    }

    double dt = 0.01;
    for (int i = 0; i < 10000; i++) {
        update_velocities(particles, n);
        update_positions(particles, n, dt);
    }

    for (int i = 0; i < n; i++) {
        printf("Particle %d: (%f, %f)\n", i, particles[i].x, particles[i].y);
    }

    free(particles);
    return 0;
}