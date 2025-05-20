//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define G 6.67e-11 // m^3 kg^-1 s^-2
#define AU 1.495e11 // m (1 AU = 1 Astronomical Unit = avg Earth-Sun distance)
#define DAY 86400 // s (1 day = 86400 seconds)
#define YEAR 365.25 // days (1 year = 365.25 days)

// Structures
typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

// Function prototypes
void updateVelocity(Body *body, Body *bodies, int numBodies, double dt);
void updatePosition(Body *body, double dt);
void runSimulation(Body *bodies, int numBodies, double dt, double t_final);
void printState(Body *bodies, int numBodies, double t);

int main() {
    // Initialize bodies
    int numBodies = 4;
    Body *bodies = (Body*)malloc(numBodies * sizeof(Body));
    bodies[0] = (Body){1.989e30, 0, 0, 0, 0, 0, 0}; // Sun
    bodies[1] = (Body){5.97e24, AU, 0, 0, 0, 29783, 0}; // Earth
    bodies[2] = (Body){7.34e22, AU + 384400000, 0, 0, 0, 3075 + 29783, 0}; // Moon
    bodies[3] = (Body){3.29e23, AU + 778500000000, 0, 0, 0, 13069, 0}; // Jupiter
    
    // Run simulation
    double dt = DAY;
    double t_final = YEAR;
    runSimulation(bodies, numBodies, dt, t_final);
    
    // Free memory
    free(bodies);
    
    return 0;
}

void updateVelocity(Body *body, Body *bodies, int numBodies, double dt) {
    double ax = 0, ay = 0, az = 0;
    for (int i = 0; i < numBodies; i++) {
        if (body == &bodies[i]) continue; // Skip current body
        double dx = bodies[i].x - body->x;
        double dy = bodies[i].y - body->y;
        double dz = bodies[i].z - body->z;
        double r = sqrt(dx*dx + dy*dy + dz*dz);
        double f = G * body->mass * bodies[i].mass / (r*r);
        ax += f * dx / r;
        ay += f * dy / r;
        az += f * dz / r;
    }
    body->vx += ax * dt;
    body->vy += ay * dt;
    body->vz += az * dt;
}

void updatePosition(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

void runSimulation(Body *bodies, int numBodies, double dt, double t_final) {
    double t = 0;
    while (t < t_final) {
        for (int i = 0; i < numBodies; i++) {
            updateVelocity(&bodies[i], bodies, numBodies, dt);
        }
        for (int i = 0; i < numBodies; i++) {
            updatePosition(&bodies[i], dt);
        }
        t += dt;
        printState(bodies, numBodies, t);
    }
}

void printState(Body *bodies, int numBodies, double t) {
    printf("Time: %0.1f days\n", t/DAY);
    printf("Body\tX\tY\tZ\tVx\tVy\tVz\n");
    for (int i = 0; i < numBodies; i++) {
        printf("%d\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\n",
               i, bodies[i].x/AU, bodies[i].y/AU, bodies[i].z/AU,
               bodies[i].vx, bodies[i].vy, bodies[i].vz);
    }
    printf("\n");
}