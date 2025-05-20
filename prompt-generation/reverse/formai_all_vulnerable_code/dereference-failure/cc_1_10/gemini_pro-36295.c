//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    double x, y;
} Vec2;

typedef struct {
    Vec2 pos;
    Vec2 vel;
    double mass;
    double radius;
} Body;

typedef struct {
    int nbodies;
    Body *bodies;
} Galaxy;

// Gravitational constant
#define G 6.67408e-11

// Time step
#define DT 0.01

// Create a new galaxy with nbodies bodies
Galaxy *create_galaxy(int nbodies) {
    Galaxy *galaxy = malloc(sizeof(Galaxy));
    galaxy->nbodies = nbodies;
    galaxy->bodies = malloc(sizeof(Body) * nbodies);

    // Initialize the bodies
    for (int i = 0; i < nbodies; i++) {
        galaxy->bodies[i].pos.x = (rand() / (double)RAND_MAX) * WIDTH;
        galaxy->bodies[i].pos.y = (rand() / (double)RAND_MAX) * HEIGHT;
        galaxy->bodies[i].vel.x = (rand() / (double)RAND_MAX) * 100;
        galaxy->bodies[i].vel.y = (rand() / (double)RAND_MAX) * 100;
        galaxy->bodies[i].mass = (rand() / (double)RAND_MAX) * 1000;
        galaxy->bodies[i].radius = sqrt(galaxy->bodies[i].mass / (4 / 3 * M_PI * 1000));
    }

    return galaxy;
}

// Update the positions and velocities of the bodies in the galaxy
void update_galaxy(Galaxy *galaxy) {
    // Calculate the forces on each body
    for (int i = 0; i < galaxy->nbodies; i++) {
        Vec2 force = {0, 0};
        for (int j = 0; j < galaxy->nbodies; j++) {
            if (i == j) continue;

            // Calculate the distance between the bodies
            Vec2 r = {galaxy->bodies[j].pos.x - galaxy->bodies[i].pos.x, galaxy->bodies[j].pos.y - galaxy->bodies[i].pos.y};
            double r_mag = sqrt(r.x * r.x + r.y * r.y);

            // Calculate the force between the bodies
            double f = G * galaxy->bodies[i].mass * galaxy->bodies[j].mass / (r_mag * r_mag);
            force.x += f * r.x / r_mag;
            force.y += f * r.y / r_mag;
        }

        // Update the velocity of the body
        galaxy->bodies[i].vel.x += force.x / galaxy->bodies[i].mass * DT;
        galaxy->bodies[i].vel.y += force.y / galaxy->bodies[i].mass * DT;

        // Update the position of the body
        galaxy->bodies[i].pos.x += galaxy->bodies[i].vel.x * DT;
        galaxy->bodies[i].pos.y += galaxy->bodies[i].vel.y * DT;
    }
}

// Draw the galaxy to the screen
void draw_galaxy(Galaxy *galaxy) {
    // Clear the screen
    system("clear");

    // Draw the bodies
    for (int i = 0; i < galaxy->nbodies; i++) {
        // Calculate the screen coordinates of the body
        int x = (int)galaxy->bodies[i].pos.x;
        int y = (int)galaxy->bodies[i].pos.y;

        // Draw the body
        printf("\033[%d;%dH○", y, x);
    }
}

// Free the memory allocated for the galaxy
void destroy_galaxy(Galaxy *galaxy) {
    free(galaxy->bodies);
    free(galaxy);
}

int main() {
    // Create a new galaxy with 100 bodies
    Galaxy *galaxy = create_galaxy(100);

    // Update the galaxy for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        update_galaxy(galaxy);
        draw_galaxy(galaxy);
    }

    // Destroy the galaxy
    destroy_galaxy(galaxy);

    return 0;
}