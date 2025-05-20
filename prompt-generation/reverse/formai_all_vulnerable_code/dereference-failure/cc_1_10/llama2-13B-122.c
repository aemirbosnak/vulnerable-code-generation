//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: intelligent
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
        world->particles[i].x = (float)i / WORLD_SIZE * WORLD_SIZE;
        world->particles[i].y = (float)i / WORLD_SIZE * WORLD_SIZE;
    }
    world->num_particles = WORLD_SIZE;
}

void update_world(World *world, float dt) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *particle = world->particles + i;
        particle->x += dt * GRAVITY;
        particle->y += dt * GRAVITY;
        if (particle->x < 0 || particle->x >= WORLD_SIZE) {
            particle->x = (float)i / WORLD_SIZE * WORLD_SIZE;
            particle->y = (float)i / WORLD_SIZE * WORLD_SIZE;
        }
    }
}

void draw_world(World *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *particle = world->particles + i;
        printf("%.2f,%.2f\n", particle->x, particle->y);
    }
}

int main() {
    World world;
    init_world(&world);
    update_world(&world, 0.01);
    draw_world(&world);
    return 0;
}