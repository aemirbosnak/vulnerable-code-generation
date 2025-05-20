//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

struct command {
    char *name;
    void (*function)(void);
};

void turn_on_lights(void) {
    printf("Turning on the lights\n");
}

void turn_off_lights(void) {
    printf("Turning off the lights\n");
}

void open_door(void) {
    printf("Opening the door\n");
}

void close_door(void) {
    printf("Closing the door\n");
}

void set_temperature(int temp) {
    printf("Setting temperature to %d\n", temp);
}

int main(int argc, char **argv) {
    struct command commands[MAX_COMMANDS];
    int num_commands = 0;

    // Add commands
    commands[num_commands++] = (struct command) {.name = "turn_on_lights",.function = turn_on_lights };
    commands[num_commands++] = (struct command) {.name = "turn_off_lights",.function = turn_off_lights };
    commands[num_commands++] = (struct command) {.name = "open_door",.function = open_door };
    commands[num_commands++] = (struct command) {.name = "close_door",.function = close_door };
    commands[num_commands++] = (struct command) {.name = "set_temperature",.function = set_temperature };

    // Example usage
    char *input = "set_temperature 72";
    char *command_name = strtok(input, " ");
    int i;
    for (i = 0; i < num_commands; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            commands[i].function();
            break;
        }
    }

    return 0;
}