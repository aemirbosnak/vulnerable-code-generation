//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81 // gravity constant in meters per second squared
#define TIMESTEP 0.1 // simulation timestep in seconds
#define MAX_TIME 60 // simulation maximum time in seconds

typedef struct {
    double x; // position along x-axis
    double y; // position along y-axis
    double vx; // velocity along x-axis
    double vy; // velocity along y-axis
    double m; // mass
} Body;

int main() {
    // initialize simulation variables
    int num_bodies = 3;
    Body *bodies = (Body*) malloc(num_bodies * sizeof(Body));
    double ax, ay, dx, dy, distance, force;

    // set up initial conditions for bodies
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[0].m = 1000;

    bodies[1].x = 10;
    bodies[1].y = 10;
    bodies[1].vx = 0;
    bodies[1].vy = 0;
    bodies[1].m = 500;

    bodies[2].x = -10;
    bodies[2].y = -10;
    bodies[2].vx = 0;
    bodies[2].vy = 0;
    bodies[2].m = 2000;

    // simulate motion of bodies
    for (double t = 0; t < MAX_TIME; t += TIMESTEP) {
        // calculate net forces on each body
        for (int i = 0; i < num_bodies; i++) {
            ax = 0;
            ay = 0;

            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;

                dx = bodies[j].x - bodies[i].x;
                dy = bodies[j].y - bodies[i].y;

                distance = sqrt(dx*dx + dy*dy);
                force = (G * bodies[i].m * bodies[j].m) / (distance * distance);

                ax += force * (dx / distance) / bodies[i].m;
                ay += force * (dy / distance) / bodies[i].m;
            }

            // update velocity and position of body using net force
            bodies[i].vx += ax * TIMESTEP;
            bodies[i].vy += ay * TIMESTEP;
            bodies[i].x += bodies[i].vx * TIMESTEP;
            bodies[i].y += bodies[i].vy * TIMESTEP;
        }

        // print out current positions of bodies
        printf("Time: %lf\n", t);
        for (int i = 0; i < num_bodies; i++) {
            printf("Body %d: (%lf, %lf)\n", i, bodies[i].x, bodies[i].y);
        }
        printf("\n");
    }

    free(bodies);
    return 0;
}