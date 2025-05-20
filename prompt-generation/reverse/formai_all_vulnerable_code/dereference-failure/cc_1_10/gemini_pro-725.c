//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

#define G 6.67408e-11

int main() {
    int nPlanets;
    printf("Enter the number of planets: ");
    scanf("%d", &nPlanets);

    Planet *planets = malloc(sizeof(Planet) * nPlanets);

    for (int i = 0; i < nPlanets; i++) {
        printf("Enter the mass of planet %d: ", i + 1);
        scanf("%lf", &planets[i].mass);

        printf("Enter the x-coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].x);

        printf("Enter the y-coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].y);

        printf("Enter the z-coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].z);

        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].vz = 0;
    }

    double dt = 0.001;
    double t = 0;

    while (t < 100) {
        for (int i = 0; i < nPlanets; i++) {
            double ax = 0;
            double ay = 0;
            double az = 0;

            for (int j = 0; j < nPlanets; j++) {
                if (i == j) {
                    continue;
                }

                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dz = planets[j].z - planets[i].z;

                double r = sqrt(dx * dx + dy * dy + dz * dz);

                ax += G * planets[j].mass * dx / (r * r * r);
                ay += G * planets[j].mass * dy / (r * r * r);
                az += G * planets[j].mass * dz / (r * r * r);
            }

            planets[i].vx += ax * dt;
            planets[i].vy += ay * dt;
            planets[i].vz += az * dt;

            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }

        t += dt;
    }

    for (int i = 0; i < nPlanets; i++) {
        printf("The final position of planet %d is (%lf, %lf, %lf)\n", i + 1, planets[i].x, planets[i].y, planets[i].z);
    }

    free(planets);

    return 0;
}