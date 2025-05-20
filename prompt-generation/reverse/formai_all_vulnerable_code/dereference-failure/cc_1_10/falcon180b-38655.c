//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 100

struct command {
    char *name;
    void (*func)(void);
};

void turn_on_light(void) {
    printf("Turning on the light.\n");
}

void turn_off_light(void) {
    printf("Turning off the light.\n");
}

void set_light_brightness(int level) {
    printf("Setting the light brightness to %d.\n", level);
}

struct command commands[MAX_COMMANDS] = {
    {"turn_on_light", turn_on_light},
    {"turn_off_light", turn_off_light},
    {"set_light_brightness", set_light_brightness}
};

int num_commands = sizeof(commands) / sizeof(commands[0]);

void execute_command(char *input) {
    int i;
    char *token;

    token = strtok(input, " ");
    if (token == NULL) {
        printf("Invalid command.\n");
        return;
    }

    for (i = 0; i < num_commands; i++) {
        if (strcmp(token, commands[i].name) == 0) {
            commands[i].func();
            return;
        }
    }

    printf("Invalid command.\n");
}

int main(void) {
    char input[1024];

    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        execute_command(input);
    }

    return 0;
}