//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t launch_shell(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_COMMAND_LEN];
    char **arguments;
    pid_t pid;

    printf("Enter your command: ");
    fgets(input_buffer, MAX_COMMAND_LEN, stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    arguments = split_string(input_buffer);

    pid = launch_shell(arguments);

    waitpid(pid, NULL, 0);

    return 0;
}

char **split_string(char *str) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    int count = 0;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted by user\n");
            break;
        case SIGQUIT:
            printf("\nQuit by user\n");
            break;
        case SIGTERM:
            printf("\nTerminated\n");
            break;
        default:
            printf("\nUnknown signal %d\n", signum);
            break;
    }

    exit(1);
}