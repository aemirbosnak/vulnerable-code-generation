//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter commands, type 'exit' to quit:\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        char *command = strtok(input, DELIM);
        if (strcmp(command, "exit") == 0) {
            break;
        }

        char **args = split_command(command);
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            printf("Fork failed\n");
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (strlen(command) / 2 + 2));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        printf("Fork failed\n");
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("Interrupted by user\n");
    }
}