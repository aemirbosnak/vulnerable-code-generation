//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char *copy = strdup(str);

    for (token = strtok(copy, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        words++;
    }

    tokens = malloc((words + 1) * sizeof(char *));

    for (token = strtok(copy, DELIM); token!= NULL; token = strtok(NULL, DELIM)) {
        tokens[bufsize++] = strdup(token);
    }

    tokens[bufsize] = NULL;

    return tokens;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Ada Lovelace Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;

        printf("Invalid command: %s\n", args[0]);
    }

    return 0;
}