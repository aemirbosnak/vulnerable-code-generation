//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11

typedef struct {
    double x, y;
} Vector;

typedef struct {
    Vector pos, vel, force;
    double mass;
} Body;

void update_forces(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].force.x = 0;
        bodies[i].force.y = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            Vector r;
            r.x = bodies[j].pos.x - bodies[i].pos.x;
            r.y = bodies[j].pos.y - bodies[i].pos.y;

            double distance = sqrt(r.x * r.x + r.y * r.y);

            double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);

            bodies[i].force.x += force * r.x / distance;
            bodies[i].force.y += force * r.y / distance;
        }
    }
}

void update_positions(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].vel.x += bodies[i].force.x / bodies[i].mass * dt;
        bodies[i].vel.y += bodies[i].force.y / bodies[i].mass * dt;

        bodies[i].pos.x += bodies[i].vel.x * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt;
    }
}

int main() {
    int n = 3;
    Body *bodies = malloc(n * sizeof(Body));

    // Sun
    bodies[0].mass = 1.989e30;
    bodies[0].pos.x = 0;
    bodies[0].pos.y = 0;
    bodies[0].vel.x = 0;
    bodies[0].vel.y = 0;

    // Earth
    bodies[1].mass = 5.972e24;
    bodies[1].pos.x = 1.496e11;
    bodies[1].pos.y = 0;
    bodies[1].vel.x = 0;
    bodies[1].vel.y = 2.978e4;

    // Moon
    bodies[2].mass = 7.342e22;
    bodies[2].pos.x = 1.496e11;
    bodies[2].pos.y = 3.844e8;
    bodies[2].vel.x = 1.022e3;
    bodies[2].vel.y = 2.978e4;

    double dt = 24 * 3600;  // One day

    for (int i = 0; i < 365; i++) {
        update_forces(bodies, n);
        update_positions(bodies, n, dt);

        printf("%f %f %f %f %f %f %f %f %f\n",
               bodies[0].pos.x, bodies[0].pos.y,
               bodies[0].vel.x, bodies[0].vel.y,
               bodies[1].pos.x, bodies[1].pos.y,
               bodies[1].vel.x, bodies[1].vel.y,
               bodies[2].pos.y);
    }

    free(bodies);

    return 0;
}