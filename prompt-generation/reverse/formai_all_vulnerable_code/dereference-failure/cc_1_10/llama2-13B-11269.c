//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 10

typedef struct {
    float x, y;
} Particle;

typedef struct {
    Particle *particles;
    int num_particles;
} World;

void init_world(World *world) {
    int i;
    for (i = 0; i < WORLD_SIZE; i++) {
        world->particles[i].x = (float)rand() / RAND_MAX * WORLD_SIZE;
        world->particles[i].y = (float)rand() / RAND_MAX * WORLD_SIZE;
    }
    world->num_particles = WORLD_SIZE;
}

void update_world(World *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *particle = world->particles + i;
        particle->x += GRAVITY * particle->y;
        particle->y -= GRAVITY * particle->x;
    }
}

void draw_world(World *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *particle = world->particles + i;
        printf("(%f, %f)\n", particle->x, particle->y);
    }
}

int main() {
    World world;
    init_world(&world);

    for (int i = 0; i < 100; i++) {
        update_world(&world);
        draw_world(&world);
    }

    return 0;
}