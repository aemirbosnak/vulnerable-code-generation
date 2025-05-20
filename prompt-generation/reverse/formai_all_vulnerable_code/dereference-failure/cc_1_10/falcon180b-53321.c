//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *command;
    void (*function)();
} command_t;

void takeoff() {
    printf("Taking off...\n");
}

void land() {
    printf("Landing...\n");
}

void forward() {
    printf("Moving forward...\n");
}

void backward() {
    printf("Moving backward...\n");
}

void left() {
    printf("Moving left...\n");
}

void right() {
    printf("Moving right...\n");
}

void up() {
    printf("Moving up...\n");
}

void down() {
    printf("Moving down...\n");
}

int main() {
    command_t commands[MAX_COMMANDS] = {
        {"takeoff", &takeoff},
        {"land", &land},
        {"forward", &forward},
        {"backward", &backward},
        {"left", &left},
        {"right", &right},
        {"up", &up},
        {"down", &down}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, " ");
        int i;
        for (i = 0; i < num_commands; i++) {
            if (strcmp(command, commands[i].command) == 0) {
                commands[i].function();
                break;
            }
        }

        if (i == num_commands) {
            printf("Invalid command.\n");
        }
    }

    return 0;
}