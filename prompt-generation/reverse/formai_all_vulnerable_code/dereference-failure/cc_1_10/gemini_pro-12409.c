//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_BODIES 9
#define G 6.674e-11

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

Body bodies[NUM_BODIES] = {
    {1.989e30, 0, 0, 0, 0, 0, 0}, // Sun
    {0.33e24, 5.79e10, 0, 0, 0, 12.44e3, 0}, // Mercury
    {4.87e24, 1.082e11, 0, 0, 0, 9.69e3, 0}, // Venus
    {5.97e24, 1.496e11, 0, 0, 0, 6.91e3, 0}, // Earth
    {0.643e24, 2.28e11, 0, 0, 0, 3.5e3, 0}, // Mars
    {1899e24, 7.78e11, 0, 0, 0, 1.33e3, 0}, // Jupiter
    {568e24, 1.433e12, 0, 0, 0, 970, 0}, // Saturn
    {86.8e24, 2.87e12, 0, 0, 0, 680, 0}, // Uranus
    {102e24, 4.5e12, 0, 0, 0, 543, 0} // Neptune
};

void calculateForces(double *f[NUM_BODIES][3]) {
    for (int i = 0; i < NUM_BODIES; i++) {
        for (int j = i + 1; j < NUM_BODIES; j++) {
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double force = G * bodies[i].mass * bodies[j].mass / (r * r);
            f[i][0][0] += force * dx / r;
            f[i][0][1] += force * dy / r;
            f[i][0][2] += force * dz / r;
            f[j][0][0] -= force * dx / r;
            f[j][0][1] -= force * dy / r;
            f[j][0][2] -= force * dz / r;
        }
    }
}

void updatePositions(double dt) {
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void updateVelocities(double dt, double *f[NUM_BODIES][3]) {
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].vx += f[i][0][0] * dt / bodies[i].mass;
        bodies[i].vy += f[i][0][1] * dt / bodies[i].mass;
        bodies[i].vz += f[i][0][2] * dt / bodies[i].mass;
    }
}

int main() {
    double dt = 1e3; // Time step in seconds

    // Create an array to store the forces on each body
    double *f[NUM_BODIES][3];
    for (int i = 0; i < NUM_BODIES; i++) {
        for (int j = 0; j < 3; j++) {
            f[i][j] = malloc(sizeof(double) * NUM_BODIES);
            if (f[i][j] == NULL) {
                return 1;
            }
        }
    }

    // Initialize the forces to zero
    for (int i = 0; i < NUM_BODIES; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < NUM_BODIES; k++) {
                f[i][j][k] = 0;
            }
        }
    }

    // Simulation loop
    for (int i = 0; i < 10000; i++) {
        // Calculate the forces on each body
        calculateForces(f);

        // Update the velocities of each body
        updateVelocities(dt, f);

        // Update the positions of each body
        updatePositions(dt);

        // Print the positions of the bodies
        printf("Positions at time t = %f:\n", i * dt);
        for (int j = 0; j < NUM_BODIES; j++) {
            printf("Body %d: (%f, %f, %f)\n", j, bodies[j].x, bodies[j].y, bodies[j].z);
        }
        printf("\n");
    }

    // Free the memory allocated for the forces
    for (int i = 0; i < NUM_BODIES; i++) {
        for (int j = 0; j < 3; j++) {
            free(f[i][j]);
        }
    }

    return 0;
}