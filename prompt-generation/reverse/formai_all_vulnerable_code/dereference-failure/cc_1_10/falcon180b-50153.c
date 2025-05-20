//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_PARTICLES 1000
#define NUM_THREADS 4

struct particle {
    double x, y, vx, vy, ax, ay;
};

void *update_particles(void *arg) {
    int start = *(int *) arg;
    struct particle *particles = (struct particle *) malloc(NUM_PARTICLES * sizeof(struct particle));

    for (int i = start; i < NUM_PARTICLES; i += NUM_THREADS) {
        particles[i].x += particles[i].vx;
        particles[i].y += particles[i].vy;
        particles[i].vx += particles[i].ax;
        particles[i].vy += particles[i].ay;
    }

    free(particles);
    return NULL;
}

int main() {
    srand(time(NULL));

    struct particle *particles = (struct particle *) malloc(NUM_PARTICLES * sizeof(struct particle));

    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = rand() % 800 - 400;
        particles[i].y = rand() % 600 - 300;
        particles[i].vx = (rand() % 20 - 10) / 10.0;
        particles[i].vy = (rand() % 20 - 10) / 10.0;
        particles[i].ax = 0;
        particles[i].ay = 0;
    }

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int start = i * NUM_PARTICLES / NUM_THREADS;
        pthread_create(&threads[i], NULL, update_particles, (void *) &start);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(particles);

    return 0;
}