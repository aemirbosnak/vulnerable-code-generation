//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} planet;

const double G = 6.67408e-11;
const double dt = 1;

int main(int argc, char **argv) {
    int n = 100;
    planet *planets = malloc(n * sizeof(planet));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        planets[i].mass = 1e22;
        planets[i].x = rand() % 10000;
        planets[i].y = rand() % 10000;
        planets[i].vx = 0;
        planets[i].vy = 0;
    }

    for (int t = 0; t < 10000; t++) {
        for (int i = 0; i < n; i++) {
            double fx = 0;
            double fy = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double r = sqrt(dx * dx + dy * dy);
                double f = G * planets[i].mass * planets[j].mass / (r * r * r);
                fx += f * dx / r;
                fy += f * dy / r;
            }
            planets[i].vx += dt * fx / planets[i].mass;
            planets[i].vy += dt * fy / planets[i].mass;
        }

        for (int i = 0; i < n; i++) {
            planets[i].x += dt * planets[i].vx;
            planets[i].y += dt * planets[i].vy;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lf %lf\n", planets[i].x, planets[i].y);
    }

    return 0;
}