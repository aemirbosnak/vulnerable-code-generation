//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define G 6.674e-11
#define MAX_BODIES 100
#define MAX_STEPS 100000

typedef struct {
    double x, y, z, vx, vy, vz, ax, ay, az, m;
} body;

body *bodies;
int nbodies;
double dt;

void init(void) {
    srand(time(NULL));
    dt = 1e-3;
    nbodies = rand() % MAX_BODIES + 1;
    bodies = (body*) malloc(nbodies * sizeof(body));
    for (int i = 0; i < nbodies; i++) {
        bodies[i].x = rand() % 1000 - 500;
        bodies[i].y = rand() % 1000 - 500;
        bodies[i].z = rand() % 1000 - 500;
        bodies[i].vx = rand() % 100 - 50;
        bodies[i].vy = rand() % 100 - 50;
        bodies[i].vz = rand() % 100 - 50;
        bodies[i].m = rand() % 100 + 1;
    }
}

void free_bodies(void) {
    free(bodies);
}

void advance(int step) {
    for (int i = 0; i < nbodies; i++) {
        for (int j = 0; j < nbodies; j++) {
            if (i!= j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double r = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * bodies[i].m * bodies[j].m / (r*r);
                bodies[i].ax -= dx * f / r;
                bodies[i].ay -= dy * f / r;
                bodies[i].az -= dz * f / r;
            }
        }
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;
        bodies[i].vz += bodies[i].az * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void print_bodies(void) {
    for (int i = 0; i < nbodies; i++) {
        printf("Body %d: (%f, %f, %f) v(%f, %f, %f) a(%f, %f, %f)\n", i, bodies[i].x, bodies[i].y, bodies[i].z, bodies[i].vx, bodies[i].vy, bodies[i].vz, bodies[i].ax, bodies[i].ay, bodies[i].az);
    }
}

int main(void) {
    init();
    for (int step = 0; step < MAX_STEPS; step++) {
        advance(step);
        print_bodies();
    }
    free_bodies();
    return 0;
}