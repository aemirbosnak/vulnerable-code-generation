//MISTRAL-7B DATASET v1.0 Category: Physics simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Struct for a particle
typedef struct {
    double x, y, vx, vy, mass;
} Particle;

// Function to initialize particles
void init_particles(Particle particles[], int num_particles, double width, double height) {
    int i;
    for (i = 0; i < num_particles; i++) {
        particles[i].x = rand() % (int)(width * 10) / 10.0;
        particles[i].y = rand() % (int)(height * 10) / 10.0;
        particles[i].vx = (double)rand() / RAND_MAX * 2 - 1;
        particles[i].vy = (double)rand() / RAND_MAX * 2 - 1;
        particles[i].mass = (double)rand() / RAND_MAX * 5 + 2.5;
    }
}

// Function to update particles' velocities and positions based on gravity
void update(Particle particles[], int num_particles, double width, double height) {
    double g = 0.1; // Gravity acceleration
    int i;
    for (i = 0; i < num_particles; i++) {
        // Update velocities
        particles[i].vx += particles[i].vy * g * particles[i].mass / width;
        particles[i].vy += g;

        // Update positions
        particles[i].x += particles[i].vx;
        particles[i].y += particles[i].vy;

        // Wrap around edges
        if (particles[i].x < 0)
            particles[i].x = width;
        if (particles[i].x > width)
            particles[i].x = 0;
        if (particles[i].y < 0)
            particles[i].y = height;
        if (particles[i].y > height)
            particles[i].y = 0;
    }
}

int main() {
    // Set up random seed
    srand(time(NULL));

    // Number of particles
    int num_particles = 50;

    // Width and height of the simulation area
    double width = 10.0, height = 10.0;

    // Allocate memory for particles
    Particle *particles = (Particle*)calloc(num_particles, sizeof(Particle));

    // Initialize particles
    init_particles(particles, num_particles, width, height);

    // Simulation loop
    int i;
    for (i = 0; i < 1000; i++) {
        update(particles, num_particles, width, height);
        // Print particles' positions for every 100th iteration
        if (i % 100 == 0) {
            int j;
            for (j = 0; j < num_particles; j++)
                printf("(%lf, %lf) ", particles[j].x, particles[j].y);
            printf("\n");
        }
    }

    // Free memory
    free(particles);

    return 0;
}