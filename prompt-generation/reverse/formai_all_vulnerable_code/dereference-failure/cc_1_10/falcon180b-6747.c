//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    return tokens;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Welcome to the Basic Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);

        if (strcmp(arguments[0], "exit") == 0) {
            break;
        } else if (strcmp(arguments[0], "cd") == 0) {
            if (argc > 1) {
                chdir(arguments[1]);
            } else {
                printf("Error: Please provide a directory to change to.\n");
            }
        } else if (strcmp(arguments[0], "pwd") == 0) {
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            printf("%s\n", cwd);
        } else {
            printf("Error: Command not found.\n");
        }

        free(arguments);
    }

    return 0;
}