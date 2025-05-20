//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);
    int count = 0;

    while (token!= NULL) {
        tokens[count] = malloc(sizeof(char) * strlen(token) + 1);
        strcpy(tokens[count], token);
        token = strtok(NULL, DELIM);
        count++;
    }

    tokens[count] = NULL;
    return tokens;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Artistic Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "help") == 0) {
            printf("Available commands:\n");
            printf("  exit\n");
            printf("  help\n");
        } else {
            printf("Command not found.\n");
        }

        for (int i = 0; args[i]!= NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    return 0;
}