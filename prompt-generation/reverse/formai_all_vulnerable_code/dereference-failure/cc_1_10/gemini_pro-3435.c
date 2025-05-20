//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Gravitational constant
const double G = 6.67408e-11; // m^3 kg^-1 s^-2

// Planet structure
typedef struct planet {
    double mass; // kg
    double x, y, z; // m
    double vx, vy, vz; // m/s
} planet;

// Initialize a planet
void init_planet(planet *p, double mass, double x, double y, double z, double vx, double vy, double vz) {
    p->mass = mass;
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

// Calculate the gravitational force between two planets
void calc_force(planet *p1, planet *p2, double *fx, double *fy, double *fz) {
    // Calculate the distance between the planets
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    // Calculate the gravitational force
    *fx = G * p1->mass * p2->mass * dx / (r*r*r);
    *fy = G * p1->mass * p2->mass * dy / (r*r*r);
    *fz = G * p1->mass * p2->mass * dz / (r*r*r);
}

// Update the position and velocity of a planet
void update_planet(planet *p, double dt) {
    // Calculate the gravitational force on the planet
    double fx, fy, fz;
    calc_force(p, NULL, &fx, &fy, &fz);

    // Update the planet's position
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;

    // Update the planet's velocity
    p->vx += fx / p->mass * dt;
    p->vy += fy / p->mass * dt;
    p->vz += fz / p->mass * dt;
}

// Main function
int main() {
    // Initialize the planets
    planet planets[3];
    init_planet(&planets[0], 1e24, 0, 0, 0, 0, 0, 0); // Sun
    init_planet(&planets[1], 5.972e24, 1.5e11, 0, 0, 0, 30000, 0); // Earth
    init_planet(&planets[2], 7.348e22, 2.5e11, 0, 0, 0, 20000, 0); // Moon

    // Set the time step
    double dt = 1e3; // s

    // Simulate the planet motion
    for (int i = 0; i < 10000; i++) {
        // Update the position and velocity of each planet
        for (int j = 0; j < 3; j++) {
            update_planet(&planets[j], dt);
        }

        // Print the position of each planet
        for (int j = 0; j < 3; j++) {
            printf("%d: (%lf, %lf, %lf)\n", j, planets[j].x, planets[j].y, planets[j].z);
        }
        printf("\n");
    }

    return 0;
}