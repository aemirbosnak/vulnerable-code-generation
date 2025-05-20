//Falcon-180B DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

char **split_command(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(command, " ");
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork process\n");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Failed to execute command '%s'\n", args[0]);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Command '%s' terminated abnormally\n", args[0]);
            return 1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_command(input);
    status = execute_command(args);

    if (status == 0) {
        printf("Command executed successfully\n");
    } else {
        printf("Command execution failed with status %d\n", status);
    }

    return 0;
}