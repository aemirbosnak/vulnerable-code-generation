//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define AU 1.495978707e11 // Astronomical unit in meters

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    double mass;
} Body;

void update_velocity(Body *bodies, int num_bodies, int i, double dt) {
    double ax = 0, ay = 0, az = 0;
    for (int j = 0; j < num_bodies; j++) {
        if (i == j) continue;
        Body other = bodies[j];
        double dx = other.position.x - bodies[i].position.x;
        double dy = other.position.y - bodies[i].position.y;
        double dz = other.position.z - bodies[i].position.z;
        double dist = sqrt(dx*dx + dy*dy + dz*dz);
        double force = G * bodies[i].mass * other.mass / (dist*dist);
        ax += force * dx / dist;
        ay += force * dy / dist;
        az += force * dz / dist;
    }
    bodies[i].velocity.x += ax * dt;
    bodies[i].velocity.y += ay * dt;
    bodies[i].velocity.z += az * dt;
}

void update_position(Body *bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * dt;
        bodies[i].position.y += bodies[i].velocity.y * dt;
        bodies[i].position.z += bodies[i].velocity.z * dt;
    }
}

void simulate(Body *bodies, int num_bodies, double dt, double tmax) {
    int num_steps = (int) (tmax / dt);
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_bodies; i++) {
            update_velocity(bodies, num_bodies, i, dt);
        }
        update_position(bodies, num_bodies, dt);
    }
}

int main() {
    int num_bodies = 3;
    Body *bodies = malloc(num_bodies * sizeof(Body));

    // Sun
    bodies[0].position.x = 0;
    bodies[0].position.y = 0;
    bodies[0].position.z = 0;
    bodies[0].velocity.x = 0;
    bodies[0].velocity.y = 0;
    bodies[0].velocity.z = 0;
    bodies[0].mass = 1.989e30;

    // Earth
    bodies[1].position.x = AU;
    bodies[1].position.y = 0;
    bodies[1].position.z = 0;
    bodies[1].velocity.x = 0;
    bodies[1].velocity.y = 29800;
    bodies[1].velocity.z = 0;
    bodies[1].mass = 5.972e24;

    // Mars
    bodies[2].position.x = 1.524 * AU;
    bodies[2].position.y = 0;
    bodies[2].position.z = 0;
    bodies[2].velocity.x = 0;
    bodies[2].velocity.y = 24100;
    bodies[2].velocity.z = 0;
    bodies[2].mass = 6.39e23;

    double tmax = 31536000; // One year in seconds
    double dt = 86400; // One day in seconds

    simulate(bodies, num_bodies, dt, tmax);

    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: x=%e, y=%e, z=%e\n", i, bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
    }

    free(bodies);
    return 0;
}