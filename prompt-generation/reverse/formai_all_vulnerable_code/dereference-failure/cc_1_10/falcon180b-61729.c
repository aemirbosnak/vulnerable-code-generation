//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(1024 * sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error forking process\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command '%s'\n", args[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_sigint(int signum) {
    fprintf(stderr, "Interrupted by user\n");
    exit(1);
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;
    int exit_status = 0;

    signal(SIGINT, handle_sigint);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "bg") == 0 && args[1]!= NULL) {
            background = 1;
            launch_shell(args);
        } else if (strcmp(args[0], "fg") == 0 && args[1]!= NULL) {
            int pid = atoi(args[1]);
            if (kill(pid, SIGCONT) == -1) {
                fprintf(stderr, "Error resuming process with PID %d\n", pid);
            }
        } else if (strcmp(args[0], "jobs") == 0) {
            fprintf(stdout, "No background jobs currently running\n");
        } else {
            launch_shell(args);
        }
    }

    return 0;
}