//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *command;
    void (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on lights...\n");
}

void turn_off_lights(void) {
    printf("Turning off lights...\n");
}

void set_light_brightness(int brightness) {
    printf("Setting light brightness to %d...\n", brightness);
}

void set_light_color(char *color) {
    printf("Setting light color to %s...\n", color);
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands].command = "on";
    commands[num_commands].function = turn_on_lights;
    num_commands++;

    commands[num_commands].command = "off";
    commands[num_commands].function = turn_off_lights;
    num_commands++;

    commands[num_commands].command = "brightness";
    commands[num_commands].function = set_light_brightness;
    num_commands++;

    commands[num_commands].command = "color";
    commands[num_commands].function = set_light_color;
    num_commands++;

    if (argc < 2) {
        printf("Usage: %s <command> [args]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    if (strlen(command) > MAX_COMMAND_LENGTH) {
        printf("Command too long.\n");
        return 1;
    }

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command.\n");
    return 1;
}