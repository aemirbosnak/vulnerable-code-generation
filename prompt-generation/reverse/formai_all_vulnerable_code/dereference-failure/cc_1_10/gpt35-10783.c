//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430E-11   // gravitational constant

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
    double mass;
} Body;

int main()
{
    const int N = 3;    // number of bodies

    // initialize bodies
    Body* bodies = (Body*)malloc(N * sizeof(Body));
    // body 1
    bodies[0].x = 0.0;
    bodies[0].y = 0.0;
    bodies[0].z = 0.0;
    bodies[0].vx = 0.0;
    bodies[0].vy = 0.0;
    bodies[0].vz = 0.0;
    bodies[0].mass = 1.0;
    // body 2
    bodies[1].x = 1.0;
    bodies[1].y = 0.0;
    bodies[1].z = 0.0;
    bodies[1].vx = 0.0;
    bodies[1].vy = 2.0;
    bodies[1].vz = 0.0;
    bodies[1].mass = 2.0;
    // body 3
    bodies[2].x = 0.0;
    bodies[2].y = 1.0;
    bodies[2].z = 0.0;
    bodies[2].vx = -1.0;
    bodies[2].vy = 0.0;
    bodies[2].vz = 0.0;
    bodies[2].mass = 3.0;

    // simulation parameters
    const int steps = 1000;
    const double dt = 0.01;
    const double tol = 1E-6;

    // simulation loop
    for (int s = 0; s < steps; s++) {
        // compute forces
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                // distance vector
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                if (r < tol) r = tol;   // avoid division by zero
                // gravitational force
                double f = G * bodies[i].mass * bodies[j].mass / (r*r*r);
                double fx = f * dx;
                double fy = f * dy;
                double fz = f * dz;
                // add to force on body i
                bodies[i].fx += fx;
                bodies[i].fy += fy;
                bodies[i].fz += fz;
                // subtract from force on body j
                bodies[j].fx -= fx;
                bodies[j].fy -= fy;
                bodies[j].fz -= fz;
            }
        }
        // compute new velocities and positions
        for (int i = 0; i < N; i++) {
            // update velocity
            bodies[i].vx += bodies[i].fx * dt / bodies[i].mass;
            bodies[i].vy += bodies[i].fy * dt / bodies[i].mass;
            bodies[i].vz += bodies[i].fz * dt / bodies[i].mass;
            // update position
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
            // reset force
            bodies[i].fx = 0.0;
            bodies[i].fy = 0.0;
            bodies[i].fz = 0.0;
        }
    }

    // print results
    for (int i = 0; i < N; i++) {
        printf("Body %d: x=%f, y=%f, z=%f\n", i+1, bodies[i].x, bodies[i].y, bodies[i].z);
    }

    free(bodies);
    return 0;
}