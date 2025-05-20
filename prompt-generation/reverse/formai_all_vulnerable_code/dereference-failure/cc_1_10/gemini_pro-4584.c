//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
    double vx, vy;
    double m;
    double r;
} Particle;

typedef struct {
    double x, y;
    double m;
    double r;
} Planet;

const double G = 6.67408e-11;  // Gravitational constant
const double dt = 0.01;  // Time step

int main() {
    int n_particles = 1000;
    int n_planets = 10;

    // Create the particles
    Particle* particles = malloc(n_particles * sizeof(Particle));
    for (int i = 0; i < n_particles; i++) {
        particles[i].x = (double)rand() / RAND_MAX;
        particles[i].y = (double)rand() / RAND_MAX;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].m = 1.0;
        particles[i].r = 0.01;
    }

    // Create the planets
    Planet* planets = malloc(n_planets * sizeof(Planet));
    for (int i = 0; i < n_planets; i++) {
        planets[i].x = (double)rand() / RAND_MAX;
        planets[i].y = (double)rand() / RAND_MAX;
        planets[i].m = 1000.0;
        planets[i].r = 0.1;
    }

    // Integrate the equations of motion using the symplectic "leapfrog" method
    for (int t = 0; t < 100000; t++) {
        // Calculate the forces on the particles
        for (int i = 0; i < n_particles; i++) {
            particles[i].vx += dt * G * planets[0].m / 1.0 / sqrt(pow(particles[i].x - planets[0].x, 2) + pow(particles[i].y - planets[0].y, 2));
            particles[i].vy += dt * G * planets[0].m / 1.0 / sqrt(pow(particles[i].x - planets[0].x, 2) + pow(particles[i].y - planets[0].y, 2));
        }
        for (int i = 0; i < n_particles; i++) {
            // Update the positions of the particles
            particles[i].x += dt * particles[i].vx;
            particles[i].y += dt * particles[i].vy;
        }
        for (int i = 0; i < n_particles; i++) {
            // Calculate the forces on the particles
            particles[i].vx += dt * G * planets[0].m / 1.0 / sqrt(pow(particles[i].x - planets[0].x, 2) + pow(particles[i].y - planets[0].y, 2));
            particles[i].vy += dt * G * planets[0].m / 1.0 / sqrt(pow(particles[i].x - planets[0].x, 2) + pow(particles[i].y - planets[0].y, 2));
        }
    }

    // Free the memory
    free(particles);
    free(planets);

    return 0;
}