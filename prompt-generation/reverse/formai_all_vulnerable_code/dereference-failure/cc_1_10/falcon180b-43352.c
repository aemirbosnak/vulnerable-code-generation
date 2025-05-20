//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int argc = 0;
    int len = strlen(string);
    char **argv = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        argv[argc] = strdup(token);
        argc++;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    arguments = split_string(input);

    if (argc == 1) {
        printf("No command entered.\n");
    } else {
        printf("Command entered: %s\n", arguments[0]);
        for (int i = 1; i < argc; i++) {
            printf("Argument %d: %s\n", i, arguments[i]);
        }
    }

    for (int i = 0; i < argc; i++) {
        free(arguments[i]);
    }
    free(arguments);

    return 0;
}