//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11  // Gravitational constant
#define DAY 86400      // Seconds in a day

typedef struct {
    double x, y, z;     // Position
    double vx, vy, vz;  // Velocity
    double mass;        // Mass
    double fx, fy, fz;  // Forces
} Body;

Body* new_body(double x, double y, double z, double vx, double vy, double vz, double mass) {
    Body* body = (Body*)malloc(sizeof(Body));
    body->x = x;
    body->y = y;
    body->z = z;
    body->vx = vx;
    body->vy = vy;
    body->vz = vz;
    body->mass = mass;
    body->fx = 0;
    body->fy = 0;
    body->fz = 0;
    return body;
}

void calculate_forces(Body* bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].fx = 0;
        bodies[i].fy = 0;
        bodies[i].fz = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            double distance = sqrt(dx*dx + dy*dy + dz*dz);
            double force = (G * bodies[i].mass * bodies[j].mass) / (distance * distance);
            bodies[i].fx += force * dx / distance;
            bodies[i].fy += force * dy / distance;
            bodies[i].fz += force * dz / distance;
        }
    }
}

void update_positions(Body* bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].fx / bodies[i].mass * dt;
        bodies[i].vy += bodies[i].fy / bodies[i].mass * dt;
        bodies[i].vz += bodies[i].fz / bodies[i].mass * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void simulate(Body* bodies, int n, double dt, int steps) {
    for (int step = 0; step < steps; step++) {
        calculate_forces(bodies, n);
        update_positions(bodies, n, dt);
        printf("Step %d:\n", step+1);
        for (int i = 0; i < n; i++) {
            printf("Body %d: x=%f y=%f z=%f vx=%f vy=%f vz=%f\n", i+1, bodies[i].x, bodies[i].y, bodies[i].z, bodies[i].vx, bodies[i].vy, bodies[i].vz);
        }
    }
}

int main() {
    Body* sun = new_body(0, 0, 0, 0, 0, 0, 1.98847e30);
    Body* earth = new_body(147e9, 0, 0, 0, 30.29e3, 0, 5.9736e24);
    Body* moon = new_body(147e9 + 384.4e6, 0, 0, 0, 30.29e3 + 1022, 0, 7.342e22);
    Body* bodies[3] = {sun, earth, moon};

    simulate(bodies, 3, DAY, 365);
    return 0;
}