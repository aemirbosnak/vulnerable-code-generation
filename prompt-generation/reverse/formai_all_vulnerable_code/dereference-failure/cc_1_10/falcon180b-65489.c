//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: imaginative
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
    printf("Turning on the lights!\n");
}

void turn_off_lights(void) {
    printf("Turning off the lights!\n");
}

void set_light_color(char *color) {
    printf("Setting light color to %s...\n", color);
}

void set_light_brightness(int brightness) {
    printf("Setting light brightness to %d...\n", brightness);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [parameters]\n", argv[0]);
        return 1;
    }

    command_t commands[MAX_COMMANDS] = {
        {"turn_on_lights", turn_on_lights},
        {"turn_off_lights", turn_off_lights},
        {"set_light_color", set_light_color},
        {"set_light_brightness", set_light_brightness}
    };

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);
    tolower(command);

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", argv[1]);
    return 1;
}