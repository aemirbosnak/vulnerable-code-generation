//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Object structure
typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Object;

// Simulation parameters
#define N 1000
#define DT 0.01
#define G 6.674e-11

// Initialize objects
void initialize(Object *objects) {
    for (int i = 0; i < N; i++) {
        objects[i].mass = 1e24;
        objects[i].x = (rand() / (RAND_MAX + 1.0)) * 1e12;
        objects[i].y = (rand() / (RAND_MAX + 1.0)) * 1e12;
        objects[i].z = (rand() / (RAND_MAX + 1.0)) * 1e12;
        objects[i].vx = 0;
        objects[i].vy = 0;
        objects[i].vz = 0;
    }
}

// Calculate gravitational force
void calculate_force(Object *objects, double *fx, double *fy, double *fz) {
    for (int i = 0; i < N; i++) {
        fx[i] = 0;
        fy[i] = 0;
        fz[i] = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            double dx = objects[j].x - objects[i].x;
            double dy = objects[j].y - objects[i].y;
            double dz = objects[j].z - objects[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * objects[i].mass * objects[j].mass / (r * r * r);
            fx[i] += f * dx / r;
            fy[i] += f * dy / r;
            fz[i] += f * dz / r;
        }
    }
}

// Update positions and velocities
void update(Object *objects, double *fx, double *fy, double *fz) {
    for (int i = 0; i < N; i++) {
        objects[i].x += objects[i].vx * DT;
        objects[i].y += objects[i].vy * DT;
        objects[i].z += objects[i].vz * DT;
        objects[i].vx += fx[i] * DT / objects[i].mass;
        objects[i].vy += fy[i] * DT / objects[i].mass;
        objects[i].vz += fz[i] * DT / objects[i].mass;
    }
}

// Main function
int main() {
    // Allocate memory for objects
    Object *objects = (Object *)malloc(N * sizeof(Object));

    // Initialize objects
    initialize(objects);

    // Simulation loop
    for (int i = 0; i < 10000; i++) {
        
        // Calculate gravitational force
        double *fx = (double *)malloc(N * sizeof(double));
        double *fy = (double *)malloc(N * sizeof(double));
        double *fz = (double *)malloc(N * sizeof(double));
        calculate_force(objects, fx, fy, fz);
        
        // Update positions and velocities
        update(objects, fx, fy, fz);
        
        
        free(fx);
        free(fy);
        free(fz);
    }

    // Free memory
    free(objects);

    return 0;
}