//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

typedef struct Vec {
    double x;
    double y;
    double z;
} Vec;

typedef struct Body {
    double mass;
    Vec pos;
    Vec vel;
    Vec force;
} Body;

void initBody(Body* body, double mass, Vec pos, Vec vel) {
    body->mass = mass;
    body->pos = pos;
    body->vel = vel;
    body->force = (Vec){0, 0, 0};
}

Vec calcForce(Body* a, Body* b) {
    Vec diff = (Vec){b->pos.x - a->pos.x, b->pos.y - a->pos.y, b->pos.z - a->pos.x};
    double dist = sqrt(diff.x*diff.x + diff.y*diff.y + diff.z*diff.z);
    double f = (G * a->mass * b->mass) / (dist * dist);
    return (Vec){f * diff.x / dist, f * diff.y / dist, f * diff.z / dist};
}

void updateBody(Body* body, double timestep) {
    Vec acceleration = (Vec){body->force.x / body->mass, body->force.y / body->mass, body->force.z / body->mass};
    body->vel.x += timestep * acceleration.x;
    body->vel.y += timestep * acceleration.y;
    body->vel.z += timestep * acceleration.z;
    body->pos.x += timestep * body->vel.x;
    body->pos.y += timestep * body->vel.y;
    body->pos.z += timestep * body->vel.z;
}

int main(void) {
    const int numBodies = 2;
    Body* bodies = malloc(numBodies * sizeof(Body));

    initBody(&bodies[0], 5.972e24, (Vec){0, 0, 0}, (Vec){0, 0, 0});
    initBody(&bodies[1], 7.342e22, (Vec){384400000, 0, 0}, (Vec){0, 1022, 0});

    const double timestep = 1000;
    const int maxSteps = 86400 / timestep; // simulate one day

    for (int step=0; step<maxSteps; ++step) {
        for (int i=0; i<numBodies; ++i) {
            for (int j=i+1; j<numBodies; ++j) {
                Vec force = calcForce(&bodies[i], &bodies[j]);
                bodies[i].force.x += force.x;
                bodies[i].force.y += force.y;
                bodies[i].force.z += force.z;
                bodies[j].force.x -= force.x;
                bodies[j].force.y -= force.y;
                bodies[j].force.z -= force.z;
            }
        }
        for (int i=0; i<numBodies; ++i) {
            updateBody(&bodies[i], timestep);
            bodies[i].force = (Vec){0, 0, 0};
        }
    }

    printf("Position of Earth after one day: (%f, %f, %f)\n", bodies[0].pos.x, bodies[0].pos.y, bodies[0].pos.z);

    free(bodies);
    return 0;
}