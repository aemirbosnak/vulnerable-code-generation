//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Body;

typedef struct {
    Body *bodies;
    int n_bodies;
} System;

double distance(Body *a, Body *b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    double dz = a->z - b->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void apply_gravity(System *system, double dt) {
    for (int i = 0; i < system->n_bodies; i++) {
        Body *a = &system->bodies[i];
        for (int j = i + 1; j < system->n_bodies; j++) {
            Body *b = &system->bodies[j];
            double d = distance(a, b);
            double f = a->mass * b->mass / (d * d);
            double dx = b->x - a->x;
            double dy = b->y - a->y;
            double dz = b->z - a->z;
            a->vx += f * dx / d * dt;
            a->vy += f * dy / d * dt;
            a->vz += f * dz / d * dt;
            b->vx -= f * dx / d * dt;
            b->vy -= f * dy / d * dt;
            b->vz -= f * dz / d * dt;
        }
    }
}

void update_positions(System *system, double dt) {
    for (int i = 0; i < system->n_bodies; i++) {
        Body *body = &system->bodies[i];
        body->x += body->vx * dt;
        body->y += body->vy * dt;
        body->z += body->vz * dt;
    }
}

void simulate(System *system, double dt, int steps) {
    for (int i = 0; i < steps; i++) {
        apply_gravity(system, dt);
        update_positions(system, dt);
    }
}

void print_system(System *system) {
    for (int i = 0; i < system->n_bodies; i++) {
        Body *body = &system->bodies[i];
        printf("Body %d: (%f, %f, %f)\n", i, body->x, body->y, body->z);
    }
}

int main() {
    // Create a system of bodies
    System system;
    system.n_bodies = 3;
    system.bodies = (Body *)malloc(sizeof(Body) * system.n_bodies);
    system.bodies[0].mass = 1.0;
    system.bodies[0].x = 0.0;
    system.bodies[0].y = 0.0;
    system.bodies[0].z = 0.0;
    system.bodies[0].vx = 0.0;
    system.bodies[0].vy = 0.0;
    system.bodies[0].vz = 0.0;
    system.bodies[1].mass = 2.0;
    system.bodies[1].x = 1.0;
    system.bodies[1].y = 0.0;
    system.bodies[1].z = 0.0;
    system.bodies[1].vx = 0.0;
    system.bodies[1].vy = 0.0;
    system.bodies[1].vz = 0.0;
    system.bodies[2].mass = 3.0;
    system.bodies[2].x = 2.0;
    system.bodies[2].y = 0.0;
    system.bodies[2].z = 0.0;
    system.bodies[2].vx = 0.0;
    system.bodies[2].vy = 0.0;
    system.bodies[2].vz = 0.0;

    // Simulate the system
    simulate(&system, 0.01, 1000);

    // Print the system
    print_system(&system);

    return 0;
}