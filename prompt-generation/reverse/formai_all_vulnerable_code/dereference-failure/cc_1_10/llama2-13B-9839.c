//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 100

typedef struct {
    float x;
    float y;
} Particle;

typedef struct {
    Particle *particles;
    int num_particles;
} World;

void init_world(World *world) {
    int i;
    for (i = 0; i < WORLD_SIZE; i++) {
        world->particles[i].x = (float)i / 10.0f;
        world->particles[i].y = 5.0f;
    }
    world->num_particles = WORLD_SIZE;
}

void update_world(World *world, float dt) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *particle = world->particles + i;
        particle->x += dt * 2.0f * (particle->y - world->particles[i - 1].y);
        particle->y += dt * 2.0f * (particle->x - world->particles[i - 1].x);
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

    while (1) {
        update_world(&world, 0.01f);
        draw_world(&world);
    }

    return 0;
}