//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8
#define WALL_THICKNESS 0.1
#define WALL_VELOCITY 2.0

typedef struct {
    float x, y;
} Particle;

typedef struct {
    Particle *particles;
    int num_particles;
} System;

void init_system(System *sys) {
    sys->particles = calloc(10, sizeof(Particle));
    sys->num_particles = 10;

    for (int i = 0; i < sys->num_particles; i++) {
        sys->particles[i].x = (float)rand() / RAND_MAX * 10 - 5;
        sys->particles[i].y = (float)rand() / RAND_MAX * 10 - 5;
    }
}

void update_particles(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        float acc = GRAVITY * (sys->particles[i].y - WALL_THICKNESS);
        sys->particles[i].y += acc;

        if (sys->particles[i].y >= WALL_THICKNESS) {
            sys->particles[i].y = WALL_THICKNESS;
            sys->particles[i].x += WALL_VELOCITY;
        }
    }
}

void draw_particles(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        printf("Particle %d: (%f, %f)\n", i, sys->particles[i].x, sys->particles[i].y);
    }
}

int main() {
    System sys;

    init_system(&sys);

    for (int i = 0; i < 1000; i++) {
        update_particles(&sys);
        draw_particles(&sys);
    }

    return 0;
}