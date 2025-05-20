//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define PI 3.14159265

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    Vector acceleration;
    double mass;
    double radius;
} Particle;

typedef struct {
    Particle* particles;
    int numParticles;
} System;

void initSystem(System* system, int numParticles) {
    system->particles = malloc(sizeof(Particle) * numParticles);
    system->numParticles = numParticles;
    for (int i = 0; i < numParticles; i++) {
        system->particles[i].position.x = rand() / (RAND_MAX / 2.0) - 1.0;
        system->particles[i].position.y = rand() / (RAND_MAX / 2.0) - 1.0;
        system->particles[i].position.z = rand() / (RAND_MAX / 2.0) - 1.0;
        system->particles[i].velocity.x = 0.0;
        system->particles[i].velocity.y = 0.0;
        system->particles[i].velocity.z = 0.0;
        system->particles[i].acceleration.x = 0.0;
        system->particles[i].acceleration.y = 0.0;
        system->particles[i].acceleration.z = 0.0;
        system->particles[i].mass = 1.0;
        system->particles[i].radius = 0.1;
    }
}

void freeSystem(System* system) {
    free(system->particles);
}

void updateSystem(System* system, double dt) {
    for (int i = 0; i < system->numParticles; i++) {
        system->particles[i].velocity.x += system->particles[i].acceleration.x * dt;
        system->particles[i].velocity.y += system->particles[i].acceleration.y * dt;
        system->particles[i].velocity.z += system->particles[i].acceleration.z * dt;
        system->particles[i].position.x += system->particles[i].velocity.x * dt;
        system->particles[i].position.y += system->particles[i].velocity.y * dt;
        system->particles[i].position.z += system->particles[i].velocity.z * dt;
    }
}

void renderSystem(System* system, double t) {
    char* buffer = malloc(sizeof(char) * 80 * 25);
    memset(buffer, ' ', sizeof(char) * 80 * 25);
    for (int i = 0; i < system->numParticles; i++) {
        int x = (int)(system->particles[i].position.x * 40.0 + 40.0);
        int y = (int)(system->particles[i].position.y * 20.0 + 12.0);
        buffer[y * 80 + x] = '*';
    }
    printf("\n%s\n", buffer);
    free(buffer);
}

int main() {
    System system;
    initSystem(&system, 100);
    for (double t = 0.0; t < 100.0; t += 0.1) {
        updateSystem(&system, 0.1);
        renderSystem(&system, t);
    }
    freeSystem(&system);
    return 0;
}