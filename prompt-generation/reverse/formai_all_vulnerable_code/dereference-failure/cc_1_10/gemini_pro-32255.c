//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;           // Mass in kilograms
    double x;             // X coordinate in meters
    double y;             // Y coordinate in meters
    double vx;            // X velocity in meters per second
    double vy;            // Y velocity in meters per second
} Body;

// Gravitational constant in meters cubed per kilogram per second squared
const double G = 6.674e-11;

// Time step in seconds
const double dt = 1000;

// Number of bodies
const int N = 10;

// Initialize bodies randomly
void initBodies(Body *bodies) {
    for (int i = 0; i < N; i++) {
        // Mass between 1e24 and 1e25 kilograms
        bodies[i].mass = 1e24 + 1e25 * (double)rand() / RAND_MAX;

        // Position between -1e12 and 1e12 meters
        bodies[i].x = -1e12 + 2e12 * (double)rand() / RAND_MAX;
        bodies[i].y = -1e12 + 2e12 * (double)rand() / RAND_MAX;

        // Velocity between -100 and 100 meters per second
        bodies[i].vx = -100 + 200 * (double)rand() / RAND_MAX;
        bodies[i].vy = -100 + 200 * (double)rand() / RAND_MAX;
    }
}

// Calculate the gravitational force between two bodies
void calcForce(Body *body1, Body *body2) {
    // Calculate the distance between the bodies
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double distance = sqrt(dx*dx + dy*dy);

    // Calculate the force
    double force = G * body1->mass * body2->mass / (distance*distance);

    // Calculate the direction of the force
    double angle = atan2(dy, dx);

    // Apply the force to the bodies
    body1->vx -= force * cos(angle) / body1->mass * dt;
    body1->vy -= force * sin(angle) / body1->mass * dt;
    body2->vx += force * cos(angle) / body2->mass * dt;
    body2->vy += force * sin(angle) / body2->mass * dt;
}

// Update the positions and velocities of the bodies
void updateBodies(Body *bodies) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            calcForce(&bodies[i], &bodies[j]);
        }

        // Update the position
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

// Print the positions of the bodies to a file
void printBodiesToFile(Body *bodies, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < N; i++) {
        fprintf(file, "%lf %lf\n", bodies[i].x, bodies[i].y);
    }

    fclose(file);
}

// Main function
int main() {
    // Allocate memory for the bodies
    Body *bodies = (Body *)malloc(N * sizeof(Body));

    // Initialize the bodies
    initBodies(bodies);

    // Update the bodies for a number of time steps
    for (int i = 0; i < 100000; i++) {
        updateBodies(bodies);
    }

    // Print the positions of the bodies to a file
    printBodiesToFile(bodies, "bodies.txt");

    // Free the memory allocated for the bodies
    free(bodies);

    return 0;
}