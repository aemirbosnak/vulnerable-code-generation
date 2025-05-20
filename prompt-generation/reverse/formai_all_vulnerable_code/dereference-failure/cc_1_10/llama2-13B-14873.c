//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8
#define FPS 60

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
} Particle;

int main() {
    srand(time(NULL));

    Particle* particles = malloc(100 * sizeof(Particle));
    for (int i = 0; i < 100; i++) {
        particles[i].x = (float)rand() / RAND_MAX * 10 - 5;
        particles[i].y = (float)rand() / RAND_MAX * 10 - 5;
        particles[i].vx = (float)rand() / RAND_MAX * 2 - 1;
        particles[i].vy = (float)rand() / RAND_MAX * 2 - 1;
    }

    while (1) {
        for (int i = 0; i < 100; i++) {
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;

            if (particles[i].x < -5) {
                particles[i].x = -5;
                particles[i].vx = -2;
            } else if (particles[i].x > 5) {
                particles[i].x = 5;
                particles[i].vx = 2;
            }

            if (particles[i].y < -5) {
                particles[i].y = -5;
                particles[i].vy = -2;
            } else if (particles[i].y > 5) {
                particles[i].y = 5;
                particles[i].vy = 2;
            }
        }

        for (int i = 0; i < 100; i++) {
            printf("Particle %d: (%.2f, %.2f) vx: %.2f vy: %.2f\n", i, particles[i].x, particles[i].y, particles[i].vx, particles[i].vy);
        }

        usleep(1000000 / FPS);
    }

    free(particles);
    return 0;
}