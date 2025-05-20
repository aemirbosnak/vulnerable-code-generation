//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct {
    double mass; // Mass (kg)
    double x; // Position x (m)
    double y; // Position y (m)
    double z; // Position z (m)
    double vx; // Velocity x (m/s)
    double vy; // Velocity y (m/s)
    double vz; // Velocity z (m/s)
} Body;

Body* bodies; // Array of bodies
int numBodies; // Number of bodies

// Calculate the force between two bodies
void calcForce(Body* a, Body* b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double r = sqrt(dx * dx + dy * dy + dz * dz); // Distance between bodies
    double f = G * a->mass * b->mass / (r * r); // Force
    
    // Calculate the components of the force
    double fx = f * dx / r;
    double fy = f * dy / r;
    double fz = f * dz / r;

    // Update the forces on the bodies
    a->vx += fx / a->mass;
    a->vy += fy / a->mass;
    a->vz += fz / a->mass;
    b->vx -= fx / b->mass;
    b->vy -= fy / b->mass;
    b->vz -= fz / b->mass;
}

// Update the positions and velocities of all bodies
void updateBodies() {
    // Calculate the forces between all bodies
    for (int i = 0; i < numBodies; i++) {
        for (int j = i + 1; j < numBodies; j++) {
            calcForce(&bodies[i], &bodies[j]);
        }
    }

    // Update the positions and velocities of all bodies
    for (int i = 0; i < numBodies; i++) {
        bodies[i].x += bodies[i].vx * (1/60); // Time step
        bodies[i].y += bodies[i].vy * (1/60);
        bodies[i].z += bodies[i].vz * (1/60);
    }
}

// Main function
int main() {
    // Create the array of bodies
    bodies = malloc(sizeof(Body) * 10);
    numBodies = 10;

    // Initialize the bodies
    bodies[0].mass = 5.972e24; // Earth
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].z = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[0].vz = 0;
    
    bodies[1].mass = 1.989e30; // Sun
    bodies[1].x = 0;
    bodies[1].y = 1.5e11;
    bodies[1].z = 0;
    bodies[1].vx = 0;
    bodies[1].vy = 0;
    bodies[1].vz = 0;
        
    // Simulate the gravity
    for (int i = 0; i < 1000; i++) {
        updateBodies();
    }

    // Print the positions of the bodies
    for (int i = 0; i < numBodies; i++) {
        printf("Body %d: (%f, %f, %f)\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }

    return 0;
}