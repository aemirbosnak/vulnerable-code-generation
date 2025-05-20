//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string, int *argc);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int argc, status;

    printf("Unix Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        args = split_string(input, &argc);

        if (argc == 0) {
            continue;
        }

        status = execute_command(args);

        if (WIFEXITED(status)) {
            printf("Exit status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}

char **split_string(char *string, int *argc) {
    char **args;
    int i, j;

    args = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));

    i = 0;
    args[i] = strtok(string, DELIM);

    while (args[i]!= NULL && i < MAX_ARGUMENTS) {
        i++;
        args[i] = strtok(NULL, DELIM);
    }

    args[i] = NULL;
    *argc = i;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL || strcmp(args[0], "") == 0) {
        fprintf(stderr, "Error: Command not found\n");
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Failed to fork\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Failed to execute command\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}