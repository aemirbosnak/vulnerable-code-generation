//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMAND_ARGUMENTS 10

typedef struct {
    char *name;
    void (*function)(char **arguments);
} command_t;

void turn_on_light(char **arguments) {
    printf("Turning on the light\n");
}

void turn_off_light(char **arguments) {
    printf("Turning off the light\n");
}

void set_light_brightness(char **arguments) {
    int brightness;

    if (sscanf(arguments[1], "%d", &brightness)!= 1 || brightness < 0 || brightness > 100) {
        printf("Invalid brightness level\n");
        return;
    }

    printf("Setting light brightness to %d%%\n", brightness);
}

command_t commands[] = {
    {"turn_on_light", turn_on_light},
    {"turn_off_light", turn_off_light},
    {"set_light_brightness", set_light_brightness}
};

int num_commands = sizeof(commands) / sizeof(commands[0]);

void execute_command(char *input) {
    char *command_name = strtok(input, " ");
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            char **arguments = malloc(MAX_COMMAND_ARGUMENTS * sizeof(char *));
            int num_arguments = 0;

            char *token = strtok(NULL, " ");
            while (token!= NULL && num_arguments < MAX_COMMAND_ARGUMENTS) {
                arguments[num_arguments] = strdup(token);
                num_arguments++;
                token = strtok(NULL, " ");
            }

            commands[i].function(arguments);
            free(arguments);

            return;
        }
    }

    printf("Invalid command\n");
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        execute_command(input);
    }

    return 0;
}