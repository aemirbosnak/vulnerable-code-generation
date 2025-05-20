//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    char name[20];
    double mass; // kg
    double x;    // position x (m)
    double y;    // position y (m)
    double vx;   // velocity x (m/s)
    double vy;   // velocity y (m/s)
} Planet;

void print_planets(Planet *planets, int count) {
    printf("\nCurrent state of planets:\n");
    for (int i = 0; i < count; i++) {
        printf("Planet %s: Position(%f, %f), Velocity(%f, %f)\n",
                planets[i].name, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }
}

void update_velocity(Planet *p1, Planet *p2, double dt) {
    double distance_x = p2->x - p1->x;
    double distance_y = p2->y - p1->y;
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    double force = (G * p1->mass * p2->mass) / (distance * distance);

    double force_x = force * (distance_x / distance);
    double force_y = force * (distance_y / distance);

    p1->vx += (force_x / p1->mass) * dt;
    p1->vy += (force_y / p1->mass) * dt;
}

void update_position(Planet *planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
}

void simulate(Planet *planets, int count, double time_step, double total_time) {
    for (double t = 0; t < total_time; t += time_step) {
        // Update velocities based on gravitational forces
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (i != j) {
                    update_velocity(&planets[i], &planets[j], time_step);
                }
            }
        }
        
        // Update positions based on velocities
        for (int i = 0; i < count; i++) {
            update_position(&planets[i], time_step);
        }

        print_planets(planets, count);
    }
}

int main() {
    int count = 3; // Number of planets
    Planet *planets = (Planet *)malloc(count * sizeof(Planet));
    
    // Initialize planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.972e24; // kg
    planets[0].x = 0; // m
    planets[0].y = 0; // m
    planets[0].vx = 0; // m/s
    planets[0].vy = 0; // m/s
    
    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.4171e23; // kg
    planets[1].x = 227.9e9; // m
    planets[1].y = 0; // m
    planets[1].vx = 0; // m/s
    planets[1].vy = 24077; // m/s (orbital speed)

    strcpy(planets[2].name, "Venus");
    planets[2].mass = 4.8675e24; // kg
    planets[2].x = 108.2e9; // m
    planets[2].y = 0; // m
    planets[2].vx = 0; // m/s
    planets[2].vy = 35020; // m/s (orbital speed)

    // Simulation parameters
    double time_step = 60; // seconds
    double total_time = 3600; // 1 hour

    printf("Starting gravity simulation for %d planets...\n", count);
    simulate(planets, count, time_step, total_time);
    
    free(planets);
    return 0;
}