//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MAX_STEERING_ANGLE 60

struct Vehicle {
    int speed;
    int steering_angle;
};

void print_vehicle_status(struct Vehicle *vehicle) {
    printf("Speed: %d\n", vehicle->speed);
    printf("Steering Angle: %d\n", vehicle->steering_angle);
}

void accelerate(struct Vehicle *vehicle, int speed_increase) {
    if (vehicle->speed + speed_increase <= MAX_SPEED) {
        vehicle->speed += speed_increase;
    } else {
        vehicle->speed = MAX_SPEED;
    }
}

void decelerate(struct Vehicle *vehicle, int speed_decrease) {
    if (vehicle->speed - speed_decrease >= 0) {
        vehicle->speed -= speed_decrease;
    } else {
        vehicle->speed = 0;
    }
}

void steer_left(struct Vehicle *vehicle, int angle_increase) {
    if (vehicle->steering_angle + angle_increase <= MAX_STEERING_ANGLE) {
        vehicle->steering_angle += angle_increase;
    } else {
        vehicle->steering_angle = MAX_STEERING_ANGLE;
    }
}

void steer_right(struct Vehicle *vehicle, int angle_decrease) {
    if (vehicle->steering_angle - angle_decrease >= -MAX_STEERING_ANGLE) {
        vehicle->steering_angle -= angle_decrease;
    } else {
        vehicle->steering_angle = -MAX_STEERING_ANGLE;
    }
}

int main() {
    struct Vehicle *car = malloc(sizeof(struct Vehicle));
    car->speed = 0;
    car->steering_angle = 0;

    printf("Initial vehicle status:\n");
    print_vehicle_status(car);

    accelerate(car, 50);
    printf("\nAfter accelerating 50:\n");
    print_vehicle_status(car);

    decelerate(car, 30);
    printf("\nAfter decelerating 30:\n");
    print_vehicle_status(car);

    steer_left(car, 20);
    printf("\nAfter steering left 20:\n");
    print_vehicle_status(car);

    steer_right(car, 40);
    printf("\nAfter steering right 40:\n");
    print_vehicle_status(car);

    free(car);
    return 0;
}