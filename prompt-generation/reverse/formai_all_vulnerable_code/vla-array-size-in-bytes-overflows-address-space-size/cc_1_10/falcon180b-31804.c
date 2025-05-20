//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

// Define a struct for particles
struct particle {
    double x, y, z, vx, vy, vz, mass;
};

// Function to calculate distance between two particles
double distance(struct particle p1, struct particle p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate gravitational force between two particles
void gravity(struct particle p1, struct particle p2, double dt) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * p1.mass * p2.mass / (r*r);
    p1.vx -= force*dx/r*dt;
    p1.vy -= force*dy/r*dt;
    p1.vz -= force*dz/r*dt;
    p2.vx += force*dx/r*dt;
    p2.vy += force*dy/r*dt;
    p2.vz += force*dz/r*dt;
}

// Function to update position and velocity of a particle
void update_particle(struct particle p, double dt) {
    p.x += p.vx*dt;
    p.y += p.vy*dt;
    p.z += p.vz*dt;
}

// Function to print a particle
void print_particle(struct particle p) {
    printf("Particle (%lf, %lf, %lf) with mass %lf\n", p.x, p.y, p.z, p.mass);
}

// Function to simulate the system
void simulate(int num_particles, double dt) {
    struct particle particles[num_particles];

    // Initialize particles
    for(int i=0; i<num_particles; i++) {
        particles[i].x = (double)i;
        particles[i].y = 0.0;
        particles[i].z = 0.0;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].vz = 0.0;
        particles[i].mass = 1.0;
    }

    // Simulate for a while
    for(int t=0; t<1000; t++) {
        for(int i=0; i<num_particles-1; i++) {
            for(int j=i+1; j<num_particles; j++) {
                gravity(particles[i], particles[j], dt);
            }
        }
        for(int i=0; i<num_particles; i++) {
            update_particle(particles[i], dt);
        }
    }
}

int main() {
    int num_particles;
    printf("Enter number of particles: ");
    scanf("%d", &num_particles);

    double dt = 0.01;
    printf("Simulating %d particles with time step %lf\n", num_particles, dt);

    simulate(num_particles, dt);

    return 0;
}