//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    void (*function)(void);
} command_t;

void takeoff(void) {
    printf("Drone taking off...\n");
}

void land(void) {
    printf("Drone landing...\n");
}

void forward(int speed) {
    printf("Drone moving forward at %d m/s...\n", speed);
}

void backward(int speed) {
    printf("Drone moving backward at %d m/s...\n", speed);
}

void left(int speed) {
    printf("Drone moving left at %d m/s...\n", speed);
}

void right(int speed) {
    printf("Drone moving right at %d m/s...\n", speed);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"takeoff", takeoff},
        {"land", land},
        {"forward", forward},
        {"backward", backward},
        {"left", left},
        {"right", right}
    };

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    tolower(command[0]);

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            break;
        }
    }

    if (i == MAX_COMMANDS) {
        printf("Invalid command.\n");
    }

    return 0;
}