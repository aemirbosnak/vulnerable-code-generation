//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 100
#define MAX_ARG_LENGTH 100

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
    bool is_executed;
} Command;

int num_commands = 0;
Command *commands = NULL;

void add_command(char *command, int num_arguments, char **arguments) {
    Command *new_command = (Command *)malloc(sizeof(Command));
    new_command->command = command;
    new_command->arguments = arguments;
    new_command->num_arguments = num_arguments;
    new_command->is_executed = false;
    commands = (Command *)realloc(commands, sizeof(Command) * ++num_commands);
    commands[num_commands - 1] = *new_command;
}

void execute_command(char *command) {
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(commands[i].command, command) == 0) {
            for (int j = 0; j < commands[i].num_arguments; j++) {
                printf("%s ", commands[i].arguments[j]);
            }
            printf("\n");
            commands[i].is_executed = true;
            break;
        }
    }
}

int main() {
    add_command("ls", 0, NULL);
    add_command("echo", 1, (char **)malloc(sizeof(char *) * 2));
    strcpy(commands[1].arguments[0], "Hello World!");
    add_command("mkdir", 1, (char **)malloc(sizeof(char *) * 2));
    strcpy(commands[2].arguments[0], "test_folder");
    execute_command("ls");
    execute_command("echo");
    execute_command("mkdir");
    return 0;
}