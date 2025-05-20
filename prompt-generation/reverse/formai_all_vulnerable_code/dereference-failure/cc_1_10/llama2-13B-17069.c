//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67408e-11 // Gravitational constant
#define M 5.97237e24 // Mass of the Earth
#define R 6.37101e6 // Radius of the Earth

typedef struct {
    double x; // Position x-coordinate
    double y; // Position y-coordinate
    double z; // Position z-coordinate
} Position;

typedef struct {
    double vx; // Velocity x-coordinate
    double vy; // Velocity y-coordinate
    double vz; // Velocity z-coordinate
} Velocity;

typedef struct {
    Position p; // Position
    Velocity v; // Velocity
} Particle;

// Function to generate a random position and velocity for a particle
Particle* generate_particle(void) {
    double x = (double)rand() / RAND_MAX * R;
    double y = (double)rand() / RAND_MAX * R;
    double z = (double)rand() / RAND_MAX * R;
    double vx = (double)rand() / RAND_MAX * 10;
    double vy = (double)rand() / RAND_MAX * 10;
    double vz = (double)rand() / RAND_MAX * 10;
    Particle* p = malloc(sizeof(Particle));
    p->p.x = x;
    p->p.y = y;
    p->p.z = z;
    p->v.vx = vx;
    p->v.vy = vy;
    p->v.vz = vz;
    return p;
}

// Function to update the position and velocity of a particle based on gravity
void update_particle(Particle* p) {
    double dt = 0.01; // Time step
    double g = G * M / sqrt(pow(p->p.x, 2) + pow(p->p.y, 2) + pow(p->p.z, 2));
    p->p.x += p->v.vx * dt;
    p->p.y += p->v.vy * dt;
    p->p.z += p->v.vz * dt;
    p->v.vx += g * dt * cos(p->p.x * dt);
    p->v.vy += g * dt * cos(p->p.y * dt);
    p->v.vz += g * dt * cos(p->p.z * dt);
}

// Function to draw the particles
void draw_particles(Particle** particles, int num_particles) {
    for (int i = 0; i < num_particles; i++) {
        printf("Particle %d: (%.2f, %.2f, %.2f) vx: %.2f, vy: %.2f, vz: %.2f\n", i, particles[i]->p.x, particles[i]->p.y, particles[i]->p.z, particles[i]->v.vx, particles[i]->v.vy, particles[i]->v.vz);
    }
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator
    int num_particles = 100; // Number of particles to generate
    Particle** particles = malloc(num_particles * sizeof(Particle*));
    for (int i = 0; i < num_particles; i++) {
        particles[i] = generate_particle();
    }
    for (int i = 0; i < num_particles; i++) {
        update_particle(particles[i]);
    }
    draw_particles(particles, num_particles);
    return 0;
}