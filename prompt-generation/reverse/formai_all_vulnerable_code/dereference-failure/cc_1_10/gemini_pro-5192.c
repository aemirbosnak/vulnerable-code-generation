//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
} Particle;

const double G = 6.67408e-11; // gravitational constant (m^3 kg^-1 s^-2)

int main() {
    // create an array of particles
    const int N = 1000;
    Particle *particles = malloc(N * sizeof(Particle));

    // initialize the particles
    for (int i = 0; i < N; i++) {
        particles[i].mass = 1.0; // mass (kg)
        particles[i].x = 0.0; // position (m)
        particles[i].y = 0.0; // position (m)
        particles[i].z = 0.0; // position (m)
        particles[i].vx = 0.0; // velocity (m/s)
        particles[i].vy = 0.0; // velocity (m/s)
        particles[i].vz = 0.0; // velocity (m/s)
        particles[i].fx = 0.0; // force (N)
        particles[i].fy = 0.0; // force (N)
        particles[i].fz = 0.0; // force (N)
    }

    // simulate the physics
    const double dt = 0.001; // time step (s)
    for (int t = 0; t < 10000; t++) {
        // calculate the forces
        for (int i = 0; i < N; i++) {
            particles[i].fx = 0.0; // reset the force
            particles[i].fy = 0.0; // reset the force
            particles[i].fz = 0.0; // reset the force
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    // calculate the distance between the particles
                    const double dx = particles[i].x - particles[j].x;
                    const double dy = particles[i].y - particles[j].y;
                    const double dz = particles[i].z - particles[j].z;
                    const double r = sqrt(dx * dx + dy * dy + dz * dz);

                    // calculate the force between the particles
                    const double f = G * particles[i].mass * particles[j].mass / (r * r);

                    // add the force to the first particle
                    particles[i].fx += f * dx / r;
                    particles[i].fy += f * dy / r;
                    particles[i].fz += f * dz / r;
                }
            }
        }

        // update the velocities
        for (int i = 0; i < N; i++) {
            particles[i].vx += particles[i].fx / particles[i].mass * dt;
            particles[i].vy += particles[i].fy / particles[i].mass * dt;
            particles[i].vz += particles[i].fz / particles[i].mass * dt;
        }

        // update the positions
        for (int i = 0; i < N; i++) {
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
            particles[i].z += particles[i].vz * dt;
        }
    }

    // free the particles
    free(particles);

    return 0;
}