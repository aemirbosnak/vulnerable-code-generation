//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define TIME_STEP 10 // time step in seconds

typedef struct {
    double mass; // mass of the planet
    double radius; // radius of the planet
    double x; // x position of the planet
    double y; // y position of the planet
    double vx; // x velocity of the planet
    double vy; // y velocity of the planet
} planet_t;

void update_planet(planet_t *planet, planet_t *other_planets, int num_planets)
{
    double ax = 0.0, ay = 0.0; // acceleration in x and y direction
    for (int i = 0; i < num_planets; i++) {
        if (&other_planets[i] == planet) {
            continue; // skip the current planet
        }
        double dx = other_planets[i].x - planet->x; // distance in x direction
        double dy = other_planets[i].y - planet->y; // distance in y direction
        double distance = sqrt(dx*dx + dy*dy); // distance between the planets
        double force = G * planet->mass * other_planets[i].mass / (distance * distance); // gravitational force between the planets
        ax += force * dx / distance / planet->mass; // acceleration in x direction
        ay += force * dy / distance / planet->mass; // acceleration in y direction
    }
    planet->vx += ax * TIME_STEP; // update velocity in x direction
    planet->vy += ay * TIME_STEP; // update velocity in y direction
    planet->x += planet->vx * TIME_STEP; // update position in x direction
    planet->y += planet->vy * TIME_STEP; // update position in y direction
}

int main()
{
    int num_planets = 2;
    planet_t *planets = malloc(sizeof(planet_t) * num_planets);
    planets[0].mass = 5.97e24; // earth mass
    planets[0].radius = 6.371e6; // earth radius
    planets[0].x = 0.0; // x position of earth
    planets[0].y = 0.0; // y position of earth
    planets[0].vx = 0.0; // x velocity of earth
    planets[0].vy = 0.0; // y velocity of earth
    planets[1].mass = 7.34e22; // moon mass
    planets[1].radius = 1.737e6; // moon radius
    planets[1].x = 3.84e8; // x position of moon
    planets[1].y = 0.0; // y position of moon
    planets[1].vx = 0.0; // x velocity of moon
    planets[1].vy = 1022.0; // y velocity of moon
    
    int num_steps = 365 * 24 * 3600 / TIME_STEP; // simulate for 1 year
    for (int i = 0; i < num_steps; i++) {
        update_planet(&planets[0], planets, num_planets);
        update_planet(&planets[1], planets, num_planets);
    }
    
    printf("Earth: x=%f, y=%f, vx=%f, vy=%f\n", planets[0].x, planets[0].y, planets[0].vx, planets[0].vy);
    printf("Moon: x=%f, y=%f, vx=%f, vy=%f\n", planets[1].x, planets[1].y, planets[1].vx, planets[1].vy);
    
    free(planets);
    return 0;
}