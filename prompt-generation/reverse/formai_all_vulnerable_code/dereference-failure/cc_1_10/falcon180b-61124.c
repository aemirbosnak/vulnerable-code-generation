//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational Constant
#define PI 3.14159265358979323846 // Pi

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double ax;
    double ay;
    double az;
    double mass;
} Particle;

void init_particle(Particle* p, double x, double y, double z, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = 0;
    p->vy = 0;
    p->vz = 0;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
    p->mass = mass;
}

void update_acceleration(Particle* p1, Particle* p2, double dt) {
    double r = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
    double F = G * p1->mass * p2->mass / pow(r, 2);
    double ax = F * (p1->x - p2->x) / r;
    double ay = F * (p1->y - p2->y) / r;
    double az = F * (p1->z - p2->z) / r;
    p1->ax += ax;
    p2->ax -= ax;
    p1->ay += ay;
    p2->ay -= ay;
    p1->az += az;
    p2->az -= az;
}

void update_velocity(Particle* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(Particle* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    int num_particles = 1000;
    Particle* particles = malloc(sizeof(Particle) * num_particles);
    srand(time(NULL));
    for (int i = 0; i < num_particles; i++) {
        double x = rand() % 1000 - 500;
        double y = rand() % 1000 - 500;
        double z = rand() % 1000 - 500;
        double mass = rand() % 1000 + 1;
        init_particle(&particles[i], x, y, z, mass);
    }

    double dt = 0.001;
    int iterations = 1000;

    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < num_particles - 1; j++) {
            for (int k = j + 1; k < num_particles; k++) {
                update_acceleration(&particles[j], &particles[k], dt);
            }
        }

        for (int j = 0; j < num_particles; j++) {
            update_velocity(&particles[j], dt);
            update_position(&particles[j], dt);
        }
    }

    free(particles);
    return 0;
}