//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11 // gravitational constant

typedef struct {
    double x, y;
    double vx, vy;
    double mass;
} body;

void update_pos(body *b, double dt) {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

void update_vel(body *b, double fx, double fy, double dt) {
    double ax = fx / b->mass;
    double ay = fy / b->mass;
    b->vx += ax * dt;
    b->vy += ay * dt;
}

double distance(body *b1, body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    return sqrt(dx * dx + dy * dy);
}

void apply_force(body *b1, body *b2) {
    double r = distance(b1, b2);
    double f = G * b1->mass * b2->mass / (r * r);
    double fx = f * (b2->x - b1->x) / r;
    double fy = f * (b2->y - b1->y) / r;
    update_vel(b1, fx, fy, 1);
    update_vel(b2, -fx, -fy, 1);
}

void simulate(body *bodies, int N, double dt, double tmax) {
    int i, j;
    double fx, fy;
    for (double t = 0; t < tmax; t += dt) {
        for (i = 0; i < N; i++) {
            fx = fy = 0.0;
            for (j = 0; j < N; j++) {
                if (i != j) {
                    apply_force(&bodies[i], &bodies[j]);
                }
            }
            update_pos(&bodies[i], dt);
        }
        printf("t = %.2f\n", t);
        for (i = 0; i < N; i++) {
            printf("body %d: (%.2f, %.2f)\n", i, bodies[i].x, bodies[i].y);
        }
    }
}

int main() {
    srand(time(NULL));
    int N = 3;
    double dt = 0.01;
    double tmax = 10.0;
    body *bodies = malloc(sizeof(body) * N);
    for (int i = 0; i < N; i++) {
        bodies[i].x = (double) rand() / RAND_MAX * 10.0;
        bodies[i].y = (double) rand() / RAND_MAX * 10.0;
        bodies[i].vx = (double) rand() / RAND_MAX * 2.0 - 1.0;
        bodies[i].vy = (double) rand() / RAND_MAX * 2.0 - 1.0;
        bodies[i].mass = (double) rand() / RAND_MAX * 100.0;
    }
    simulate(bodies, N, dt, tmax);
    free(bodies);
    return 0;
}