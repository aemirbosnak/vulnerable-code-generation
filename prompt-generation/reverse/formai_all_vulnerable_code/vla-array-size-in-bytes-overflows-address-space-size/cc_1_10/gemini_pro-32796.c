//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define dt 100

typedef struct {
    double m;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);

    Planet planets[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the mass, x, y, z, vx, vy, and vz of planet %d: ", i + 1);
        scanf("%lf %lf %lf %lf %lf %lf %lf", &planets[i].m, &planets[i].x, &planets[i].y, &planets[i].z, &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    double t = 0;
    while (1) {
        // Calculate the forces on each planet
        for (int i = 0; i < n; i++) {
            planets[i].vx = 0;
            planets[i].vy = 0;
            planets[i].vz = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dz = planets[j].z - planets[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * planets[i].m * planets[j].m / (r * r);
                planets[i].vx += f * dx / r;
                planets[i].vy += f * dy / r;
                planets[i].vz += f * dz / r;
            }
        }

        // Update the positions and velocities of each planet
        for (int i = 0; i < n; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }

        // Print the positions of each planet
        printf("t = %.2f\n", t);
        for (int i = 0; i < n; i++) {
            printf("Planet %d: (%.2f, %.2f, %.2f)\n", i + 1, planets[i].x, planets[i].y, planets[i].z);
        }

        t += dt;
    }

    return 0;
}