//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

char *commands[MAX_COMMANDS];
int num_commands = 0;

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(command, command) == -1) {
            fprintf(stderr, "Error executing command '%s'\n", command);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signal) {
    switch (signal) {
        case SIGINT:
            fprintf(stdout, "\nInterrupted by user\n");
            exit(1);
        default:
            fprintf(stdout, "Ignoring signal %d\n", signal);
            break;
    }
}

int main() {
    char input[BUFFER_SIZE];
    char *token;
    signal(SIGINT, handle_signal);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, BUFFER_SIZE, stdin);

        token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "exit") == 0) {
            break;
        } else if (strcmp(token, "cd") == 0) {
            token = strtok(NULL, " ");
            if (token == NULL) {
                fprintf(stderr, "Error: missing directory argument for 'cd'\n");
            } else {
                if (chdir(token) == -1) {
                    fprintf(stderr, "Error: could not change directory to '%s'\n", token);
                }
            }
        } else if (strcmp(token, "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                fprintf(stdout, "%s\n", cwd);
            } else {
                fprintf(stderr, "Error: could not get current working directory\n");
            }
        } else {
            commands[num_commands] = strdup(input);
            num_commands++;
        }
    }

    for (int i = 0; i < num_commands; i++) {
        execute_command(commands[i]);
        free(commands[i]);
    }

    return 0;
}