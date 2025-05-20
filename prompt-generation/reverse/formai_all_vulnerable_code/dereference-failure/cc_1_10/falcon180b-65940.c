//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

struct planet {
    double x, y, z, vx, vy, vz, mass;
};

void init_planet(struct planet *p, double x, double y, double z, double vx, double vy, double vz, double mass) {
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->mass = mass;
}

void move_planet(struct planet *p, double dt) {
    double ax, ay, az;
    ax = 0;
    ay = 0;
    az = G * p->mass;

    p->vx += p->vx * dt;
    p->vy += p->vy * dt;
    p->vz += p->vz * dt + az * dt;

    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void print_planet(struct planet *p) {
    printf("Planet at (%lf, %lf, %lf) with velocity (%lf, %lf, %lf)\n", p->x, p->y, p->z, p->vx, p->vy, p->vz);
}

int main() {
    int num_planets;
    scanf("%d", &num_planets);

    struct planet *planets = malloc(num_planets * sizeof(struct planet));

    for (int i = 0; i < num_planets; i++) {
        double x, y, z, vx, vy, vz, mass;
        scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &z, &vx, &vy, &vz);
        scanf("%lf", &mass);

        init_planet(&planets[i], x, y, z, vx, vy, vz, mass);
    }

    double dt = 0.01;

    while (1) {
        for (int i = 0; i < num_planets; i++) {
            move_planet(&planets[i], dt);
        }

        for (int i = 0; i < num_planets; i++) {
            print_planet(&planets[i]);
        }

        fflush(stdout);
    }

    return 0;
}