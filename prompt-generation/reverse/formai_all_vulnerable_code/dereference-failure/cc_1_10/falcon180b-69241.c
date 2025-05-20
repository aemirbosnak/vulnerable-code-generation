//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
void execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t child_pid;

    while (1) {
        printf("Player 1: ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        arguments = split_string(input_buffer, DELIM);

        if (arguments[0] == NULL) {
            continue;
        }

        child_pid = fork();

        if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (child_pid < 0) {
            printf("Error forking process: %s\n", strerror(errno));
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens;
    char *token;

    tokens = malloc(sizeof(char *) * (MAX_ARGUMENTS + 1));
    if (tokens == NULL) {
        printf("Error allocating memory for tokens\n");
        exit(1);
    }

    token = strtok(string, delimiter);
    while (token!= NULL && count < MAX_ARGUMENTS) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **arguments) {
    pid_t child_pid;
    int status;

    if (arguments[0] == NULL) {
        return;
    }

    child_pid = fork();

    if (child_pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else if (child_pid < 0) {
        printf("Error forking process: %s\n", strerror(errno));
    } else {
        waitpid(child_pid, &status, 0);
    }
}

void print_prompt(void) {
    printf("> ");
}