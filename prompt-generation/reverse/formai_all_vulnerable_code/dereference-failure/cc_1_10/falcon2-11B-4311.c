//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 6.67408e-11

void print_gravity_simulation(int num_planets, double *planet_mass, double *planet_radius, double *planet_position, double *planet_velocity, double dt, double time) {
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d - Mass: %f, Radius: %f, Position: %f, Velocity: %f\n", i, planet_mass[i], planet_radius[i], planet_position[i], planet_velocity[i]);
    }
    printf("Time: %f\n", time);
}

int main() {
    int num_planets = 3;
    double *planet_mass = (double*)malloc(num_planets * sizeof(double));
    double *planet_radius = (double*)malloc(num_planets * sizeof(double));
    double *planet_position = (double*)malloc(num_planets * sizeof(double));
    double *planet_velocity = (double*)malloc(num_planets * sizeof(double));
    
    planet_mass[0] = 5.97e24;
    planet_radius[0] = 6.371e6;
    planet_position[0] = 7.348e9;
    planet_velocity[0] = 29.78;
    
    planet_mass[1] = 5.972e24;
    planet_radius[1] = 6.378e6;
    planet_position[1] = 7.342e9;
    planet_velocity[1] = 29.78;
    
    planet_mass[2] = 5.972e24;
    planet_radius[2] = 6.378e6;
    planet_position[2] = 7.342e9;
    planet_velocity[2] = 29.78;
    
    double dt = 0.0001;
    double time = 0.0;
    
    while (time <= 10000.0) {
        for (int i = 0; i < num_planets; i++) {
            planet_position[i] += planet_velocity[i] * dt;
            planet_velocity[i] += -GRAVITY * planet_mass[i] / (planet_radius[i] * planet_radius[i]) * (planet_position[i] - planet_position[i]);
        }
        time += dt;
        print_gravity_simulation(num_planets, planet_mass, planet_radius, planet_position, planet_velocity, dt, time);
    }
    
    free(planet_mass);
    free(planet_radius);
    free(planet_position);
    free(planet_velocity);
    
    return 0;
}