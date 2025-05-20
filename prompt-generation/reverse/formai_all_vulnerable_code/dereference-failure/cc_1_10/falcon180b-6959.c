//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100
#define MAX_DELAY_TIME 86400

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    time_t delay;
} Command;

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *token;
    time_t current_time, delay_time;
    int num_commands = 0;
    Command commands[MAX_COMMANDS];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Enter commands in the format 'command delay_time'\n");
    printf("Commands can be 'on', 'off', or 'dim [0-100]'.\n");
    printf("Delays are in seconds. Use 'now' for immediate execution.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        token = strtok(input, " ");
        strcpy(commands[num_commands].command, token);
        token = strtok(NULL, " ");

        if (strcmp(token, "now") == 0) {
            commands[num_commands].delay = 0;
        } else {
            commands[num_commands].delay = atoi(token);
        }

        num_commands++;

        if (num_commands >= MAX_COMMANDS) {
            printf("Maximum number of commands reached.\n");
            break;
        }
    }

    current_time = time(NULL);

    for (int i = 0; i < num_commands; i++) {
        delay_time = current_time + commands[i].delay;
        while (current_time < delay_time) {
            current_time = time(NULL);
        }

        if (strcmp(commands[i].command, "on") == 0) {
            printf("Turning lights on.\n");
        } else if (strcmp(commands[i].command, "off") == 0) {
            printf("Turning lights off.\n");
        } else if (strcmp(commands[i].command, "dim") == 0) {
            char *brightness_str = strtok(NULL, " ");
            int brightness = atoi(brightness_str);
            printf("Dimming lights to %d%% brightness.\n", brightness);
        }
    }

    return 0;
}