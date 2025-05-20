//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.674e-11 // gravitational constant

typedef struct {
    double x, y, z; // position coordinates
    double vx, vy, vz; // velocity components
    double ax, ay, az; // acceleration components
    double mass; // mass of planet
} Planet;

void calculate_acceleration(Planet* p, Planet* planets, int num_planets)
{
    double dx, dy, dz, r, f, ax, ay, az;
    for(int i=0; i<num_planets; i++) {
        if(p == &planets[i]) continue; // skip self
        dx = planets[i].x - p->x;
        dy = planets[i].y - p->y;
        dz = planets[i].z - p->z;
        r = sqrt(dx*dx + dy*dy + dz*dz); // distance between planets
        f = G * p->mass * planets[i].mass / (r*r*r); // gravitational force
        ax = f * dx / p->mass;
        ay = f * dy / p->mass;
        az = f * dz / p->mass;
        p->ax += ax;
        p->ay += ay;
        p->az += az;
    }
}

void update_velocity_position(Planet* p, double dt)
{
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
    p->ax = p->ay = p->az = 0.0; // reset acceleration for next step
}

int main()
{
    double dt = 0.01; // time step
    int num_steps = 10000; // total number of steps
    int num_planets = 5;
    double max_distance = 1e10; // maximum initial distance from origin
    double max_velocity = 1e4; // maximum initial velocity
    Planet* planets = (Planet*)malloc(num_planets * sizeof(Planet));

    // initialize planets with random position, velocity, and mass
    for(int i=0; i<num_planets; i++) {
        planets[i].x = (double)rand()/RAND_MAX * max_distance - max_distance/2;
        planets[i].y = (double)rand()/RAND_MAX * max_distance - max_distance/2;
        planets[i].z = (double)rand()/RAND_MAX * max_distance - max_distance/2;
        planets[i].vx = (double)rand()/RAND_MAX * max_velocity - max_velocity/2;
        planets[i].vy = (double)rand()/RAND_MAX * max_velocity - max_velocity/2;
        planets[i].vz = (double)rand()/RAND_MAX * max_velocity - max_velocity/2;
        planets[i].mass = (double)rand()/RAND_MAX * 1e20;
    }

    // simulation loop
    for(int step=0; step<num_steps; step++) {
        // calculate acceleration for each planet
        for(int i=0; i<num_planets; i++) {
            calculate_acceleration(&planets[i], planets, num_planets);
        }
        // update velocity and position for each planet
        for(int i=0; i<num_planets; i++) {
            update_velocity_position(&planets[i], dt);
        }
        // output position of first planet every 100 steps
        if(step%100 == 0) {
            printf("%f %f %f\n", planets[0].x, planets[0].y, planets[0].z);
        }
    }

    free(planets);
    return 0;
}