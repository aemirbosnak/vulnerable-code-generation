//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A curious particle with mass and charge
typedef struct {
    double mass;
    double charge;
    double x, y, z;  // position
    double vx, vy, vz;  // velocity
    double ax, ay, az;  // acceleration
} Particle;

// Create a new particle with the given properties
Particle* create_particle(double mass, double charge, double x, double y, double z, double vx, double vy, double vz) {
    Particle* p = malloc(sizeof(Particle));
    p->mass = mass;
    p->charge = charge;
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    return p;
}

// Calculate the force on a particle due to the presence of another particle
void calculate_force(Particle* p1, Particle* p2) {
    // Calculate the distance between the particles
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    // Calculate the force
    double F = (p1->charge * p2->charge) / (r*r);

    // Calculate the acceleration due to the force
    p1->ax = F * dx / p1->mass;
    p1->ay = F * dy / p1->mass;
    p1->az = F * dz / p1->mass;
}

// Update the velocity and position of a particle based on its acceleration
void update_particle(Particle* p, double dt) {
    // Update the velocity
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;

    // Update the position
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// Simulate the motion of a particle for a given period of time
void simulate_particle(Particle* p, double dt, double t_max) {
    // Loop over the time steps
    for (double t = 0; t < t_max; t += dt) {
        // Calculate the force on the particle due to the presence of the other particles
        calculate_force(p, p);

        // Update the velocity and position of the particle
        update_particle(p, dt);
    }
}

// Print the final position of the particle
void print_particle(Particle* p) {
    printf("Final position: (%f, %f, %f)\n", p->x, p->y, p->z);
}

// Main function
int main() {
    // Create two particles
    Particle* p1 = create_particle(1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    Particle* p2 = create_particle(1.0, -1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0);

    // Simulate the motion of the particles
    simulate_particle(p1, 0.01, 10.0);
    simulate_particle(p2, 0.01, 10.0);

    // Print the final positions of the particles
    print_particle(p1);
    print_particle(p2);

    return 0;
}