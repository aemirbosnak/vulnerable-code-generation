//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674 * pow(10, -11) // gravitational constant

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass
} Body;

void compute_gravity(Body* bodies, int n) {
    for (int i = 0; i < n; i++) {
        double fx = 0, fy = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx*dx + dy*dy);
                double f = G * bodies[i].mass * bodies[j].mass / (r*r);
                fx += f * dx / r;
                fy += f * dy / r;
            }
        }
        bodies[i].ax = fx / bodies[i].mass;
        bodies[i].ay = fy / bodies[i].mass;
    }
}

void update_bodies(Body* bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

void print_bodies(Body* bodies, int n) {
    for (int i = 0; i < n; i++) {
        printf("Body %d: (%.2f, %.2f) (%.2f, %.2f)\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
}

int main() {
    int n = 3; // number of bodies
    Body* bodies = (Body*) malloc(n * sizeof(Body));

    // initialize bodies
    bodies[0] = (Body) {0, 0, 0, 0, 0, 1000}; // massive body at center
    bodies[1] = (Body) {100, 0, 0, 1, 0, 1}; // small body to the right
    bodies[2] = (Body) {0, 100, -1, 0, 0, 1}; // small body above

    double dt = 0.001; // time step
    int steps = 10000; // number of simulation steps

    for (int i = 0; i < steps; i++) {
        compute_gravity(bodies, n);
        update_bodies(bodies, n, dt);
    }

    print_bodies(bodies, n);

    free(bodies);
    return 0;
}