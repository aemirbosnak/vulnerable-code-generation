//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>

#define PI 3.1415926535897932384626433832795
#define MAX_SPEED 100
#define MIN_SPEED 0
#define TICKS_PER_SEC 1000
#define MAX_ACCELERATION 10
#define MAX_DECELERATION 10

typedef struct {
    float x, y, z;
} point;

typedef struct {
    point pos;
    point vel;
    point accel;
} vehicle;

vehicle car;

void update_car_position(vehicle* car) {
    car->pos.x += car->vel.x * TICKS_PER_SEC;
    car->pos.y += car->vel.y * TICKS_PER_SEC;
    car->pos.z += car->vel.z * TICKS_PER_SEC;
}

void update_car_velocity(vehicle* car) {
    car->vel.x += car->accel.x * TICKS_PER_SEC;
    car->vel.y += car->accel.y * TICKS_PER_SEC;
    car->vel.z += car->accel.z * TICKS_PER_SEC;
}

void update_car_acceleration(vehicle* car) {
    car->accel.x += car->vel.x * MAX_ACCELERATION * TICKS_PER_SEC;
    car->accel.y += car->vel.y * MAX_ACCELERATION * TICKS_PER_SEC;
    car->accel.z += car->vel.z * MAX_ACCELERATION * TICKS_PER_SEC;
}

void simulate_car_movement(vehicle* car, float speed) {
    float dist = speed * TICKS_PER_SEC;
    float accel = dist / (2 * TICKS_PER_SEC);
    car->vel.x = speed;
    car->vel.y = speed;
    car->vel.z = speed;
    car->accel.x = accel;
    car->accel.y = accel;
    car->accel.z = accel;
    while (dist > 0) {
        update_car_position(car);
        update_car_velocity(car);
        update_car_acceleration(car);
        dist -= car->vel.x * TICKS_PER_SEC;
        dist -= car->vel.y * TICKS_PER_SEC;
        dist -= car->vel.z * TICKS_PER_SEC;
    }
}

int main() {
    srand(time(NULL));
    car.pos.x = 0;
    car.pos.y = 0;
    car.pos.z = 0;
    car.vel.x = 0;
    car.vel.y = 0;
    car.vel.z = 0;
    car.accel.x = 0;
    car.accel.y = 0;
    car.accel.z = 0;

    float speed = (rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED) / 10.0f;
    float acceleration = (rand() % (MAX_ACCELERATION - MAX_DECELERATION) + MAX_DECELERATION) / 10.0f;
    simulate_car_movement(&car, speed);
    printf("Car travelled %.2f km.\n", car.pos.x / 1000.0f);
    return 0;
}