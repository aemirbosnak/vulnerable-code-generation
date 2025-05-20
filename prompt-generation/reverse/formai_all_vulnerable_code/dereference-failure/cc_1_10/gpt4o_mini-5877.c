//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11    // Gravitational constant
#define DT 0.01          // Time step
#define NUM_PLANETS 5    // Number of planets
#define MAX_TIME 10      // Total simulation time

typedef struct {
    double mass;       // Mass of the planet (kg)
    double posX;      // X position (m)
    double posY;      // Y position (m)
    double velX;      // Velocity in X (m/s)
    double velY;      // Velocity in Y (m/s)
} Planet;

void initializePlanets(Planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].mass = (rand() % 100 + 1) * 1e24; // Random mass (1e24 to 1e26 kg)
        planets[i].posX = (rand() % 1000) * 1e3;    // Random position (0 to 1000 km)
        planets[i].posY = (rand() % 1000) * 1e3;    // Random position (0 to 1000 km)
        planets[i].velX = ((rand() % 200) - 100) * 1e3; // Random velocity (m/s)
        planets[i].velY = ((rand() % 200) - 100) * 1e3; // Random velocity (m/s)
    }
}

void calculateForces(Planet *planets, double *forceX, double *forceY) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        forceX[i] = 0.0;
        forceY[i] = 0.0;
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dx = planets[j].posX - planets[i].posX;
                double dy = planets[j].posY - planets[i].posY;
                double distance = sqrt(dx * dx + dy * dy);
                double force = (G * planets[i].mass * planets[j].mass) / (distance * distance);
                double angle = atan2(dy, dx);
                forceX[i] += force * cos(angle);
                forceY[i] += force * sin(angle);
            }
        }
    }
}

void updatePlanets(Planet *planets, double *forceX, double *forceY) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double accelerationX = forceX[i] / planets[i].mass;
        double accelerationY = forceY[i] / planets[i].mass;
        planets[i].velX += accelerationX * DT;
        planets[i].velY += accelerationY * DT;
        planets[i].posX += planets[i].velX * DT;
        planets[i].posY += planets[i].velY * DT;
    }
}

void printPlanets(Planet *planets, double time) {
    printf("Time: %.2f seconds\n", time);
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d - Mass: %.2e kg | Position: (%.2e, %.2e) m | Velocity: (%.2e, %.2e) m/s\n",
               i + 1, planets[i].mass, planets[i].posX, planets[i].posY, planets[i].velX, planets[i].velY);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Planet *planets = malloc(NUM_PLANETS * sizeof(Planet));
    double forceX[NUM_PLANETS], forceY[NUM_PLANETS];

    initializePlanets(planets);

    for (double t = 0; t < MAX_TIME; t += DT) {
        calculateForces(planets, forceX, forceY);
        updatePlanets(planets, forceX, forceY);
        printPlanets(planets, t);
        usleep(100000); // Sleep for visualization (0.1 seconds)
    }

    free(planets);
    return 0;
}