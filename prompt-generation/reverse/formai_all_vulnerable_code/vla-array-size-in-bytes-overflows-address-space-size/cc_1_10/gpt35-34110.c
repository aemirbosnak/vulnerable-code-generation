//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets;
    printf("Welcome to the C Planet Gravity Simulation!\n");
    printf("How many planets would you like to simulate? ");
    scanf("%d", &num_planets);

    srand(time(NULL));

    float G = 6.67430e-11; // Universal gravitational constant
    float mass[num_planets];
    float x[num_planets];
    float y[num_planets];
    float vx[num_planets];
    float vy[num_planets];

    // Initialize the planets with random mass, x/y positions, and velocities
    for (int i = 0; i < num_planets; i++) {
        mass[i] = ((float)rand()/(float)RAND_MAX) * 1e22 + 1e20; // Mass between 1e20 kg and 1e22 kg
        x[i] = ((float)rand()/(float)RAND_MAX) * 1e9 - 5e8; // x position between -5e8 and 5e8 meters
        y[i] = ((float)rand()/(float)RAND_MAX) * 1e9 - 5e8; // y position between -5e8 and 5e8 meters
        vx[i] = ((float)rand()/(float)RAND_MAX) * 1e4 - 5e3; // x velocity between -5e3 and 5e3 m/s
        vy[i] = ((float)rand()/(float)RAND_MAX) * 1e4 - 5e3; // y velocity between -5e3 and 5e3 m/s
    }

    float dt = 1; // Time step in seconds
    int num_steps = 10000; // Number of steps to simulate

    // Simulation loop
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_planets; i++) {
            float Fx = 0;
            float Fy = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    float dx = x[j] - x[i];
                    float dy = y[j] - y[i];
                    float r = sqrt(dx*dx + dy*dy);
                    float F = G * mass[i] * mass[j] / (r*r);
                    Fx += F * dx / r;
                    Fy += F * dy / r;
                }
            }
            vx[i] += Fx / mass[i] * dt;
            vy[i] += Fy / mass[i] * dt;
            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
        }
    }

    // Print the final positions and velocities of the planets
    printf("Final positions and velocities:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: mass = %e kg, x = %e m, y = %e m, vx = %e m/s, vy = %e m/s\n", i+1, mass[i], x[i], y[i], vx[i], vy[i]);
    }

    return 0;
}