//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command not found.\n");
            exit(1);
        }
    } else if (pid < 0) {
        printf("Fork failed.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted.\n");
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;
    int exit_shell = 0;

    signal(SIGINT, handle_signal);

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(args[0], "bg") == 0 && args[1]!= NULL) {
            background = 1;
        } else if (strcmp(args[0], "fg") == 0 && args[1]!= NULL) {
            background = 0;
        } else if (strcmp(args[0], "jobs") == 0) {
            printf("No background jobs.\n");
        } else {
            execute_command(args);
        }
    }

    return 0;
}