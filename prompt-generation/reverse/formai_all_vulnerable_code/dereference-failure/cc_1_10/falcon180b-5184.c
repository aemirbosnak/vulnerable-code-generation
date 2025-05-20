//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // number of particles
#define L 2.0 // length of box
#define M 1.0 // mass of each particle
#define K 1.0 // force constant
#define T 3.0 // temperature
#define DT 0.01 // time step

// initialize position and velocity of particles
void init(double **r, double **v) {
    int i, j;
    for (i = 0; i < N; i++) {
        r[i][0] = (double) rand() / RAND_MAX * L; // random position in box
        r[i][1] = (double) rand() / RAND_MAX * L;
        v[i][0] = (double) rand() / RAND_MAX * 2 * T - T; // random velocity in box
        v[i][1] = (double) rand() / RAND_MAX * 2 * T - T;
    }
}

// calculate force on particle i due to particle j
void force(double **r, double **v, double f[], int i, int j) {
    double r2 = r[i][0] - r[j][0];
    double v2 = v[i][0] - v[j][0];
    double fx = K * r2 * v2;
    double fy = K * r[i][1] - r[j][1] * v2;
    f[0] += fx;
    f[1] += fy;
}

// update position and velocity of particles
void update(double **r, double **v, double f[], int i, int j) {
    double vx = v[i][0] + f[0] * DT;
    double vy = v[i][1] + f[1] * DT;
    r[i][0] += vx * DT;
    r[i][1] += vy * DT;
    v[i][0] = vx;
    v[i][1] = vy;
}

// main program
int main() {
    srand(time(NULL));
    double **r = (double **) malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        r[i] = (double *) malloc(2 * sizeof(double));
    }
    double **v = (double **) malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        v[i] = (double *) malloc(2 * sizeof(double));
    }
    double f[2];
    init(r, v);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i!= j) {
                force(r, v, f, i, j);
            }
        }
        update(r, v, f, i, 0);
    }
    for (int i = 0; i < N; i++) {
        free(r[i]);
        free(v[i]);
    }
    free(r);
    free(v);
    return 0;
}