//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONSTANT 6.67430E-11 // Gravitational constant

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass;
} body_t;

int main() {
    const int num_bodies = 3; // number of celestial bodies
    const double dt = 1.0 / 30.0; // time step

    // Define the celestial bodies
    body_t bodies[] = {
        { 0.0, 0.0, 0.0, 0.0, 1.0e+5 }, // Sun
        { 1.49597870700E+11, 0.0, 0.0, 2.9783E+4, 5.97e+24 }, // Earth
        { 1.4969e+11, 384400000.0, -1022.0, 0.0, 7.342e+22 } // Moon
    };

    // Define the number of steps
    const int num_steps = 365*24*3600/(int)(dt);
    int i, j, step;

    // Calculate the force on each body
    double fx[num_bodies], fy[num_bodies];
    for (step = 0; step < num_steps; ++step) {
        for (i = 0; i < num_bodies; ++i) {
            double fx_i = 0.0, fy_i = 0.0;
            for (j = 0; j < num_bodies; ++j) {
                if (i != j) {
                    double dx = bodies[j].x - bodies[i].x;
                    double dy = bodies[j].y - bodies[i].y;
                    double dist = sqrt(dx*dx + dy*dy);
                    double f = G_CONSTANT * bodies[i].mass * bodies[j].mass / (dist * dist);
                    fx_i += f * dx / dist;
                    fy_i += f * dy / dist;
                }
            }
            fx[i] = fx_i;
            fy[i] = fy_i;
        }

        // Update the position and velocity of each body
        for (i = 0; i < num_bodies; ++i) {
            bodies[i].vx += fx[i] / bodies[i].mass * dt;
            bodies[i].vy += fy[i] / bodies[i].mass * dt;
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
        }

        printf("%lf\t%lf\n", bodies[1].x, bodies[1].y); // Print the position of the Earth in x and y coordinates
    }

    return 0;
}