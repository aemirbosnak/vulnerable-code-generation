//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = NULL;
    char *token;

    while ((token = strtok(command, DELIM))) {
        if (++argc >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Error: Command too long\n");
            exit(1);
        }
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
    }

    argv[argc] = NULL;
    return argv;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_command(input);

    if (args[0] == NULL) {
        printf("Error: Empty command\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}