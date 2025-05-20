//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Particle {
    float x, y;
    float vx, vy;
    float m;
};

struct Particle *particles;
int nparticles;

void init_particles(int n) {
    particles = malloc(n * sizeof(struct Particle));
    nparticles = n;
    for (int i = 0; i < n; i++) {
        particles[i].x = rand() / (float)RAND_MAX;
        particles[i].y = rand() / (float)RAND_MAX;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].m = 1;
    }
}

void free_particles() {
    free(particles);
}

void update_particles(float dt) {
    for (int i = 0; i < nparticles; i++) {
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
    }
}

void draw_particles() {
    for (int i = 0; i < nparticles; i++) {
        printf("%f %f\n", particles[i].x, particles[i].y);
    }
}

int main() {
    init_particles(100);
    for (int i = 0; i < 1000; i++) {
        update_particles(0.01);
    }
    draw_particles();
    free_particles();
    return 0;
}