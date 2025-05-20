//Falcon-180B DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENVIRONMENT_VARIABLES 10
#define MAX_ENVIRONMENT_VARIABLE_LENGTH 1024
#define MAX_ENVIRONMENT_STRING_LENGTH 8192

typedef struct {
    char *name;
    char *value;
} environment_variable_t;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char **arguments = (char **)malloc((argc - 2) * sizeof(char *));
    int argument_count = 0;

    for (int i = 2; i < argc; i++) {
        if (argument_count >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            return 1;
        }

        arguments[argument_count] = argv[i];
        argument_count++;
    }

    char *shell_command = (char *)malloc(strlen(command) + 1);
    strcpy(shell_command, command);

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Failed to fork\n");
        return 1;
    } else if (pid == 0) {
        if (execve(shell_command, arguments, NULL) == -1) {
            fprintf(stderr, "Failed to execute command\n");
            return 1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}