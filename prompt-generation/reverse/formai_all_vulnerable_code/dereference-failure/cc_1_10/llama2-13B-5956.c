//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 100

struct particle {
    double x;
    double y;
    double vx;
    double vy;
};

struct world {
    struct particle** particles;
    int num_particles;
};

void init_world(struct world* world) {
    int i;
    for (i = 0; i < WORLD_SIZE; i++) {
        struct particle* particle = malloc(sizeof(struct particle));
        particle->x = (double)i / WORLD_SIZE * 2 - 1;
        particle->y = (double)i / WORLD_SIZE * 2 - 1;
        particle->vx = 0.1 * (double)i / WORLD_SIZE;
        particle->vy = 0.1 * (double)i / WORLD_SIZE;
        world->particles[i] = particle;
    }
    world->num_particles = WORLD_SIZE;
}

void update_world(struct world* world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        struct particle* particle = world->particles[i];
        particle->x += particle->vx;
        particle->y += particle->vy;
        particle->vx += GRAVITY * particle->y;
        particle->vy += GRAVITY * particle->x;
    }
}

void draw_world(struct world* world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        struct particle* particle = world->particles[i];
        printf("%.2f,%.2f\n", particle->x, particle->y);
    }
}

int main() {
    struct world world;
    init_world(&world);
    for (int i = 0; i < 1000; i++) {
        update_world(&world);
        draw_world(&world);
        usleep(100000);
    }
    return 0;
}