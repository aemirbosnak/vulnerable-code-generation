//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAV_CONST 6.67408e-11
#define MASS_UNIT 1e24
#define TIME_UNIT  3600  // 1 hour

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Body;

void update_position(Body *bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        for (int j = i + 1; j < num_bodies; j++) {
            double dx = bodies[i].x - bodies[j].x;
            double dy = bodies[i].y - bodies[j].y;
            double dz = bodies[i].z - bodies[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double force = GRAV_CONST * bodies[i].mass * bodies[j].mass / (r * r * r);
            bodies[i].vx += force * dx / bodies[i].mass * dt;
            bodies[i].vy += force * dy / bodies[i].mass * dt;
            bodies[i].vz += force * dz / bodies[i].mass * dt;
            bodies[j].vx -= force * dx / bodies[j].mass * dt;
            bodies[j].vy -= force * dy / bodies[j].mass * dt;
            bodies[j].vz -= force * dz / bodies[j].mass * dt;
        }
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

int main() {
    srand(time(NULL));
    int num_bodies = 10;
    Body *bodies = malloc(sizeof(Body) * num_bodies);
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].mass = ((double)rand() / RAND_MAX) * 1e3 * MASS_UNIT;
        bodies[i].x = ((double)rand() / RAND_MAX) * 1e12;
        bodies[i].y = ((double)rand() / RAND_MAX) * 1e12;
        bodies[i].z = ((double)rand() / RAND_MAX) * 1e12;
        bodies[i].vx = ((double)rand() / RAND_MAX) * 1e3;
        bodies[i].vy = ((double)rand() / RAND_MAX) * 1e3;
        bodies[i].vz = ((double)rand() / RAND_MAX) * 1e3;
    }

    double dt = TIME_UNIT;
    int t = 0;
    while (1) {
        printf("Time: %d hours\n", t);
        for (int i = 0; i < num_bodies; i++) {
            printf("Body %d: (%e, %e, %e) (%e, %e, %e)\n", i, bodies[i].x, bodies[i].y, bodies[i].z, bodies[i].vx, bodies[i].vy, bodies[i].vz);
        }
        printf("\n");
        update_position(bodies, num_bodies, dt);
        t += dt;
    }
    free(bodies);
    return 0;
}