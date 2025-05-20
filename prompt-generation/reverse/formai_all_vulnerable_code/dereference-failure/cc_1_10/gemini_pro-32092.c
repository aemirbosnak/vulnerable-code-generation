//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, z;
} vector3d;

typedef struct {
    double mass;
    vector3d position;
    vector3d velocity;
    vector3d acceleration;
} particle;

void update_particle(particle *p, double dt) {
    p->velocity.x += p->acceleration.x * dt;
    p->velocity.y += p->acceleration.y * dt;
    p->velocity.z += p->acceleration.z * dt;
    p->position.x += p->velocity.x * dt;
    p->position.y += p->velocity.y * dt;
    p->position.z += p->velocity.z * dt;
}

void calculate_acceleration(particle *p, particle *other) {
    double dx = other->position.x - p->position.x;
    double dy = other->position.y - p->position.y;
    double dz = other->position.z - p->position.z;
    double r2 = dx*dx + dy*dy + dz*dz;
    double r = sqrt(r2);
    double a = (6.674e-11 * other->mass) / (r2 * r);
    p->acceleration.x += a * dx / r;
    p->acceleration.y += a * dy / r;
    p->acceleration.z += a * dz / r;
}

int main(int argc, char **argv) {
    int nparticles = 100;
    particle *particles = malloc(nparticles * sizeof(particle));
    for (int i = 0; i < nparticles; i++) {
        particles[i].mass = 1.0;
        particles[i].position.x = 0.0;
        particles[i].position.y = 0.0;
        particles[i].position.z = 0.0;
        particles[i].velocity.x = 0.0;
        particles[i].velocity.y = 0.0;
        particles[i].velocity.z = 0.0;
        particles[i].acceleration.x = 0.0;
        particles[i].acceleration.y = 0.0;
        particles[i].acceleration.z = 0.0;
    }

    double dt = 1.0 / 60.0;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < nparticles; j++) {
            for (int k = 0; k < nparticles; k++) {
                if (j == k) continue;
                calculate_acceleration(&particles[j], &particles[k]);
            }
        }
        for (int j = 0; j < nparticles; j++) {
            update_particle(&particles[j], dt);
        }
    }

    for (int i = 0; i < nparticles; i++) {
        printf("%f %f %f\n", particles[i].position.x, particles[i].position.y, particles[i].position.z);
    }

    free(particles);
    return 0;
}