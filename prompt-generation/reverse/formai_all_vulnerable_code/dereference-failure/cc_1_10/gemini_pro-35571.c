//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double m;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

int main() {
    int n = 10;
    Planet *planets = malloc(n * sizeof(Planet));

    for (int i = 0; i < n; i++) {
        planets[i].m = 1.0;
        planets[i].x = (double)rand() / (double)RAND_MAX;
        planets[i].y = (double)rand() / (double)RAND_MAX;
        planets[i].vx = 0.0;
        planets[i].vy = 0.0;
    }

    double dt = 0.001;
    double G = 6.674e-11;

    for (int t = 0; t < 10000; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double r = sqrt(dx*dx + dy*dy);
                double F = G * planets[i].m * planets[j].m / (r*r);

                planets[i].vx += F * dx / r * dt;
                planets[i].vy += F * dy / r * dt;
            }
        }

        for (int i = 0; i < n; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Planet %d: (%.2f, %.2f)\n", i, planets[i].x, planets[i].y);
    }

    return 0;
}