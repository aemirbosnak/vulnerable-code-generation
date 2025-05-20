//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67408e-11

typedef struct {
    double x, y, z;
} vector;

typedef struct {
    double mass;
    vector position;
    vector velocity;
    vector acceleration;
} body;

body *bodies;
int num_bodies;

void init_bodies(int n) {
    bodies = malloc(n * sizeof(body));
    num_bodies = n;

    for (int i = 0; i < n; i++) {
        bodies[i].mass = rand() / (double)RAND_MAX;
        bodies[i].position.x = rand() / (double)RAND_MAX;
        bodies[i].position.y = rand() / (double)RAND_MAX;
        bodies[i].position.z = rand() / (double)RAND_MAX;
        bodies[i].velocity.x = 0;
        bodies[i].velocity.y = 0;
        bodies[i].velocity.z = 0;
    }
}

//a longer and more mathematical way to calculate the acceleration of a body with position and mass
double force_law (body *b1, body *b2) {
    vector r = {b2->position.x - b1->position.x, b2->position.y - b1->position.y, b2->position.z - b1->position.z};
    double r_mag = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
    return (-G*b1->mass*b2->mass)/pow(r_mag, 2.0);
}

//update all the accelerations in the bodies array
void update_accelerations() {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].acceleration.x = 0;
        bodies[i].acceleration.y = 0;
        bodies[i].acceleration.z = 0;
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            vector r = {bodies[j].position.x - bodies[i].position.x, bodies[j].position.y - bodies[i].position.y, bodies[j].position.z - bodies[i].position.z};
            double r_mag = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
            bodies[i].acceleration.x += (-G*bodies[j].mass*r.x/pow(r_mag, 3.0));
            bodies[i].acceleration.y += (-G*bodies[j].mass*r.y/pow(r_mag, 3.0));
            bodies[i].acceleration.z += (-G*bodies[j].mass*r.z/pow(r_mag, 3.0));
        }
    }
}

void update_positions() {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * 0.01;
        bodies[i].position.y += bodies[i].velocity.y * 0.01;
        bodies[i].position.z += bodies[i].velocity.z * 0.01;
    }
}

void update_velocities() {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].velocity.x += bodies[i].acceleration.x * 0.01;
        bodies[i].velocity.y += bodies[i].acceleration.y * 0.01;
        bodies[i].velocity.z += bodies[i].acceleration.z * 0.01;
    }
}

int main() {
    srand(time(NULL));
    init_bodies(1000);
    for (int i = 0; i < 100000; i++) {
        update_accelerations();
        update_positions();
        update_velocities();
    }
    return 0;
}