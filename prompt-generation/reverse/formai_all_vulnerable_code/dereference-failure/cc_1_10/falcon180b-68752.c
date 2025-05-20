//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846
#define EPS 1e-10

typedef struct particle {
    double x, y, z, vx, vy, vz, ax, ay, az, mass;
} Particle;

void update_acceleration(Particle *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!= j) {
                double dx = p[j].x - p[i].x;
                double dy = p[j].y - p[i].y;
                double dz = p[j].z - p[i].z;
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                p[i].ax += -G * p[j].mass * dx / (r*r*r);
                p[i].ay += -G * p[j].mass * dy / (r*r*r);
                p[i].az += -G * p[j].mass * dz / (r*r*r);
            }
        }
    }
}

void update_velocity(Particle *p, int n, double dt) {
    for (int i = 0; i < n; i++) {
        p[i].vx += p[i].ax * dt;
        p[i].vy += p[i].ay * dt;
        p[i].vz += p[i].az * dt;
    }
}

void update_position(Particle *p, int n, double dt) {
    for (int i = 0; i < n; i++) {
        p[i].x += p[i].vx * dt;
        p[i].y += p[i].vy * dt;
        p[i].z += p[i].vz * dt;
    }
}

int main() {
    int n = 100;
    Particle *p = malloc(sizeof(Particle) * n);
    for (int i = 0; i < n; i++) {
        p[i].x = (double)i / n * 10;
        p[i].y = 0;
        p[i].z = 0;
        p[i].vx = 0;
        p[i].vy = 0;
        p[i].vz = 0;
        p[i].ax = 0;
        p[i].ay = 0;
        p[i].az = 0;
        p[i].mass = 1;
    }
    double dt = 0.01;
    int steps = 1000;
    for (int i = 0; i < steps; i++) {
        update_acceleration(p, n);
        update_velocity(p, n, dt);
        update_position(p, n, dt);
    }
    free(p);
    return 0;
}