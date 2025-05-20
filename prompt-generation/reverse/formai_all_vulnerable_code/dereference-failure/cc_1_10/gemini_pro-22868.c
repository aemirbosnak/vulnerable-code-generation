//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    double mass;
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
} Particle;

Particle *createParticle(double mass, double x, double y, double z, double vx, double vy, double vz) {
    Particle *particle = malloc(sizeof(Particle));
    particle->mass = mass;
    particle->position.x = x;
    particle->position.y = y;
    particle->position.z = z;
    particle->velocity.x = vx;
    particle->velocity.y = vy;
    particle->velocity.z = vz;
    particle->acceleration.x = 0;
    particle->acceleration.y = 0;
    particle->acceleration.z = 0;
    return particle;
}

void destroyParticle(Particle *particle) {
    free(particle);
}

void updateParticle(Particle *particle, double dt) {
    particle->velocity.x += particle->acceleration.x * dt;
    particle->velocity.y += particle->acceleration.y * dt;
    particle->velocity.z += particle->acceleration.z * dt;
    particle->position.x += particle->velocity.x * dt;
    particle->position.y += particle->velocity.y * dt;
    particle->position.z += particle->velocity.z * dt;
}

double calculateGravitationalForce(Particle *particle1, Particle *particle2) {
    double dx = particle1->position.x - particle2->position.x;
    double dy = particle1->position.y - particle2->position.y;
    double dz = particle1->position.z - particle2->position.z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double f = (6.674e-11 * particle1->mass * particle2->mass) / (r * r);
    return f;
}

void calculateGravitationalForceAndAcceleration(Particle *particle1, Particle *particle2) {
    double f = calculateGravitationalForce(particle1, particle2);
    double dx = particle1->position.x - particle2->position.x;
    double dy = particle1->position.y - particle2->position.y;
    double dz = particle1->position.z - particle2->position.z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    particle1->acceleration.x += f * dx / r;
    particle1->acceleration.y += f * dy / r;
    particle1->acceleration.z += f * dz / r;
}

int main() {
    int nparticles = 10;
    Particle *particles[nparticles];
    for (int i = 0; i < nparticles; i++) {
        particles[i] = createParticle(1000, 0, 0, 0, 0, 0, 0);
    }
    double dt = 0.01;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < nparticles; j++) {
            for (int k = j + 1; k < nparticles; k++) {
                calculateGravitationalForceAndAcceleration(particles[j], particles[k]);
            }
        }
        for (int j = 0; j < nparticles; j++) {
            updateParticle(particles[j], dt);
        }
    }
    for (int i = 0; i < nparticles; i++) {
        printf("%f %f %f\n", particles[i]->position.x, particles[i]->position.y, particles[i]->position.z);
        destroyParticle(particles[i]);
    }
    return 0;
}