//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {
    double x, y, z, mass, name[20];
} Planet;

void gravity(Planet* p1, Planet* p2) {
    double g = 6.67430e-11;
    double distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
    double force = g * p1->mass * p2->mass / pow(distance, 2);

    p1->x -= force * (p2->x - p1->x) / distance;
    p1->y -= force * (p2->y - p1->y) / distance;
    p1->z -= force * (p2->z - p1->z) / distance;

    p2->x -= force * (p1->x - p2->x) / distance;
    p2->y -= force * (p1->y - p2->y) / distance;
    p2->z -= force * (p1->z - p2->z) / distance;
}

int main() {
    srand(time(NULL));

    int numPlanets = 5;
    Planet* planets = (Planet*) malloc(numPlanets * sizeof(Planet));

    for (int i = 0; i < numPlanets; i++) {
        planets[i].mass = (rand() % 10000 + 5000) / 1000.0;
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 1000;
        planets[i].z = rand() % 1000;

        sprintf(planets[i].name, "Planet %d", i + 1);
    }

    double timeStep = 0.0001;
    double time = 0;

    while (time < 10) {
        for (int i = 0; i < numPlanets; i++) {
            for (int j = i + 1; j < numPlanets; j++) {
                gravity(&planets[i], &planets[j]);
            }
        }

        time += timeStep;

        for (int i = 0; i < numPlanets; i++) {
            printf("%s (%lf, %lf, %lf) %lf\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z, planets[i].mass);
        }

        printf("\n");
        system("clear");
        fflush(stdout);
        sleep(0.01);
    }

    free(planets);

    return 0;
}