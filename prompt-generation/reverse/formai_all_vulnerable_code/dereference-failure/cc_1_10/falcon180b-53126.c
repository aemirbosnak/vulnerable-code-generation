//Falcon-180B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define MAX_ENV_VARIABLES 256

typedef struct {
    char **arguments;
    char **environment;
    int num_arguments;
    int num_environment_variables;
} Command;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [argument1] [argument2]...\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char *token = strtok(argv[1], " ");
    Command cmd;
    cmd.arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    cmd.environment = malloc(MAX_ENV_VARIABLES * sizeof(char*));
    cmd.num_arguments = 0;
    cmd.num_environment_variables = 0;

    while (token!= NULL) {
        if (cmd.num_arguments >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            return 1;
        }
        cmd.arguments[cmd.num_arguments++] = strdup(token);
        token = strtok(NULL, " ");
    }

    if (cmd.num_arguments == 0) {
        printf("No arguments specified.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(cmd.arguments[0], cmd.arguments);
        perror("execvp");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        return 0;
    }
}