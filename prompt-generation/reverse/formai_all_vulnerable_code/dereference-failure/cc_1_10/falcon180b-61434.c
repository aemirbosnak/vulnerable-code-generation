//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265359

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double mass;
} Planet;

void init_planet(Planet *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
    p->mass = mass;
}

void update_acceleration(Planet *p1, Planet *p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (r*r);
    p1->ax += dx * f / r;
    p1->ay += dy * f / r;
    p1->az += dz * f / r;
    p2->ax -= dx * f / r;
    p2->ay -= dy * f / r;
    p2->az -= dz * f / r;
}

void update_velocity(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    int n;
    scanf("%d", &n);

    Planet *planets = malloc(sizeof(Planet) * n);

    for (int i = 0; i < n; i++) {
        double x, y, z, vx, vy, vz, mass;
        scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &z, &vx, &vy, &vz);
        init_planet(&planets[i], x, y, z, vx, vy, vz, mass);
    }

    double dt = 0.01;

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                update_acceleration(&planets[i], &planets[j], dt);
            }
        }

        for (int i = 0; i < n; i++) {
            update_velocity(&planets[i], dt);
            update_position(&planets[i], dt);
        }
    }

    return 0;
}