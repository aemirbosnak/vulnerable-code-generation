//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000
#define G 6.674e-11
#define STEP 0.01
#define TIME_STEP 0.01

// Function to calculate force between two particles
double force(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * (x1*x2 + y1*y2 + z1*z2) / (r*r);
    return f;
}

// Function to update particle velocities and positions
void update(double *pos, double *vel, double *acc, int n, double dt) {
    for(int i=0; i<n; i++) {
        vel[i] += acc[i] * dt;
        pos[i] += vel[i] * dt;
    }
}

// Function to calculate accelerations
void calc_acc(double *pos, double *vel, double *acc, int n) {
    for(int i=0; i<n; i++) {
        acc[i] = 0.0;
        for(int j=0; j<n; j++) {
            if(i!= j) {
                acc[i] += force(pos[i],pos[i+1],pos[i+2],pos[j],pos[j+1],pos[j+2]) / pos[i+2];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    double *pos = malloc(N * 3 * sizeof(double));
    double *vel = malloc(N * 3 * sizeof(double));
    double *acc = malloc(N * 3 * sizeof(double));

    // Initialize particle positions and velocities
    for(int i=0; i<N; i++) {
        pos[i] = rand() % 100;
        vel[i] = rand() % 10 - 5;
    }

    while(1) {
        calc_acc(pos, vel, acc, N);
        update(pos, vel, acc, N, STEP);
        printf("Simulation running...\n");
        sleep(1);
    }

    return 0;
}