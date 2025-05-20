//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t launch_shell(char **args);
void handle_signal(int signum);

int main(int argc, char **argv) {
    char input[MAX_COMMANDS];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    printf("Welcome to the Basic Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = launch_shell(args);

        if (pid == -1) {
            printf("Error launching shell.\n");
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    char **tokens;
    int count = 0;
    char *token;

    tokens = malloc(sizeof(char *) * MAX_ARGUMENTS);

    token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;

        if (count >= MAX_ARGUMENTS) {
            break;
        }

        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        return -1;
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user.\n");
    }
}