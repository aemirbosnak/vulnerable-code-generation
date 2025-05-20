//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define PI 3.14159265358979323846

typedef struct {
    double mass;
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
} Body;

int main() {
    // Number of bodies
    int n = 1000;

    // Allocate memory for bodies
    Body *bodies = malloc(n * sizeof(Body));

    // Initialize bodies
    for (int i = 0; i < n; i++) {
        bodies[i].mass = 1e24; // Mass of the Earth
        bodies[i].x = 0; // Position
        bodies[i].y = 0; // Position
        bodies[i].z = 0; // Position
        bodies[i].vx = 0; // Velocity
        bodies[i].vy = 0; // Velocity
        bodies[i].vz = 0; // Velocity
    }

    // Time step
    double dt = 1e6; // 1 million seconds

    // Simulation time
    double t = 0;

    // Simulation loop
    while (t < 1e12) { // 1 trillion seconds
        // Calculate gravitational forces
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate distance between bodies
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);

                // Calculate gravitational force
                double F = G * bodies[i].mass * bodies[j].mass / (r * r);

                // Calculate acceleration
                double ax = F * dx / r;
                double ay = F * dy / r;
                double az = F * dz / r;

                // Update velocities
                bodies[i].vx += ax * dt;
                bodies[i].vy += ay * dt;
                bodies[i].vz += az * dt;
                bodies[j].vx -= ax * dt;
                bodies[j].vy -= ay * dt;
                bodies[j].vz -= az * dt;
            }
        }

        // Update positions
        for (int i = 0; i < n; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        // Update time
        t += dt;
    }

    // Print final positions
    for (int i = 0; i < n; i++) {
        printf("Body %d: (%.2f, %.2f, %.2f)\n", i + 1, bodies[i].x, bodies[i].y, bodies[i].z);
    }

    // Free memory
    free(bodies);

    return 0;
}