//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11 // Gravitational constant

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

Body *bodies;
int num_bodies;

void update_forces(Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        double fx = 0, fy = 0, fz = 0;
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }
            double dx = bodies[i].x - bodies[j].x;
            double dy = bodies[i].y - bodies[j].y;
            double dz = bodies[i].z - bodies[j].z;
            double r2 = dx*dx + dy*dy + dz*dz;
            double r = sqrt(r2);
            double f = G * bodies[i].mass * bodies[j].mass / r2;
            fx += f * dx / r;
            fy += f * dy / r;
            fz += f * dz / r;
        }
        bodies[i].vx += fx / bodies[i].mass;
        bodies[i].vy += fy / bodies[i].mass;
        bodies[i].vz += fz / bodies[i].mass;
    }
}

void update_positions(Body *bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void print_bodies(Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: (%.2f, %.2f, %.2f)\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }
}

int main() {
    srand(time(NULL));

    // Create a system of bodies
    num_bodies = 10;
    bodies = malloc(sizeof(Body) * num_bodies);
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].mass = rand() / (double)RAND_MAX;
        bodies[i].x = rand() / (double)RAND_MAX;
        bodies[i].y = rand() / (double)RAND_MAX;
        bodies[i].z = rand() / (double)RAND_MAX;
        bodies[i].vx = 0;
        bodies[i].vy = 0;
        bodies[i].vz = 0;
    }

    // Simulate the system
    double dt = 0.01;
    for (int i = 0; i < 1000; i++) {
        update_forces(bodies, num_bodies);
        update_positions(bodies, num_bodies, dt);
        print_bodies(bodies, num_bodies);
    }

    return 0;
}