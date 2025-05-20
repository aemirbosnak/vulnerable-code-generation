//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8

typedef struct {
    float x, y, vx, vy;
} Particle;

void initParticles(int numParticles, float xMin, float xMax, float yMin, float yMax) {
    int i;
    for (i = 0; i < numParticles; i++) {
        Particle* p = (Particle*)malloc(sizeof(Particle));
        p->x = (float)(xMin + (xMax - xMin) * (rand() / RAND_MAX));
        p->y = (float)(yMin + (yMax - yMin) * (rand() / RAND_MAX));
        p->vx = (float)(2 * GRAVITY * (rand() / RAND_MAX) - GRAVITY);
        p->vy = (float)(2 * GRAVITY * (rand() / RAND_MAX) - GRAVITY);
        printf("Particle %d: (%.2f, %.2f) vx: %.2f vy: %.2f\n", i, p->x, p->y, p->vx, p->vy);
    }
}

void updateParticles(Particle* particles, int numParticles) {
    int i;
    for (i = 0; i < numParticles; i++) {
        particles[i].x += particles[i].vx;
        particles[i].y += particles[i].vy;
        particles[i].vx += GRAVITY;
        particles[i].vy += GRAVITY;
        if (particles[i].x < 0 || particles[i].x > 10 || particles[i].y < 0 || particles[i].y > 10) {
            particles[i].x = (float)(rand() / RAND_MAX) * 10 - 5;
            particles[i].y = (float)(rand() / RAND_MAX) * 10 - 5;
            particles[i].vx = (float)(rand() / RAND_MAX) * 2 - 1;
            particles[i].vy = (float)(rand() / RAND_MAX) * 2 - 1;
            printf("Particle %d: (%.2f, %.2f) vx: %.2f vy: %.2f\n", i, particles[i].x, particles[i].y, particles[i].vx, particles[i].vy);
        }
    }
}

int main() {
    srand(time(NULL));
    int numParticles = 100;
    float xMin = 0, xMax = 10, yMin = 0, yMax = 10;
    Particle* particles = (Particle*)malloc(sizeof(Particle) * numParticles);
    initParticles(numParticles, xMin, xMax, yMin, yMax);
    updateParticles(particles, numParticles);
    sleep(1);
    updateParticles(particles, numParticles);
    sleep(1);
    updateParticles(particles, numParticles);
    // ...
    return 0;
}