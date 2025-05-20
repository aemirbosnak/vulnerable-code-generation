//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char **split_command(char *command);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    args = split_command(input);

    if (args == NULL) {
        printf("Invalid command.\n");
        return 1;
    }

    int status = execute_command(args);

    if (status == -1) {
        printf("Error executing command.\n");
    } else {
        printf("Command executed successfully.\n");
    }

    return status;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        printf("No command specified.\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("execvp failed.\n");
        return -1;
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}