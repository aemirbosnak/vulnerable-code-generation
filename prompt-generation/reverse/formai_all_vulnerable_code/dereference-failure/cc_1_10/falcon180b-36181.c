//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_PARTICLES 1000
#define BOX_SIZE 100

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
} Particle;

void init_particle(Particle *p) {
    double r = rand() / (double)RAND_MAX;
    p->x = r * BOX_SIZE;
    p->y = r * BOX_SIZE;
    p->z = r * BOX_SIZE;
    p->vx = (rand() / (double)RAND_MAX - 0.5) * 10;
    p->vy = (rand() / (double)RAND_MAX - 0.5) * 10;
    p->vz = (rand() / (double)RAND_MAX - 0.5) * 10;
    p->ax = p->ay = p->az = 0;
}

void update_particle(Particle *p) {
    p->ax += 0;
    p->ay += 0;
    p->az += -9.8;
    p->vx += p->ax;
    p->vy += p->ay;
    p->vz += p->az;
    p->x += p->vx;
    p->y += p->vy;
    p->z += p->vz;
}

int main() {
    srand(time(NULL));
    Particle *particles = malloc(NUM_PARTICLES * sizeof(Particle));
    for (int i = 0; i < NUM_PARTICLES; i++) {
        init_particle(&particles[i]);
    }

    pthread_t threads[NUM_PARTICLES];
    for (int i = 0; i < NUM_PARTICLES; i++) {
        pthread_create(&threads[i], NULL, (void*)update_particle, &particles[i]);
    }

    for (int i = 0; i < NUM_PARTICLES; i++) {
        pthread_join(threads[i], NULL);
    }

    free(particles);
    return 0;
}