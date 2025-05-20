//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000
#define D 2
#define SPEED 5
#define GRAVITY 9.8

// Structure to store particle data
typedef struct {
    double x;
    double y;
    double vx;
    double vy;
} Particle;

// Function to generate random initial positions and velocities
void initParticles(Particle *particles, int n) {
    int i;
    for (i = 0; i < n; i++) {
        particles[i].x = (double)rand() / RAND_MAX * 10 - 5;
        particles[i].y = (double)rand() / RAND_MAX * 10 - 5;
        particles[i].vx = (double)rand() / RAND_MAX * 2 - 1;
        particles[i].vy = (double)rand() / RAND_MAX * 2 - 1;
    }
}

// Function to simulate particle movement
void simulate(Particle *particles, int n, double time) {
    int i;
    for (i = 0; i < n; i++) {
        particles[i].x += particles[i].vx * time;
        particles[i].y += particles[i].vy * time;
        particles[i].vx += GRAVITY * time;
        particles[i].vy += GRAVITY * time;
    }
}

// Function to print particle positions and velocities
void printParticles(Particle *particles, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2f %.2f %.2f %.2f\n", particles[i].x, particles[i].y, particles[i].vx, particles[i].vy);
    }
}

int main() {
    srand(time(NULL));
    int n = N;
    Particle *particles = malloc(n * sizeof(Particle));
    initParticles(particles, n);

    for (int i = 0; i < 10; i++) {
        simulate(particles, n, 0.1);
        printParticles(particles, n);
    }

    free(particles);
    return 0;
}