//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 20
#define MAX_ENV_VARIABLES 20

struct argument {
    char *value;
    int length;
};

struct env_variable {
    char *name;
    char *value;
    int length;
};

int main(int argc, char **argv) {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int num_arguments = 0;
    struct argument *arguments = NULL;
    int num_env_variables = 0;
    struct env_variable *env_variables = NULL;

    if (argc < 2) {
        printf("Usage: %s command [argument...]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);
    num_arguments = argc - 2;

    if (num_arguments > 0) {
        arguments = malloc(num_arguments * sizeof(struct argument));

        for (int i = 0; i < num_arguments; i++) {
            arguments[i].value = argv[i + 2];
            arguments[i].length = strlen(argv[i + 2]);
        }
    }

    if (getenv("TERM")!= NULL) {
        num_env_variables = 1;
        env_variables = malloc(num_env_variables * sizeof(struct env_variable));

        env_variables[0].name = "TERM";
        env_variables[0].value = getenv("TERM");
        env_variables[0].length = strlen(getenv("TERM"));
    }

    pid = fork();

    if (pid == 0) {
        char **new_argv = malloc((num_arguments + 2) * sizeof(char *));
        new_argv[0] = command;

        for (int i = 0; i < num_arguments; i++) {
            new_argv[i + 1] = arguments[i].value;
        }
        new_argv[num_arguments + 1] = NULL;

        execve(command, new_argv, env_variables);
        perror("execve");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}