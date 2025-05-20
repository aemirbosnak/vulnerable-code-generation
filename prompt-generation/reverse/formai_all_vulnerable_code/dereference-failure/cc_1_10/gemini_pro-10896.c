//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x, y, z;
} vec3;

typedef struct {
    double mass;
    vec3 pos, vel, acc;
} planet;

#define G 6.67408e-11

void init(planet *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].mass = 1e24;
        p[i].pos.x = 1e11 * sin(2 * M_PI * i / n);
        p[i].pos.y = 1e11 * cos(2 * M_PI * i / n);
        p[i].pos.z = 0;
        p[i].vel.x = 0;
        p[i].vel.y = 0;
        p[i].vel.z = 0;
    }
}

void gravity(planet *p1, planet *p2) {
    vec3 r = {p2->pos.x - p1->pos.x, p2->pos.y - p1->pos.y, p2->pos.z - p1->pos.z};
    double r2 = r.x * r.x + r.y * r.y + r.z * r.z;
    double f = G * p1->mass * p2->mass / r2;
    p1->acc.x += f * r.x / sqrt(r2);
    p1->acc.y += f * r.y / sqrt(r2);
    p1->acc.z += f * r.z / sqrt(r2);
}

void update(planet *p, int n, double dt) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            gravity(&p[i], &p[j]);
        }
        p[i].vel.x += p[i].acc.x * dt;
        p[i].vel.y += p[i].acc.y * dt;
        p[i].vel.z += p[i].acc.z * dt;
        p[i].pos.x += p[i].vel.x * dt;
        p[i].pos.y += p[i].vel.y * dt;
        p[i].pos.z += p[i].vel.z * dt;
        p[i].acc.x = 0;
        p[i].acc.y = 0;
        p[i].acc.z = 0;
    }
}

int main() {
    int n = 100;
    planet *p = malloc(n * sizeof(planet));
    init(p, n);
    double dt = 1e4;
    for (int i = 0; i < 10000; i++) {
        update(p, n, dt);
    }
    free(p);
    return 0;
}