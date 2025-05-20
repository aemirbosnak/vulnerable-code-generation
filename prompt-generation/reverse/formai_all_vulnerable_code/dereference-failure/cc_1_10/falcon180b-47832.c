//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000 // Number of particles
#define dt 0.01 // Time step
#define G 6.674e-11 // Gravitational constant
#define pi 3.14159265358979323846 // Pi

// Initialize the positions and velocities of the particles
void init_particles(double *pos, double *vel) {
    for (int i = 0; i < N; i++) {
        pos[i] = (double)rand() / RAND_MAX * 10.0;
        vel[i] = (double)rand() / RAND_MAX * 0.1 - 0.05;
    }
}

// Calculate the force between two particles
void force(double *pos, double *vel, double *acc, int i, int j) {
    double r = sqrt(pow(pos[j*3]-pos[i*3],2) + pow(pos[j*3+1]-pos[i*3+1],2) + pow(pos[j*3+2]-pos[i*3+2],2));
    double f = G * pow(0.1,3) * vel[j*3] * vel[i*3] / (r * r);
    acc[i*3] += f * vel[j*3] / r;
    acc[j*3] -= f * vel[i*3] / r;
}

// Update the positions and velocities of the particles
void update_particles(double *pos, double *vel, double *acc, int n) {
    for (int i = 0; i < n; i++) {
        pos[i*3] += vel[i*3] * dt;
        pos[i*3+1] += vel[i*3+1] * dt;
        pos[i*3+2] += vel[i*3+2] * dt;
        vel[i*3] += acc[i*3] * dt;
        vel[i*3+1] += acc[i*3+1] * dt;
        vel[i*3+2] += acc[i*3+2] * dt;
        acc[i*3] = 0.0;
        acc[i*3+1] = 0.0;
        acc[i*3+2] = 0.0;
    }
}

// Print the positions of the particles
void print_particles(double *pos) {
    for (int i = 0; i < N; i++) {
        printf("%.2f %.2f %.2f\n", pos[i*3], pos[i*3+1], pos[i*3+2]);
    }
}

// Main function
int main() {
    srand(time(NULL));
    double *pos = (double*)malloc(N * 3 * sizeof(double));
    double *vel = (double*)malloc(N * 3 * sizeof(double));
    double *acc = (double*)malloc(N * 3 * sizeof(double));
    init_particles(pos, vel);
    while (1) {
        printf("Enter 'p' to print the positions of the particles, 'q' to quit: ");
        char c = getchar();
        if (c == 'p') {
            print_particles(pos);
        } else if (c == 'q') {
            break;
        }
        update_particles(pos, vel, acc, N);
    }
    free(pos);
    free(vel);
    free(acc);
    return 0;
}