//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
int execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    int status;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        arguments = split_command(input);
        status = execute_command(arguments);

        if (status == -1) {
            printf("Error: command not found\n");
        } else if (status == -2) {
            printf("Error: permission denied\n");
        }

        free(arguments);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        arguments = realloc(arguments, sizeof(char *) * argc);
        arguments[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return -1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

void print_prompt(void) {
    printf("Paranoid Shell > ");
}