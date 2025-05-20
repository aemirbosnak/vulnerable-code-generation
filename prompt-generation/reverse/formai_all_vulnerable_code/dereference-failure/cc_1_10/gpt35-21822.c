//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 //Gravitational Constant

typedef struct {
    double x;
    double y;
    double z;
} Vector3d;

typedef struct {
    Vector3d position;
    Vector3d velocity;
    double mass;
} Body;

void update_velocities(Body *bodies, double dt, int num_bodies) {
    int i, j;
    Vector3d acceleration;
    for(i = 0; i < num_bodies; i++) {
        acceleration.x = 0.0;
        acceleration.y = 0.0;
        acceleration.z = 0.0;
        for(j = 0; j < num_bodies; j++) {
            if(i != j) {
                double dist_x = bodies[j].position.x - bodies[i].position.x;
                double dist_y = bodies[j].position.y - bodies[i].position.y;
                double dist_z = bodies[j].position.z - bodies[i].position.z;
                double dist = sqrt(dist_x * dist_x + dist_y * dist_y + dist_z * dist_z);
                double force = G * bodies[i].mass * bodies[j].mass / (dist * dist);
                acceleration.x += dist_x / dist * force / bodies[i].mass;
                acceleration.y += dist_y / dist * force / bodies[i].mass;
                acceleration.z += dist_z / dist * force / bodies[i].mass;
            }
        }
        bodies[i].velocity.x += acceleration.x * dt;
        bodies[i].velocity.y += acceleration.y * dt;
        bodies[i].velocity.z += acceleration.z * dt;
    }
}

void update_positions(Body *bodies, double dt, int num_bodies) {
    int i;
    for(i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * dt;
        bodies[i].position.y += bodies[i].velocity.y * dt;
        bodies[i].position.z += bodies[i].velocity.z * dt;
    }
}

int main(int argc, char** argv) {
    int num_bodies = 3;
    double timestep = 1.0;
    int num_steps = 100;
    Body* bodies = (Body*) malloc(num_bodies * sizeof(Body));

    // Set up initial state of system (three massive planets)

    bodies[0].position.x = 0.0;
    bodies[0].position.y = 0.0;
    bodies[0].position.z = 0.0;
    bodies[0].velocity.x = 0.0;
    bodies[0].velocity.y = 0.0;
    bodies[0].velocity.z = 0.0;
    bodies[0].mass = 1000.0;

    bodies[1].position.x = 1000000.0;
    bodies[1].position.y = 0.0;
    bodies[1].position.z = 0.0;
    bodies[1].velocity.x = 0.0;
    bodies[1].velocity.y = 100.0;
    bodies[1].velocity.z = 0.0;
    bodies[1].mass = 1000.0;

    bodies[2].position.x = 0.0;
    bodies[2].position.y = 1000000.0;
    bodies[2].position.z = 0.0;
    bodies[2].velocity.x = -100.0;
    bodies[2].velocity.y = 0.0;
    bodies[2].velocity.z = 0.0;
    bodies[2].mass = 1000.0;

    // Run simulation

    int i, j;
    for(i = 0; i < num_steps; i++) {
        printf("Step %d:\n", i);
        for(j = 0; j < num_bodies; j++) {
            printf("Body %d:\n", j);
            printf("Position: (%f, %f, %f)\n", bodies[j].position.x, bodies[j].position.y, bodies[j].position.z);
            printf("Velocity: (%f, %f, %f)\n", bodies[j].velocity.x, bodies[j].velocity.y, bodies[j].velocity.z);
            printf("Mass: %f\n", bodies[j].mass);
        }
        update_velocities(bodies, timestep, num_bodies);
        update_positions(bodies, timestep, num_bodies);
    }

    free(bodies);

    return 0;
}