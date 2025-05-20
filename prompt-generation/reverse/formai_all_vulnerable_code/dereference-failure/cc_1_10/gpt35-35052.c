//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11    // Gravitational constant
#define DAY 86400       // Length of a day in seconds

typedef struct {
    double x, y;    // position
    double vx, vy;  // velocity
    double ax, ay;  // acceleration
    double mass;    // mass
} Body;

void calculateForces(Body* bodies, int num_bodies)
{
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].ax = 0;
        bodies[i].ay = 0;
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double d = sqrt(dx*dx + dy*dy);
            double f = G * bodies[i].mass * bodies[j].mass / (d*d);
            bodies[i].ax += f*dx / (d*bodies[i].mass);
            bodies[i].ay += f*dy / (d*bodies[i].mass);
        }
    }
}

void updatePositions(Body* bodies, int num_bodies, double dt)
{
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].x += bodies[i].vx*dt + 0.5*bodies[i].ax*dt*dt;
        bodies[i].y += bodies[i].vy*dt + 0.5*bodies[i].ay*dt*dt;
    }
}

void updateVelocities(Body* bodies, int num_bodies, double dt)
{
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].vx += 0.5*(bodies[i].ax + bodies[i].ax)*dt;
        bodies[i].vy += 0.5*(bodies[i].ay + bodies[i].ay)*dt;
    }
}

int main()
{
    // Define the initial position, velocity, and mass of the sun, planets, and moon
    Body sun = {0, 0, 0, 0, 0, 1.98e30};
    Body earth = {1.5e11, 0, 0, 3e4, 0, 5.97e24};
    Body moon = {1.5e11 + 3.84e8, 0, 0, 3e4 + 1022, 0, 7.342e22};
    Body mars = {2.3e11, 0, 0, 2.4e4, 0, 6.39e23};
    Body venus = {1.1e11, 0, 0, 6.4e3, 0, 4.87e24};

    // Set up the simulation parameters
    const double dt = 1000*DAY;  // Time step
    const int num_steps = 365*2; // Number of time steps to simulate
    const int num_bodies = 5;

    Body* bodies = malloc(num_bodies * sizeof(Body));

    bodies[0] = sun;
    bodies[1] = earth;
    bodies[2] = moon;
    bodies[3] = mars;
    bodies[4] = venus;

    for (int i = 0; i < num_steps; i++) {
        calculateForces(bodies, num_bodies);
        updatePositions(bodies, num_bodies, dt);
        calculateForces(bodies, num_bodies);
        updateVelocities(bodies, num_bodies, dt);
        printf("Step %d\n", i+1);
        for (int j = 0; j < num_bodies; j++) {
            printf("Body %d - Position: (%f, %f) - Velocity: (%f, %f)\n", j+1, bodies[j].x, bodies[j].y, bodies[j].vx, bodies[j].vy);
        }
    }

    free(bodies);

    return 0;
}