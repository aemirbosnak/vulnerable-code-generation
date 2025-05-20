//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN_RADIUS 100
#define MIN_TURN_RADIUS 1
#define MAX_ACCELERATION 2
#define MIN_ACCELERATION 0.1
#define MIN_DELAY 10

typedef struct {
    double speed;
    double turn_radius;
    double acceleration;
} Vehicle;

Vehicle *create_vehicle() {
    Vehicle *v = malloc(sizeof(Vehicle));
    v->speed = rand() % MAX_SPEED + MIN_SPEED;
    v->turn_radius = rand() % MAX_TURN_RADIUS + MIN_TURN_RADIUS;
    v->acceleration = rand() % MAX_ACCELERATION + MIN_ACCELERATION;
    return v;
}

void simulate_vehicle(Vehicle *v, int delay) {
    srand(time(NULL));
    int direction = rand() % 2;
    int turn_direction = rand() % 2;
    int speed_change = rand() % 2;
    int turn_radius_change = rand() % 2;
    int acceleration_change = rand() % 2;

    if (speed_change) {
        v->speed += rand() % MAX_SPEED - MIN_SPEED;
    }

    if (turn_radius_change) {
        v->turn_radius += rand() % MAX_TURN_RADIUS - MIN_TURN_RADIUS;
    }

    if (acceleration_change) {
        v->acceleration += rand() % MAX_ACCELERATION - MIN_ACCELERATION;
    }

    if (direction) {
        v->speed = -v->speed;
    }

    if (turn_direction) {
        v->turn_radius = -v->turn_radius;
    }

    printf("Vehicle speed: %.2f\n", v->speed);
    printf("Vehicle turn radius: %.2f\n", v->turn_radius);
    printf("Vehicle acceleration: %.2f\n", v->acceleration);

    if (delay > MIN_DELAY) {
        sleep(delay);
    }
}

int main() {
    Vehicle *v = create_vehicle();
    int delay = rand() % 1000 + MIN_DELAY;

    simulate_vehicle(v, delay);

    free(v);
    return 0;
}