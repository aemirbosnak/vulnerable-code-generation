//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONSTANT 6.674e-11 
#define MAX_ITERATIONS 10000
#define TIME_STEP 60*60*24

typedef struct {
    double x, y, z;
} vector; 

typedef struct {
    vector pos, vel, force;
    double mass;
} particle;

particle* create_particle(double x, double y, double z, double vx, double vy, double vz, double mass) {
    particle* p = (particle*) malloc(sizeof(particle));
    p->pos.x = x; 
    p->pos.y = y;
    p->pos.z = z;
    p->vel.x = vx; 
    p->vel.y = vy;
    p->vel.z = vz;
    p->mass = mass;
    return p;
}

void update_particle(particle* p, double time_step) {
    p->vel.x += p->force.x / p->mass * time_step;
    p->vel.y += p->force.y / p->mass * time_step;
    p->vel.z += p->force.z / p->mass * time_step;
    p->pos.x += p->vel.x * time_step;
    p->pos.y += p->vel.y * time_step;
    p->pos.z += p->vel.z * time_step;
}

void calculate_force(particle* a, particle* b) {
    vector distance;
    distance.x = b->pos.x - a->pos.x;
    distance.y = b->pos.y - a->pos.y;
    distance.z = b->pos.z - a->pos.z;
    double r = sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
    double f = GRAV_CONSTANT * a->mass * b->mass / (r*r);
    a->force.x += f * distance.x / r;
    a->force.y += f * distance.y / r;
    a->force.z += f * distance.z / r;
}

void simulate_gravity(particle** particles, int num_particles, int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        // Reset forces
        for (int j = 0; j < num_particles; j++) {
            particles[j]->force.x = 0.0;
            particles[j]->force.y = 0.0;
            particles[j]->force.z = 0.0;
        }
        // Calculate forces
        for (int j = 0; j < num_particles; j++) {
            for (int k = j+1; k < num_particles; k++) {
                calculate_force(particles[j], particles[k]);
                calculate_force(particles[k], particles[j]);
            }
        }
        // Update particles
        for (int j = 0; j < num_particles; j++) {
            update_particle(particles[j], TIME_STEP);
        }
    }
}

int main() {
    // Initialize particles
    particle* sun = create_particle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.989e30);
    particle* earth = create_particle(1.496e11, 0.0, 0.0, 0.0, 29783.0, 0.0, 5.97e24);
    particle* moon = create_particle(1.496e11 + 3.844e8, 0.0, 0.0, 0.0, 3078.0 + 29783.0, 0.0, 7.342e22);
    particle* particles[] = {sun, earth, moon};
    int num_particles = 3;
    // Simulate gravity
    simulate_gravity(particles, num_particles, MAX_ITERATIONS);
    // Print final positions
    printf("Final positions:\n");
    printf("Sun: (%.2f, %.2f, %.2f)\n", sun->pos.x, sun->pos.y, sun->pos.z);
    printf("Earth: (%.2f, %.2f, %.2f)\n", earth->pos.x, earth->pos.y, earth->pos.z);
    printf("Moon: (%.2f, %.2f, %.2f)\n", moon->pos.x, moon->pos.y, moon->pos.z);
    // Free memory
    free(sun);
    free(earth);
    free(moon);
    return 0;
}