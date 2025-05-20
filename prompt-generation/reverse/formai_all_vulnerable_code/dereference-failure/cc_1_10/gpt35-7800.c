//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BODIES 10
#define GRAVITATIONAL_CONSTANT 6.6743e-11

typedef struct {
   double x, y;         /* position */
   double vx, vy;       /* velocity */
   double fx, fy;       /* force */
   double mass;         /* mass */
} Body;

int main(int argc, char* argv[]) {

    int num_bodies;                 /* number of bodies in simulation */
    double universe_size;           /* size of universe */
    double time_step;               /* simulation time step */
    int i, j, k;                    /* loop indices */
    double dx, dy;                  /* distance between two bodies */
    double dist_squared;            /* squared distance between two bodies */
    double force_magnitude;         /* magnitude of force between two bodies */
    double x_force, y_force;        /* force in x and y directions */
    int num_iterations;             /* number of iterations */

    /* read input parameters */
    scanf("%d", &num_bodies);
    scanf("%lf", &universe_size);
    scanf("%lf", &time_step);
    scanf("%d", &num_iterations);

    /* allocate space for bodies */
    Body* bodies = (Body*) malloc(num_bodies * sizeof(Body));

    /* read in body data */
    for (i = 0; i < num_bodies; i++) {
        scanf("%lf %lf %lf %lf %lf", &bodies[i].mass, &bodies[i].x, &bodies[i].y, &bodies[i].vx, &bodies[i].vy);
        bodies[i].fx = 0.0;
        bodies[i].fy = 0.0;
    }

    /* simulate motion */
    for (k = 0; k < num_iterations; k++) {

        /* reset forces */
        for (i = 0; i < num_bodies; i++) {
            bodies[i].fx = 0.0;
            bodies[i].fy = 0.0;
        }

        /* compute forces */
        for (i = 0; i < num_bodies; i++) {
            for (j = i+1; j < num_bodies; j++) {
                dx = bodies[j].x - bodies[i].x;
                dy = bodies[j].y - bodies[i].y;
                dist_squared = dx*dx + dy*dy;
                force_magnitude = GRAVITATIONAL_CONSTANT * bodies[i].mass * bodies[j].mass / dist_squared;
                x_force = force_magnitude * dx / sqrt(dist_squared);
                y_force = force_magnitude * dy / sqrt(dist_squared);
                bodies[i].fx += x_force;
                bodies[i].fy += y_force;
                bodies[j].fx -= x_force;
                bodies[j].fy -= y_force;
            }
        }

        /* update velocities and positions */
        for (i = 0; i < num_bodies; i++) {
            bodies[i].vx += bodies[i].fx * time_step / bodies[i].mass;
            bodies[i].vy += bodies[i].fy * time_step / bodies[i].mass;
            bodies[i].x += bodies[i].vx * time_step;
            bodies[i].y += bodies[i].vy * time_step;
        }

    }

    /* print final positions */
    for (i = 0; i < num_bodies; i++) {
        printf("%.3f %.3f\n", bodies[i].x, bodies[i].y);
    }

    /* free memory */
    free(bodies);

    return 0;
}