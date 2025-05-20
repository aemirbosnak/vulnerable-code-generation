//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

Body *bodies;
int num_bodies;

void init_bodies(int n) {
    bodies = malloc(n * sizeof(Body));
    num_bodies = n;
    
    // Initialize the bodies with random masses and positions
    for (int i = 0; i < n; i++) {
        bodies[i].mass = rand() % 100000;
        bodies[i].x = rand() % 100000;
        bodies[i].y = rand() % 100000;
        bodies[i].z = rand() % 100000;
        bodies[i].vx = 0;
        bodies[i].vy = 0;
        bodies[i].vz = 0;
    }
}

void update_forces() {
    // Calculate the forces between all pairs of bodies
    for (int i = 0; i < num_bodies; i++) {
        for (int j = i + 1; j < num_bodies; j++) {
            // Calculate the distance between the bodies
            double dx = bodies[i].x - bodies[j].x;
            double dy = bodies[i].y - bodies[j].y;
            double dz = bodies[i].z - bodies[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            
            // Calculate the force between the bodies
            double f = G * bodies[i].mass * bodies[j].mass / (r * r);
            
            // Apply the force to the bodies
            bodies[i].vx += f * dx / r;
            bodies[i].vy += f * dy / r;
            bodies[i].vz += f * dz / r;
            bodies[j].vx -= f * dx / r;
            bodies[j].vy -= f * dy / r;
            bodies[j].vz -= f * dz / r;
        }
    }
}

void update_positions() {
    // Update the positions of the bodies
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].x += bodies[i].vx;
        bodies[i].y += bodies[i].vy;
        bodies[i].z += bodies[i].vz;
    }
}

void print_bodies() {
    // Print the positions of the bodies
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: (%.2f, %.2f, %.2f)\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }
}

int main() {
    // Initialize the bodies
    init_bodies(10);
    
    // Update the forces and positions of the bodies for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        update_forces();
        update_positions();
    }
    
    // Print the positions of the bodies
    print_bodies();
    
    return 0;
}