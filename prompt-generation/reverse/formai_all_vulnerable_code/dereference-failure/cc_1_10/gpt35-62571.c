//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double x, y;
    double vx, vy;
    double ax, ay;
    double m;
} Body;

void update_acc(Body *bodies, int n) {
    // Update acceleration of all bodies based on Newton's law of gravitation
    for (int i = 0; i < n; i++) {
        double ax = 0.0, ay = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx * dx + dy * dy);
                double f = G * bodies[j].m / (r * r);
                ax += f * dx / r;
                ay += f * dy / r;
            }
        }
        bodies[i].ax = ax;
        bodies[i].ay = ay;
    }
}

void update_vel(Body *bodies, int n, double dt) {
    // Update velocity of all bodies based on acceleration
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;
    }
}

void update_pos(Body *bodies, int n, double dt) {
    // Update position of all bodies based on velocity
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

void simulate(Body *bodies, int n, double dt, int steps) {
    // Simulate the motion of n bodies for a given number of time steps
    for (int i = 0; i < steps; i++) {
        update_acc(bodies, n);
        update_vel(bodies, n, dt);
        update_pos(bodies, n, dt);
    }
}

int main() {
    // Example usage
    int n = 3; // Number of bodies
    Body *bodies = (Body *) malloc(n * sizeof(Body));
    bodies[0] = (Body) {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0}; // Body 1
    bodies[1] = (Body) {1.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0}; // Body 2
    bodies[2] = (Body) {0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 3.0}; // Body 3

    // Simulate the motion of the bodies for 1000 time steps with a time step of 0.01 seconds
    simulate(bodies, n, 0.01, 1000);

    // Output the final positions and velocities of the bodies
    printf("Final positions and velocities:\n");
    for (int i = 0; i < n; i++) {
        printf("Body %d: x=%.3f y=%.3f vx=%.3f vy=%.3f\n",
               i+1, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }

    free(bodies);
    return 0;
}