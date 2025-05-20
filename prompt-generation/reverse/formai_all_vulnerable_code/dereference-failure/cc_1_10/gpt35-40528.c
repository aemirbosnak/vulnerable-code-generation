//FormAI DATASET v1.0 Category: Physics simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.674E-11 // N * m^2 / kg^2

typedef struct {
    double x;
    double y;
} Vec2;

typedef struct {
    double mass;
    Vec2 position;
    Vec2 velocity;
} Body;

Vec2 calculateGravitationalForce(Body body1, Body body2) {
    double forceMagnitude = GRAVITATIONAL_CONSTANT * body1.mass * body2.mass / pow((body2.position.x - body1.position.x), 2) +
            pow((body2.position.y - body1.position.y), 2);
    Vec2 forceDirection = {
        .x = (body2.position.x - body1.position.x) / sqrt(pow((body2.position.x - body1.position.x), 2) +
                pow((body2.position.y - body1.position.y), 2)),
        .y = (body2.position.y - body1.position.y) / sqrt(pow((body2.position.x - body1.position.x), 2) +
                pow((body2.position.y - body1.position.y), 2))
    };
    Vec2 force = {
        .x = forceMagnitude * forceDirection.x,
        .y = forceMagnitude * forceDirection.y
    };
    return force;
}

void updateBodies(Body* bodies, int numberOfBodies, double timeStep) {
    for (int i = 0; i < numberOfBodies; i++) {
        Vec2 acceleration = { .x = 0, .y = 0};
        for (int j = 0; j < numberOfBodies; j++) {
            if (i != j) {
                Vec2 force = calculateGravitationalForce(bodies[i], bodies[j]);
                acceleration.x += force.x / bodies[i].mass;
                acceleration.y += force.y / bodies[i].mass;
            }
        }
        bodies[i].velocity.x += acceleration.x * timeStep;
        bodies[i].velocity.y += acceleration.y * timeStep;
        bodies[i].position.x += bodies[i].velocity.x * timeStep;
        bodies[i].position.y += bodies[i].velocity.y * timeStep;
    }
}

int main() {
    const int numberOfBodies = 3; // Change this number to simulate more bodies
    Body* bodies = malloc(numberOfBodies * sizeof(Body));

    // Set up the bodies with random positions, velocities, and masses
    for (int i = 0; i < numberOfBodies; i++) {
        bodies[i].position.x = (double) rand() / RAND_MAX * 10 - 5; // Random number between -5 and 5
        bodies[i].position.y = (double) rand() / RAND_MAX * 10 - 5; // Random number between -5 and 5
        bodies[i].velocity.x = (double) rand() / RAND_MAX * 4 - 2; // Random number between -2 and 2
        bodies[i].velocity.y = (double) rand() / RAND_MAX * 4 - 2; // Random number between -2 and 2
        bodies[i].mass = (double) rand() / RAND_MAX * 1000 + 1000; // Random number between 1000 and 2000 kg
    }

    for (int i = 0; i < 100000; i++) { // Run the simulation for 100000 time steps
        updateBodies(bodies, numberOfBodies, 0.01);
    }

    for (int i = 0; i < numberOfBodies; i++) {
        printf("Body %d final position: (%f, %f)\n", i, bodies[i].position.x, bodies[i].position.y);
    }

    free(bodies);
    return 0;
}