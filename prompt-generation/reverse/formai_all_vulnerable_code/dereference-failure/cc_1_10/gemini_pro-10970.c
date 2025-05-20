//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Particle;

Particle* createParticle(double mass, double x, double y, double z, double vx, double vy, double vz) {
    Particle* particle = malloc(sizeof(Particle));
    particle->mass = mass;
    particle->x = x;
    particle->y = y;
    particle->z = z;
    particle->vx = vx;
    particle->vy = vy;
    particle->vz = vz;
    return particle;
}

void freeParticle(Particle* particle) {
    free(particle);
}

void calculateForce(Particle* particle1, Particle* particle2) {
    double dx = particle2->x - particle1->x;
    double dy = particle2->y - particle1->y;
    double dz = particle2->z - particle1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * particle1->mass * particle2->mass / (r*r);
    particle1->vx += f * dx / r;
    particle1->vy += f * dy / r;
    particle1->vz += f * dz / r;
}

void updateParticle(Particle* particle, double dt) {
    particle->x += particle->vx * dt;
    particle->y += particle->vy * dt;
    particle->z += particle->vz * dt;
}

int main() {
    int nParticles = 1000;
    Particle* particles[nParticles];
    for (int i = 0; i < nParticles; i++) {
        double mass = 1e3;
        double x = rand() / (double)RAND_MAX * 1e6;
        double y = rand() / (double)RAND_MAX * 1e6;
        double z = rand() / (double)RAND_MAX * 1e6;
        double vx = rand() / (double)RAND_MAX * 100;
        double vy = rand() / (double)RAND_MAX * 100;
        double vz = rand() / (double)RAND_MAX * 100;
        particles[i] = createParticle(mass, x, y, z, vx, vy, vz);
    }

    double dt = 1e-3;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < nParticles; j++) {
            for (int k = j + 1; k < nParticles; k++) {
                calculateForce(particles[j], particles[k]);
            }
        }
        for (int j = 0; j < nParticles; j++) {
            updateParticle(particles[j], dt);
        }
    }

    for (int i = 0; i < nParticles; i++) {
        printf("%f %f %f\n", particles[i]->x, particles[i]->y, particles[i]->z);
        freeParticle(particles[i]);
    }

    return 0;
}