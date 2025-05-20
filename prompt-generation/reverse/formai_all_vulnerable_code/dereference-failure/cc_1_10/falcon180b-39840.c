//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_COMMANDS 1000
#define MAX_ARGUMENTS 100
#define MAX_ARG_LENGTH 100

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

int num_commands = 0;
Command *commands = NULL;

void add_command(char *command, int num_arguments, char **arguments) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: too many commands\n");
        exit(1);
    }

    Command *new_command = malloc(sizeof(Command));
    if (new_command == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }

    new_command->command = strdup(command);
    new_command->num_arguments = num_arguments;
    new_command->arguments = malloc(sizeof(char *) * num_arguments);

    for (int i = 0; i < num_arguments; i++) {
        new_command->arguments[i] = strdup(arguments[i]);
    }

    commands = realloc(commands, sizeof(Command) * (num_commands + 1));
    commands[num_commands] = *new_command;
    num_commands++;
}

void execute_command(char *command) {
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            for (int j = 0; j < commands[i].num_arguments; j++) {
                printf("%s ", commands[i].arguments[j]);
            }
            printf("\n");
            return;
        }
    }

    printf("Command not found\n");
}

int main() {
    add_command("echo", 1, (char **) {"Hello, world!"});
    add_command("ls", 0, NULL);
    add_command("mkdir", 1, (char **) {"test"});

    char input[MAX_ARG_LENGTH];
    while (fgets(input, MAX_ARG_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        execute_command(input);
    }

    return 0;
}