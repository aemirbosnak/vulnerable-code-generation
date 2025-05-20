//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    Vector acceleration;
} Drone;

Drone* drone_create(double x, double y, double z) {
    Drone* d = malloc(sizeof(Drone));
    d->position.x = x;
    d->position.y = y;
    d->position.z = z;
    d->velocity.x = 0;
    d->velocity.y = 0;
    d->velocity.z = 0;
    d->acceleration.x = 0;
    d->acceleration.y = 0;
    d->acceleration.z = 0;
    return d;
}

void drone_move(Drone* d, double dx, double dy, double dz) {
    d->velocity.x += dx;
    d->velocity.y += dy;
    d->velocity.z += dz;
}

void drone_accelerate(Drone* d, double ax, double ay, double az) {
    d->acceleration.x += ax;
    d->acceleration.y += ay;
    d->acceleration.z += az;
}

void drone_update(Drone* d, double dt) {
    d->position.x += d->velocity.x * dt;
    d->position.y += d->velocity.y * dt;
    d->position.z += d->velocity.z * dt;
    d->velocity.x += d->acceleration.x * dt;
    d->velocity.y += d->acceleration.y * dt;
    d->velocity.z += d->acceleration.z * dt;
}

void drone_print(Drone* d) {
    printf("Position: (%lf, %lf, %lf)\n", d->position.x, d->position.y, d->position.z);
    printf("Velocity: (%lf, %lf, %lf)\n", d->velocity.x, d->velocity.y, d->velocity.z);
    printf("Acceleration: (%lf, %lf, %lf)\n", d->acceleration.x, d->acceleration.y, d->acceleration.z);
}

int main() {
    Drone* d = drone_create(0, 0, 0);
    drone_move(d, 1, 2, 3);
    drone_accelerate(d, 4, 5, 6);
    drone_update(d, 0.1);
    drone_print(d);
    return 0;
}