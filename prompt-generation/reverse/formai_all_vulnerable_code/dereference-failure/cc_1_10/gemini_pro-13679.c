//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

typedef struct {
    int num_planets;
    Planet *planets;
} SolarSystem;

SolarSystem *create_solar_system(int num_planets) {
    SolarSystem *solar_system = (SolarSystem *)malloc(sizeof(SolarSystem));
    solar_system->num_planets = num_planets;
    solar_system->planets = (Planet *)malloc(num_planets * sizeof(Planet));
    return solar_system;
}

void free_solar_system(SolarSystem *solar_system) {
    free(solar_system->planets);
    free(solar_system);
}

void initialize_planet(Planet *planet, double mass, double x, double y, double vx, double vy) {
    planet->mass = mass;
    planet->x = x;
    planet->y = y;
    planet->vx = vx;
    planet->vy = vy;
}

void simulate_step(SolarSystem *solar_system, double dt) {
    for (int i = 0; i < solar_system->num_planets; i++) {
        Planet *planet_i = &solar_system->planets[i];
        for (int j = i + 1; j < solar_system->num_planets; j++) {
            Planet *planet_j = &solar_system->planets[j];
            double dx = planet_i->x - planet_j->x;
            double dy = planet_i->y - planet_j->y;
            double r = sqrt(dx * dx + dy * dy);
            double force = (planet_i->mass * planet_j->mass) / (r * r);
            double theta = atan2(dy, dx);
            planet_i->vx -= force * cos(theta) * dt / planet_i->mass;
            planet_i->vy -= force * sin(theta) * dt / planet_i->mass;
            planet_j->vx += force * cos(theta) * dt / planet_j->mass;
            planet_j->vy += force * sin(theta) * dt / planet_j->mass;
        }
        planet_i->x += planet_i->vx * dt;
        planet_i->y += planet_i->vy * dt;
    }
}

int main() {
    int num_planets = 10;
    double dt = 0.01;
    int num_steps = 10000;
    SolarSystem *solar_system = create_solar_system(num_planets);
    for (int i = 0; i < num_planets; i++) {
        double mass = 1.0;
        double x = (i + 1) * 10.0;
        double y = (i + 1) * 10.0;
        double vx = 0.0;
        double vy = 0.0;
        initialize_planet(&solar_system->planets[i], mass, x, y, vx, vy);
    }
    for (int i = 0; i < num_steps; i++) {
        simulate_step(solar_system, dt);
    }
    for (int i = 0; i < num_planets; i++) {
        Planet planet = solar_system->planets[i];
        printf("Planet %d: (%.2f, %.2f)\n", i, planet.x, planet.y);
    }
    free_solar_system(solar_system);
    return 0;
}