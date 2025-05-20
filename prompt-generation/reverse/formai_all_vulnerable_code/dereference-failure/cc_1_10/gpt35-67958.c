//FormAI DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SOLAR_MASS 1.9891e30 // kg
#define GRAV_CONST 6.67430e-11 // N*(m/kg)^2

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D position, velocity, acceleration;
    double mass;
} Body;

typedef struct {
    Body *bodies;
    int num_bodies;
} Universe;

Vector2D vector_addition(Vector2D v1, Vector2D v2) {
    Vector2D v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}

double vector_distance(Vector2D v1, Vector2D v2) {
    double dx = v2.x - v1.x;
    double dy = v2.y - v1.y;
    return sqrt(dx * dx + dy * dy);
}

void calculate_gravity(Body *b1, Body *b2) {
    Vector2D r12 = {b2->position.x - b1->position.x, b2->position.y - b1->position.y};
    double distance = vector_distance(b1->position, b2->position);
    double force = GRAV_CONST * b1->mass * b2->mass / (distance * distance);
    Vector2D f12 = {force * r12.x / distance, force * r12.y / distance};
    b1->acceleration.x += f12.x / b1->mass;
    b1->acceleration.y += f12.y / b1->mass;
    b2->acceleration.x -= f12.x / b2->mass;
    b2->acceleration.y -= f12.y / b2->mass;
}

void update(Universe *u, double time_step) {
    for (int i = 0; i < u->num_bodies; ++i) {
        u->bodies[i].velocity.x += u->bodies[i].acceleration.x * time_step;
        u->bodies[i].velocity.y += u->bodies[i].acceleration.y * time_step;
        u->bodies[i].position.x += u->bodies[i].velocity.x * time_step;
        u->bodies[i].position.y += u->bodies[i].velocity.y * time_step;
        u->bodies[i].acceleration.x = 0;
        u->bodies[i].acceleration.y = 0;
    }
    for (int i = 0; i < u->num_bodies; ++i) {
        for (int j = i+1; j < u->num_bodies; ++j) {
            calculate_gravity(&u->bodies[i], &u->bodies[j]);
        }
    }
}

int main() {
    Universe u = {
        .num_bodies = 2,
        .bodies = (Body *) malloc(sizeof(Body) * 2)
    };
    u.bodies[0] = (Body) {
        .position = {0, 0},
        .velocity = {0, 0},
        .acceleration = {0, 0},
        .mass = SOLAR_MASS
    };
    u.bodies[1] = (Body) {
        .position = {1.496e11, 0},
        .velocity = {0, 29783},
        .acceleration = {0, 0},
        .mass = 5.972e24
    };
    int num_steps = 365 * 24 * 60;
    double time_step = 60.0;
    for (int i = 0; i < num_steps; ++i) {
        printf("%lf %lf\n", u.bodies[1].position.x, u.bodies[1].position.y);
        update(&u, time_step);
    }
    free(u.bodies);
}