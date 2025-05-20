//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct planet {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} planet;

planet *planets;
int num_planets;
double G = 6.674e-11;  // Gravitational constant

// Calculate the force of gravity between two planets
void calculate_force(planet *p1, planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx * dx + dy * dy);
    double force = G * p1->mass * p2->mass / (r * r);
    double theta = atan2(dy, dx);
    p1->vx += force * cos(theta) / p1->mass;
    p1->vy += force * sin(theta) / p1->mass;
    p2->vx -= force * cos(theta) / p2->mass;
    p2->vy -= force * sin(theta) / p2->mass;
}

// Update the position and velocity of each planet
void update_planets(double dt) {
    for (int i = 0; i < num_planets; i++) {
        for (int j = i + 1; j < num_planets; j++) {
            calculate_force(&planets[i], &planets[j]);
        }
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

// Print the position and velocity of each planet
void print_planets() {
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.2f, %.2f) (%.2f, %.2f)\n",
               i, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }
}

// Initialize the planets
void init_planets(int n) {
    planets = malloc(sizeof(planet) * n);
    num_planets = n;
    planets[0].mass = 1.989e30;  // Sun
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[1].mass = 5.972e24;  // Earth
    planets[1].x = 1.5e11;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 30000;
    planets[2].mass = 7.348e22;  // Mars
    planets[2].x = 2.4e11;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 24000;
}

// Free the memory allocated for the planets
void free_planets() {
    free(planets);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of planets>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    init_planets(n);
    double dt = 3600;  // Time step in seconds
    double t = 0;      // Time in seconds
    while (t < 365 * 24 * 3600) {  // Run for one year
        update_planets(dt);
        t += dt;
    }
    print_planets();
    free_planets();
    return 0;
}