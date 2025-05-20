//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define G 6.6743e-11 // Gravitational constant
#define DT 86400.0 // Time step (seconds)

// Structs
typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double mass; // Mass
} Body;

// Function prototypes
void compute_acceleration(Body *body, Body *others, int n, double *ax, double *ay);
void update_velocity_position(Body *body, double ax, double ay, double dt);

int main() {
    // Initialize bodies
    int n = 3;
    Body *bodies = malloc(n * sizeof(Body));

    bodies[0].x = 0.0;
    bodies[0].y = 5000000.0;
    bodies[0].vx = 7000.0;
    bodies[0].vy = 0.0;
    bodies[0].mass = 5.97e24;

    bodies[1].x = -150000000.0;
    bodies[1].y = 0.0;
    bodies[1].vx = 0.0;
    bodies[1].vy = -29000.0;
    bodies[1].mass = 7.34e22;

    bodies[2].x = 0.0;
    bodies[2].y = -42164000.0;
    bodies[2].vx = -1022.0;
    bodies[2].vy = 0.0;
    bodies[2].mass = 2.2e5;

    // Simulation loop
    double ax, ay;
    int i, j, k;
    for (i = 0; i < 365; i++) { // 1 year
        printf("Day %d:\n", i+1);
        for (j = 0; j < n; j++) {
            compute_acceleration(&bodies[j], bodies, n, &ax, &ay);
            update_velocity_position(&bodies[j], ax, ay, DT);
            printf("Body %d position: (%f, %f)\n", j+1, bodies[j].x, bodies[j].y);
        }
    }

    free(bodies);
    return 0;
}

void compute_acceleration(Body *body, Body *others, int n, double *ax, double *ay) {
    *ax = 0.0;
    *ay = 0.0;
    double dx, dy, r, f;

    int i;
    for (i = 0; i < n; i++) {
        if (body == &others[i]) {
            continue;
        }
        dx = others[i].x - body->x;
        dy = others[i].y - body->y;
        r = sqrt(dx*dx + dy*dy);
        f = G * body->mass * others[i].mass / (r*r);
        *ax += f * dx / r;
        *ay += f * dy / r;
    }
}

void update_velocity_position(Body *body, double ax, double ay, double dt) {
    body->vx += ax * dt;
    body->vy += ay * dt;
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}