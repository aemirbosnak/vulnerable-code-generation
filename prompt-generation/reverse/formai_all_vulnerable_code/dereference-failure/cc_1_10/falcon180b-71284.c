//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **split_command(char *command);
int execute_command(char **arguments);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input_buffer);
        if (arguments == NULL) {
            printf("Invalid command.\n");
            continue;
        }

        int status = execute_command(arguments);
        if (status == 0) {
            printf("Command executed successfully.\n");
        } else {
            printf("Command failed with status %d.\n", status);
        }

        for (int i = 0; arguments[i]!= NULL; i++) {
            free(arguments[i]);
        }
        free(arguments);
    }

    return 0;
}

char **split_command(char *command) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argument_count = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        arguments[argument_count] = strdup(token);
        argument_count++;

        if (argument_count >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            for (int i = 0; i < argument_count; i++) {
                free(arguments[i]);
            }
            free(arguments);
            return NULL;
        }

        token = strtok(NULL, " ");
    }

    arguments[argument_count] = NULL;
    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        printf("No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Exec failed.\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}