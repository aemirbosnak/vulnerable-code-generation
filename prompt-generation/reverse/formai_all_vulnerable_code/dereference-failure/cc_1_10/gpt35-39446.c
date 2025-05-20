//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    Vec3 pos;
    Vec3 velocity;
    Vec3 force;
    double mass;
} Body;

int main() {
    // Set up bodies
    const int numBodies = 3;
    Body* bodies = malloc(numBodies * sizeof(Body));
    bodies[0] = (Body) { .pos = {0, 0, 0}, .velocity = {0, 0, 0}, .force = {0, 0, 0}, .mass = 5.9722e24 };
    bodies[1] = (Body) { .pos = {-1.496e11, 0, 0}, .velocity = {0, 29783, 0}, .force = {0, 0, 0}, .mass = 1.9885e30 };
    bodies[2] = (Body) { .pos = {0, 0, 384400000}, .velocity = {1022, 0, 0}, .force = {0, 0, 0}, .mass = 7.342e22 };

    // Set up simulation parameters
    const double timeStep = 86400; // 1 day
    const double simulationDuration = 365 * timeStep;
    const int numTimeSteps = simulationDuration / timeStep;

    // Run simulation
    for (int i = 0; i < numTimeSteps; i++) {
        // Calculate forces on each body
        for (int j = 0; j < numBodies; j++) {
            bodies[j].force.x = 0;
            bodies[j].force.y = 0;
            bodies[j].force.z = 0;
            for (int k = 0; k < numBodies; k++) {
                if (j != k) {
                    Vec3 r = { bodies[k].pos.x - bodies[j].pos.x, bodies[k].pos.y - bodies[j].pos.y, bodies[k].pos.z - bodies[j].pos.z };
                    double distance = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
                    double magnitude = G * bodies[j].mass * bodies[k].mass / pow(distance, 2);
                    bodies[j].force.x += magnitude * r.x / distance;
                    bodies[j].force.y += magnitude * r.y / distance;
                    bodies[j].force.z += magnitude * r.z / distance;
                }
            }
        }

        // Update velocity and position of each body
        for (int j = 0; j < numBodies; j++) {
            // Update velocity
            bodies[j].velocity.x += bodies[j].force.x / bodies[j].mass * timeStep;
            bodies[j].velocity.y += bodies[j].force.y / bodies[j].mass * timeStep;
            bodies[j].velocity.z += bodies[j].force.z / bodies[j].mass * timeStep;

            // Update position
            bodies[j].pos.x += bodies[j].velocity.x * timeStep;
            bodies[j].pos.y += bodies[j].velocity.y * timeStep;
            bodies[j].pos.z += bodies[j].velocity.z * timeStep;

            // Print position of Earth and Moon every 10th time step
            if (j == 0 && i % 10 == 0) {
                printf("Earth: (%.0f, %.0f, %.0f)\n", bodies[0].pos.x, bodies[0].pos.y, bodies[0].pos.z);
                printf("Moon: (%.0f, %.0f, %.0f)\n", bodies[2].pos.x, bodies[2].pos.y, bodies[2].pos.z);
            }
        }
    }

    free(bodies);

    return 0;
}