//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct Planet {
    char name[20];
    double mass;
    double distance;
    double orbitalSpeed;
    double revolutionSpeed;
    double eccentricity;
    struct Planet* next;
} Planet;

Planet* createPlanet(char* name, double mass, double distance, double orbitalSpeed, double revolutionSpeed, double eccentricity) {
    Planet* newPlanet = malloc(sizeof(Planet));
    strcpy(newPlanet->name, name);
    newPlanet->mass = mass;
    newPlanet->distance = distance;
    newPlanet->orbitalSpeed = orbitalSpeed;
    newPlanet->revolutionSpeed = revolutionSpeed;
    newPlanet->eccentricity = eccentricity;
    newPlanet->next = NULL;

    return newPlanet;
}

void simulateSolarSystem(Planet* planets) {
    double time = 0.0;
    while (time < 1000.0) {
        for (Planet* planet = planets; planet; planet = planet->next) {
            double x = planet->distance * sin(planet->revolutionSpeed * time) * (1.0 - planet->eccentricity);
            double y = planet->distance * cos(planet->revolutionSpeed * time) * (1.0 - planet->eccentricity);

            printf("%s: (x, y) = (%f, %f)\n", planet->name, x, y);
        }

        time += 0.1;
    }
}

int main() {
    Planet* planets = createPlanet("Sun", 1.0, 0.0, 0.0, 0.0, 0.0);
    planets = createPlanet("Mercury", 0.05, 5.8e10, 30.0, 0.24, 0.2);
    planets = createPlanet("Venus", 0.81, 6.2e10, 24.0, 0.0, 0.0);
    planets = createPlanet("Earth", 0.05, 9.3e10, 16.0, 0.0, 0.0);
    planets = createPlanet("Mars", 0.04, 2.2e11, 13.0, 0.0, 0.0);
    planets = createPlanet("Jupiter", 5.9e24, 5.2e11, 9.0, 0.0, 0.0);
    planets = createPlanet("Saturn", 5.3e24, 8.8e11, 6.0, 0.0, 0.0);
    planets = createPlanet("Uranus", 1.0e24, 1.7e12, 4.0, 0.0, 0.0);
    planets = createPlanet("Neptune", 1.0e24, 2.3e12, 3.0, 0.0, 0.0);

    simulateSolarSystem(planets);

    return 0;
}