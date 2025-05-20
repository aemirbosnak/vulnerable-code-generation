//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 8
#define GRAV_CONST 6.67408e-11
#define YEAR 31536000 // seconds in one earth year

typedef struct {
    char name[20];
    double mass; // kg
    double radius; // m
    double x; // position x coord
    double y; // position y coord
    double vx; // velocity x coord
    double vy; // velocity y coord
} planet;

void init_planets(planet planets[]) {
    sprintf(planets[0].name, "Sun");
    planets[0].mass = 1.989e30;
    planets[0].radius = 695700000;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;

    sprintf(planets[1].name, "Mercury");
    planets[1].mass = 3.285e23;
    planets[1].radius = 2440000;
    planets[1].x = 57910000000;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 47360;

    sprintf(planets[2].name, "Venus");
    planets[2].mass = 4.87e24;
    planets[2].radius = 6052000;
    planets[2].x = 108200000000;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 35020;

    sprintf(planets[3].name, "Earth");
    planets[3].mass = 5.972e24;
    planets[3].radius = 6371000;
    planets[3].x = 149600000000;
    planets[3].y = 0;
    planets[3].vx = 0;
    planets[3].vy = 29783;

    sprintf(planets[4].name, "Mars");
    planets[4].mass = 6.39e23;
    planets[4].radius = 3390000;
    planets[4].x = 227940000000;
    planets[4].y = 0;
    planets[4].vx = 0;
    planets[4].vy = 24080;

    sprintf(planets[5].name, "Jupiter");
    planets[5].mass = 1.898e27;
    planets[5].radius = 69911000;
    planets[5].x = 778330000000;
    planets[5].y = 0;
    planets[5].vx = 0;
    planets[5].vy = 13070;

    sprintf(planets[6].name, "Saturn");
    planets[6].mass = 5.683e26;
    planets[6].radius = 58232000;
    planets[6].x = 1429400000000;
    planets[6].y = 0;
    planets[6].vx = 0;
    planets[6].vy = 9690;

    sprintf(planets[7].name, "Uranus");
    planets[7].mass = 8.681e25;
    planets[7].radius = 25362000;
    planets[7].x = 2870990000000;
    planets[7].y = 0;
    planets[7].vx = 0;
    planets[7].vy = 6810;

    sprintf(planets[8].name, "Neptune");
    planets[8].mass = 1.024e26;
    planets[8].radius = 24622000;
    planets[8].x = 4504300000000;
    planets[8].y = 0;
    planets[8].vx = 0;
    planets[8].vy = 5430;
}

void calculate_gravity(planet planets[]) {
    int i, j;
    double dx, dy, r, f;

    for (i = 0; i < NUM_PLANETS; i++) {
        for (j = i + 1; j < NUM_PLANETS; j++) {
            dx = planets[j].x - planets[i].x;
            dy = planets[j].y - planets[i].y;
            r = sqrt(dx*dx + dy*dy);
            f = GRAV_CONST * planets[i].mass * planets[j].mass / (r*r);

            planets[i].vx += f / planets[i].mass * dx / r;
            planets[i].vy += f / planets[i].mass * dy / r;
            planets[j].vx -= f / planets[j].mass * dx / r;
            planets[j].vy -= f / planets[j].mass * dy / r;
        }
    }
}

void update_positions(planet planets[], double dt) {
    int i;

    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

void simulate_solar_system(planet planets[], double duration, double dt) {
    double t = 0;

    while (t < duration) {
        calculate_gravity(planets);
        update_positions(planets, dt);
        t += dt;
    }
}

void print_planets(planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("%s - x: %lf m, y: %lf m, vx: %lf m/s, vy: %lf m/s\n", planets[i].name, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }
}

int main() {
    planet planets[NUM_PLANETS];
    double duration = 1 * YEAR;
    double dt = 3600;

    init_planets(planets);
    simulate_solar_system(planets, duration, dt);
    print_planets(planets);

    return 0;
}