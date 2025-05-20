//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LENGTH 100
#define WIDTH 100
#define HEIGHT 100
#define NUM_PARTICLES 1000
#define GRAVITY 9.81
#define BOUNCE_FACTOR 0.7
#define DAMPING_FACTOR 0.99

typedef struct {
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
} particle;

particle create_particle(float x, float y, float z) {
    particle p;
    p.x = x;
    p.y = y;
    p.z = z;
    p.vx = 0;
    p.vy = 0;
    p.vz = 0;
    return p;
}

void update_particle(particle* p, float dt) {
    p->vx += p->vy * dt;
    p->vy += GRAVITY * dt;
    p->vz += p->vx * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void bounce_particle(particle* p) {
    if (p->y < 0) {
        p->y = 0;
        p->vy *= BOUNCE_FACTOR;
    } else if (p->y > HEIGHT) {
        p->y = HEIGHT;
        p->vy *= BOUNCE_FACTOR;
    }
}

void damp_particle(particle* p) {
    p->vx *= DAMPING_FACTOR;
    p->vy *= DAMPING_FACTOR;
    p->vz *= DAMPING_FACTOR;
}

int main() {
    srand(time(NULL));
    particle* particles = malloc(NUM_PARTICLES * sizeof(particle));
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i] = create_particle(rand() % LENGTH, rand() % WIDTH, rand() % HEIGHT);
    }
    float dt = 1.0 / 60.0;
    while (1) {
        for (int i = 0; i < NUM_PARTICLES; i++) {
            update_particle(&particles[i], dt);
            bounce_particle(&particles[i]);
            damp_particle(&particles[i]);
        }
    }
    return 0;
}