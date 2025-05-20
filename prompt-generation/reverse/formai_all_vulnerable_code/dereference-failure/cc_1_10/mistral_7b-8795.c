//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    double x;
    double y;
    double mass;
    char name[20];
} Planet;

double gravitational_force(double mass1, double mass2, double distance) {
    const double G = 6.67430e-11; // Gravitational constant
    return G * mass1 * mass2 / pow(distance, 2);
}

void calculate_forces(Planet planets[], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        Planet planet = planets[i];
        double total_force = 0;

        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                Planet other_planet = planets[j];
                double distance = sqrt(pow(planet.x - other_planet.x, 2) + pow(planet.y - other_planet.y, 2));
                double force = gravitational_force(planet.mass, other_planet.mass, distance);
                total_force += force * (other_planet.x - planet.x) / distance;
                total_force += force * (other_planet.y - planet.y) / distance;
            }
        }

        planet.x += total_force * 0.001;
        planet.y += total_force * 0.001;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s num_planets num_iterations\n", argv[0]);
        return 1;
    }

    int num_planets = atoi(argv[1]);
    int num_iterations = atoi(argv[2]);

    Planet *planets = malloc(num_planets * sizeof(Planet));

    for (int i = 0; i < num_planets; i++) {
        printf("Enter name and initial position for planet %d:\n", i + 1);
        scanf("%s %lf %lf", planets[i].name, &planets[i].x, &planets[i].y);
        planets[i].mass = 5.97e24; // Earth mass as an example
    }

    for (int step = 0; step < num_iterations; step++) {
        calculate_forces(planets, num_planets);
        printf("\nIteration %d:\n", step + 1);
        for (int i = 0; i < num_planets; i++) {
            printf("%s (x=%.2f, y=%.2f)\n", planets[i].name, planets[i].x, planets[i].y);
        }
    }

    free(planets);

    return 0;
}