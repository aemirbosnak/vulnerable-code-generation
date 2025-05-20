//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* A fun planet gravity simulation program! */

#define G 6.674 * pow(10, -11) /* Gravitational Constant */
#define FRAME_RATE 60 /* Frames per second */
#define FRAME_TIME 1000 / FRAME_RATE /* Time for each frame */

/* Struct to hold coordinates of a body and its velocity */
struct Body {
    double x, y, vx, vy;
    double mass;
};

/* Calculate the distance between two bodies */
double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

/* Calculate the force between two bodies */
double force(double m1, double m2, double r) {
    return G * m1 * m2 / (r * r);
}

/* Update the velocity and position of a body due to gravitational force from other bodies */
void update(struct Body *body, struct Body *bodies, int n) {
    double ax = 0, ay = 0;
    for (int i = 0; i < n; i++) {
        if (bodies[i].x != body->x && bodies[i].y != body->y) { /* Skip self */
            double r = distance(body->x, body->y, bodies[i].x, bodies[i].y);
            double f = force(body->mass, bodies[i].mass, r);
            double theta = atan2(bodies[i].y - body->y, bodies[i].x - body->x);
            ax += f / body->mass * cos(theta);
            ay += f / body->mass * sin(theta);
        }
    }
    body->vx += ax * FRAME_TIME / 1000;
    body->vy += ay * FRAME_TIME / 1000;
    body->x += body->vx * FRAME_TIME / 1000;
    body->y += body->vy * FRAME_TIME / 1000;
}

int main() {
    int num_bodies = 4;
    struct Body *bodies = malloc(num_bodies * sizeof(struct Body));
    bodies[0] = (struct Body) {.x = 0, .y = 0, .vx = 0, .vy = 0, .mass = 5.97 * pow(10,24)}; /* Earth */
    bodies[1] = (struct Body) {.x = 150000000000, .y = 0, .vx = 0, .vy = 30000, .mass = 100000}; /* Spaceship */
    bodies[2] = (struct Body) {.x = 0, .y = 200000000000, .vx = -20000, .vy = 0, .mass = 5000}; /* Moon */
    bodies[3] = (struct Body) {.x = -300000000000, .y = 0, .vx = 0, .vx = -15000, .mass = 25000}; /* Star */

    for (int t = 0; t < 10000; t += FRAME_TIME) { /* Simulate 10 seconds */
        printf("Time: %dms\n", t);
        for (int i = 0; i < num_bodies; i++) {
            update(&bodies[i], bodies, num_bodies);
            printf("Body %d: x=%f, y=%f, vx=%f, vy=%f\n", i, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
        }
        printf("\n");
        usleep(FRAME_TIME * 1000); /* Sleep before next frame */
    }

    free(bodies);
    return 0;
}