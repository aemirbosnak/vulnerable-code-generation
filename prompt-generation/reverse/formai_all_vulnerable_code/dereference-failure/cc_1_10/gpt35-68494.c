//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double mass; // mass
} body;

int main() {
    int num_bodies = 3; // number of bodies
    int num_steps = 100; // number of time steps
    double time_step = 1.0; // time step in seconds
    body **bodies; // array of pointers to bodies
    
    // allocate memory for bodies
    bodies = (body **)malloc(num_bodies * sizeof(body *));
    for (int i = 0; i < num_bodies; i++) {
        bodies[i] = (body *)malloc(sizeof(body));
    }
    
    // set initial positions, velocities, masses
    bodies[0]->x = 0.0;
    bodies[0]->y = 0.0;
    bodies[0]->z = 0.0;
    bodies[0]->vx = 0.0;
    bodies[0]->vy = 0.0;
    bodies[0]->vz = 0.0;
    bodies[0]->mass = 5.97e24;
    
    bodies[1]->x = 0.0;
    bodies[1]->y = 6371000.0;
    bodies[1]->z = 0.0;
    bodies[1]->vx = 7700.0;
    bodies[1]->vy = 0.0;
    bodies[1]->vz = 0.0;
    bodies[1]->mass = 7.34e22;
    
    bodies[2]->x = 384400000.0;
    bodies[2]->y = 0.0;
    bodies[2]->z = 0.0;
    bodies[2]->vx = 0.0;
    bodies[2]->vy = 1023.0;
    bodies[2]->vz = 0.0;
    bodies[2]->mass = 7.34e22;
    
    // simulate motion of bodies
    for (int step = 0; step < num_steps; step++) {
        // calculate gravitational forces on bodies
        for (int i = 0; i < num_bodies; i++) {
            bodies[i]->ax = 0.0;
            bodies[i]->ay = 0.0;
            bodies[i]->az = 0.0;
            
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    double dx = bodies[j]->x - bodies[i]->x;
                    double dy = bodies[j]->y - bodies[i]->y;
                    double dz = bodies[j]->z - bodies[i]->z;
                    double r = sqrt(dx*dx + dy*dy + dz*dz);
                    double f = G * bodies[i]->mass * bodies[j]->mass / (r*r);
                    bodies[i]->ax += f * dx / r;
                    bodies[i]->ay += f * dy / r;
                    bodies[i]->az += f * dz / r;
                }
            }
        }
        
        // update positions and velocities of bodies
        for (int i = 0; i < num_bodies; i++) {
            bodies[i]->vx += bodies[i]->ax * time_step;
            bodies[i]->vy += bodies[i]->ay * time_step;
            bodies[i]->vz += bodies[i]->az * time_step;
            bodies[i]->x += bodies[i]->vx * time_step;
            bodies[i]->y += bodies[i]->vy * time_step;
            bodies[i]->z += bodies[i]->vz * time_step;
        }
    }
    
    // print final positions and velocities of bodies
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d: Position=(%.2f, %.2f, %.2f) Velocity=(%.2f, %.2f, %.2f)\n", i, bodies[i]->x, bodies[i]->y, bodies[i]->z, bodies[i]->vx, bodies[i]->vy, bodies[i]->vz);
    }
    
    // free memory
    for (int i = 0; i < num_bodies; i++) {
        free(bodies[i]);
    }
    free(bodies);
    
    return 0;
}