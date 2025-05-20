//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SPEED 10
#define MAX_ANGLE 90

typedef struct {
    int speed;
    int angle;
} rc_vehicle;

void print_vehicle(rc_vehicle v) {
    printf("Speed: %d\n", v.speed);
    printf("Angle: %d\n", v.angle);
}

bool is_valid_speed(int speed) {
    return speed >= 0 && speed <= MAX_SPEED;
}

bool is_valid_angle(int angle) {
    return angle >= 0 && angle <= MAX_ANGLE;
}

void set_speed(rc_vehicle* v, int speed) {
    if (is_valid_speed(speed)) {
        v->speed = speed;
    } else {
        printf("Error: Invalid speed value\n");
    }
}

void set_angle(rc_vehicle* v, int angle) {
    if (is_valid_angle(angle)) {
        v->angle = angle;
    } else {
        printf("Error: Invalid angle value\n");
    }
}

int main() {
    rc_vehicle my_vehicle;
    my_vehicle.speed = 0;
    my_vehicle.angle = 0;

    char input[100];
    char* token;
    int value;

    while (true) {
        printf("Enter command: ");
        fgets(input, 100, stdin);

        token = strtok(input, " ");
        if (strcmp(token, "speed") == 0) {
            token = strtok(NULL, " ");
            value = atoi(token);
            set_speed(&my_vehicle, value);
        } else if (strcmp(token, "angle") == 0) {
            token = strtok(NULL, " ");
            value = atoi(token);
            set_angle(&my_vehicle, value);
        } else if (strcmp(token, "status") == 0) {
            print_vehicle(my_vehicle);
        } else if (strcmp(token, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command\n");
        }
    }

    return 0;
}