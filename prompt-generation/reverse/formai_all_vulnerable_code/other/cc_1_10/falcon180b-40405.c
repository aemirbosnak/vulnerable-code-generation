//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 10
#define BUFFER_SIZE 100
#define PI 3.14159

typedef struct {
    char *command;
    int (*function)(void);
} Command;

void fly(void) {
    printf("The drone is flying!\n");
}

void land(void) {
    printf("The drone is landing.\n");
}

void takeoff(void) {
    printf("The drone is taking off.\n");
}

void move(int direction) {
    if (direction == 1) {
        printf("The drone is moving forward.\n");
    } else if (direction == -1) {
        printf("The drone is moving backward.\n");
    } else {
        printf("Invalid direction.\n");
    }
}

int main(void) {
    Command commands[MAX_COMMANDS];
    char buffer[BUFFER_SIZE];
    int num_commands = 0;

    commands[num_commands++] = (Command) {"fly", fly};
    commands[num_commands++] = (Command) {"land", land};
    commands[num_commands++] = (Command) {"takeoff", takeoff};
    commands[num_commands++] = (Command) {"move", move};

    printf("Welcome to the drone remote control!\n");
    while (1) {
        printf("Enter a command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        char *token = strtok(buffer, " ");

        if (token == NULL) {
            continue;
        }

        int i;
        for (i = 0; i < num_commands; i++) {
            if (strcmp(token, commands[i].command) == 0) {
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