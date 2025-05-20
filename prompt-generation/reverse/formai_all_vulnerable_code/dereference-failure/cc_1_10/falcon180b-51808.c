//Falcon-180B DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <command> <arguments>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *args[MAX_ARGS];
    int num_args = 0;

    for (int i = 2; i < argc; i++) {
        args[num_args] = argv[i];
        num_args++;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        char **new_args = (char **)malloc(sizeof(char *) * (num_args + 1));

        for (int i = 0; i < num_args; i++) {
            new_args[i] = args[i];
        }

        new_args[num_args] = NULL;

        execvp(command, new_args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        // Fork failed
        perror("fork");
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}