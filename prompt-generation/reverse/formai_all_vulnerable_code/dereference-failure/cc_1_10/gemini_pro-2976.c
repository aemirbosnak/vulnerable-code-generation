//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant (N m^2 kg^-2)
#define DT 1000.0 // Time step (s)
#define RADIUS 10000.0 // Radius of the planet (m)
#define MASS 5.972e24 // Mass of the planet (kg)

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double m;
} Body;

int main() {
    // Initialize the planet
    Body planet;
    planet.x = 0.0;
    planet.y = 0.0;
    planet.z = 0.0;
    planet.vx = 0.0;
    planet.vy = 0.0;
    planet.vz = 0.0;
    planet.m = MASS;

    // Initialize the projectiles
    int num_projectiles = 1000;
    Body* projectiles = malloc(num_projectiles * sizeof(Body));
    for (int i = 0; i < num_projectiles; i++) {
        projectiles[i].x = (rand() / (RAND_MAX / (2 * RADIUS))) - RADIUS;
        projectiles[i].y = (rand() / (RAND_MAX / (2 * RADIUS))) - RADIUS;
        projectiles[i].z = (rand() / (RAND_MAX / (2 * RADIUS))) - RADIUS;
        projectiles[i].vx = (rand() / (RAND_MAX / 1000.0)) - 500.0;
        projectiles[i].vy = (rand() / (RAND_MAX / 1000.0)) - 500.0;
        projectiles[i].vz = (rand() / (RAND_MAX / 1000.0)) - 500.0;
        projectiles[i].m = 1000.0;
    }

    // Simulate the gravity
    double t = 0.0;
    while (t < 100000.0) {
        // Calculate the gravitational force between the planet and each projectile
        for (int i = 0; i < num_projectiles; i++) {
            double dx = projectiles[i].x - planet.x;
            double dy = projectiles[i].y - planet.y;
            double dz = projectiles[i].z - planet.z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * planet.m * projectiles[i].m / (r * r);
            double fx = f * dx / r;
            double fy = f * dy / r;
            double fz = f * dz / r;

            // Update the acceleration of each projectile
            projectiles[i].vx += fx / projectiles[i].m * DT;
            projectiles[i].vy += fy / projectiles[i].m * DT;
            projectiles[i].vz += fz / projectiles[i].m * DT;
        }

        // Update the position of each projectile
        for (int i = 0; i < num_projectiles; i++) {
            projectiles[i].x += projectiles[i].vx * DT;
            projectiles[i].y += projectiles[i].vy * DT;
            projectiles[i].z += projectiles[i].vz * DT;
        }

        // Update the time
        t += DT;
    }

    // Print the final positions of the projectiles
    for (int i = 0; i < num_projectiles; i++) {
        printf("Projectile %d: (%.2f, %.2f, %.2f)\n", i, projectiles[i].x, projectiles[i].y, projectiles[i].z);
    }

    // Free the memory allocated for the projectiles
    free(projectiles);

    return 0;
}