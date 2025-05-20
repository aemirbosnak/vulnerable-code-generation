//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 80
#define NUM_COMMANDS 6

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

void forward(int distance) {
    printf("Moving forward %d meters...\n", distance);
}

void backward(int distance) {
    printf("Moving backward %d meters...\n", distance);
}

void left(int distance) {
    printf("Moving left %d meters...\n", distance);
}

void right(int distance) {
    printf("Moving right %d meters...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    command_t commands[] = {
        {"takeoff", takeoff},
        {"land", land},
        {"forward", forward},
        {"backward", backward},
        {"left", left},
        {"right", right}
    };

    int i;
    for (i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}