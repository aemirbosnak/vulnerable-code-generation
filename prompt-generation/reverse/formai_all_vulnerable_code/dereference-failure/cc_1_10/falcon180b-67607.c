//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: medieval
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

void turn_on_light(void) {
    printf("Thou hast commanded me to turn on the light.\n");
}

void turn_off_light(void) {
    printf("Thou hast commanded me to turn off the light.\n");
}

void set_light_brightness(int brightness) {
    printf("Thou hast commanded me to set the light brightness to %d.\n", brightness);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    tolower(command);

    command_t commands[MAX_COMMANDS] = {
        {"turn on light", turn_on_light},
        {"turn off light", turn_off_light},
        {"set light brightness", set_light_brightness}
    };

    int num_commands = 0;
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            commands[i].function();
            return 0;
        }
    }

    printf("Invalid command: %s\n", command);
    return 1;
}