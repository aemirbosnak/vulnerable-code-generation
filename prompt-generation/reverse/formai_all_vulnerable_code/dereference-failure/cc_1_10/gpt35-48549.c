//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant
#define M_sun 1.989e+30 // mass of sun

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    vector position;
    vector velocity;
    double mass;
} body;

vector subtract(vector v1, vector v2);
double distance(vector v1, vector v2);
vector acceleration(body b1, body b2);
void update_velocity(body *b, vector a, double dt);
void update_position(body *b, double dt);
void simulate(body **bodies, int num_bodies, double dt, int num_steps);

int main() {
    int num_bodies = 4;
    double dt = 1e3;
    int num_steps = 10;

    body **bodies = malloc(num_bodies * sizeof(body*));

    // set up initial conditions
    bodies[0] = malloc(sizeof(body));
    bodies[0]->position = (vector) {0, 0, 0};
    bodies[0]->velocity = (vector) {0, 0, 0};
    bodies[0]->mass = M_sun;

    bodies[1] = malloc(sizeof(body));
    bodies[1]->position = (vector) {1.4710e+11, 0, 0};
    bodies[1]->velocity = (vector) {0, 3.0287e+4, 0};
    bodies[1]->mass = 5.97e+24;

    bodies[2] = malloc(sizeof(body));
    bodies[2]->position = (vector) {0, 0, 2.7e+10};
    bodies[2]->velocity = (vector) {-2.6602e+4, 0, 0};
    bodies[2]->mass = 3.3e+23;

    bodies[3] = malloc(sizeof(body));
    bodies[3]->position = (vector) {0, 7.7855e+11, 0};
    bodies[3]->velocity = (vector) {12.44e+3, 0, 0};
    bodies[3]->mass = 4.87e+24;

    simulate(bodies, num_bodies, dt, num_steps);

    for (int i = 0; i < num_bodies; i++) {
        free(bodies[i]);
    }

    free(bodies);

    return 0;
}

// subtracts two vectors
vector subtract(vector v1, vector v2) {
    vector result = {
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };

    return result;
}

// calculates the distance between two vectors
double distance(vector v1, vector v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

// calculates the acceleration due to gravity between two bodies
vector acceleration(body b1, body b2) {
    double dist = distance(b1.position, b2.position);
    double magnitude = G * b1.mass * b2.mass / pow(dist, 2);
    vector direction = subtract(b2.position, b1.position);
    direction.x /= dist;
    direction.y /= dist;
    direction.z /= dist;
    vector result = {
        magnitude * direction.x,
        magnitude * direction.y,
        magnitude * direction.z
    };

    return result;
}

// updates the velocity of a body
void update_velocity(body *b, vector a, double dt) {
    b->velocity.x += a.x * dt;
    b->velocity.y += a.y * dt;
    b->velocity.z += a.z * dt;
}

// updates the position of a body
void update_position(body *b, double dt) {
    b->position.x += b->velocity.x * dt;
    b->position.y += b->velocity.y * dt;
    b->position.z += b->velocity.z * dt;
}

// simulates the system for a given number of steps
void simulate(body **bodies, int num_bodies, double dt, int num_steps) {
    vector a[num_bodies];

    for (int i = 0; i < num_steps; i++) {
        // calculate acceleration for each body
        for (int j = 0; j < num_bodies; j++) {
            a[j] = (vector) {0, 0, 0};

            for (int k = 0; k < num_bodies; k++) {
                if (j != k) {
                    vector acc = acceleration(*bodies[j], *bodies[k]);
                    a[j].x += acc.x;
                    a[j].y += acc.y;
                    a[j].z += acc.z;
                }
            }
        }

        // update velocities and positions for each body
        for (int j = 0; j < num_bodies; j++) {
            update_velocity(bodies[j], a[j], dt);
            update_position(bodies[j], dt);
        }

        // print current positions
        for (int j = 0; j < num_bodies; j++) {
            printf("Body %d: (%e, %e, %e)\n", j, bodies[j]->position.x, bodies[j]->position.y, bodies[j]->position.z);
        }

        printf("\n");
    }
}