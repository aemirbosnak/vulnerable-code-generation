//Falcon-180B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    Command c = {.command = strdup(command),.num_arguments = 0};
    char *token = strtok(command, " ");

    while (token!= NULL) {
        if (c.num_arguments >= MAX_ARGUMENTS) {
            printf("Error: Too many arguments\n");
            return 1;
        }

        c.arguments[c.num_arguments] = strdup(token);
        c.num_arguments++;

        token = strtok(NULL, " ");
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error: Fork failed\n");
        return 1;
    } else if (pid == 0) {
        execvp(c.command, c.arguments);
        printf("Error: Exec failed\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    for (int i = 0; i < c.num_arguments; i++) {
        free(c.arguments[i]);
    }
    free(c.command);
    free(c.arguments);

    return 0;
}