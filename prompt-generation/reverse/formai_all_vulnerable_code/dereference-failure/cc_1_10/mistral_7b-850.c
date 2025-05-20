//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 10
#define MAX_ITERATIONS 10000

typedef struct {
    double x, y, vx, vy, mass;
} planet;

void initializePlanets(planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = (double) rand() / RAND_MAX * 1000;
        planets[i].y = (double) rand() / RAND_MAX * 1000;
        planets[i].vx = (double) rand() / RAND_MAX * 2.0 - 1.0;
        planets[i].vy = (double) rand() / RAND_MAX * 2.0 - 1.0;
        planets[i].mass = (double) rand() / RAND_MAX * 10 + 5;
    }
}

void printPlanets(planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (%.2f, %.2f), vx = %.2f, vy = %.2f, mass = %.2f\n", i + 1, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy, planets[i].mass);
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void gravityForce(planet *planet1, planet *planet2, double *fx, double *fy) {
    double d = distance(planet1->x, planet1->y, planet2->x, planet2->y);
    double g = 6.6743e-11; // gravitational constant

    *fx = (planet2->mass * (planet1->x - planet2->x) / pow(d, 2));
    *fy = (planet2->mass * (planet1->y - planet2->y) / pow(d, 2));
}

void updatePlanetVelocities(planet *planets, int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        double sumFx = 0.0, sumFy = 0.0;
        for (int j = 0; j < numPlanets; j++) {
            if (i != j) {
                double fx, fy;
                gravityForce(&planets[i], &planets[j], &fx, &fy);
                sumFx += fx;
                sumFy += fy;
            }
        }
        planets[i].vx += sumFx * 0.01;
        planets[i].vy += sumFy * 0.01;
    }
}

int main() {
    srand(time(NULL));

    planet *planets = malloc(NUM_PLANETS * sizeof(planet));

    initializePlanets(planets);
    printPlanets(planets);

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        updatePlanetVelocities(planets, NUM_PLANETS);
    }

    printPlanets(planets);

    free(planets);

    return 0;
}