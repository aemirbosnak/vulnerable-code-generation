//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_MASS 5.972e24
#define EARTH_RADIUS 6371
#define JUPITER_MASS 1.8986e27
#define JUPITER_RADIUS 69911
#define EARTH_YEAR 31557600
#define JUPITER_YEAR 4332

typedef struct planet {
    double mass;
    double radius;
    double period;
    int id;
} Planet;

void initPlanets(Planet* planets, int num) {
    for (int i = 0; i < num; i++) {
        planets[i].mass = 0.0;
        planets[i].radius = 0.0;
        planets[i].period = 0.0;
        planets[i].id = 0;
    }
}

void addPlanet(Planet* planets, int id, double mass, double radius, double period) {
    planets[id].mass = mass;
    planets[id].radius = radius;
    planets[id].period = period;
    planets[id].id = id;
}

double distance(Planet* p1, Planet* p2) {
    return sqrt(pow(p1->radius - p2->radius, 2) + pow(p1->mass / p1->radius - p2->mass / p2->radius, 2));
}

double timeStep(Planet* planets, int num) {
    double deltaTime = 0.0;
    for (int i = 0; i < num; i++) {
        double newPeriod = planets[i].period / 2;
        double newMass = planets[i].mass / 2;
        planets[i].radius += (newPeriod - planets[i].period) * planets[i].radius;
        planets[i].mass *= 2;
        planets[i].period = newPeriod;
        deltaTime += distance(planets, &planets[i]);
    }
    return deltaTime;
}

int main() {
    Planet earth = {EARTH_MASS, EARTH_RADIUS, EARTH_YEAR, 0};
    Planet jupiter = {JUPITER_MASS, JUPITER_RADIUS, JUPITER_YEAR, 1};
    Planet* planets = (Planet*)malloc(2 * sizeof(Planet));
    initPlanets(planets, 2);
    addPlanet(planets, 0, earth.mass, earth.radius, earth.period);
    addPlanet(planets, 1, jupiter.mass, jupiter.radius, jupiter.period);

    double totalDistance = 0.0;
    for (int i = 0; i < 1000; i++) {
        totalDistance += timeStep(planets, 2);
        printf("Time step %d: Total distance traveled = %.2f\n", i, totalDistance);
        fflush(stdout);
    }

    free(planets);
    return 0;
}