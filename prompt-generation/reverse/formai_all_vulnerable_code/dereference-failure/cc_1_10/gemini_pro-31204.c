//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} Command;

void forward(void) {
    printf("Moving forward\n");
}

void backward(void) {
    printf("Moving backward\n");
}

void left(void) {
    printf("Turning left\n");
}

void right(void) {
    printf("Turning right\n");
}

void stop(void) {
    printf("Stopping\n");
}

Command commands[] = {
    {"forward", forward},
    {"backward", backward},
    {"left", left},
    {"right", right},
    {"stop", stop},
    {NULL, NULL}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *command = argv[1];

    for (int i = 0; commands[i].command != NULL; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return EXIT_SUCCESS;
        }
    }

    printf("Invalid command: %s\n", command);
    return EXIT_FAILURE;
}