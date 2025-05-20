//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double m;       // mass in kg
    double x, y;    // position in m
    double vx, vy;  // velocity in m/s
    double fx, fy;  // force in N
} Particle;

void update_forces(Particle *p1, Particle *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r2 = dx*dx + dy*dy;
    double F = (6.674e-11) * p1->m * p2->m / r2;

    p1->fx += F * dx / sqrt(r2);
    p1->fy += F * dy / sqrt(r2);

    p2->fx -= F * dx / sqrt(r2);
    p2->fy -= F * dy / sqrt(r2);
}

void update_positions(Particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void update_velocities(Particle *p, double dt) {
    p->vx += p->fx * dt / p->m;
    p->vy += p->fy * dt / p->m;
}

void print_particles(Particle *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Particle %d: m=%f, x=%f, y=%f, vx=%f, vy=%f, fx=%f, fy=%f\n",
               i, p[i].m, p[i].x, p[i].y, p[i].vx, p[i].vy, p[i].fx, p[i].fy);
    }
}

int main() {
    // Create two particles
    Particle p1 = {1.0, 0.0, 0.0, 0.0, 0.0};
    Particle p2 = {1.0, 1.0, 0.0, 0.0, 0.0};

    // Set the timestep
    double dt = 0.01;

    // Run the simulation for 1000 timesteps
    for (int i = 0; i < 1000; i++) {
        // Update the forces between the particles
        update_forces(&p1, &p2);

        // Update the positions of the particles
        update_positions(&p1, dt);
        update_positions(&p2, dt);

        // Update the velocities of the particles
        update_velocities(&p1, dt);
        update_velocities(&p2, dt);

        // Print the positions of the particles
        print_particles(&p1, 2);
    }

    return 0;
}