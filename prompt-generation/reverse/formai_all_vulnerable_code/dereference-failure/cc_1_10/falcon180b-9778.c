//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void fly(void) {
    printf("Drone is flying...\n");
}

void land(void) {
    printf("Drone is landing...\n");
}

void takeoff(void) {
    printf("Drone is taking off...\n");
}

void turn_left(void) {
    printf("Drone is turning left...\n");
}

void turn_right(void) {
    printf("Drone is turning right...\n");
}

void move_forward(void) {
    printf("Drone is moving forward...\n");
}

void move_backward(void) {
    printf("Drone is moving backward...\n");
}

void rotate_clockwise(void) {
    printf("Drone is rotating clockwise...\n");
}

void rotate_counterclockwise(void) {
    printf("Drone is rotating counterclockwise...\n");
}

command_t commands[] = {
    {"fly", fly},
    {"land", land},
    {"takeoff", takeoff},
    {"turn left", turn_left},
    {"turn right", turn_right},
    {"move forward", move_forward},
    {"move backward", move_backward},
    {"rotate clockwise", rotate_clockwise},
    {"rotate counterclockwise", rotate_counterclockwise}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int i;

    for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        if (strcmp(command, commands[i].name) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}