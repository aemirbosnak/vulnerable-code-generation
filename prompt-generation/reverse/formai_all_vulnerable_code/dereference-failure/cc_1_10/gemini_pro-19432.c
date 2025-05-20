//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define G 6.674e-11

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} body;

body *bodies;
int nbodies;

void init_bodies(int n) {
    bodies = malloc(n * sizeof(body));
    nbodies = n;
    for (int i = 0; i < n; i++) {
        bodies[i].mass = rand() % 1000000 + 1;
        bodies[i].x = rand() % 1000000000 - 500000000;
        bodies[i].y = rand() % 1000000000 - 500000000;
        bodies[i].z = rand() % 1000000000 - 500000000;
        bodies[i].vx = 0;
        bodies[i].vy = 0;
        bodies[i].vz = 0;
    }
}

void update_bodies(double dt) {
    for (int i = 0; i < nbodies; i++) {
        double ax = 0, ay = 0, az = 0;
        for (int j = 0; j < nbodies; j++) {
            if (i == j) continue;
            double dx = bodies[i].x - bodies[j].x;
            double dy = bodies[i].y - bodies[j].y;
            double dz = bodies[i].z - bodies[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * bodies[i].mass * bodies[j].mass / (r * r);
            ax += f * dx / r;
            ay += f * dy / r;
            az += f * dz / r;
        }
        bodies[i].vx += ax * dt;
        bodies[i].vy += ay * dt;
        bodies[i].vz += az * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void print_bodies() {
    for (int i = 0; i < nbodies; i++) {
        printf("body %d: mass=%f, x=%f, y=%f, z=%f, vx=%f, vy=%f, vz=%f\n",
               i, bodies[i].mass, bodies[i].x, bodies[i].y, bodies[i].z, bodies[i].vx, bodies[i].vy, bodies[i].vz);
    }
}

int main() {
    init_bodies(1000);
    for (int i = 0; i < 10000; i++) {
        update_bodies(0.001);
    }
    print_bodies();
    return 0;
}