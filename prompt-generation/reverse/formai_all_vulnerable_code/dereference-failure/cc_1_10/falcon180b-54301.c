//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Funky Fresh Shell!\n");
    printf("Type 'help' for a list of commands.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);
        execute_command(args);
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "help") == 0) {
        printf("Available commands:\n");
        printf("  help\n");
        printf("  exit\n");
    } else {
        printf("Command not found.\n");
    }

    return 1;
}