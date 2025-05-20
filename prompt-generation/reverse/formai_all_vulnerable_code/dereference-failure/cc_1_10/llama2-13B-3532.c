//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

struct particle {
    float x;
    float y;
    float vx;
    float vy;
};

struct universe {
    struct particle *particles;
    int num_particles;
};

void init_universe(struct universe *u, int num_particles) {
    u->particles = malloc(num_particles * sizeof(struct particle));
    u->num_particles = num_particles;

    for (int i = 0; i < num_particles; i++) {
        u->particles[i].x = (float)rand() / RAND_MAX * 10 - 5;
        u->particles[i].y = (float)rand() / RAND_MAX * 10 - 5;
        u->particles[i].vx = (float)rand() / RAND_MAX * 2 - 1;
        u->particles[i].vy = (float)rand() / RAND_MAX * 2 - 1;
    }
}

void update_particles(struct universe *u) {
    for (int i = 0; i < u->num_particles; i++) {
        u->particles[i].x += u->particles[i].vx;
        u->particles[i].y += u->particles[i].vy;

        if (u->particles[i].x > 10) {
            u->particles[i].x = 10;
            u->particles[i].vx = (float)rand() / RAND_MAX * 2 - 1;
        }

        if (u->particles[i].y > 10) {
            u->particles[i].y = 10;
            u->particles[i].vy = (float)rand() / RAND_MAX * 2 - 1;
        }

        if (u->particles[i].x < 0) {
            u->particles[i].x = 0;
            u->particles[i].vx = (float)rand() / RAND_MAX * 2 - 1;
        }

        if (u->particles[i].y < 0) {
            u->particles[i].y = 0;
            u->particles[i].vy = (float)rand() / RAND_MAX * 2 - 1;
        }
    }
}

void draw_particles(struct universe *u) {
    for (int i = 0; i < u->num_particles; i++) {
        printf("Particle %d: (%f, %f)\n", i, u->particles[i].x, u->particles[i].y);
    }
}

int main() {
    struct universe u;
    init_universe(&u, 100);

    for (int i = 0; i < 1000; i++) {
        update_particles(&u);
        draw_particles(&u);
    }

    return 0;
}