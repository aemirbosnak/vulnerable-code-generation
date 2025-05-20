//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 /* Gravitational constant */

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Body;

Body *bodies;
int nbodies;

void init_bodies(int n) {
    bodies = malloc(n * sizeof(Body));
    nbodies = n;

    for (int i = 0; i < n; i++) {
        bodies[i].mass = 1.0;
        bodies[i].x = (double)rand() / RAND_MAX;
        bodies[i].y = (double)rand() / RAND_MAX;
        bodies[i].z = (double)rand() / RAND_MAX;
        bodies[i].vx = 0.0;
        bodies[i].vy = 0.0;
        bodies[i].vz = 0.0;
    }
}

void update_velocities(double dt) {
    for (int i = 0; i < nbodies; i++) {
        double ax = 0.0, ay = 0.0, az = 0.0;
        for (int j = 0; j < nbodies; j++) {
            if (i == j) continue;

            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);

            ax -= G * bodies[j].mass * dx / (r * r * r);
            ay -= G * bodies[j].mass * dy / (r * r * r);
            az -= G * bodies[j].mass * dz / (r * r * r);
        }

        bodies[i].vx += ax * dt;
        bodies[i].vy += ay * dt;
        bodies[i].vz += az * dt;
    }
}

void update_positions(double dt) {
    for (int i = 0; i < nbodies; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void simulate(double dt, int nsteps) {
    for (int i = 0; i < nsteps; i++) {
        update_velocities(dt);
        update_positions(dt);
    }
}

void print_bodies() {
    for (int i = 0; i < nbodies; i++) {
        printf("Body %d: (%.3f, %.3f, %.3f)\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }
}

int main() {
    init_bodies(100);
    simulate(0.001, 10000);
    print_bodies();

    return 0;
}