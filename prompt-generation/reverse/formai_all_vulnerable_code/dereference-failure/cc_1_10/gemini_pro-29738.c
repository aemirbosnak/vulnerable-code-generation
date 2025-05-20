//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double x, y, z;  // position
    double vx, vy, vz;  // velocity
    double m;  // mass
} Body;

const double G = 6.67408e-11;  // Gravitational constant
const double DT = 1000;  // Time step (seconds)
const int NUM_BODIES = 10000;  // Number of bodies

// Initialize the bodies randomly
void initialize_bodies(Body *bodies) {
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].x = (double)rand() / RAND_MAX * 100000;
        bodies[i].y = (double)rand() / RAND_MAX * 100000;
        bodies[i].z = (double)rand() / RAND_MAX * 100000;
        bodies[i].vx = (double)rand() / RAND_MAX * 100;
        bodies[i].vy = (double)rand() / RAND_MAX * 100;
        bodies[i].vz = (double)rand() / RAND_MAX * 100;
        bodies[i].m = (double)rand() / RAND_MAX * 1000;
    }
}

// Calculate the gravitational force between two bodies
void calculate_force(Body *body1, Body *body2, double *fx, double *fy, double *fz) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double dz = body2->z - body1->z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * body1->m * body2->m / (r * r);
    *fx = f * dx / r;
    *fy = f * dy / r;
    *fz = f * dz / r;
}

// Update the velocities and positions of the bodies
void update_bodies(Body *bodies) {
    for (int i = 0; i < NUM_BODIES; i++) {
        double fx = 0, fy = 0, fz = 0;
        for (int j = 0; j < NUM_BODIES; j++) {
            if (i == j) continue;
            calculate_force(&bodies[i], &bodies[j], &fx, &fy, &fz);
        }
        bodies[i].vx += fx / bodies[i].m * DT;
        bodies[i].vy += fy / bodies[i].m * DT;
        bodies[i].vz += fz / bodies[i].m * DT;
        bodies[i].x += bodies[i].vx * DT;
        bodies[i].y += bodies[i].vy * DT;
        bodies[i].z += bodies[i].vz * DT;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Allocate memory for the bodies
    Body *bodies = (Body *)malloc(sizeof(Body) * NUM_BODIES);

    // Initialize the bodies randomly
    initialize_bodies(bodies);

    // Simulate the system for 100 time steps
    for (int i = 0; i < 100; i++) {
        // Update the velocities and positions of the bodies
        update_bodies(bodies);
    }

    // Free the memory allocated for the bodies
    free(bodies);

    return 0;
}