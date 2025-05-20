//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

struct planet {
    char name[10];
    double mass; // in kg
    double radius; // in m
    double distance; // in m
    double period; // in days
    double angle; // in radians
    double x; // x-coordinate
    double y; // y-coordinate
    double xv; // x-velocity
    double yv; // y-velocity
};

typedef struct planet planet_t;

void calculate_angle(planet_t *p) {
    p->angle += 2 * PI / (p->period * 86400); // convert period from days to seconds
}

void calculate_position(planet_t *p, double time_step) {
    p->x = p->distance * cos(p->angle);
    p->y = p->distance * sin(p->angle);
    p->xv = -p->distance * sin(p->angle) / p->period * 2 * PI;
    p->yv = p->distance * cos(p->angle) / p->period * 2 * PI;
    p->angle += time_step * 2 * PI / (p->period * 86400);
}

void initialize_planets(planet_t *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("Enter planet %d name, mass (kg), radius (m), distance (m), period (days): ", i + 1);
        scanf("%s %lf %lf %lf %lf", planets[i].name, &planets[i].mass, &planets[i].radius, &planets[i].distance, &planets[i].period);
        planets[i].angle = 0;
        calculate_position(&planets[i], 0);
    }
}

void simulate_planets(planet_t *planets, int num_planets, double duration, double time_step) {
    for (double t = 0; t <= duration; t += time_step) {
        for (int i = 0; i < num_planets; i++) {
            calculate_position(&planets[i], time_step);
        }
    }
}

void print_planets(planet_t *planets, int num_planets) {
    printf("\nName\tMass\tRadius\tDistance\tPeriod\tX\tY\tXV\tYV\n");
    for (int i = 0; i < num_planets; i++) {
        printf("%s\t%g\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n", planets[i].name, planets[i].mass, planets[i].radius, planets[i].distance, planets[i].period, planets[i].x, planets[i].y, planets[i].xv, planets[i].yv);
    }
}

int main() {
    int num_planets;
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    planet_t *planets = malloc(num_planets * sizeof(planet_t));

    initialize_planets(planets, num_planets);

    simulate_planets(planets, num_planets, 365, 0.01);

    print_planets(planets, num_planets);

    free(planets);

    return 0;
}