//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

void move_forward(void) {
    printf("Moving forward...\n");
}

void move_backward(void) {
    printf("Moving backward...\n");
}

void move_left(void) {
    printf("Moving left...\n");
}

void move_right(void) {
    printf("Moving right...\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    command_t commands[] = {{"takeoff", takeoff}, {"land", land}, {"forward", move_forward}, {"backward", move_backward}, {"left", move_left}, {"right", move_right}};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char *command_name = argv[1];
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command_name);
    return 1;
}