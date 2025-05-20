//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t fork();
void execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            pid = fork();

            if (pid == -1) {
                printf("Error forking process\n");
            } else if (pid > 0) {
                wait(NULL);
            } else {
                execute_command(args);
                exit(0);
            }
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    }

    return pid;
}

void execute_command(char **args) {
    int status;
    pid_t pid;

    if (args[0] == NULL) {
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user\n");
    }
}