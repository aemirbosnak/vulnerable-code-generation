//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct planet {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} planet_t;

typedef struct simulation {
    int n;
    planet_t *planets;
    double dt;
    double t;
} simulation_t;

simulation_t *simulation_init(int n, double dt) {
    simulation_t *sim = malloc(sizeof(simulation_t));
    sim->n = n;
    sim->planets = malloc(n * sizeof(planet_t));
    sim->dt = dt;
    sim->t = 0.0;
    return sim;
}

void simulation_free(simulation_t *sim) {
    free(sim->planets);
    free(sim);
}

void planet_init(planet_t *p, double mass, double x, double y, double z, double vx, double vy, double vz) {
    p->mass = mass;
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

void simulation_update(simulation_t *sim) {
    double G = 6.67408e-11;
    for (int i = 0; i < sim->n; i++) {
        planet_t *p = &sim->planets[i];
        double ax = 0.0, ay = 0.0, az = 0.0;
        for (int j = 0; j < sim->n; j++) {
            if (i == j) continue;
            planet_t *q = &sim->planets[j];
            double dx = q->x - p->x;
            double dy = q->y - p->y;
            double dz = q->z - p->z;
            double r2 = dx * dx + dy * dy + dz * dz;
            double r3 = r2 * sqrt(r2);
            ax += G * q->mass * dx / r3;
            ay += G * q->mass * dy / r3;
            az += G * q->mass * dz / r3;
        }
        p->vx += sim->dt * ax;
        p->vy += sim->dt * ay;
        p->vz += sim->dt * az;
        p->x += sim->dt * p->vx;
        p->y += sim->dt * p->vy;
        p->z += sim->dt * p->vz;
    }
    sim->t += sim->dt;
}

void simulation_output(simulation_t *sim) {
    for (int i = 0; i < sim->n; i++) {
        planet_t *p = &sim->planets[i];
        printf("%d %f %f %f %f %f %f %f\n", i, p->mass, p->x, p->y, p->z, p->vx, p->vy, p->vz);
    }
}

int main() {
    simulation_t *sim = simulation_init(3, 0.001);
    planet_init(&sim->planets[0], 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    planet_init(&sim->planets[1], 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    planet_init(&sim->planets[2], 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    for (int i = 0; i < 10000; i++) {
        simulation_update(sim);
    }
    simulation_output(sim);
    simulation_free(sim);
    return 0;
}