//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11 // Gravitational constant
#define DT 0.01       // Time step for simulation

typedef struct {
    double x, y;     // Position
    double vx, vy;   // Velocity
    double mass;     // Mass
} Planet;

void updatePosition(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void updateVelocity(Planet *p1, Planet *p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx * dx + dy * dy);
    if (distance == 0) return; // Avoid division by zero

    double force = (G * p1->mass * p2->mass) / (distance * distance);
    double ax = force / p1->mass * (dx / distance);
    double ay = force / p1->mass * (dy / distance);

    p1->vx += ax * dt;
    p1->vy += ay * dt;
}

void simulate(Planet *planets, int numPlanets, double duration) {
    int steps = (int)(duration / DT);
    for (int step = 0; step < steps; step++) {
        // Update velocities based on gravitational forces
        for (int i = 0; i < numPlanets; i++) {
            for (int j = 0; j < numPlanets; j++) {
                if (i != j) {
                    updateVelocity(&planets[i], &planets[j], DT);
                }
            }
        }

        // Update positions
        for (int i = 0; i < numPlanets; i++) {
            updatePosition(&planets[i], DT);
        }

        // Output the positions of planets
        printf("Time: %.2fs\n", step * DT);
        for (int i = 0; i < numPlanets; i++) {
            printf("Planet %d: Position(%.2f, %.2f), Velocity(%.2f, %.2f)\n", 
                    i, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
        }
        printf("\n");

        // Slow down the output for observation
        usleep(100000); // Sleep for 0.1 seconds
    }
}

int main() {
    int numPlanets = 3;
    Planet *planets = (Planet *)malloc(numPlanets * sizeof(Planet));

    // Initialize planets
    planets[0] = (Planet){0.0, 0.0, 0.0, 0.0, 5.972e24}; // Earth-like planet
    planets[1] = (Planet){1.0e11, 0.0, 0.0, 29780.0, 6.39e23}; // Mars-like planet
    planets[2] = (Planet){0.0, 1.0e11, -29780.0, 0.0, 7.35e22}; // Moon-like planet

    double simulationDuration = 100.0; // Total time for simulation in seconds

    printf("Starting gravitational simulation...\n\n");
    simulate(planets, numPlanets, simulationDuration);

    free(planets);
    return 0;
}