//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **arguments);
void print_prompt(char *prompt);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t child_pid;

    print_prompt("Unix-like Shell>");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (input[0] == '\n' || input[0] == '\r') {
            continue;
        }

        arguments = split_command(input);

        if (arguments[0] == NULL) {
            continue;
        }

        child_pid = fork();

        if (child_pid == -1) {
            printf("Error: fork failed\n");
            exit(1);
        } else if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token;

    token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;

    return arguments;
}

pid_t fork() {
    return fork();
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Error: fork failed\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error: %s not found\n", arguments[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(char *prompt) {
    printf("%s", prompt);
    fflush(stdout);
}