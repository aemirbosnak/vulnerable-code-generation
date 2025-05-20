//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100 // Maximum length of a command
#define NUM_COMMANDS 5 // Number of commands the drone can execute

typedef struct {
    char *command; // The command string
    void (*function)(void); // Pointer to the function that executes the command
} command_t;

void takeoff(void) {
    printf("Drone takes off\n");
}

void land(void) {
    printf("Drone lands\n");
}

void move_forward(void) {
    printf("Drone moves forward\n");
}

void turn_left(void) {
    printf("Drone turns left\n");
}

void turn_right(void) {
    printf("Drone turns right\n");
}

int main(void) {
    command_t commands[NUM_COMMANDS] = {
        {"takeoff", &takeoff},
        {"land", &land},
        {"move_forward", &move_forward},
        {"turn_left", &turn_left},
        {"turn_right", &turn_right}
    };

    char input_buffer[MAX_COMMAND_LENGTH];
    char *command_name;
    int command_index;

    printf("Sherlock Holmes' Drone Remote Control\n");
    printf("Enter 'help' for a list of commands\n");

    while (1) {
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        command_name = strtok(input_buffer, " ");

        if (strcmp(command_name, "help") == 0) {
            printf("Available commands:\n");
            for (int i = 0; i < NUM_COMMANDS; i++) {
                printf("%s\n", commands[i].command);
            }
        } else if (strcmp(command_name, "quit") == 0) {
            break;
        } else {
            command_index = -1;

            for (int i = 0; i < NUM_COMMANDS; i++) {
                if (strcmp(command_name, commands[i].command) == 0) {
                    command_index = i;
                    break;
                }
            }

            if (command_index >= 0) {
                commands[command_index].function();
            } else {
                printf("Invalid command\n");
            }
        }
    }

    return 0;
}