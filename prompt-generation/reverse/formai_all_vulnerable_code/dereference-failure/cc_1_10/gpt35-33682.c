//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

typedef struct {
    double x, y; // position components
} Point;

typedef struct {
    Point pos; // position
    Point vel; // velocity
    double mass; // mass
} Body;

int main() {
    // initialize bodies
    const int numBodies = 4;
    Body *bodies = malloc(numBodies * sizeof(Body));
    bodies[0].pos.x = 0;
    bodies[0].pos.y = 0;
    bodies[0].vel.x = 0;
    bodies[0].vel.y = 0;
    bodies[0].mass = 1.989e30; // mass of the sun
    bodies[1].pos.x = 147095000000;
    bodies[1].pos.y = 0;
    bodies[1].vel.x = 0;
    bodies[1].vel.y = 30290;
    bodies[1].mass = 5.97e24; // mass of earth
    bodies[2].pos.x = 0;
    bodies[2].pos.y = 1520982322000;
    bodies[2].vel.x = 29300;
    bodies[2].vel.y = 0;
    bodies[2].mass = 3.285e23; // mass of mars
    bodies[3].pos.x = -778547200000;
    bodies[3].pos.y = 0;
    bodies[3].vel.x = 0;
    bodies[3].vel.y = -13100;
    bodies[3].mass = 1.898e27; // mass of jupiter

    const double dt = 86400; // time step size (1 day in seconds)
    const double simTime = 365.25 * 10 * 86400; // simulate 10 years

    // simulate motion
    for (double t = 0; t < simTime; t += dt) {
        // calculate gravitational forces
        for (int i = 0; i < numBodies; i++) {
            double fx = 0, fy = 0; // total force on body i
            for (int j = 0; j < numBodies; j++) {
                if (i == j) continue; // skip self-interaction
                double dx = bodies[j].pos.x - bodies[i].pos.x;
                double dy = bodies[j].pos.y - bodies[i].pos.y;
                double r = sqrt(dx*dx + dy*dy);
                double f = G * bodies[i].mass * bodies[j].mass / (r*r);
                fx += f * dx / r;
                fy += f * dy / r;
            }
            // update velocity and position
            bodies[i].vel.x += fx / bodies[i].mass * dt;
            bodies[i].vel.y += fy / bodies[i].mass * dt;
            bodies[i].pos.x += bodies[i].vel.x * dt;
            bodies[i].pos.y += bodies[i].vel.y * dt;
        }
        // print current state of system
        printf("%.0f: sun(%.8e,%.8e), earth(%.8e,%.8e), mars(%.8e,%.8e), jupiter(%.8e,%.8e)\n", t/dt+1, bodies[0].pos.x, bodies[0].pos.y, bodies[1].pos.x, bodies[1].pos.y, bodies[2].pos.x, bodies[2].pos.y, bodies[3].pos.x, bodies[3].pos.y);
    }

    free(bodies);
    return 0;
}