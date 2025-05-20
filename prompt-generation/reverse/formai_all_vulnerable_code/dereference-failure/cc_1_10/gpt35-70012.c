//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67430e-11

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double mass;
} Body;

void update_velocity(Body* body, double fx, double fy, double fz, double dt) {
    double ax = fx / body->mass;
    double ay = fy / body->mass;
    double az = fz / body->mass;

    body->vx += ax * dt;
    body->vy += ay * dt;
    body->vz += az * dt;
}

void update_position(Body* body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void compute_forces(Body* bodies, int num_bodies, double* fx, double* fy, double* fz) {
    for (int i = 0; i < num_bodies; ++i) {
        double fxi = 0;
        double fyi = 0;
        double fzi = 0;

        for (int j = 0; j < num_bodies; ++j) {
            if (i == j) continue;

            double dist = distance(bodies[i].x, bodies[i].y, bodies[i].z,
                                   bodies[j].x, bodies[j].y, bodies[j].z);
            double f = GRAVITATIONAL_CONSTANT * bodies[i].mass * bodies[j].mass / (dist * dist);

            fxi += f * (bodies[j].x - bodies[i].x) / dist;
            fyi += f * (bodies[j].y - bodies[i].y) / dist;
            fzi += f * (bodies[j].z - bodies[i].z) / dist;
        }

        fx[i] = fxi;
        fy[i] = fyi;
        fz[i] = fzi;
    }
}

void simulate(Body* bodies, int num_bodies, double dt, int num_steps) {
    double* fx = malloc(sizeof(double) * num_bodies);
    double* fy = malloc(sizeof(double) * num_bodies);
    double* fz = malloc(sizeof(double) * num_bodies);

    for (int step = 0; step < num_steps; ++step) {
        compute_forces(bodies, num_bodies, fx, fy, fz);
        for (int i = 0; i < num_bodies; ++i) {
            update_velocity(&bodies[i], fx[i], fy[i], fz[i], dt);
        }

        for (int i = 0; i < num_bodies; ++i) {
            update_position(&bodies[i], dt);
        }
    }

    free(fx);
    free(fy);
    free(fz);
}

int main() {
    Body planets[] = {
        {0, 0, 0, 0, 0, 0, 1.98e+30},
        {147095000000, 0, 0, 0, 30200, 0, 5.97e+24},
    };
    int num_bodies = sizeof(planets) / sizeof(Body);
    double dt = 3600 * 24;
    int num_steps = 365 * 2;

    simulate(planets, num_bodies, dt, num_steps);

    printf("Earth at x=%f, y=%f, z=%f\n", planets[1].x, planets[1].y, planets[1].z);

    return 0;
}