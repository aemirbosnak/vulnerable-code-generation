//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define DT 0.01

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} planet;

int main() {
    int nplanets;
    printf("Enter the number of planets: ");
    scanf("%d", &nplanets);

    // Create an array of planets
    planet *planets = malloc(nplanets * sizeof(planet));

    // Get the mass and position of each planet
    for (int i = 0; i < nplanets; i++) {
        printf("Enter the mass of planet %d: ", i + 1);
        scanf("%lf", &planets[i].mass);

        printf("Enter the x-coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].x);

        printf("Enter the y-coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].y);

        printf("Enter the z-coordinate of planet %d: ", i + 1);
        scanf("%lf", &planets[i].z);

        // Initialize the velocity of each planet to zero
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].vz = 0;
    }

    // Simulate the motion of the planets
    for (double t = 0; t < 100; t += DT) {
        // Calculate the acceleration of each planet due to the gravity of all other planets
        for (int i = 0; i < nplanets; i++) {
            planets[i].vx = 0;
            planets[i].vy = 0;
            planets[i].vz = 0;

            for (int j = 0; j < nplanets; j++) {
                if (i == j) {
                    continue;
                }

                // Calculate the distance between the two planets
                double dx = planets[i].x - planets[j].x;
                double dy = planets[i].y - planets[j].y;
                double dz = planets[i].z - planets[j].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);

                // Calculate the force between the two planets
                double f = G * planets[i].mass * planets[j].mass / (r * r);

                // Calculate the acceleration of planet i due to the gravity of planet j
                planets[i].vx += f * dx / r;
                planets[i].vy += f * dy / r;
                planets[i].vz += f * dz / r;
            }
        }

        // Update the position of each planet
        for (int i = 0; i < nplanets; i++) {
            planets[i].x += planets[i].vx * DT;
            planets[i].y += planets[i].vy * DT;
            planets[i].z += planets[i].vz * DT;
        }
    }

    // Print the final positions of the planets
    for (int i = 0; i < nplanets; i++) {
        printf("The final position of planet %d is (%lf, %lf, %lf)\n", i + 1, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}