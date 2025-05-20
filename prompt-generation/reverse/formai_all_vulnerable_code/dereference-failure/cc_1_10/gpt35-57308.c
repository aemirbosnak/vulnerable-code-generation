//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11    // gravitational constant (m^3/kg.s^2)

typedef struct {
    double x, y, z;    // position vector components (m)
    double vx, vy, vz; // velocity vector components (m/s)
    double mass;       // mass (kg)
} Body;

void compute_forces(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            double distance = sqrt(dx * dx + dy * dy + dz * dz);
            double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);
            double fx = force * dx / distance;
            double fy = force * dy / distance;
            double fz = force * dz / distance;
            bodies[i].vx += fx / bodies[i].mass;
            bodies[i].vy += fy / bodies[i].mass;
            bodies[i].vz += fz / bodies[i].mass;
            bodies[j].vx -= fx / bodies[j].mass;
            bodies[j].vy -= fy / bodies[j].mass;
            bodies[j].vz -= fz / bodies[j].mass;
        }
    }
}

void update_positions(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void simulate(Body *bodies, int n, double dt, int steps) {
    for (int i = 0; i < steps; i++) {
        compute_forces(bodies, n);
        update_positions(bodies, n, dt);
    }
}

int main() {
    srand(time(NULL));
    int n = 4;
    double dt = 0.01;
    int steps = 1000;
    Body *bodies = (Body *) malloc(n * sizeof(Body));
    for (int i = 0; i < n; i++) {
        bodies[i].x = rand() % 1000;
        bodies[i].y = rand() % 1000;
        bodies[i].z = rand() % 1000;
        bodies[i].vx = (rand() % 100) - 50;
        bodies[i].vy = (rand() % 100) - 50;
        bodies[i].vz = (rand() % 100) - 50;
        bodies[i].mass = (rand() % 100) + 1;
    }
    simulate(bodies, n, dt, steps);
    for (int i = 0; i < n; i++) {
        printf("Body %d: position {%f, %f, %f} velocity {%f, %f, %f} mass %f\n", i+1, bodies[i].x, bodies[i].y, bodies[i].z, bodies[i].vx, bodies[i].vy, bodies[i].vz, bodies[i].mass);
    }
    free(bodies);
    return 0;
}