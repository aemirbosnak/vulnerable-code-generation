//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of planets
#define NUM_PLANETS 4

// Define constants
#define G_CONST 6.674e-11

// Define planet struct
typedef struct {
    char* name;
    double mass; // in kg
    double radius; // in m
    double x; // x position in m
    double y; // y position in m
    double vx; // x velocity in m/s
    double vy; // y velocity in m/s
} Planet;

// Function prototypes
double calc_distance(double x1, double y1, double x2, double y2);
double calc_force(double m1, double m2, double d);
double calc_acceleration(double f, double m);
void update_position(Planet* p, double delta_t);
void update_velocity(Planet* p, double ax, double ay, double delta_t);
void print_planets(Planet* p_arr, int size);
void simulate(Planet* p_arr, int size, double delta_t, int num_steps);

int main() {
    // Allocate memory for array of planets
    Planet* planets = (Planet*) malloc(sizeof(Planet) * NUM_PLANETS);
    
    // Initialize planets with name, mass, radius, position, and velocity
    planets[0].name = "Sun";
    planets[0].mass = 1.9885e30; // kg
    planets[0].radius = 695700000; // m
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    
    planets[1].name = "Earth";
    planets[1].mass = 5.9722e24; // kg
    planets[1].radius = 6.371e6; // m
    planets[1].x = 147e9; // m
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 30300; // m/s
    
    planets[2].name = "Mars";
    planets[2].mass = 6.39e23; // kg
    planets[2].radius = 3.389e6; // m
    planets[2].x = 206.7e9; // m
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 26500; // m/s
    
    planets[3].name = "Jupiter";
    planets[3].mass = 1.898e27; // kg
    planets[3].radius = 69.911e6; // m
    planets[3].x = 740e9; // m
    planets[3].y = 0;
    planets[3].vx = 0;
    planets[3].vy = 13720; // m/s
    
    // Simulate the solar system for 1000 years with timestep of 1 day
    simulate(planets, NUM_PLANETS, 86400, 365000);
    
    // Free memory
    free(planets);
    
    return 0;
}

// Calculate the distance between two points (x1, y1) and (x2, y2)
double calc_distance(double x1, double y1, double x2, double y2) {
    double delta_x = x2 - x1;
    double delta_y = y2 - y1;
    double d = sqrt(delta_x * delta_x + delta_y * delta_y);
    return d;
}

// Calculate the gravitational force between two masses (m1 and m2) separated by a distance (d)
double calc_force(double m1, double m2, double d) {
    double f = (G_CONST * m1 * m2) / (d * d);
    return f;
}

// Calculate the acceleration given a force (f) and mass (m)
double calc_acceleration(double f, double m) {
    double a = f / m;
    return a;
}

// Update the position of a planet given the velocity and timestep
void update_position(Planet* p, double delta_t) {
    p->x += p->vx * delta_t;
    p->y += p->vy * delta_t;
}

// Update the velocity of a planet given the acceleration and timestep
void update_velocity(Planet* p, double ax, double ay, double delta_t) {
    p->vx += ax * delta_t;
    p->vy += ay * delta_t;
}

// Print the properties of each planet in the array
void print_planets(Planet* p_arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s:\n", p_arr[i].name);
        printf("    mass: %e kg\n", p_arr[i].mass);
        printf("    radius: %e m\n", p_arr[i].radius);
        printf("    position: (%e, %e) m\n", p_arr[i].x, p_arr[i].y);
        printf("    velocity: (%e, %e) m/s\n", p_arr[i].vx, p_arr[i].vy);
    }
}

// Simulate the motion of the planets in the solar system
void simulate(Planet* p_arr, int size, double delta_t, int num_steps) {
    // Outer loop for number of steps
    for (int i = 0; i < num_steps; i++) {
        // Calculate the force and acceleration for each planet
        for (int p1 = 0; p1 < size; p1++) {
            double fx_total = 0, fy_total = 0; // Total force on planet p1
            for (int p2 = 0; p2 < size; p2++) {
                if (p1 != p2) {
                    double d = calc_distance(p_arr[p1].x, p_arr[p1].y, p_arr[p2].x, p_arr[p2].y);
                    double f = calc_force(p_arr[p1].mass, p_arr[p2].mass, d);
                    double ax = calc_acceleration(f, p_arr[p1].mass);
                    double ay = calc_acceleration(f, p_arr[p1].mass);
                    fx_total += f * (p_arr[p2].x - p_arr[p1].x) / d;
                    fy_total += f * (p_arr[p2].y - p_arr[p1].y) / d;
                }
            }
            double ax_total = fx_total / p_arr[p1].mass;
            double ay_total = fy_total / p_arr[p1].mass;
            // Update velocity and position of planet p1
            update_velocity(&p_arr[p1], ax_total, ay_total, delta_t);
            update_position(&p_arr[p1], delta_t);
        }
        // Print the properties of each planet every 10 years
        if (i % 3650 == 0) {
            printf("Year %d:\n", i / 365);
            print_planets(p_arr, size);
            printf("\n");
        }
    }
}