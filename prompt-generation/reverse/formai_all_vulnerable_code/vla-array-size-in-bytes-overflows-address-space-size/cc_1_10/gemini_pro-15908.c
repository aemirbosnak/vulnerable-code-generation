//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;
    double x, y;
    double vx, vy;
} Planet;

#define G 6.67408e-11

int main() {
    int n, i, j;
    double dt;

    printf("Enter the number of planets: ");
    scanf("%d", &n);

    Planet planets[n];

    for (i = 0; i < n; i++) {
        printf("Enter the mass, x, y, vx, and vy of planet %d: ", i + 1);
        scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
    }

    printf("Enter the time step: ");
    scanf("%lf", &dt);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double r = sqrt(dx * dx + dy * dy);
            double force = G * planets[i].mass * planets[j].mass / (r * r);
            double theta = atan2(dy, dx);

            planets[i].vx += dt * force * cos(theta) / planets[i].mass;
            planets[i].vy += dt * force * sin(theta) / planets[i].mass;
            planets[j].vx -= dt * force * cos(theta) / planets[j].mass;
            planets[j].vy -= dt * force * sin(theta) / planets[j].mass;
        }
    }

    for (i = 0; i < n; i++) {
        printf("The position of planet %d after one time step is (%lf, %lf)\n", i + 1, planets[i].x, planets[i].y);
    }

    return 0;
}