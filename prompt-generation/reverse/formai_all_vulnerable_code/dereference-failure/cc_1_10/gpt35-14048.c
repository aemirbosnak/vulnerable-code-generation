//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.674e-11   // gravitational constant
#define TIME_STEP 0.1 // time step

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass
} Object;

void simulate(Object* objects, int num_objects, double time_steps) {
    for (int k = 0; k < time_steps; k++) {
        for (int i = 0; i < num_objects; i++) {
            double fx = 0, fy = 0;
            for (int j = 0; j < num_objects; j++) {
                if (i != j) {
                    double dx = objects[j].x - objects[i].x;
                    double dy = objects[j].y - objects[i].y;
                    double d = hypot(dx, dy);
                    double f = G * objects[i].mass * objects[j].mass / (d * d);
                    fx += f * dx / d;
                    fy += f * dy / d;
                }
            }
            objects[i].vx += fx / objects[i].mass * TIME_STEP;
            objects[i].vy += fy / objects[i].mass * TIME_STEP;
            objects[i].x += objects[i].vx * TIME_STEP;
            objects[i].y += objects[i].vy * TIME_STEP;
        }
    }
}

int main() {
    srand(time(NULL));
    int num_objects = 10;
    Object* objects = (Object*)malloc(num_objects * sizeof(Object));
    for (int i = 0; i < num_objects; i++) {
        objects[i].mass = rand() % 10 + 1;
        objects[i].x = rand() % 100 + 1;
        objects[i].y = rand() % 100 + 1;
        objects[i].vx = (rand() % 10 + 1) / objects[i].mass;
        objects[i].vy = (rand() % 10 + 1) / objects[i].mass;
    }

    simulate(objects, num_objects, 1000);

    for (int i = 0; i < num_objects; i++) {
        printf("Object %d\n", i);
        printf("Mass: %f\n", objects[i].mass);
        printf("Position: (%f, %f)\n", objects[i].x, objects[i].y);
        printf("Velocity: (%f, %f)\n", objects[i].vx, objects[i].vy);
    }

    free(objects);
    return 0;
}