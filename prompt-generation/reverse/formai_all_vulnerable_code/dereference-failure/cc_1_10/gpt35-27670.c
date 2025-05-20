//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void prompt() {
    printf(">> ");
}

void read_command(char *command) {
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    int len = strlen(command);
    if (command[len-1] == '\n') {
        command[len-1] = '\0';
    }
}

int parse_command(char *command, char **args) {
    char *delim = " \t\n";
    int arg_count = 0;
    char *token = strtok(command, delim);
    while (token != NULL && arg_count < MAX_ARGS) {
        args[arg_count++] = token;
        token = strtok(NULL, delim);
    }
    args[arg_count] = NULL;
    return arg_count;
}

int execute_command(char **args) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command\n");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Error forking\n");
    } else {
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        prompt();
        read_command(command);
        if (strcmp(command, "exit") == 0) break;
        int arg_count = parse_command(command, args);
        if (arg_count == 0) continue;
        execute_command(args);
    }

    return 0;
}