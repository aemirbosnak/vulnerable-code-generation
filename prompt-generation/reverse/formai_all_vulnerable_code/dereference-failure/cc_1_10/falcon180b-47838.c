//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    char* command;
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
    printf("Turning left...\n");
}

void right() {
    printf("Turning right...\n");
}

void emergency_stop() {
    printf("Emergency stop...\n");
}

void execute_command(char* command) {
    if (strcmp(command, "takeoff") == 0) {
        takeoff();
    } else if (strcmp(command, "land") == 0) {
        land();
    } else if (strcmp(command, "forward") == 0) {
        forward();
    } else if (strcmp(command, "backward") == 0) {
        backward();
    } else if (strcmp(command, "left") == 0) {
        left();
    } else if (strcmp(command, "right") == 0) {
        right();
    } else if (strcmp(command, "emergency_stop") == 0) {
        emergency_stop();
    } else {
        printf("Invalid command...\n");
    }
}

int main() {
    int num_commands;
    printf("Enter number of commands: ");
    scanf("%d", &num_commands);

    command_t commands[num_commands];

    for (int i = 0; i < num_commands; i++) {
        printf("Enter command %d: ", i+1);
        char* command = (char*)malloc(MAX_COMMAND_LENGTH * sizeof(char));
        scanf("%s", command);
        strcpy(commands[i].command, command);
    }

    for (int i = 0; i < num_commands; i++) {
        printf("Executing command %d: %s\n", i+1, commands[i].command);
        execute_command(commands[i].command);
    }

    return 0;
}