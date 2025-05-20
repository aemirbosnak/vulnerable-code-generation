//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *command;
    void (*handler)(void);
} command_t;

void turn_on_light(void) {
    printf("Turning on the light...\n");
}

void turn_off_light(void) {
    printf("Turning off the light...\n");
}

void toggle_light(void) {
    printf("Toggling the light...\n");
}

void set_light_brightness(int brightness) {
    printf("Setting light brightness to %d...\n", brightness);
}

void set_light_color(char *color) {
    printf("Setting light color to %s...\n", color);
}

int main(void) {
    command_t commands[] = {
        {"on", turn_on_light},
        {"off", turn_off_light},
        {"toggle", toggle_light},
        {"brightness", set_light_brightness},
        {"color", set_light_color}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    char input[MAX_COMMAND_LENGTH];
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        char *command = strtok(input, " ");
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(command, commands[i].command) == 0) {
                commands[i].handler();
                break;
            }
        }
    }

    return 0;
}