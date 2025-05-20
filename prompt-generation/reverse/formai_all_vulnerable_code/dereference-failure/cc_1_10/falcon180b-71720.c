//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *name;
    void (*function)(void);
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void add_command(char *name, void (*function)(void)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        return;
    }

    commands[num_commands].name = strdup(name);
    commands[num_commands].function = function;

    num_commands++;
}

int execute_command(char *input) {
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            commands[i].function();
            return 1;
        }
    }

    return 0;
}

void fly_drone() {
    printf("Flying drone...\n");
}

void land_drone() {
    printf("Landing drone...\n");
}

void takeoff_drone() {
    printf("Taking off...\n");
}

int main() {
    add_command("fly", fly_drone);
    add_command("land", land_drone);
    add_command("takeoff", takeoff_drone);

    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (execute_command(input)) {
            printf("Command executed.\n");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}