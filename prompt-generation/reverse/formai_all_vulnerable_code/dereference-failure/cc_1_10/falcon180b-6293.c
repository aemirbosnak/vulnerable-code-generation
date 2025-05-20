//Falcon-180B DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command, int *argc) {
    char **args = malloc(sizeof(char *) * (*argc = 1));
    args[0] = strtok(command, DELIM);
    while (args[*argc - 1]!= NULL && strlen(args[*argc - 1]) == 0) {
        free(args[*argc - 1]);
        args[*argc - 1] = strtok(NULL, DELIM);
        (*argc)--;
    }
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

void loop(char *prompt) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int argc;
    int status;

    printf("%s", prompt);
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_command(input, &argc);
    status = execute_command(args);

    free(args);
}

int main() {
    char *prompt = "Enter command: ";
    loop(prompt);

    return 0;
}