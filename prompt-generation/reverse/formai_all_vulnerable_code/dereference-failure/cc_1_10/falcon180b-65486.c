//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\n\r\a"

char **split_string(char *string, int *argc);

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    int argument_count;

    printf("Welcome to the Basic Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input, &argument_count);

        if (argument_count == 0) {
            continue;
        }

        if (strcmp(arguments[0], "exit") == 0) {
            break;
        } else if (strcmp(arguments[0], "cd") == 0) {
            if (chdir(arguments[1])!= 0) {
                perror("Error");
            }
        } else if (strcmp(arguments[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("Error");
            }
        } else {
            pid_t pid;
            int status;

            pid = fork();

            if (pid == -1) {
                perror("Error");
            } else if (pid == 0) {
                if (execvp(arguments[0], arguments) == -1) {
                    perror("Error");
                }
            } else {
                waitpid(pid, &status, 0);
            }
        }

        for (int i = 0; i < argument_count; i++) {
            free(arguments[i]);
        }
        free(arguments);
    }

    return 0;
}

char **split_string(char *string, int *argc) {
    char **arguments = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    int argument_count = 0;
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        arguments[argument_count] = strdup(token);
        argument_count++;

        if (argument_count >= MAX_ARGUMENTS) {
            break;
        }

        token = strtok(NULL, DELIM);
    }

    arguments[argument_count] = NULL;
    *argc = argument_count;

    return arguments;
}