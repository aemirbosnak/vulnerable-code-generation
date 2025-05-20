//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void move_forward(void) {
    printf("Drone moving forward\n");
}

void move_backward(void) {
    printf("Drone moving backward\n");
}

void turn_left(void) {
    printf("Drone turning left\n");
}

void turn_right(void) {
    printf("Drone turning right\n");
}

void takeoff(void) {
    printf("Drone taking off\n");
}

void land(void) {
    printf("Drone landing\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    char *command = argv[1];

    command_t commands[MAX_COMMANDS] = {
        {"forward", move_forward},
        {"backward", move_backward},
        {"left", turn_left},
        {"right", turn_right},
        {"takeoff", takeoff},
        {"land", land}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    bool found_command = false;
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            found_command = true;
            break;
        }
    }

    if (!found_command) {
        printf("Invalid command\n");
    }

    return 0;
}