//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_WIDTH 1000
#define WORLD_HEIGHT 1000

typedef struct {
    int x;
    int y;
    int mass;
} Particle;

typedef struct {
    Particle* particles;
    int num_particles;
} World;

void init_world(World* world) {
    int i;
    for (i = 0; i < WORLD_WIDTH * WORLD_HEIGHT; i++) {
        Particle particle;
        particle.x = i % WORLD_WIDTH;
        particle.y = i / WORLD_WIDTH;
        particle.mass = rand() % 10 + 1;
        world->particles[i] = particle;
    }
    world->num_particles = WORLD_WIDTH * WORLD_HEIGHT;
}

void update_world(World* world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle* particle = world->particles + i;
        particle->x += GRAVITY * particle->mass * world->num_particles;
        particle->y += GRAVITY * particle->mass * world->num_particles;
        if (particle->x < 0 || particle->x >= WORLD_WIDTH) {
            particle->x = (particle->x < 0) ? 0 : WORLD_WIDTH - 1;
        }
        if (particle->y < 0 || particle->y >= WORLD_HEIGHT) {
            particle->y = (particle->y < 0) ? 0 : WORLD_HEIGHT - 1;
        }
    }
}

void draw_world(World* world) {
    int i;
    for (i = 0; i < world->num_particles; i++) {
        Particle* particle = world->particles + i;
        printf("[%d, %d]", particle->x, particle->y);
    }
}

int main() {
    World world;
    init_world(&world);

    for (int i = 0; i < 1000; i++) {
        update_world(&world);
        draw_world(&world);
        printf("Time step %d\n", i);
    }

    return 0;
}