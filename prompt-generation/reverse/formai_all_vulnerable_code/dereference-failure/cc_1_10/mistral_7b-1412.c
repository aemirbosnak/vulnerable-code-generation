//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x, y, z, mass, vel_x, vel_y, vel_z;
} planet;

void gravity(planet *p1, planet *p2, double G) {
    double dx = p2->x - p1->x, dy = p2->y - p1->y, dz = p2->z - p1->z;
    double dist = sqrt(dx * dx + dy * dy + dz * dz), f;

    f = G * p2->mass * p1->mass / (dist * dist);

    p1->vel_x += (dx / dist) * f;
    p1->vel_y += (dy / dist) * f;
    p1->vel_z += (dz / dist) * f;

    p2->vel_x -= (dx / dist) * f;
    p2->vel_y -= (dy / dist) * f;
    p2->vel_z -= (dz / dist) * f;
}

void print_planets(planet *planets, int n) {
    for(int i = 0; i < n; i++) {
        printf("Planet %d: [%.2f, %.2f, %.2f] m=%.2f vx=%.2f vy=%.2f vz=%.2f\n", i + 1, planets[i].x, planets[i].y, planets[i].z, planets[i].mass, planets[i].vel_x, planets[i].vel_y, planets[i].vel_z);
    }
}

int main() {
    srand(time(NULL));

    int n = 5, i, j;
    planet *planets = malloc(n * sizeof(planet));

    for(i = 0; i < n; i++) {
        planets[i].x = rand() % 50 + 50;
        planets[i].y = rand() % 50 + 50;
        planets[i].z = rand() % 50 + 50;
        planets[i].mass = (rand() % 10 + 1) * 5;
        planets[i].vel_x = rand() % 10;
        planets[i].vel_y = rand() % 10;
        planets[i].vel_z = rand() % 10;
    }

    double G = 6.6743e-11;

    for(int step = 0; step < 10000; step++) {
        for(i = 0; i < n - 1; i++) {
            for(j = i + 1; j < n; j++) {
                gravity(&planets[i], &planets[j], G);
            }
        }
    }

    printf("Initial Configuration:\n");
    print_planets(planets, n);

    free(planets);

    return 0;
}