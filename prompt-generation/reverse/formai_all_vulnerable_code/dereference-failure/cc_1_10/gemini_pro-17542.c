//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass; // Mass of the body
    double x, y, z; // Position of the body
    double vx, vy, vz; // Velocity of the body
} Body;

int main() {
    // Create the solar system
    Body sun = {1.989e30, 0, 0, 0, 0, 0};
    Body earth = {5.972e24, 1.5e11, 0, 0, 0, 30000};
    Body moon = {7.348e22, 3.844e8, 0, 0, 0, 1022};

    // Define the simulation parameters
    double dt = 86400; // Time step in seconds
    double t = 0; // Current time
    double tmax = 1e8; // Maximum time to simulate
    int nbodies = 3; // Number of bodies in the simulation

    // Allocate memory for the bodies
    Body *bodies = malloc(nbodies * sizeof(Body));

    // Initialize the bodies
    bodies[0] = sun;
    bodies[1] = earth;
    bodies[2] = moon;

    // Main simulation loop
    while (t < tmax) {
        // Update the positions and velocities of the bodies
        for (int i = 0; i < nbodies; i++) {
            Body *body = &bodies[i];

            // Calculate the acceleration of the body
            double ax = 0, ay = 0, az = 0;
            for (int j = 0; j < nbodies; j++) {
                if (i == j) continue;

                Body *other = &bodies[j];

                // Calculate the distance between the bodies
                double dx = other->x - body->x;
                double dy = other->y - body->y;
                double dz = other->z - body->z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);

                // Calculate the gravitational force between the bodies
                double f = G * body->mass * other->mass / (r * r);

                // Calculate the acceleration of the body
                ax += f * dx / r;
                ay += f * dy / r;
                az += f * dz / r;
            }

            // Update the velocity of the body
            body->vx += ax * dt;
            body->vy += ay * dt;
            body->vz += az * dt;

            // Update the position of the body
            body->x += body->vx * dt;
            body->y += body->vy * dt;
            body->z += body->vz * dt;
        }

        // Print the positions of the bodies
        printf("Sun: %.2e %.2e %.2e\n", sun.x, sun.y, sun.z);
        printf("Earth: %.2e %.2e %.2e\n", earth.x, earth.y, earth.z);
        printf("Moon: %.2e %.2e %.2e\n", moon.x, moon.y, moon.z);

        // Update the time
        t += dt;
    }

    // Free the memory allocated for the bodies
    free(bodies);

    return 0;
}