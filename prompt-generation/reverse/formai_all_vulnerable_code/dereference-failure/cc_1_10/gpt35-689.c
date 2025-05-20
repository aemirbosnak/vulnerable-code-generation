//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

typedef struct {
    double x, y, z; // position vector
    double vx, vy, vz; // velocity vector
    double m; // mass
} Body;

typedef struct {
    int n; // number of bodies
    Body *bodies; // array of bodies
} System;

// calculate acceleration of body i due to body j
void acc(System *sys, int i, int j, double *ax, double *ay, double *az) {
    Body *bi = &sys->bodies[i];
    Body *bj = &sys->bodies[j];
    double dx = bj->x - bi->x;
    double dy = bj->y - bi->y;
    double dz = bj->z - bi->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * bi->m * bj->m / (r*r);
    *ax += f * dx / r;
    *ay += f * dy / r;
    *az += f * dz / r;
}

// calculate all accelerations in the system
void acc_all(System *sys, double ax[], double ay[], double az[]) {
    for (int i = 0; i < sys->n; ++i) {
        ax[i] = ay[i] = az[i] = 0;
        for (int j = 0; j < sys->n; ++j) {
            if (i == j) continue;
            acc(sys, i, j, &ax[i], &ay[i], &az[i]);
        }
    }
}

// update positions and velocities of all bodies using leapfrog integration
void step(System *sys, double dt) {
    double ax[sys->n], ay[sys->n], az[sys->n];
    acc_all(sys, ax, ay, az);
    for (int i = 0; i < sys->n; ++i) {
        Body *b = &sys->bodies[i];
        b->vx += ax[i] * dt / 2;
        b->vy += ay[i] * dt / 2;
        b->vz += az[i] * dt / 2;
        b->x += b->vx * dt;
        b->y += b->vy * dt;
        b->z += b->vz * dt;
    }
    acc_all(sys, ax, ay, az);
    for (int i = 0; i < sys->n; ++i) {
        Body *b = &sys->bodies[i];
        b->vx += ax[i] * dt / 2;
        b->vy += ay[i] * dt / 2;
        b->vz += az[i] * dt / 2;
    }
}

// print positions of all bodies
void print(System *sys) {
    for (int i = 0; i < sys->n; ++i) {
        Body *b = &sys->bodies[i];
        printf("Body %d: (%.3f, %.3f, %.3f)\n", i, b->x, b->y, b->z);
    }
}

// create a solar system containing the sun and three planets
System *create_system() {
    System *sys = malloc(sizeof(System));
    sys->n = 4;
    sys->bodies = malloc(sys->n * sizeof(Body));
    // sun
    sys->bodies[0].x = 0;
    sys->bodies[0].y = 0;
    sys->bodies[0].z = 0;
    sys->bodies[0].vx = 0;
    sys->bodies[0].vy = 0;
    sys->bodies[0].vz = 0;
    sys->bodies[0].m = 1.989e30;
    // earth
    sys->bodies[1].x = 1.496e11;
    sys->bodies[1].y = 0;
    sys->bodies[1].z = 0;
    sys->bodies[1].vx = 0;
    sys->bodies[1].vy = 2.978e4;
    sys->bodies[1].vz = 0;
    sys->bodies[1].m = 5.972e24;
    // mars
    sys->bodies[2].x = 2.279e11;
    sys->bodies[2].y = 0;
    sys->bodies[2].z = 0;
    sys->bodies[2].vx = 0;
    sys->bodies[2].vy = 2.413e4;
    sys->bodies[2].vz = 0;
    sys->bodies[2].m = 6.39e23;
    // jupiter
    sys->bodies[3].x = 7.784e11;
    sys->bodies[3].y = 0;
    sys->bodies[3].z = 0;
    sys->bodies[3].vx = 0;
    sys->bodies[3].vy = 1.308e4;
    sys->bodies[3].vz = 0;
    sys->bodies[3].m = 1.898e27;
    return sys;
}

int main() {
    System *sys = create_system();
    double dt = 3600; // timestep of 1 hour
    for (int i = 0; i < 24*365; ++i) {
        step(sys, dt);
        print(sys);
        printf("Day %d\n", i+1);
        printf("\n");
    }
    free(sys->bodies);
    free(sys);
    return 0;
}