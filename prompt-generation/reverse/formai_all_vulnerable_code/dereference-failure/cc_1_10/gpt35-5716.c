//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11      // Universal Gravitational Constant
#define SUN_MASS 1.989e30 // Mass of the Sun
#define AU 1.496e11      // Astronomical Unit

// Define a structure to hold information about the properties of each celestial body
typedef struct
{
    double x, y;    // Position
    double vx, vy;  // Velocity
    double mass;    // Mass
} Body;

// Define a function to calculate the acceleration of each body due to the gravitational forces from the others
void calculate_acceleration(Body *bodies, int num_bodies, double *ax, double *ay)
{
    for (int i = 0; i < num_bodies; i++)
    {
        ax[i] = 0.0;
        ay[i] = 0.0;
        for (int j = 0; j < num_bodies; j++)
        {
            if (i == j)
            {
                continue;   // Don't calculate the gravitational force on a body due to itself
            }
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double r_squared = dx * dx + dy * dy;
            double r = sqrt(r_squared);
            double f = G * bodies[i].mass * bodies[j].mass / r_squared;
            double ax_delta = f / bodies[i].mass * dx / r;
            double ay_delta = f / bodies[i].mass * dy / r;
            ax[i] += ax_delta;
            ay[i] += ay_delta;
        }
    }
}

int main()
{
    int num_bodies = 3;
    Body *bodies = malloc(num_bodies * sizeof(Body));

    // Set up the Sun at the center
    bodies[0].mass = SUN_MASS;
    bodies[0].x = 0.0;
    bodies[0].y = 0.0;
    bodies[0].vx = 0.0;
    bodies[0].vy = 0.0;

    // Set up Earth in orbit around the Sun
    bodies[1].mass = 5.97e24;
    bodies[1].x = AU;
    bodies[1].y = 0.0;
    bodies[1].vx = 0.0;
    bodies[1].vy = sqrt(G * SUN_MASS / AU);

    // Set up Mars in orbit around the Sun
    bodies[2].mass = 6.39e23;
    bodies[2].x = 1.52 * AU;
    bodies[2].y = 0.0;
    bodies[2].vx = 0.0;
    bodies[2].vy = sqrt(G * SUN_MASS / (1.52 * AU));

    // Simulation settings
    const double dt = 3600.0; // 1 hour in seconds
    const double t_end = 5.2e7 * dt; // Simulate 52 million years


    for (double t = 0.0; t < t_end; t += dt)
    {
        // Calculate the acceleration of each body due to the gravitational forces from the others
        double ax[num_bodies];
        double ay[num_bodies];
        calculate_acceleration(bodies, num_bodies, ax, ay);

        // Update the positions and velocities of each body using the calculated acceleration
        for (int i = 0; i < num_bodies; i++)
        {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].vx += ax[i] * dt;
            bodies[i].vy += ay[i] * dt;
        }

        // Output the positions of each body at regular intervals (in years)
        if (((int)t) % (3600 * 24 * 365) == 0)
        {
            printf("t = %d years\n", (int)(t / (3600 * 24 * 365)));
            for (int i = 0; i < num_bodies; i++)
            {
                printf("Body %d: (%.2e,%.2e)\n", i, bodies[i].x, bodies[i].y);
            }
            printf("\n");
        }
    }

    free(bodies);
    return 0;
}