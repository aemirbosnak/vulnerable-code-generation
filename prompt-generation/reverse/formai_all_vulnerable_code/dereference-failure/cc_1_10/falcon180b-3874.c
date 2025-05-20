//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t launch_shell(char **arguments);
void execute_command(char **arguments);
char *read_line(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Welcome to the Basic Unix-like Shell!\n");
    printf("Please enter your command: ");

    fgets(input, MAX_COMMAND_LENGTH, stdin);
    arguments = split_command(input);

    if (arguments[0] == NULL) {
        printf("Invalid command.\n");
    } else {
        launch_shell(arguments);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t launch_shell(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        printf("Fork failed.\n");
        return -1;
    } else if (pid == 0) {
        execute_command(arguments);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
    }

    return pid;
}

void execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return;
    }

    pid = fork();
    if (pid == -1) {
        printf("Fork failed.\n");
        return;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Command not found.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

char *read_line(void) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    getline(&line, &capacity, stdin);

    return line;
}