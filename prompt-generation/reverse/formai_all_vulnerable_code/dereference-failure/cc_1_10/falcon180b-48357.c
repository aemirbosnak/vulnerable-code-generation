//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    if (argv == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(str, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: too many arguments.\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Funny Shell!\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input);
        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;
        else if (strcmp(args[0], "help") == 0) {
            printf("Available commands:\n");
            printf("  exit - Exit the shell\n");
            printf("  help - Display this help message\n");
        } else {
            printf("Command not found: %s\n", args[0]);
        }
    }

    return 0;
}