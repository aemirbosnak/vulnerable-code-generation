//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char *command;
    void (*function)();
} command_t;

void turn_on_lights() {
    printf("Turning on the lights\n");
}

void turn_off_lights() {
    printf("Turning off the lights\n");
}

void lock_door() {
    printf("Locking the door\n");
}

void unlock_door() {
    printf("Unlocking the door\n");
}

int main() {
    command_t commands[MAX_COMMANDS] = {{"turn on lights", turn_on_lights},
                                         {"turn off lights", turn_off_lights},
                                         {"lock door", lock_door},
                                         {"unlock door", unlock_door}};

    int num_commands = 0;

    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        printf("Enter a command: ");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].command) == 0) {
                commands[i].function();
            }
        }

        if (num_commands < MAX_COMMANDS) {
            printf("Enter a new command and its corresponding function (in the format 'command function'):\n");
            char new_command[MAX_COMMAND_LENGTH];
            fgets(new_command, MAX_COMMAND_LENGTH, stdin);

            input[strcspn(input, "\n")] = '\0';

            strcpy(commands[num_commands].command, new_command);
            commands[num_commands].function = (void (*)(void))atoi(input);

            num_commands++;
        }
    }

    return 0;
}