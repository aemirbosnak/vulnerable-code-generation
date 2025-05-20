//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define G 6.674e-11      // Gravitational constant
#define DT 0.01          // Time step

typedef struct {
    double m;          // Mass in kg
    double x, y, z;   // Position in km
    double vx, vy, vz; // Velocity in km/s
} Body;

// Create a new body with the given parameters
Body *newBody(double m, double x, double y, double z, double vx, double vy, double vz) {
    Body *body = malloc(sizeof(Body));
    body->m = m;
    body->x = x;
    body->y = y;
    body->z = z;
    body->vx = vx;
    body->vy = vy;
    body->vz = vz;
    return body;
}

// Free a body
void freeBody(Body *body) {
    free(body);
}

// Calculate the gravitational force between two bodies
void calcForce(Body *body1, Body *body2) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double dz = body2->z - body1->z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * body1->m * body2->m / r / r / r;
    body1->vx += f * dx / body1->m * DT;
    body1->vy += f * dy / body1->m * DT;
    body1->vz += f * dz / body1->m * DT;
    body2->vx -= f * dx / body2->m * DT;
    body2->vy -= f * dy / body2->m * DT;
    body2->vz -= f * dz / body2->m * DT;
}

// Update the position and velocity of a body
void updateBody(Body *body) {
    body->x += body->vx * DT;
    body->y += body->vy * DT;
    body->z += body->vz * DT;
}

// Main function
int main() {
    // Create the planets
    Body *sun = newBody(1.989e30, 0, 0, 0, 0, 0, 0);
    Body *mercury = newBody(3.30e23, 57.9e9, 0, 0, 0, 47.4e3, 0);
    Body *venus = newBody(4.87e24, 108.2e9, 0, 0, 0, 35.0e3, 0);
    Body *earth = newBody(5.97e24, 149.6e9, 0, 0, 0, 30.0e3, 0);
    Body *mars = newBody(6.42e23, 227.9e9, 0, 0, 0, 24.1e3, 0);
    Body *jupiter = newBody(1.899e27, 778.5e9, 0, 0, 0, 13.1e3, 0);
    Body *saturn = newBody(5.68e26, 1433.5e9, 0, 0, 0, 9.7e3, 0);
    Body *uranus = newBody(8.68e25, 2872.5e9, 0, 0, 0, 6.8e3, 0);
    Body *neptune = newBody(1.02e26, 4495.1e9, 0, 0, 0, 5.4e3, 0);

    // Run the simulation
    for (int i = 0; i < 100000; i++) {
        // Calculate the forces
        calcForce(sun, mercury);
        calcForce(sun, venus);
        calcForce(sun, earth);
        calcForce(sun, mars);
        calcForce(sun, jupiter);
        calcForce(sun, saturn);
        calcForce(sun, uranus);
        calcForce(sun, neptune);

        // Update the positions and velocities
        updateBody(sun);
        updateBody(mercury);
        updateBody(venus);
        updateBody(earth);
        updateBody(mars);
        updateBody(jupiter);
        updateBody(saturn);
        updateBody(uranus);
        updateBody(neptune);
    }

    // Print the final positions
    printf("Sun: %.2f, %.2f, %.2f\n", sun->x, sun->y, sun->z);
    printf("Mercury: %.2f, %.2f, %.2f\n", mercury->x, mercury->y, mercury->z);
    printf("Venus: %.2f, %.2f, %.2f\n", venus->x, venus->y, venus->z);
    printf("Earth: %.2f, %.2f, %.2f\n", earth->x, earth->y, earth->z);
    printf("Mars: %.2f, %.2f, %.2f\n", mars->x, mars->y, mars->z);
    printf("Jupiter: %.2f, %.2f, %.2f\n", jupiter->x, jupiter->y, jupiter->z);
    printf("Saturn: %.2f, %.2f, %.2f\n", saturn->x, saturn->y, saturn->z);
    printf("Uranus: %.2f, %.2f, %.2f\n", uranus->x, uranus->y, uranus->z);
    printf("Neptune: %.2f, %.2f, %.2f\n", neptune->x, neptune->y, neptune->z);

    // Free the bodies
    freeBody(sun);
    freeBody(mercury);
    freeBody(venus);
    freeBody(earth);
    freeBody(mars);
    freeBody(jupiter);
    freeBody(saturn);
    freeBody(uranus);
    freeBody(neptune);

    return 0;
}