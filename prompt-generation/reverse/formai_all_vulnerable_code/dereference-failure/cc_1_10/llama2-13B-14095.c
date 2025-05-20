//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.14159

typedef struct {
    double x;
    double y;
    double vx;
    double vy;
} Particle;

typedef struct {
    Particle *particles;
    int num_particles;
} System;

void init_system(System *sys) {
    sys->particles = calloc(10, sizeof(Particle));
    sys->num_particles = 10;

    for (int i = 0; i < sys->num_particles; i++) {
        Particle *particle = &sys->particles[i];
        particle->x = (double)rand() / RAND_MAX * 10 - 5;
        particle->y = (double)rand() / RAND_MAX * 10 - 5;
        particle->vx = (double)rand() / RAND_MAX * 2 - 1;
        particle->vy = (double)rand() / RAND_MAX * 2 - 1;
    }
}

void update_particles(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle *particle = &sys->particles[i];
        particle->x += particle->vx;
        particle->y += particle->vy;

        if (particle->x < 0) {
            particle->x = 0;
            particle->vx = -particle->vx;
        } else if (particle->x > 10) {
            particle->x = 10;
            particle->vx = -particle->vx;
        }

        if (particle->y < 0) {
            particle->y = 0;
            particle->vy = -particle->vy;
        } else if (particle->y > 10) {
            particle->y = 10;
            particle->vy = -particle->vy;
        }
    }
}

void render_particles(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle *particle = &sys->particles[i];
        printf("%.2f,%.2f\n", particle->x, particle->y);
    }
}

int main() {
    System sys;

    init_system(&sys);

    for (int i = 0; i < 1000; i++) {
        update_particles(&sys);
        render_particles(&sys);
    }

    return 0;
}