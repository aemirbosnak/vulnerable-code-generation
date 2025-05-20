//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    if (command == NULL || strlen(command) == 0) {
        return argv;
    }

    argv = malloc((argc + 1) * sizeof(char *));
    if (argv == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed.\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: Execvp failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;

    fprintf(stdout, "Ken Thompson Shell\n");
    fprintf(stdout, "Type 'exit' to quit.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        argv = split_command(input);
        if (strcmp(argv[0], "exit") == 0) {
            break;
        }

        pid = launch_shell(argv);
        if (pid == -1) {
            continue;
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}