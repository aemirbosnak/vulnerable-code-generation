//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 80
#define NUM_COMMANDS 10

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void move_forward(void) {
    printf("Drone is moving forward\n");
}

void move_backward(void) {
    printf("Drone is moving backward\n");
}

void turn_left(void) {
    printf("Drone is turning left\n");
}

void turn_right(void) {
    printf("Drone is turning right\n");
}

void takeoff(void) {
    printf("Drone is taking off\n");
}

void land(void) {
    printf("Drone is landing\n");
}

void emergency_stop(void) {
    printf("Drone is stopping immediately\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    command_t commands[NUM_COMMANDS] = {
        {"move_forward", move_forward},
        {"move_backward", move_backward},
        {"turn_left", turn_left},
        {"turn_right", turn_right},
        {"takeoff", takeoff},
        {"land", land},
        {"emergency_stop", emergency_stop}
    };

    char command_name[MAX_COMMAND_LENGTH];
    strcpy(command_name, argv[1]);
    tolower(command_name);

    int i;
    for (i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            commands[i].function();
            break;
        }
    }

    if (i == NUM_COMMANDS) {
        printf("Invalid command\n");
    }

    return 0;
}