//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define dt 1e3 // Time step (seconds)
#define N 1000 // Number of timesteps

// Body structure
typedef struct body {
    double m; // Mass (kg)
    double x; // Position (x-coordinate, m)
    double y; // Position (y-coordinate, m)
    double z; // Position (z-coordinate, m)
    double vx; // Velocity (x-component, m/s)
    double vy; // Velocity (y-component, m/s)
    double vz; // Velocity (z-component, m/s)
} body;

// Create a new body
body *body_new(double m, double x, double y, double z, double vx, double vy, double vz) {
    body *b = malloc(sizeof(body));
    b->m = m;
    b->x = x;
    b->y = y;
    b->z = z;
    b->vx = vx;
    b->vy = vy;
    b->vz = vz;
    return b;
}

// Free a body
void body_free(body *b) {
    free(b);
}

// Calculate the gravitational force between two bodies
void force(body *a, body *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * a->m * b->m / (r * r);
    a->vx -= f * dx / r;
    a->vy -= f * dy / r;
    a->vz -= f * dz / r;
    b->vx += f * dx / r;
    b->vy += f * dy / r;
    b->vz += f * dz / r;
}

// Update the positions and velocities of all bodies
void update(body *bodies[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            force(bodies[i], bodies[j]);
        }
        bodies[i]->x += bodies[i]->vx * dt;
        bodies[i]->y += bodies[i]->vy * dt;
        bodies[i]->z += bodies[i]->vz * dt;
    }
}

// Print the positions and velocities of all bodies
void print(body *bodies[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f %f %f %f %f %f %f\n", bodies[i]->m, bodies[i]->x, bodies[i]->y, bodies[i]->z, bodies[i]->vx, bodies[i]->vy, bodies[i]->vz);
    }
}

// Main function
int main() {
    // Create the bodies
    body *bodies[] = {
        body_new(1e30, 0, 0, 0, 0, 0, 0), // Sun
        body_new(5.972e24, -2e11, 0, 0, 0, 2e4, 0), // Earth
        body_new(7.348e22, -4e11, 0, 0, 0, 1e4, 0), // Mars
        body_new(1.899e27, 1e11, 0, 0, 0, -1e3, 0), // Jupiter
        body_new(5.685e26, 2e11, 0, 0, 0, -2e3, 0), // Saturn
        body_new(8.683e25, 3e11, 0, 0, 0, -3e3, 0), // Uranus
        body_new(1.024e26, 4e11, 0, 0, 0, -4e3, 0) // Neptune
    };

    // Update the positions and velocities of the bodies
    for (int i = 0; i < N; i++) {
        update(bodies, 7);
    }

    // Print the positions and velocities of the bodies
    print(bodies, 7);

    // Free the bodies
    for (int i = 0; i < 7; i++) {
        body_free(bodies[i]);
    }

    return 0;
}