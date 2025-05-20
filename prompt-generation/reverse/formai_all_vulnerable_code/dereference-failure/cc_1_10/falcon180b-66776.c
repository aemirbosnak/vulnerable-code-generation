//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 50

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void fly_forward(void) {
    printf("Drone flying forward\n");
}

void fly_backward(void) {
    printf("Drone flying backward\n");
}

void fly_left(void) {
    printf("Drone flying left\n");
}

void fly_right(void) {
    printf("Drone flying right\n");
}

void take_off(void) {
    printf("Drone taking off\n");
}

void land(void) {
    printf("Drone landing\n");
}

void emergency_stop(void) {
    printf("Emergency stop\n");
}

void initialize_commands(command_t commands[MAX_COMMANDS]) {
    int i = 0;

    strcpy(commands[i].command, "forward");
    commands[i++].function = fly_forward;

    strcpy(commands[i].command, "backward");
    commands[i++].function = fly_backward;

    strcpy(commands[i].command, "left");
    commands[i++].function = fly_left;

    strcpy(commands[i].command, "right");
    commands[i++].function = fly_right;

    strcpy(commands[i].command, "takeoff");
    commands[i++].function = take_off;

    strcpy(commands[i].command, "land");
    commands[i++].function = land;

    strcpy(commands[i].command, "stop");
    commands[i++].function = emergency_stop;
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS];
    initialize_commands(commands);

    char input_buffer[MAX_COMMAND_LENGTH];
    printf("Enter commands (type 'help' for list of commands):\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        char *command = strtok(input_buffer, " ");

        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            for (int i = 0; i < MAX_COMMANDS; i++) {
                printf("%s\n", commands[i].command);
            }
        } else {
            for (int i = 0; i < MAX_COMMANDS; i++) {
                if (strcmp(command, commands[i].command) == 0) {
                    commands[i].function();
                    break;
                }
            }
        }
    }

    return 0;
}