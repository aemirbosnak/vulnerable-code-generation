//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20
#define MAX_ROOMS 10
#define MAX_ROOM_LENGTH 20

typedef struct {
    char *name;
    int (*func)(int argc, char **argv);
} command_t;

int turn_on_light(int argc, char **argv) {
    printf("Turning on the light\n");
    return 0;
}

int turn_off_light(int argc, char **argv) {
    printf("Turning off the light\n");
    return 0;
}

int change_room(int argc, char **argv) {
    printf("Changing to room %s\n", argv[1]);
    return 0;
}

command_t commands[MAX_COMMANDS] = {
    {"turn_on_light", turn_on_light},
    {"turn_off_light", turn_off_light},
    {"change_room", change_room}
};

int num_commands = 3;

void execute_command(char *command) {
    char *token = strtok(command, " ");
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(token, commands[i].name) == 0) {
            commands[i].func(0, NULL);
            return;
        }
    }

    printf("Invalid command\n");
}

int main() {
    char *command;

    while (1) {
        printf("Enter a command: ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = '\0';
        execute_command(command);
    }

    return 0;
}