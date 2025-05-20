//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 1000

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
} Particle;

typedef struct {
    Particle **particles;
    int num_particles;
} World;

void init_world(World *world) {
    int i;
    for (i = 0; i < WORLD_SIZE; i++) {
        world->particles[i] = malloc(sizeof(Particle));
        world->particles[i]->x = (float)i / 10.0;
        world->particles[i]->y = (float)i / 10.0;
        world->particles[i]->vx = 0.1 * (float)sin(world->particles[i]->x);
        world->particles[i]->vy = 0.1 * (float)cos(world->particles[i]->y);
    }
    world->num_particles = WORLD_SIZE;
}

void update_world(World *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *p = world->particles[i];
        p->x += p->vx;
        p->y += p->vy;
        p->vx += GRAVITY * p->y;
        p->vy -= GRAVITY * p->x;
    }
}

void render_world(World *world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle *p = world->particles[i];
        printf("Particle %d: (%.2f, %.2f) vx: %.2f, vy: %.2f\n", i, p->x, p->y, p->vx, p->vy);
    }
}

int main() {
    World world;
    init_world(&world);
    update_world(&world);
    render_world(&world);
    return 0;
}