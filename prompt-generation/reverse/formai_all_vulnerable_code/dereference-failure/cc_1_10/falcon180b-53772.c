//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split(char *str, char delimiter) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, delimiter);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_sigint(int signum) {
    fprintf(stdout, "Interrupted.\n");
    exit(1);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int background = 0;
    int exit_status;

    signal(SIGINT, handle_sigint);

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input, DELIM);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "bg") == 0 || strcmp(args[0], "fg") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "No job found.\n");
            } else {
                int job_id = atoi(args[1]);
                if (job_id < 0 || job_id >= MAX_ARGUMENTS) {
                    fprintf(stderr, "Invalid job ID.\n");
                } else {
                    if (strcmp(args[0], "bg") == 0) {
                        fprintf(stdout, "[%d] %s\n", job_id, args[1]);
                    } else if (strcmp(args[0], "fg") == 0) {
                        execute_command(args);
                    }
                }
            }
        } else {
            if (background == 0) {
                execute_command(args);
            } else {
                fprintf(stdout, "[%d] %s\n", getpid(), args[0]);
                background = 0;
            }
        }
    }

    return 0;
}