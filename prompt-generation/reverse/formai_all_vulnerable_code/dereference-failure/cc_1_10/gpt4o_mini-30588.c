//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11 // Universal gravitational constant
#define TIME_STEP 0.1 // Time step for simulation
#define WIDTH 80 // Width of the simulation space
#define HEIGHT 20 // Height of the simulation space

typedef struct {
    double x;
    double y;
    double mass;
    double vx; // Velocity in x
    double vy; // Velocity in y
} Body;

void update_position(Body *body) {
    body->x += body->vx * TIME_STEP;
    body->y += body->vy * TIME_STEP;
}

void apply_gravity(Body *b1, Body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double distance_squared = dx * dx + dy * dy;

    if (distance_squared > 0) {
        double force = G * b1->mass * b2->mass / distance_squared;
        double fx = force * (dx / sqrt(distance_squared));
        double fy = force * (dy / sqrt(distance_squared));
        
        b1->vx += fx / b1->mass * TIME_STEP;
        b1->vy += fy / b1->mass * TIME_STEP;
        b2->vx -= fx / b2->mass * TIME_STEP;
        b2->vy -= fy / b2->mass * TIME_STEP;
    }
}

void print_space(Body *bodies, int num_bodies) {
    char space[HEIGHT][WIDTH];
    // Clear space
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            space[i][j] = ' ';
        }
    }

    // Draw bodies
    for (int i = 0; i < num_bodies; i++) {
        int x = (int)(bodies[i].x / WIDTH);
        int y = (int)(bodies[i].y / HEIGHT);
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            space[y][x] = 'O'; // Represent body with 'O'
        }
    }

    // Print space
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(space[i][j]);
        }
        putchar('\n');
    }
}

void simulate(Body *bodies, int num_bodies, int steps) {
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < num_bodies; i++) {
            for (int j = i + 1; j < num_bodies; j++) {
                apply_gravity(&bodies[i], &bodies[j]);
            }
        }

        for (int i = 0; i < num_bodies; i++) {
            update_position(&bodies[i]);
        }

        system("clear"); // Clear the terminal for a fresh view
        print_space(bodies, num_bodies);
        usleep(100000); // Sleep for 100ms to slow down the simulation
    }
}

int main() {
    int num_bodies = 3;
    Body *bodies = malloc(num_bodies * sizeof(Body));

    // Initialize some bodies with random positions and masses
    bodies[0] = (Body){40.0, 10.0, 5.0e24, 0.0, 0.0}; // Body 1 (Planet)
    bodies[1] = (Body){20.0, 5.0, 7.0e23, 0.0, 3.0};  // Body 2 (Moon)
    bodies[2] = (Body){10.0, 15.0, 1.0e22, 0.0, -2.0}; // Body 3 (Asteroid)

    // Start the simulation for 100 steps!
    simulate(bodies, num_bodies, 100);

    free(bodies);
    return 0;
}