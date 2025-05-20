//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_command(char *command);
pid_t fork();
int execute_command(char **command);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **command = split_command(input);
        pid_t pid = fork();
        if (pid == 0) {
            execute_command(command);
            exit(0);
        } else if (pid < 0) {
            printf("Error forking\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2 + 1));
    char *token = strtok(command, DELIM);
    int count = 0;
    while (token!= NULL) {
        args[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **command) {
    pid_t pid = fork();
    if (pid == 0) {
        if (command[0] == NULL) {
            return 1;
        }
        if (strcmp(command[0], "exit") == 0) {
            exit(0);
        } else {
            execvp(command[0], command);
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
    return 0;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted\n");
            break;
        case SIGQUIT:
            printf("\nQuit\n");
            exit(0);
        case SIGTERM:
            printf("\nTerminated\n");
            exit(0);
        default:
            printf("Received signal %d\n", signum);
    }
}