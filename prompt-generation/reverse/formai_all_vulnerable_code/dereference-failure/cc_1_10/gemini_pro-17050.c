//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double mass;
    double x, y;
    double vx, vy;
} planet;

void update_position(planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void update_velocity(planet *p, planet *other, double dt, double G) {
    double dx = other->x - p->x;
    double dy = other->y - p->y;
    double r_sq = dx*dx + dy*dy;
    double F = G * p->mass * other->mass / r_sq;
    p->vx += F * dx / p->mass * dt;
    p->vy += F * dy / p->mass * dt;
}

void simulate(planet *planets, int n, double dt, double G) {
    for (int i = 0; i < n; i++) {
        update_position(&planets[i], dt);
        for (int j = i + 1; j < n; j++) {
            update_velocity(&planets[i], &planets[j], dt, G);
            update_velocity(&planets[j], &planets[i], dt, G);
        }
    }
}

void print_positions(planet *planets, int n) {
    for (int i = 0; i < n; i++) {
        printf("Planet %d: x = %lf, y = %lf\n", i, planets[i].x, planets[i].y);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s n dt G [seed]\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    double dt = atof(argv[2]);
    double G = atof(argv[3]);
    int seed = argc >= 5 ? atoi(argv[4]) : time(NULL);

    srand(seed);

    planet *planets = malloc(n * sizeof(planet));
    for (int i = 0; i < n; i++) {
        planets[i].mass = 1 + (double)rand() / RAND_MAX;
        planets[i].x = (double)rand() / RAND_MAX;
        planets[i].y = (double)rand() / RAND_MAX;
        planets[i].vx = 0;
        planets[i].vy = 0;
    }

    print_positions(planets, n);

    for (int t = 0; t < 1000; t++) {
        simulate(planets, n, dt, G);
        print_positions(planets, n);
    }

    free(planets);
    return 0;
}