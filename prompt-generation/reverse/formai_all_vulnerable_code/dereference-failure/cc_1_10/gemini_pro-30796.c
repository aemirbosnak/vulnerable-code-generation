//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SPEED 100
#define MAX_TURN_RATE 30

#define FORWARD 1
#define BACKWARD -1

typedef struct {
    int x;
    int y;
    int angle;
} Position;

typedef struct {
    int speed;
    int turn_rate;
} Controls;

void update_position(Position *position, Controls *controls) {
    position->x += controls->speed * cos(position->angle * M_PI / 180);
    position->y += controls->speed * sin(position->angle * M_PI / 180);
    position->angle += controls->turn_rate;
    if (position->angle >= 360) {
        position->angle -= 360;
    } else if (position->angle < 0) {
        position->angle += 360;
    }
}

void print_position(Position *position) {
    printf("X: %d, Y: %d, Angle: %d\n", position->x, position->y, position->angle);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <speed> <turn_rate>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int speed = atoi(argv[1]);
    int turn_rate = atoi(argv[2]);

    if (speed < 0 || speed > MAX_SPEED) {
        fprintf(stderr, "Invalid speed: %d\n", speed);
        return EXIT_FAILURE;
    }

    if (turn_rate < -MAX_TURN_RATE || turn_rate > MAX_TURN_RATE) {
        fprintf(stderr, "Invalid turn rate: %d\n", turn_rate);
        return EXIT_FAILURE;
    }

    Position position = {0, 0, 0};
    Controls controls = {speed, turn_rate};

    for (int i = 0; i < 100; i++) {
        update_position(&position, &controls);
        print_position(&position);
    }

    return EXIT_SUCCESS;
}