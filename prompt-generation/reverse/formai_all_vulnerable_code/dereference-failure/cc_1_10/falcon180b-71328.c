//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly_forward(void) {
    printf("Flying forward...\n");
}

void fly_backward(void) {
    printf("Flying backward...\n");
}

void fly_left(void) {
    printf("Flying left...\n");
}

void fly_right(void) {
    printf("Flying right...\n");
}

void take_off(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s COMMAND [ARGUMENTS]\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"forward", fly_forward},
        {"backward", fly_backward},
        {"left", fly_left},
        {"right", fly_right},
        {"takeoff", take_off},
        {"land", land},
    };

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(argv[1], commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", argv[1]);
    return 1;
}