//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant
#define SUN_MASS 1.989e30 // Mass of the sun
#define AU 149.6e9 // 1 Astronomical Unit = 149.6 million km

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
} Body;

void update_velocity(Body *body, double dt, double fx, double fy) {
    double ax = fx / body->mass;
    double ay = fy / body->mass;
    body->vx += ax * dt;
    body->vy += ay * dt;
}

void update_position(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

double calculate_force(double mass1, double mass2, double distance) {
    return G * mass1 * mass2 / (distance * distance);
}

void print_state(int time_step, int num_bodies, Body *bodies) {
    printf("Time step %d\n", time_step);
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: x=%g, y=%g, vx=%g, vy=%g\n",
               i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
    printf("\n");
}

int main() {
    int num_bodies = 4;
    Body *bodies = malloc(num_bodies * sizeof(Body));
    
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[0].mass = SUN_MASS;
    
    bodies[1].x = AU;
    bodies[1].y = 0;
    bodies[1].vx = 0;
    bodies[1].vy = 30e3;
    bodies[1].mass = 5.972e24;
    
    bodies[2].x = 0;
    bodies[2].y = AU;
    bodies[2].vx = -30e3;
    bodies[2].vy = 0;
    bodies[2].mass = 5.972e24;
    
    bodies[3].x = -2 * AU;
    bodies[3].y = -2 * AU;
    bodies[3].vx = 23e3;
    bodies[3].vy = 23e3;
    bodies[3].mass = 1.989e30;
    
    double dt = 60 * 60; // time step = 1 hour
    
    for (int time_step = 0; time_step < 365*24; time_step++) {
        // Calculate forces on each body
        for (int i = 0; i < num_bodies; i++) {
            double total_fx = 0;
            double total_fy = 0;
            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;
                double dist = distance(bodies[i].x, bodies[i].y, bodies[j].x, bodies[j].y);
                double force = calculate_force(bodies[i].mass, bodies[j].mass, dist);
                double fx = force * (bodies[j].x - bodies[i].x) / dist;
                double fy = force * (bodies[j].y - bodies[i].y) / dist;
                total_fx += fx;
                total_fy += fy;
            }
            update_velocity(&bodies[i], dt, total_fx, total_fy);
        }
        // Update positions of each body
        for (int i = 0; i < num_bodies; i++) {
            update_position(&bodies[i], dt);
        }
        // Print current state
        print_state(time_step, num_bodies, bodies);
    }
    
    free(bodies);
    return 0;
}