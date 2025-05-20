//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define DEG2RAD (PI / 180.0)

typedef struct {
    double x, y, z;
} vec3;

typedef struct {
    vec3 pos, vel, acc;
    double mass;
} body;

body* bodies;
int nbodies;
double G = 1.0;

void init_bodies(int n) {
    bodies = malloc(n * sizeof(body));
    nbodies = n;
    for (int i = 0; i < n; i++) {
        bodies[i].pos.x = rand() / (double)RAND_MAX * 1000.0;
        bodies[i].pos.y = rand() / (double)RAND_MAX * 1000.0;
        bodies[i].pos.z = rand() / (double)RAND_MAX * 1000.0;
        bodies[i].vel.x = 0.0;
        bodies[i].vel.y = 0.0;
        bodies[i].vel.z = 0.0;
        bodies[i].acc.x = 0.0;
        bodies[i].acc.y = 0.0;
        bodies[i].acc.z = 0.0;
        bodies[i].mass = rand() / (double)RAND_MAX * 1000.0;
    }
}

void update_forces() {
    for (int i = 0; i < nbodies; i++) {
        bodies[i].acc.x = 0.0;
        bodies[i].acc.y = 0.0;
        bodies[i].acc.z = 0.0;
        for (int j = 0; j < nbodies; j++) {
            if (i == j) continue;
            vec3 r = {
                bodies[j].pos.x - bodies[i].pos.x,
                bodies[j].pos.y - bodies[i].pos.y,
                bodies[j].pos.z - bodies[i].pos.z
            };
            double r_mag = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
            double f = G * bodies[i].mass * bodies[j].mass / (r_mag * r_mag);
            bodies[i].acc.x += f * r.x / r_mag;
            bodies[i].acc.y += f * r.y / r_mag;
            bodies[i].acc.z += f * r.z / r_mag;
        }
    }
}

void update_positions(double dt) {
    for (int i = 0; i < nbodies; i++) {
        bodies[i].pos.x += bodies[i].vel.x * dt + 0.5 * bodies[i].acc.x * dt * dt;
        bodies[i].pos.y += bodies[i].vel.y * dt + 0.5 * bodies[i].acc.y * dt * dt;
        bodies[i].pos.z += bodies[i].vel.z * dt + 0.5 * bodies[i].acc.z * dt * dt;
        bodies[i].vel.x += bodies[i].acc.x * dt;
        bodies[i].vel.y += bodies[i].acc.y * dt;
        bodies[i].vel.z += bodies[i].acc.z * dt;
    }
}

int main() {
    int nbodies = 1000;
    double dt = 0.01;
    init_bodies(nbodies);
    for (int i = 0; i < 10000; i++) {
        update_forces();
        update_positions(dt);
    }
    for (int i = 0; i < nbodies; i++) {
        printf("%f %f %f\n", bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);
    }
    free(bodies);
    return 0;
}