//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11

typedef struct {
    double x;
    double y;
    double mass;
    double vx;
    double vy;
} body;

body* create_body(double x, double y, double mass) {
    body* b = malloc(sizeof(body));
    b->x = x;
    b->y = y;
    b->mass = mass;
    b->vx = 0;
    b->vy = 0;
    return b;
}

void free_body(body* b) {
    free(b);
}

double distance(body* a, body* b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx*dx + dy*dy);
}

void update_forces(body* a, body* b) {
    double r = distance(a, b);
    double f = G * a->mass * b->mass / (r * r);
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double f_x = f * dx / r;
    double f_y = f * dy / r;
    a->vx += f_x / a->mass;
    a->vy += f_y / a->mass;
    b->vx -= f_x / b->mass;
    b->vy -= f_y / b->mass;
}

void update_positions(body* b) {
    b->x += b->vx;
    b->y += b->vy;
}

int main() {
    srand(time(NULL));
    body* bodies[100];
    for (int i = 0; i < 100; i++) {
        bodies[i] = create_body(rand() % 1000, rand() % 1000, rand() % 100);
    }
    for (int i = 0; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            update_forces(bodies[i], bodies[j]);
        }
    }
    for (int i = 0; i < 100; i++) {
        update_positions(bodies[i]);
    }
    for (int i = 0; i < 100; i++) {
        free_body(bodies[i]);
    }
    return 0;
}