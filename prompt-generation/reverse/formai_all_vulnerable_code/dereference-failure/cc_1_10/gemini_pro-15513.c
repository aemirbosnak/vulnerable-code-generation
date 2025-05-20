//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 
#define AU 1.496e11 
#define YR 3.156e7 

typedef struct {
    double mass; 
    double pos[3]; 
    double vel[3]; 
} Body;

typedef struct {
    int n; 
    Body *bodies; 
} System;

System *create_system(int n) {
    System *system = malloc(sizeof(System));
    system->n = n;
    system->bodies = malloc(n * sizeof(Body));
    return system;
}

void destroy_system(System *system) {
    free(system->bodies);
    free(system);
}

void initialize_system(System *system, double masses[], double positions[][3], double velocities[][3]) {
    for (int i = 0; i < system->n; i++) {
        system->bodies[i].mass = masses[i];
        for (int j = 0; j < 3; j++) {
            system->bodies[i].pos[j] = positions[i][j] * AU;
            system->bodies[i].vel[j] = velocities[i][j] * AU / YR;
        }
    }
}

void update_system(System *system, double dt) {
    for (int i = 0; i < system->n; i++) {
        double a[3] = {0, 0, 0}; 
        for (int j = 0; j < system->n; j++) {
            if (i == j) continue;
            double dx[3]; 
            for (int k = 0; k < 3; k++) dx[k] = system->bodies[j].pos[k] - system->bodies[i].pos[k];
            double r = sqrt(dx[0] * dx[0] + dx[1] * dx[1] + dx[2] * dx[2]);
            for (int k = 0; k < 3; k++) a[k] += G * system->bodies[j].mass * dx[k] / (r * r * r);
        }
        for (int k = 0; k < 3; k++) {
            system->bodies[i].vel[k] += a[k] * dt;
            system->bodies[i].pos[k] += system->bodies[i].vel[k] * dt;
        }
    }
}

void print_system(System *system) {
    for (int i = 0; i < system->n; i++) {
        printf("Body %d:\n", i);
        printf("Mass: %.2e kg\n", system->bodies[i].mass);
        printf("Position: (%.2e, %.2e, %.2e) m\n", system->bodies[i].pos[0], system->bodies[i].pos[1], system->bodies[i].pos[2]);
        printf("Velocity: (%.2e, %.2e, %.2e) m/s\n", system->bodies[i].vel[0], system->bodies[i].vel[1], system->bodies[i].vel[2]);
        printf("\n");
    }
}

int main() {
    int n = 5; 
    double masses[] = {1.989e30, 5.685e26, 5.972e24, 4.869e24, 1.899e27}; 
    double positions[][3] = {
        {0, 0, 0}, 
        {0, 0, 1.496e11}, 
        {0, 0, 1.51e11}, 
        {0, 0, 2.28e11}, 
        {0, 0, 3.84e12}
    }; 
    double velocities[][3] = {
        {0, 0, 0}, 
        {0, 29.78e3, 0}, 
        {0, 30.29e3, 0}, 
        {0, 23.96e3, 0}, 
        {0, 13.07e3, 0}
    }; 
    System *system = create_system(n);
    initialize_system(system, masses, positions, velocities);
    print_system(system);
    double dt = 3600; 
    for (int i = 0; i < 10000; i++) {
        update_system(system, dt);
    }
    print_system(system);
    destroy_system(system);
    return 0;
}