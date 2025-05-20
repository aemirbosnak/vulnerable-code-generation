//Falcon-180B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define MAX_ENVIRONMENT_VARIABLES 1024

typedef struct {
    char *name;
    char *value;
} environment_variable_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [argument...]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    char **arguments = (char **) malloc((argc - 1) * sizeof(char *));

    int argument_count = 0;
    for (int i = 2; i < argc; i++) {
        arguments[argument_count++] = argv[i];
    }

    char **environment = NULL;
    environment_variable_t *env_vars = NULL;
    int env_var_count = 0;

    if (getenv("PATH") == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set.\n");
        return 1;
    }

    if (chdir("/")!= 0) {
        fprintf(stderr, "Error: Failed to change directory to /\n");
        return 1;
    }

    pid_t child_pid;
    if ((child_pid = fork()) == -1) {
        fprintf(stderr, "Error: Failed to fork process\n");
        return 1;
    } else if (child_pid == 0) {
        if (execve(command, arguments, environment) == -1) {
            fprintf(stderr, "Error: Failed to execute command: %s\n", strerror(errno));
            return 1;
        }
    } else {
        int status;
        waitpid(child_pid, &status, 0);
    }

    return 0;
}