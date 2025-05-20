//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split(char *str, char delimiter);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    while (TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input, DELIM);

        if (args[0] == NULL) {
            continue;
        }

        status = execute_command(args);

        if (status == 0) {
            printf("\n");
        }
    }

    return 0;
}

char **split(char *str, char delimiter) {
    char *token;
    int count = 0;
    char **result = NULL;

    token = strtok(str, delimiter);
    while (token!= NULL) {
        count++;
        result = realloc(result, sizeof(char *) * count);
        result[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    result[count - 1] = NULL;
    return result;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
            return 1;
        }

        if (chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }

        return 0;
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                return WEXITSTATUS(status);
            } else {
                return 1;
            }
        }
    }
}