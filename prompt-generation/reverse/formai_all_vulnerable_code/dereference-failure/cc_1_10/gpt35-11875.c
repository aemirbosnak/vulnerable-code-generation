//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant in metres cubed per kilogram second squared

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double mass; // mass
} Body;

int main(int argc, char* argv[]) {
    int num_bodies = 4; // number of bodies
    int duration = 10; // duration of simulation (in seconds)
    double delta_t = 1e-3; // time step (in seconds)

    Body* bodies = calloc(num_bodies, sizeof(Body));

    // set initial position, velocity, mass of each body
    bodies[0] = (Body) {.x = 3e8, .y = 0, .z = 0, .vx = 0, .vy = 5e3, .vz = 0, .mass = 2e30}; // sun
    bodies[1] = (Body) {.x = 1.5e11, .y = 0, .z = 0, .vx = 0, .vy = 3e4, .vz = 0, .mass = 6e24}; // earth
    bodies[2] = (Body) {.x = 2.28e11, .y = 0, .z = 0, .vx = 0, .vy = 2.3e4, .vz = 0, .mass = 6e24}; // mars
    bodies[3] = (Body) {.x = 1.08e11, .y = 0, .z = 0, .vx = 0, .vy = 4.8e4, .vz = 0, .mass = 3e23}; // venus

    int num_steps = duration / delta_t;

    for (int step = 0; step < num_steps; step++) {
        // calculate acceleration for each body
        for (int i = 0; i < num_bodies; i++) {
            double ax = 0, ay = 0, az = 0;
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    double dx = bodies[j].x - bodies[i].x;
                    double dy = bodies[j].y - bodies[i].y;
                    double dz = bodies[j].z - bodies[i].z;
                    double r = sqrt(dx*dx + dy*dy + dz*dz);
                    double force = G * bodies[i].mass * bodies[j].mass / (r*r);
                    ax += force * dx / r;
                    ay += force * dy / r;
                    az += force * dz / r;
                }
            }
            bodies[i].ax = ax / bodies[i].mass;
            bodies[i].ay = ay / bodies[i].mass;
            bodies[i].az = az / bodies[i].mass;
        }

        // calculate new velocity and position for each body
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].vx += bodies[i].ax * delta_t;
            bodies[i].vy += bodies[i].ay * delta_t;
            bodies[i].vz += bodies[i].az * delta_t;
            bodies[i].x += bodies[i].vx * delta_t;
            bodies[i].y += bodies[i].vy * delta_t;
            bodies[i].z += bodies[i].vz * delta_t;
        }

        // output position of each body
        for (int i = 0; i < num_bodies; i++) {
            printf("Body %d: x = %g m, y = %g m, z = %g m\n", i+1, bodies[i].x, bodies[i].y, bodies[i].z);
        }
        printf("\n");
    }

    free(bodies);

    return 0;
}