//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11 // Gravitational constant
#define TIMESTEP 0.01 // Time step for simulation

typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double mass; // Mass of the object
} Body;

void update_position(Body *body) {
    body->x += body->vx * TIMESTEP;
    body->y += body->vy * TIMESTEP;
}

void update_velocity(Body *body, double ax, double ay) {
    body->vx += ax * TIMESTEP;
    body->vy += ay * TIMESTEP;
}

double calculate_gravitational_force(Body *body1, Body *body2) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double distance = sqrt(dx * dx + dy * dy);
    if (distance == 0) return 0; // Prevent division by zero

    double force = (G * body1->mass * body2->mass) / (distance * distance);
    return force;
}

void compute_acceleration(Body *body, Body *other) {
    double fx = 0, fy = 0;
    
    double force = calculate_gravitational_force(body, other);
    
    if (force > 0) {
        double dx = other->x - body->x;
        double dy = other->y - body->y;
        double distance = sqrt(dx * dx + dy * dy);
        
        fx = (force * dx) / (body->mass * distance);
        fy = (force * dy) / (body->mass * distance);
    }

    update_velocity(body, fx, fy);
}

void print_state(Body *bodies, int count) {
    for (int i = 0; i < count; i++) {
        printf("Body %d: Position (%.2f, %.2f) Velocity (%.2f, %.2f)\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
    printf("\n");
}

int main() {
    // Initialize bodies
    int num_bodies = 2;
    Body *bodies = malloc(num_bodies * sizeof(Body));

    // Setting up two bodies: a planet and a satellite
    bodies[0] = (Body) {0, 0, 0, 0, 5.972e24}; // Earth
    bodies[1] = (Body) {0, 6371000 + 400000, 1000, 0, 737.1e3}; // Satellite

    // Main simulation loop
    for (int t = 0; t < 1000; t++) { // Run for a period of time
        for(int i = 0; i < num_bodies; i++) {
            for(int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    compute_acceleration(&bodies[i], &bodies[j]);
                }
            }
        }

        for (int i = 0; i < num_bodies; i++) {
            update_position(&bodies[i]);
        }

        print_state(bodies, num_bodies);
        usleep(100000); // Sleep for 0.1 seconds for better visualization
    }

    free(bodies); // Free dynamically allocated memory
    return 0;
}