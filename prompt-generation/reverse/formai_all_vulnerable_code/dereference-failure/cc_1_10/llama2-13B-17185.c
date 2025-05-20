//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define FPS 60

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
} Particle;

typedef struct {
    Particle* particles;
    int num_particles;
} System;

void init_system(System* sys) {
    sys->particles = calloc(100, sizeof(Particle));
    sys->num_particles = 100;
}

void update_particles(System* sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle* particle = &sys->particles[i];
        particle->vx += GRAVITY;
        particle->vy += GRAVITY;
        particle->x += particle->vx;
        particle->y += particle->vy;
        particle->vx *= 0.95; // damping
        particle->vy *= 0.95; // damping
        if (rand() % 100 < 5) {
            particle->vx += (rand() % 100 - 50) / 100.0 * 2.0;
            particle->vy += (rand() % 100 - 50) / 100.0 * 2.0;
        }
    }
}

void render_particles(System* sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle* particle = &sys->particles[i];
        printf("Particle %d: (%f, %f) vx: %f, vy: %f\n", i, particle->x, particle->y, particle->vx, particle->vy);
    }
}

int main() {
    srand(time(NULL));
    System sys;
    init_system(&sys);
    for (int i = 0; i < 1000; i++) {
        update_particles(&sys);
        render_particles(&sys);
        if (i % FPS == 0) {
            printf("FPS: %d\n", i);
        }
    }
    return 0;
}