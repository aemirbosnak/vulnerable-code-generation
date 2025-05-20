//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (isspace(*str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));

    str = strtok_r(str, DELIM, &token);
    while (str) {
        tokens[i] = strdup(str);
        i++;
        str = strtok_r(NULL, DELIM, &token);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }

    return pid;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t shell_pid;

    printf("Welcome to the surrealist shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        shell_pid = launch_shell(args);

        if (shell_pid == -1) {
            fprintf(stderr, "Error launching shell.\n");
        }

        waitpid(shell_pid, NULL, 0);
    }

    return 0;
}