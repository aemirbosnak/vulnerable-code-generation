//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *command;
    void (*function)(void);
} Command;

void fly(void) {
    printf("Flying...\n");
}

void land(void) {
    printf("Landing...\n");
}

void left(void) {
    printf("Turning left...\n");
}

void right(void) {
    printf("Turning right...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int command_length = strlen(command);

    if (command_length > MAX_COMMAND_LENGTH) {
        printf("Command too long.\n");
        return 1;
    }

    Command commands[MAX_COMMANDS] = {{"fly", fly}, {"land", land}, {"left", left}, {"right", right}};
    int num_commands = sizeof(commands) / sizeof(Command);

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Unknown command: %s\n", command);
    return 1;
}