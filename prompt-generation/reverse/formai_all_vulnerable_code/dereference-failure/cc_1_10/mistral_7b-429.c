//MISTRAL-7B DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

typedef struct {
    double x, y, vx, vy, ax, ay;
} Particle;

void initialize(Particle *particles) {
    for (int i = 0; i < N; i++) {
        particles[i].x = (i % 2 == 0) ? 1.0 : -1.0;
        particles[i].y = 2.0;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].ax = 0.0;
        particles[i].ay = 0.05;
    }
}

void force(Particle *a, Particle *b, double g, double k, double r) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    double r_sq = dx * dx + dy * dy;

    a->ax += (k * r_sq / r_sq) * dx;
    a->ay += g;
    b->ax -= (k * r_sq / r_sq) * dx;
    b->ay += g;
}

void integrate(Particle *particles, double dt) {
    for (int i = 0; i < N; i++) {
        double sum_ax = 0.0, sum_ay = 0.0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                force(&particles[i], &particles[j], 9.81, 10.0, 1.0);
                sum_ax += particles[i].ax;
                sum_ay += particles[i].ay;
            }
        }
        particles[i].vx += 0.5 * dt * (sum_ax + particles[i].ax);
        particles[i].vy += 0.5 * dt * (sum_ay + particles[i].ay);
        particles[i].x += dt * particles[i].vx;
        particles[i].y += dt * particles[i].vy;
        particles[i].ax = 0.0;
        particles[i].ay = 0.0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num_iterations> <time_step>\n", argv[0]);
        return 1;
    }

    int num_iterations = atoi(argv[1]);
    double time_step = atof(argv[2]);

    Particle particles[N];
    initialize(particles);

    for (int i = 0; i < num_iterations; i++) {
        integrate(particles, time_step);
        // print or save the state of particles here
    }

    return 0;
}