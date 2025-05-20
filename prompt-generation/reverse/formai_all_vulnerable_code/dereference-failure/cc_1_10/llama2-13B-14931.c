//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 10

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
} Particle;

Particle *createParticles(int num) {
    Particle *particles = calloc(num, sizeof(Particle));
    for (int i = 0; i < num; i++) {
        particles[i].x = (float)(i % WORLD_SIZE) * (WORLD_SIZE / 10);
        particles[i].y = (float)(i / WORLD_SIZE) * (WORLD_SIZE / 10);
        particles[i].vx = (float)(rand() % 2) - 1;
        particles[i].vy = (float)(rand() % 2) - 1;
    }
    return particles;
}

void updateParticles(Particle *particles, int num) {
    for (int i = 0; i < num; i++) {
        particles[i].x += particles[i].vx;
        particles[i].y += particles[i].vy;
        particles[i].vx += GRAVITY;
        particles[i].vy += GRAVITY;
        if (particles[i].x < 0 || particles[i].x >= WORLD_SIZE ||
                particles[i].y < 0 || particles[i].y >= WORLD_SIZE) {
            particles[i].vx = (float)(rand() % 2) - 1;
            particles[i].vy = (float)(rand() % 2) - 1;
        }
    }
}

void drawParticles(Particle *particles, int num) {
    for (int i = 0; i < num; i++) {
        printf("[%f, %f] ", particles[i].x, particles[i].y);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Particle *particles = createParticles(100);
    int num = 100;
    while (1) {
        updateParticles(particles, num);
        drawParticles(particles, num);
        printf("Press enter to continue...\n");
        getchar();
    }
    free(particles);
    return 0;
}