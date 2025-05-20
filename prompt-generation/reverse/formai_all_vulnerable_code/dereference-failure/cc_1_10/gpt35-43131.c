//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    double mass;
} Planet;

int main(void) {
    // Medieval-style planet names
    char *planetNames[] = {"Asgard", "Camelot", "Dragonscar", "Eldorado", "Frosthold",
                           "Goblinville", "Hyrule", "Isengard", "Jotunheim", "Knightsbridge"};
    
    // Set up the universe
    const int numPlanets = 10;
    Planet *planets = malloc(numPlanets * sizeof(Planet));
    for (int i = 0; i < numPlanets; i++) {
        // Randomly generate planet positions and velocities within a range
        planets[i].position.x = (double)rand() / RAND_MAX * 1000.0 - 500.0;
        planets[i].position.y = (double)rand() / RAND_MAX * 1000.0 - 500.0;
        planets[i].position.z = (double)rand() / RAND_MAX * 1000.0 - 500.0;
        planets[i].velocity.x = (double)rand() / RAND_MAX * 10.0 - 5.0;
        planets[i].velocity.y = (double)rand() / RAND_MAX * 10.0 - 5.0;
        planets[i].velocity.z = (double)rand() / RAND_MAX * 10.0 - 5.0;
        // Set random planet masses
        planets[i].mass = (double)rand() / RAND_MAX * 100.0 + 10.0;
    }
    
    // Simulate the universe for a certain number of time steps
    const int numTimeSteps = 1000;
    const double deltaTime = 1.0; // Time step size
    for (int t = 0; t < numTimeSteps; t++) {
        // Calculate acceleration for each planet based on gravitational forces from all other planets
        for (int i = 0; i < numPlanets; i++) {
            planets[i].acceleration.x = 0.0;
            planets[i].acceleration.y = 0.0;
            planets[i].acceleration.z = 0.0;
            for (int j = 0; j < numPlanets; j++) {
                if (i != j) {
                    Vector3 r;
                    r.x = planets[j].position.x - planets[i].position.x;
                    r.y = planets[j].position.y - planets[i].position.y;
                    r.z = planets[j].position.z - planets[i].position.z;
                    double distance = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
                    double force = G * planets[i].mass * planets[j].mass / (distance*distance);
                    Vector3 F;
                    F.x = force * r.x / distance;
                    F.y = force * r.y / distance;
                    F.z = force * r.z / distance;
                    planets[i].acceleration.x += F.x / planets[i].mass;
                    planets[i].acceleration.y += F.y / planets[i].mass;
                    planets[i].acceleration.z += F.z / planets[i].mass;
                }
            }
        }
        
        // Update planet positions and velocities based on acceleration
        for (int i = 0; i < numPlanets; i++) {
            planets[i].position.x += planets[i].velocity.x * deltaTime + 0.5 * planets[i].acceleration.x * deltaTime * deltaTime;
            planets[i].position.y += planets[i].velocity.y * deltaTime + 0.5 * planets[i].acceleration.y * deltaTime * deltaTime;
            planets[i].position.z += planets[i].velocity.z * deltaTime + 0.5 * planets[i].acceleration.z * deltaTime * deltaTime;
            planets[i].velocity.x += planets[i].acceleration.x * deltaTime;
            planets[i].velocity.y += planets[i].acceleration.y * deltaTime;
            planets[i].velocity.z += planets[i].acceleration.z * deltaTime;
        }
        
        // Print out planet positions for this time step
        printf("Time step %d\n", t+1);
        for (int i = 0; i < numPlanets; i++) {
            printf("%-10s : %8.2f %8.2f %8.2f\n", planetNames[i], planets[i].position.x, planets[i].position.y, planets[i].position.z);
        }
        printf("------------------------------------------------------------\n");
    }
    
    free(planets);
    return 0;
}