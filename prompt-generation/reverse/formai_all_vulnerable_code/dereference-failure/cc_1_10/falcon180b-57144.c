//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int (*function)(void);
} command_t;

void turn_on_light(void) {
    printf("Turning on the light.\n");
}

void turn_off_light(void) {
    printf("Turning off the light.\n");
}

void set_light_brightness(int brightness) {
    printf("Setting light brightness to %d.\n", brightness);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    command_t commands[MAX_COMMANDS] = {
        {"turn_on", &turn_on_light},
        {"turn_off", &turn_off_light},
        {"set_brightness", &set_light_brightness}
    };

    int i;
    for (i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command, commands[i].command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command.\n");
    return 1;
}