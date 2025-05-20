//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
typedef struct { double x, y, vx, vy, mass; } body;

body* planets;
double G = 6.67430e-11;

void init() {
    int i;
    planets = malloc(N * sizeof(body));
    for (i = 0; i < N; i++) {
        planets[i].x = (i % 3 > 0) ? 10 * sin(2 * M_PI * i / 3) : -10 * sin(2 * M_PI * i / 3);
        planets[i].y = (i % 3 == 0) ? 10 * cos(2 * M_PI * i / 3) : 0;
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].mass = (i % 3 > 0) ? 1.0 : 0.1;
    }
}

void update(body* p1, body* p2) {
    double dx = p2->x - p1->x, dy = p2->y - p1->y;
    double r = sqrt(dx * dx + dy * dy), fx = G * p2->mass * dx / r, fy = G * p2->mass * dy / r;
    p1->vx += fx;
    p1->vy += fy;
}

void simulate(int steps) {
    int i, j;
    for (i = 0; i < steps; i++) {
        for (j = 0; j < N; j++) {
            if (j == 0) continue;
            update(&planets[0], &planets[j]);
            update(&planets[j], &planets[0]);
        }
        for (j = 0; j < N; j++) {
            planets[j].x += planets[j].vx;
            planets[j].y += planets[j].vy;
        }
    }
}

int main() {
    init();
    simulate(100000);
    for (int i = 0; i < N; i++)
        printf("(%lf, %lf)\n", planets[i].x, planets[i].y);
    free(planets);
    return 0;
}