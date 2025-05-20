//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*string) {
        if (isspace(*string)) {
            *string++ = '\0';
        } else {
            bufsize++;
        }
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));

    string = strtok(string, DELIM);
    while (string!= NULL) {
        tokens[i++] = string;
        string = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "Launch failed: No command provided.\n");
        return -1;
    }

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error forking
        perror("fork");
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }

    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t shell_pid;

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        shell_pid = launch_shell(args);

        if (shell_pid == -1) {
            break;
        }
    }

    return 0;
}