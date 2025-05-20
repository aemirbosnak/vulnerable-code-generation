//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int (*function)(void);
} command_t;

void turn_on_lights(void) {
    printf("Turning on the lights for a romantic evening...\n");
}

void play_music(void) {
    printf("Playing some soft, romantic music...\n");
}

void set_mood_lighting(void) {
    printf("Setting the mood with some soft, warm lighting...\n");
}

void cook_dinner(void) {
    printf("Cooking a delicious, romantic dinner...\n");
}

int main(int argc, char *argv[]) {
    command_t commands[MAX_COMMANDS] = {
        {"turn on lights", turn_on_lights},
        {"play music", play_music},
        {"set mood lighting", set_mood_lighting},
        {"cook dinner", cook_dinner}
    };

    int num_commands = sizeof(commands) / sizeof(command_t);

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Enter 'help' for a list of commands.\n");

    while (1) {
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "help") == 0) {
            for (int i = 0; i < num_commands; i++) {
                printf("%s\n", commands[i].command);
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            for (int i = 0; i < num_commands; i++) {
                if (strcmp(input, commands[i].command) == 0) {
                    (*commands[i].function)();
                }
            }
        }
    }

    return 0;
}