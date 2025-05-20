//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_PARAMS 10

typedef struct {
    char *command;
    void (*function)(char **);
} Command;

void turn_on_light(char **params) {
    printf("Turning on light\n");
}

void turn_off_light(char **params) {
    printf("Turning off light\n");
}

void set_temperature(char **params) {
    printf("Setting temperature to %s\n", params[0]);
}

Command commands[MAX_COMMANDS] = {
    {"turn_on_light", turn_on_light},
    {"turn_off_light", turn_off_light},
    {"set_temperature", set_temperature}
};

int main() {
    char input[100];
    char *token;
    int i;

    printf("Smart Home Automation System\n");
    printf("Enter 'help' for a list of commands\n");

    while(fgets(input, sizeof(input), stdin)) {
        token = strtok(input, " ");
        if(strcmp(token, "help") == 0) {
            printf("Available commands:\n");
            for(i = 0; i < MAX_COMMANDS; i++) {
                printf("%s\n", commands[i].command);
            }
        } else {
            for(i = 0; i < MAX_COMMANDS; i++) {
                if(strcmp(token, commands[i].command) == 0) {
                    if(commands[i].function!= NULL) {
                        commands[i].function(strtok(NULL, " "));
                    } else {
                        printf("Invalid command\n");
                    }
                    break;
                }
            }
        }
    }

    return 0;
}