//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
void execute_command(char **args);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Happy Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **args = split_command(input);
        if (args[0] == NULL) {
            continue;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execute_command(args);
            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            printf("Error forking process.\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    char **args = malloc(sizeof(char *) * (strlen(command) / strlen(token) + 1));
    int arg_count = 0;

    while (token!= NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, DELIM);
    }

    args[arg_count] = NULL;
    return args;
}

pid_t fork(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return pid;
}

void execute_command(char **args) {
    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    } else {
        pid_t pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            printf("Error forking process.\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user.\n");
    }
}

void setup_signals(void) {
    signal(SIGINT, handle_signal);
}