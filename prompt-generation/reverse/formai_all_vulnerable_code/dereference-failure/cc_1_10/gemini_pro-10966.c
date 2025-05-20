//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: surprised
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

// Constants
#define dt 0.001
#define g 9.81

// Structs
typedef struct Vector2D {
    double x, y;
} Vector2D;

typedef struct Particle {
    double mass;
    Vector2D pos, vel, acc;
} Particle;

// Function prototypes
Vector2D addVector2D(Vector2D a, Vector2D b);
Vector2D subVector2D(Vector2D a, Vector2D b);
Vector2D mulVector2D(Vector2D a, double b);
Vector2D divVector2D(Vector2D a, double b);
double dotProductVector2D(Vector2D a, Vector2D b);

// Main function
int main() {
    // Wow! We're going to be simulating the motion of a bunch of particles!

    // Let's create a bunch of particles
    int nParticles = 100;
    Particle *particles = malloc(sizeof(Particle) * nParticles);

    // Now, let's randomly initialize the particles
    srand(time(NULL));
    for (int i = 0; i < nParticles; i++) {
        particles[i].mass = 1.0;
        particles[i].pos.x = rand() % 100;
        particles[i].pos.y = rand() % 100;
        particles[i].vel.x = 0.0;
        particles[i].vel.y = 0.0;
        particles[i].acc.x = 0.0;
        particles[i].acc.y = -g;
    }

    // Let's run the simulation for a bunch of time steps
    int nSteps = 1000;
    for (int i = 0; i < nSteps; i++) {
        // Let's calculate the acceleration of each particle
        for (int j = 0; j < nParticles; j++) {
            particles[j].acc.x = 0.0;
            particles[j].acc.y = -g;
        }

        // Let's update the velocity of each particle
        for (int j = 0; j < nParticles; j++) {
            particles[j].vel = addVector2D(particles[j].vel, mulVector2D(particles[j].acc, dt));
        }

        // Let's update the position of each particle
        for (int j = 0; j < nParticles; j++) {
            particles[j].pos = addVector2D(particles[j].pos, mulVector2D(particles[j].vel, dt));
        }
    }

    // Let's print out the final positions of the particles
    for (int i = 0; i < nParticles; i++) {
        printf("Particle %d: (%f, %f)\n", i, particles[i].pos.x, particles[i].pos.y);
    }

    // Let's clean up the memory we used
    free(particles);

    return 0;
}

// Function definitions
Vector2D addVector2D(Vector2D a, Vector2D b) {
    Vector2D result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector2D subVector2D(Vector2D a, Vector2D b) {
    Vector2D result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Vector2D mulVector2D(Vector2D a, double b) {
    Vector2D result;
    result.x = a.x * b;
    result.y = a.y * b;
    return result;
}

Vector2D divVector2D(Vector2D a, double b) {
    Vector2D result;
    result.x = a.x / b;
    result.y = a.y / b;
    return result;
}

double dotProductVector2D(Vector2D a, Vector2D b) {
    return a.x * b.x + a.y * b.y;
}