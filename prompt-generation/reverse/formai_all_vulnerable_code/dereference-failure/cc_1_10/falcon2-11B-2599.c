//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

typedef struct {
    float mass;
    float radius;
    float distance;
} planet;

typedef struct {
    planet* planets;
    int num_planets;
    float time;
} solar_system;

void print_planets(solar_system* ss) {
    int i;
    printf("Planet\tMass\tRadius\tDistance\n");
    for (i = 0; i < ss->num_planets; i++) {
        printf("%5.1f\t%5.2f\t%5.2f\t%5.2f\n",
            ss->planets[i].mass, ss->planets[i].radius,
            ss->planets[i].distance, ss->time);
    }
}

int main(int argc, char** argv) {
    solar_system ss;
    int i, j;
    float radius_earth = 6371.0;
    float radius_sun = 696300.0;
    float radius_jupiter = 69911.0;
    float time_earth = 365.25;
    float time_jupiter = 4332.80;
    float distance_earth = 1.0;
    float distance_jupiter = 778.0;
    float distance_sun = 1.0;
    float angle = 0.0;
    int num_planets = 3;

    // Initialize the solar system
    ss.num_planets = num_planets;
    ss.time = 0.0;

    // Add the planets
    for (i = 0; i < num_planets; i++) {
        planet p;
        p.mass = 5.97e24;
        p.radius = 6.95e8;
        p.distance = distance_earth;
        ss.planets[i] = p;
        distance_earth += distance_jupiter;
    }

    // Add the sun
    planet p;
    p.mass = 1.989e30;
    p.radius = radius_sun;
    p.distance = distance_sun;
    ss.planets[num_planets] = p;

    // Print the planets
    print_planets(&ss);

    // Simulate the motion of the planets
    while (ss.time < 365.25) {
        for (i = 0; i < num_planets; i++) {
            for (j = 0; j < num_planets; j++) {
                if (i!= j) {
                    float r = sqrt(pow(ss.planets[i].distance - ss.planets[j].distance, 2) +
                        pow(ss.planets[i].distance * ss.planets[j].distance / ss.planets[i].radius / ss.planets[j].radius, 2));
                    float f = ss.planets[i].mass * ss.planets[j].mass / (r * r);
                    ss.planets[i].distance += f * ss.planets[i].radius / r;
                    ss.planets[j].distance -= f * ss.planets[j].radius / r;
                }
            }
        }
        ss.time += time_earth;
    }

    // Print the final positions
    print_planets(&ss);

    return 0;
}